//1.给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
//class Solution {
//public:
//    bool canConstruct(string ransomNote, string magazine) {
//        if (ransomNote.size() > magazine.size())
//        {
//            return false;
//        }
//        bool panduan = false;
//        for (int i = 0;i < ransomNote.size();i++)
//        {
//            for (int j = 0;j < magazine.size();j++)
//            {
//                if (ransomNote[i] == magazine[j])
//                {
//                    panduan = true;
//                    magazine[j] = ' ';
//                    break;
//                }
//            }
//            if (panduan == false)
//            {
//                return false;
//            }
//            panduan = false;
//        }
//        return true;
//    }
//};
//2.给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//class Solution {
//public:
//    ListNode* middleNode(ListNode* head) {
//        ListNode* p;
//        p = head;
//        int length = 0;
//        while (p)
//        {
//            p = p->next;
//            length++;
//        }
//        int middle = length / 2;
//        ListNode* q = head;
//        for (int i = 0;i < middle;i++)
//        {
//            q = q->next;
//        }
//        return q;
//    }
//};
//3.给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
//answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
//answer[i] == "Fizz" 如果 i 是 3 的倍数。
//answer[i] == "Buzz" 如果 i 是 5 的倍数。
//answer[i] == i （以字符串形式）如果上述条件全不满足。
//class Solution {
//public:
//    vector<string> fizzBuzz(int n) {
//        vector<string> answer;
//        for (int i = 1;i < n + 1;i++)
//        {
//            string s1;
//            if (i % 5 == 0 && i % 3 == 0)
//            {
//                s1 += "FizzBuzz";
//            }
//            else if (i % 3 == 0)
//            {
//                s1 += "Fizz";
//            }
//            else if (i % 5 == 0)
//            {
//                s1 += "Buzz";
//            }
//            else
//            {
//                s1 += to_string(i);
//            }
//            answer.push_back(s1);
//        }
//        return answer;
//    }
//};
//4.给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。
//客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
//class Solution {
//public:
//    int maximumWealth(vector<vector<int>>& accounts) {
//        int sum = 0;int max = 0;
//        for (int i = 0;i < accounts.size();i++)
//        {
//            for (int j = 0;j < accounts[i].size();j++)
//            {
//                sum += accounts[i][j];
//            }
//            if (sum >= max)
//            {
//                max = sum;
//            }
//            sum = 0;
//        }
//        return max;
//    }
//};
//5.给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
//class Solution {
//public:
//    int numberOfSteps(int num) {
//        int time = 0;
//        while (num != 0)
//        {
//            if (num % 2 == 0)
//            {
//                num = num / 2;
//                time++;
//            }
//            else
//            {
//                num--;
//                time++;
//            }
//        }
//        return time;
//    }
//};
//6.给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
//请返回 nums 的动态和。
//class Solution
//{
//public:
//    vector<int> runningSum(vector<int>& nums)
//    {
//        int sum = 0;
//        vector<int> v;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            sum += nums[i];
//            v.push_back(sum);
//        }
//        return v;
//    }
//};
//
//
