#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//struct SignalNode
//{
//
//};
//
//int main()
//{
//	char s[80], c = 'a';                   // 问题：为何是s[80]，s[20]不可以吗，s[800]呢？ 
//	int i = 0;
//	scanf("%s", s);
//	while (s[i] != '\0')
//	{
//		if (s[i] == c) s[i] = s[i] - 32;         // 问题：语句含义？为什么是32。
//		else if (s[i] == c - 32) s[i] = s[i] + 32; // 问题：语句含义？为什么是32。
//		i++;
//	}
//	puts(s);
//	return 0;
//}
//
//
//class Solution {
//public:
//    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//        int s[2] = { 0 }, max_s = 0;
//        for (int i = 0; i < customers.size(); i++)
//        {
//            s[grumpy[i]] += customers[i];
//            if (i - minutes + 1 < 0)
//                continue;
//            max_s = max(max_s, s[1]);
//            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
//        }
//
//        return s[0] + max_s;
//    }
//};
//
//int main()
//{
//	
//	for (int i = 200; i <= 300; i++)
//	{
//		int sum = 0, n = 1;
//		int temp = i;
//		while (temp)
//		{
//			sum += temp % 10;
//			n *= temp % 10;
//			temp /= 10;
//		}
//		if (sum == 12 && n == 42)
//			printf("%d  ", i);
//	}
//	return 0;
//}
//int func(int i)
//{
//	if (i == 0)
//		return 1;
//	return func(i - 1) * i;
//}
//int main()
//{
//	for (int i = 100; i <= 999; i++)
//	{
//		int sum = 0, temp = i;
//		while (temp)
//		{
//			sum+=func(temp % 10);
//			temp /= 10;
//		}
//		if (sum == i)
//			printf("%d  ", i);
//	}
//
//	return 0;
//}
//int main()
//{
//	float h, m, n;
//	scanf("%d %d %d", &h, &m, &n);
//	float d = h / (m - n);
//	if (d - (int)d)
//		printf("%d", (int)d + 1);
//	else
//		printf("%d", d);
//	return 0;
//}


//int main()
//{
//    float sum = 0;
//    int arr1[30] = { 0 };
//    float arr2[26] = { 0 };
//    for (int i = 0; i < 30; i++)
//    {
//        arr1[i] = (i * 2) + 2;
//    }
//    int j = 0;
//    for (int i = 0; i < 30; i++)
//    {
//        sum += arr1[i];
//        if (i < 4)
//            continue;
//        arr2[j] = sum / 5.0f;
//        j++;
//        sum -= arr1[i - 4];
//    }
//    for (int i = 0; i < 26; i++)
//        printf("arr2[%d]=%.1f\n", i, arr2[i]);
//    return 0;
//}


//int main()
//{
//	int arr[5][5],k=1,sum=0;
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < 5; j++)
//		{
//			arr[i][j] = k++;
//			if (j <= i)
//				sum += k;
//		}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int a[10] = { 0},i=0;
//	while (i < 10)
//		scanf("%d", a+i++);
//	int b[9];
//	for ( i = 0; i < 9; i++)
//	{
//		b[i] = a[i + 1] / a[i];
//		printf("b[%d]=%d\n", i, b[i]);
//	}
//	return 0;
//}
int midfind(int arr[], int x)
{
	int left = 0,right=sizeof(arr);
	
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < x)
			left = mid;
		else
			right = mid;
	}
	return right;
}
int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d", midfind(a, 6));
	return 0;
}