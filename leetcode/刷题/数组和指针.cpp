#include<iostream>
using namespace std;
//1.给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        vector<int> v1;
//        for (int i = 0;i < nums.size();i++)
//        {
//            for (int j = i + 1;j < nums.size();j++)
//            {
//                if (nums[i] + nums[j] == target)
//                {
//                    v1.push_back(i);
//                    v1.push_back(j);
//                    return v1;
//                }
//            }
//        }
//        return v1;
//    }
//};
//2.给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log(m + n)) 。
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<double> v1;
//        int i = 0;
//        int j = 0;
//        while (i < nums1.size() && j < nums2.size())
//        {
//            if (nums1[i] > nums2[j])
//            {
//                v1.push_back(nums2[j]);
//                j++;
//            }
//            else
//            {
//                v1.push_back(nums1[i]);
//                i++;
//            }
//        }
//        if (i == nums1.size())
//        {
//            for (;j < nums2.size();j++)
//            {
//                v1.push_back(nums2[j]);
//            }
//        }
//        else
//        {
//            for (;i < nums1.size();i++)
//            {
//                v1.push_back(nums1[i]);
//            }
//        }
//        int len = nums1.size() + nums2.size();
//        if (len % 2 == 0)
//        {
//            return (v1[len / 2 - 1] + v1[len / 2]) / 2;
//        }
//        else
//        {
//            return v1[len / 2];
//        }
//
//    }
//};
//3.给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//你返回所有和为 0 且不重复的三元组。注意：答案中不可以包含重复的三元组。
// 思想:首先对容器进行排序，然后选择要查找的，从第一项开始，如果与前两项和>0,就break,说明不会存在<0的了，将该项与最后两项相加，如果小于0说明该项太小，找下一项，并且如果该项与上一项相等，跳过即可，因为要么上一项未找到
// ，那么该项也找不到；要么上一项找到了该项去找会重复，找到之后如果找到大于0的了，进入循环;
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> ans;
//        int n = nums.size();
//        for (int i = 0; i < n - 2; ++i) {
//            int x = nums[i];
//            if (i && x == nums[i - 1]) continue; // 跳过重复数字
//            if (x + nums[i + 1] + nums[i + 2] > 0) break; // 优化一
//            if (x + nums[n - 2] + nums[n - 1] < 0) continue; // 优化二
//            int j = i + 1, k = n - 1;
//            while (j < k) {
//                int s = x + nums[j] + nums[k];
//                if (s > 0) --k;
//                else if (s < 0) ++j;
//                else {
//                    ans.push_back({ x, nums[j], nums[k] });
//                    for (++j; j < k && nums[j] == nums[j - 1]; ++j); // 跳过重复数字
//                    for (--k; k > j && nums[k] == nums[k + 1]; --k); // 跳过重复数字
//                }
//            }
//        }
//        return ans;
//    }
//};
//4.给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//注意：
//对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
//如果 s 中存在这样的子串，我们保证它是唯一的答案。
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //设置哈希表用来存放窗口值以及进行比较的值
//        unordered_map<char, int> need, win;
//        //将我们所需要的值加入到哈希表（需要进行比较的值）
//        for (auto& i : t) ++need[i];
//        int left = 0, right = 0, count = 0, len = INT_MAX, start = 0;
//        //开始对窗口进行处理
//        while (right < s.size())
//        {
//            //如果我们此时字符串中的元素在我们的需要窗口中的话
//            //我们就需要扩充窗口
//            if (need.find(s[right]) != need.end())
//            {
//                //此时进行扩充窗口
//                ++win[s[right]];
//                //运用count来进行确保我们此时的窗口值完全覆盖了我们需要的子串
//                if (win[s[right]] == need[s[right]])
//                {
//                    ++count;
//                }
//            }
//            //如果此时的窗口值完全覆盖了我们需要的子串，就要进行缩小窗口的操作
//            //此时从left到right已经完全包含了我们要找的字符串
//            while (count == need.size()) {
//                //这里是进行更新我们的最小子串
//                //为什么要更新呢?是因为我们前面的处理是只要该元素存在于t中我们便right++了，但可能我们只需要一个该元素，但是连续加入两个，因此我们要缩小
//                if (len > right - left + 1)
//                {
//                    start = left;
//                    len = right - left + 1;
//                }
//                //这里开始对窗口进行处理
//                //如果此时的窗口左侧的值在我们的哈希表中的话
//                //就要进行判断是否要对count进行处理
//                if (need.find(s[left]) != need.end())
//                {
//                    //如果此时的窗口左侧的值在哈希表中且数量和哈希表中的数量一致
//                    //就对count计数位进行减一操作
//                    if (need[s[left]] == win[s[left]])
//                    {
//                        --count;
//                    }
//                    //将窗口左侧的值进行减一，缩小窗口直到与存于need中的相等
//                    --win[s[left]];
//                }
//                ++left;
//            }
//            ++right;
//        }
//        return len == INT_MAX ? "" : s.substr(start, len);
//    }
//};
//5.给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 - 1
//则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。
//class Solution {
//public:
//    ListNode* EntryNodeOfLoop(ListNode* pHead)
//    {
//        if (!pHead)
//            return null;
//        map<ListNode*, int> flag;//统计节点访问次数
//        while (pHead)
//        {
//            if (++flag[pHead] == 2)
//                return pHead;
//            pHead = pHead->next;
//        }
//        return null;
//
//    }
//};
//6.给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
//class Solution {
//public:
//    bool isPalindrome(ListNode* head)
//    {
//        map<ListNode*, int> m1;
//        map<ListNode*, int> m2;
//        int len = 0;
//        ListNode* p = head;
//        while (head)
//        {
//            len++;
//            head = head->next;
//        }
//        if (len == 0)
//        {
//            return false;
//        }
//        int arr[len];
//        int x = 0;
//        while (p)
//        {
//            arr[x] = p->val;
//            x++;
//            p = p->next;
//        }
//        for (int i = 0;i < len;i++)
//        {
//            if (arr[i] != arr[len - 1 - i])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
7.