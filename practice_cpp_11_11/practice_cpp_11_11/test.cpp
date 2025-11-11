#include"priority.h"
//#define _CRT_SECURE_NO_WARNINGS 
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector f(strs.size() + 1, vector(m + 1, vector<int>(n + 1)));
//        for (int i = 0; i < strs.size(); i++) {
//            int cnt0 = ranges::count(strs[i], '0');
//            int cnt1 = strs[i].size() - cnt0;
//            for (int j = 0; j <= m; j++) {
//                for (int k = 0; k <= n; k++) {
//
//                    if (j >= cnt0 && k >= cnt1) {
//                        f[i + 1][j][k] = max(f[i][j][k], f[i][j - cnt0][k - cnt1] + 1);
//                    }
//                    else {
//                        f[i + 1][j][k] = f[i][j][k];
//                    }
//                }
//            }
//        }
//        return f.back()[m][n];
//    }
//};
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector f(strs.size() + 1, vector(m + 1, vector<int>(n + 1)));
//        for (int i = 0; i < strs.size(); i++)
//        {
//            int cont0 = ranges::count(strs[i], '0');
//            int cont1 = strs[i].size() - cont0;
//            for (int j = 0; j <= m; j++)
//            {
//                for (int k = 0; k <= n; k++)
//                {
//                    if (j >= cont0 && k >= cont1)
//                    {
//                        f[i + 1][j][k] = max(f[i][j][k], f[i][j - cont0][k - cont1] + 1);
//                    }
//                    else {
//                        f[i + 1][j][k] = f[i][j][k];
//
//                    }
//                }
//            }
//        }
//        return f.back()[m][n];
//    }
//};
int main()
{
	why::test_priority_queue();
}