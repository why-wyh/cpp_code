#define _CRT_SECURE_NO_WARNINGS 


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//
//更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//返回 k。
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

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

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