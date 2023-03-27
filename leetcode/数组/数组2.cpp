//1.给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库内置的 sort 函数的情况下解决这个问题。
//使用冒泡排序:
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        for (int i = 0;i < nums.size() - 1;i++)
//        {
//            for (int j = 0;j < nums.size() - i - 1;j++)
//            {
//                if (nums[j] > nums[j + 1])
//                {
//                    int temp = nums[j + 1];
//                    nums[j + 1] = nums[j];
//                    nums[j] = temp;
//                }
//            }
//        }
//    }
//};
//优化算法，时间复杂度为大On,可保证left前的都是0，right后的都是2，二者之间的也就是1了
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        for (int i = 0;i < nums.size() - 1;i++)
//        {
//            for (int j = 0;j < nums.size() - i - 1;j++)
//            {
//                if (nums[j] > nums[j + 1])
//                {
//                    int temp = nums[j + 1];
//                    nums[j + 1] = nums[j];
//                    nums[j] = temp;
//                }
//            }
//        }
//    }
//};
//4.给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
        int max = nums[0];
        int min = nums[0];
        int x = nums.size();
        for (int i = 1;i < nums.size();i++)
        {
            if (nums[i] >= max)
            {
                max = nums[i];
            }
            if (nums[i] <= min)
            {
                min = nums[i];
            }
        }
        int length = max - min + 1;
        vector<int> v1(x);
        vector<int> v2(length, 0);
        for (int i = 0;i < nums.size();i++)
        {
            v2[nums[i] - min]++;
        }
        v2[0]--;
        for (int i = 1;i < length;i++)
        {
            v2[i] += v2[i - 1];
        }
        for (int i = nums.size() - 1;i >= 0;i--)
        {
            v1[v2[nums[i] - min]] = nums[i];
            v2[nums[i] - min]--;
        }
        return v1[v1.size() - k];
    }
//};
    class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
       //归并排序
       if (m == 0 && n == 1)
        {
            nums1[0] = nums2[0];
            return;
        }
       if (m == 1 && n == 0)
        {
             return;
        }
       int nums3[10000];
       int nums4[10000];
       for(int i = 0;i<m;i++)
       {
           nums3[i] = nums1[i];
       }
       for(int i = 0;i<n;i++)
       {
           nums4[i] = nums2[i];
       }
       nums3[m] = 10000;
       nums4[n] = 10000;
       int x = 0;
       int y = 0;
       for(int i = 0;i<m+n;i++)
       {
           if(nums3[x]>nums4[y])
           {
               nums1[i] = nums4[y];
               y++;
           }
           else
           {
               nums1[i] = nums3[x];
               x++;
           }
       }
    }
};
//5.给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
// 方法一:  
//  class Solution {
//    public:
//        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//        {
//            int x = 0;
//            if (m == 0 && n == 1)
//            {
//                nums1[0] = nums2[0];
//                return;
//            }
//            if (m == 1 && n == 0)
//            {
//                return;
//            }
//            for (int i = m;i < m + n;i++)
//            {
//                nums1[i] = nums2[x];
//                x++;
//            }
//            int max = nums1[0];
//            int min = nums1[0];
//            for (int i = 1;i < m + n;i++)
//            {
//                if (nums1[i] >= max)
//                {
//                    max = nums1[i];
//                }
//                if (nums1[i] <= min)
//                {
//                    min = nums1[i];
//                }
//            }
//            int length = max - min + 1;
//            vector<int> v1(m + n);
//            vector<int> v2(length, 0);
//            for (int i = 0;i < nums1.size();i++)
//            {
//                v2[nums1[i] - min]++;
//            }
//            v2[0]--;
//            for (int i = 1;i < length;i++)
//            {
//                v2[i] += v2[i - 1];
//            }
//            for (int i = nums1.size() - 1;i >= 0;i--)
//            {
//                v1[v2[nums1[i] - min]] = nums1[i];
//                v2[nums1[i] - min]--;
//            }
//            for (int i = 0;i < m + n;i++)
//            {
//                nums1[i] = v1[i];
//            }
//        }
//    };
//方法二:class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//    {
//        //归并排序
//        if (m == 0 && n == 1)
//        {
//            nums1[0] = nums2[0];
//            return;
//        }
//        if (m == 1 && n == 0)
//        {
//            return;
//        }
//        int nums3[10000];
//        int nums4[10000];
//        for (int i = 0;i < m;i++)
//        {
//            nums3[i] = nums1[i];
//        }
//        for (int i = 0;i < n;i++)
//        {
//            nums4[i] = nums2[i];
//        }
//        nums3[m] = 10000;
//        nums4[n] = 10000;
//        int x = 0;
//        int y = 0;
//        for (int i = 0;i < m + n;i++)
//        {
//            if (nums3[x] > nums4[y])
//            {
//                nums1[i] = nums4[y];
//                y++;
//            }
//            else
//            {
//                nums1[i] = nums3[x];
//                x++;
//            }
//        }
//    }
//};
