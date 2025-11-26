#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	Goods(const char* str=nullptr, double price=0, int evaluate=0)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{
	}

};
int main()
{
	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2)->bool {return g1._price > g2._price; });
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2)->bool { return g1._price < g2._price; });
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2)->bool { return g1._name < g2._name; });
	sort(v.begin(), v.end(), [](Goods& g1, Goods& g2)->bool { return g1._name > g2._name; });

}


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (k == cardPoints.size()) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int sum = INT_MAX, temp = 0, Sum = 0;
        int sz = cardPoints.size();
        for (int i = 0; i < sz; i++)
        {
            temp += cardPoints[i];
            if (i < sz - k - 1)
                continue;
            sum = min(temp, sum);
            temp -= cardPoints[i - sz + k + 1];
        }
        for (auto e : cardPoints)
            Sum += e;
        return Sum - sum;
    }
};