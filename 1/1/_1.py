# -*- coding: utf-8 -*-
"""
Excel数据Beta回归分析脚本
功能：从Excel文件中读取指定列数据，进行Beta回归分析并生成报告
"""

import numpy as np
import pandas as pd
import statsmodels.api as sm
import statsmodels.formula.api as smf
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats
import warnings
warnings.filterwarnings('ignore')

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

def load_and_preprocess_data(file_path, dependent_var, independent_vars, sheet_name=0):
    """
    从Excel加载数据并预处理
    
    参数:
    file_path: Excel文件路径
    dependent_var: 因变量列名
    independent_vars: 自变量列名列表
    sheet_name: Excel工作表名称或索引，默认为第一个工作表
    
    返回:
    预处理后的DataFrame
    """
    try:
        # 读取Excel文件
        df = pd.read_excel(file_path, sheet_name=sheet_name)
        print(f"成功读取Excel文件，数据形状: {df.shape}")
        
        # 选择需要的列
        selected_cols = [dependent_var] + independent_vars
        df = df[selected_cols].copy()
        print(f"选择的列: {selected_cols}")
        
        # 检查缺失值
        missing_values = df.isnull().sum()
        if missing_values.any():
            print(f"发现缺失值:\n{missing_values[missing_values > 0]}")
            df = df.dropna()
            print(f"删除缺失值后数据形状: {df.shape}")
        
        # 检查因变量范围
        y_min, y_max = df[dependent_var].min(), df[dependent_var].max()
        print(f"因变量范围: [{y_min}, {y_max}]")
        
        # 调整边界值（如果因变量包含0或1）
        if y_min <= 0 or y_max >= 1:
            n = len(df)
            df[f'{dependent_var}_adj'] = (df[dependent_var] * (n - 1) + 0.5) / n
            print("已调整因变量边界值")
            dependent_var_used = f'{dependent_var}_adj'
        else:
            dependent_var_used = dependent_var
        
        return df, dependent_var_used
    
    except Exception as e:
        print(f"读取或处理数据时出错: {e}")
        return None, None

def perform_beta_regression(df, dependent_var, independent_vars):
    """
    执行Beta回归分析
    
    参数:
    df: 包含数据的DataFrame
    dependent_var: 因变量列名
    independent_vars: 自变量列名列表
    
    返回:
    拟合的Beta回归模型
    """
    # 创建公式
    formula = f'{dependent_var} ~ ' + ' + '.join(independent_vars)
    print(f"回归公式: {formula}")
    
    try:
        # 拟合Beta回归模型
        model = smf.betareg(formula, data=df).fit()
        print("Beta回归模型拟合成功!")
        return model
    except Exception as e:
        print(f"拟合Beta回归模型时出错: {e}")
        return None

def generate_diagnostics(model, df, dependent_var):
    """
    生成模型诊断图
    
    参数:
    model: 拟合的Beta回归模型
    df: 数据DataFrame
    dependent_var: 因变量列名
    """
    # 创建诊断图
    fig, axes = plt.subplots(2, 2, figsize=(12, 10))
    fig.suptitle('Beta回归模型诊断图', fontsize=16)
    
    # 残差 vs 拟合值图
    residuals = model.resid_deviance
    fitted = model.fittedvalues
    axes[0, 0].scatter(fitted, residuals, alpha=0.6)
    axes[0, 0].axhline(y=0, color='r', linestyle='--')
    axes[0, 0].set_xlabel('拟合值')
    axes[0, 0].set_ylabel('残差')
    axes[0, 0].set_title('残差 vs 拟合值')
    
    # Q-Q图
    stats.probplot(residuals, dist="norm", plot=axes[0, 1])
    axes[0, 1].set_title('残差Q-Q图')
    
    # 残差直方图
    axes[1, 0].hist(residuals, bins=20, alpha=0.7, edgecolor='black')
    axes[1, 0].set_xlabel('残差')
    axes[1, 0].set_ylabel('频率')
    axes[1, 0].set_title('残差分布')
    
    # 实际值 vs 预测值
    axes[1, 1].scatter(model.fittedvalues, df[dependent_var], alpha=0.6)
    min_val = min(model.fittedvalues.min(), df[dependent_var].min())
    max_val = max(model.fittedvalues.max(), df[dependent_var].max())
    axes[1, 1].plot([min_val, max_val], [min_val, max_val], 'r--')
    axes[1, 1].set_xlabel('预测值')
    axes[1, 1].set_ylabel('实际值')
    axes[1, 1].set_title('实际值 vs 预测值')
    
    plt.tight_layout()
    plt.savefig('beta_regression_diagnostics.png', dpi=300, bbox_inches='tight')
    plt.show()

def plot_partial_effects(model, df, independent_vars):
    """
    绘制部分效应图
    
    参数:
    model: 拟合的Beta回归模型
    df: 数据DataFrame
    independent_vars: 自变量列名列表
    """
    n_vars = len(independent_vars)
    n_cols = min(3, n_vars)
    n_rows = (n_vars + n_cols - 1) // n_cols
    
    fig, axes = plt.subplots(n_rows, n_cols, figsize=(5*n_cols, 4*n_rows))
    if n_vars == 1:
        axes = [axes]
    else:
        axes = axes.flatten()
    
    fig.suptitle('Beta回归部分效应图', fontsize=16)
    
    for i, var in enumerate(independent_vars):
        if i >= len(axes):
            break
            
        # 创建预测网格
        if df[var].dtype == 'object' or len(df[var].unique()) < 5:
            # 分类变量或取值较少的变量
            unique_vals = df[var].unique()
            pred_data = pd.DataFrame({var: unique_vals})
            
            # 保持其他变量为均值/众数
            for other_var in independent_vars:
                if other_var != var:
                    if df[other_var].dtype == 'object':
                        pred_data[other_var] = df[other_var].mode()[0]
                    else:
                        pred_data[other_var] = df[other_var].mean()
            
            # 预测
            predictions = model.predict(pred_data)
            
            # 绘制条形图
            axes[i].bar(range(len(unique_vals)), predictions)
            axes[i].set_xticks(range(len(unique_vals)))
            axes[i].set_xticklabels(unique_vals, rotation=45)
            axes[i].set_xlabel(var)
            axes[i].set_ylabel('预测值')
            
        else:
            # 连续变量
            unique_vals = np.linspace(df[var].min(), df[var].max(), 100)
            pred_data = pd.DataFrame({var: unique_vals})
            
            # 保持其他变量为均值/众数
            for other_var in independent_vars:
                if other_var != var:
                    if df[other_var].dtype == 'object':
                        pred_data[other_var] = df[other_var].mode()[0]
                    else:
                        pred_data[other_var] = df[other_var].mean()
            
            # 预测
            predictions = model.predict(pred_data)
            ci_lower = model.predict(pred_data, which='mean_ci_lower')
            ci_upper = model.predict(pred_data, which='mean_ci_upper')
            
            # 绘制线图
            axes[i].plot(unique_vals, predictions, linewidth=2)
            axes[i].fill_between(unique_vals, ci_lower, ci_upper, alpha=0.2)
            axes[i].set_xlabel(var)
            axes[i].set_ylabel('预测值')
        
        axes[i].set_title(f'{var}的部分效应')
    
    # 隐藏多余的子图
    for j in range(i+1, len(axes)):
        axes[j].set_visible(False)
    
    plt.tight_layout()
    plt.savefig('beta_regression_partial_effects.png', dpi=300, bbox_inches='tight')
    plt.show()

def interpret_results(model, df, dependent_var, independent_vars):
    """
    解释Beta回归结果
    
    参数:
    model: 拟合的Beta回归模型
    df: 数据DataFrame
    dependent_var: 因变量列名
    independent_vars: 自变量列名列表
    """
    print("="*50)
    print("BETA回归分析结果解释")
    print("="*50)
    
    # 显示模型摘要
    print("\n模型摘要:")
    print(model.summary())
    
    # 计算伪R²
    pseudo_r2 = model.pseudo
