#include <stdio.h>
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//思路:先算出最后的长度，再从头开始，一个一个找等于val的值，在从后往前找不等于的进行对换，最后打印输出。
//int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int x = 0;
    int len = numsSize;
    int k = 0;
    for (i = 0;i < numsSize;i++)
    {
        if (nums[i] == val)
        {
            len--;
        }
    }
    for (x = 0;x < numsSize;x++)
    {
        if (nums[x] == val)
        {
            int j = 0;
            for (j = numsSize - 1;j > x;j--)
            {
                int tmp = 0;
                if (nums[j] != val)
                {
                    tmp = nums[x];
                    nums[x] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
        }
    }
    for (k = 0;k < len;k++)
    {
        printf("%d", nums[k]);
    }
    return len;
}
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 自己尝试错误的
// 
int removeDuplicates(int* nums, int numsSize)
{
    int i = 0;
    int k = 0;
    int x = 0;
    bool flag = false;
    int len = numsSize;
    for (i = 0;i < len;i++)
    {
        int b = i;
        if (i + 1 < len && i - 1 >= 0)
        {
            if (nums[i] == nums[i + 1] && nums[i - 1] == nums[i + 1])
            {
                len--;
                int tmp = 0;
                while (i + 2 < numsSize - k)
                {
                    tmp = nums[i + 1];
                    nums[i + 1] = nums[i + 2];
                    nums[i + 2] = tmp;
                    i++;
                    flag = true;
                }
            }
            i = b;
            if (flag = true)
            {
                k++;
            }
            flag = false;
        }
    }
    for (x = 0;x < len;x++)
    {
        printf("%d", nums[x]);
    }
    return len;
}
int main()
{
    int arr[9] = { 0,0,1,1,1,1,2,3,3 };
    int x = removeDuplicates(arr, 9);
    printf("%d", x);
}
//正确的
//思路:三个为一组比较，若比较出，总长减1，不再考虑，并从三个中最左边开始向右换，之后i--,继续在该位置检测，直到不再出现2个以上为止
int removeDuplicates(int* nums, int numsSize) {
    int ret = numsSize;
    for (int i = 0;i < ret - 2;i++) {
        if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
            for (int j = i;j < ret - 1;j++) {
                nums[j] = nums[j + 1];
            }
            ret -= 1;
            i--;
        }
    }
    return ret;
}
//给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库的sort函数的情况下解决这个问题。
//思路:这道题我本来想着用快速排序进行排序，但是时间复杂度较高并且会出错。
//先找出所有的0,0是要放的到左边的，可以设置一个i,一个j，i每当找到1个0便会加加,i表示的位置即为找到的0所放的位置，j不断++遍历整个数组，找到所有的0；
//接着再从高往低处找，找到所有的2，同上方法
void sortColors(int* nums, int numsSize) {
    if (numsSize != 1) {
        int i, j, k, temp;
        i = 0;
        k = numsSize - 1;
        for (j = 0;j < numsSize;j++) {
            if (nums[j] == 0) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        for (j = numsSize - 1;j >= 0;j--) {
            if (nums[j] == 2) {
                temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
                k--;
            }
        }
    }
}
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
//首先是自己写的，很繁琐。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int x = m;
    int z = 0;
    bool flag = false;
    if (m == 0)
    {
        for (z = 0;z < n;z++)
        {
            nums1[z] = nums2[z];
        }
    }
    for (j = 0;j < n;j++)
    {
        for (i = 0;i < m;i++)
        {
            if (nums1[i] <= nums2[j] && nums2[j] <= nums2[i + 1])
            {
                flag = true;
                nums1[m + k] = nums2[j];
                while (m > i + 1 - k && nums1[m + k] < nums1[m + k - 1])
                {
                    int tmp = 0;
                    tmp = nums1[m + k];
                    nums1[m + k] = nums1[m + k - 1];
                    nums1[m + k - 1] = tmp;
                    m--;
                    flag = true;
                }
                k++;
                m = x;
            }
            if (flag == true)
            {
                flag = false;
                break;
            }
        }
    }
}
int main()
{
    int i = 0;
    int nums1[1] = { 0 };
    int nums2[1] = { 1 };
    merge(nums1, 1, 0, nums2, 1, 1);
    for (i = 0;i < 1;i++)
    {
        printf("%d", nums1[i]);
    }
}
//分成两组进行比较，从后往前，如果1大就放到最后p--，2大也是一样,q--，然后k--，接着再进行比较，防止。若在p到0之后q未到0，需将剩下的继续填入到k中。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = m - 1, q = n - 1, k = nums1Size - 1;
    while (p >= 0 && q >= 0) {
        if (nums1[p] > nums2[q]) {
            nums1[k--] = nums1[p--];
        }
        else {
            nums1[k--] = nums2[q--];
        }
    }
    while (q >= 0) {
        nums1[k--] = nums2[q--];
    }
}