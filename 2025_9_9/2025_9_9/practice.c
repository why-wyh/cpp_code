#define _CRT_SECURE_NO_WARNINGS 


//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������

//���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����
//
//���� nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
//���� k��
int removeElement(int* nums, int numsSize, int val) {
    int src = 0;
    int dest = 0;
    for (src = 0; src < numsSize; src++)
    {
        if (nums[src] != val)
        {
            nums[dest] = nums[src];
            dest++;
        }
    }
    return dest;
}

//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
//
//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end = m + n - 1;
    int end1 = m - 1;
    int end2 = n - 1;
    while ((end1 + 1) && (end2 + 1))
    {
        if (nums1[end1] >= nums2[end2])
        {
            nums1[end--] = nums1[end1--];

        }
        else {
            nums1[end--] = nums2[end2--];
        }
    }
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}