#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//1.给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//class Solution {
//public:
//    bool isValid(string s)
//        stack<char> st;
//    if (s.size() % 2 != 0)//如果长度为奇数，则一定匹配不上，返回false
//        return false;
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (s[i] == '(' || s[i] == '[' || s[i] == '{')//如果是前置括号，则压入栈
//        {
//            st.push(s[i]);
//        }
//        else//到这说明此时是后置括号
//        {
//            if (st.empty())//如果此时栈为空，则没有可以与之匹配的，返回false
//                return false;
//            //如果匹配上了，则将当前栈顶元素删除，继续想字符串后进行查找匹配
//            if (s[i] == ')' && st.top() == '(' ||
//                s[i] == ']' && st.top() == '[' ||
//                s[i] == '}' && st.top() == '{')
//            {
//                st.pop();
//            }
//            else//如果以上情况都不是，说明当前没有匹配上，返回false，例如( '[' 和 ‘}’ )
//                return false;
//        }
//    }
//    //最后全部出栈成功，即可
//    return st.empty();
//};
//2.将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
//    ListNode* dummy = new ListNode(0);
//    ListNode* cur = dummy;
//    while (l1 != nullptr && l2 != nullptr) {
//        ListNode** pp = (l1->val < l2->val) ? &l1 : &l2;
//        cur->next = *pp;
//        cur = cur->next;
//        *pp = (*pp)->next;
//    }
//    cur->next = (l1 == nullptr) ? l2 : l1;
//
//    ListNode* ans = dummy->next;
//    delete dummy;
//    return ans;
//}
//3.给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。
//自己写的，根据水桶装水写的，出错
//int largestRectangleArea(vector<int>& heights)
//{
//    int length = heights.size();
//    int max = 0;
//    //对下标进行排序
//    for (int i = 0;i < length;i++)
//    {
//        if (heights[i] > max)
//        {
//            max = heights[i];
//        }
//    }
//    int left = 0;
//    int right = length - 1;
//    while (left < right)
//    {
//        int x = left + 1;
//        while (x < right)
//        {
//            if (heights[x] < heights[left])
//            {
//                break;
//            }
//            x++;
//        }
//        int a = (x - left) * heights[left] > (x - left + 1) * min(heights[x], heights[left]) ? (x - left) * heights[left] : (x - left + 1) * min(heights[x], heights[left]);
//        max = max > a ? max : a;
//        left++;
//    }
//    return max;
//}
//int main()
//{
//    vector<int> v1{ 2,1,2 };
//    int x = largestRectangleArea(v1);
//    cout << x << endl;
//int FieldSum(vector<int>& v)
//{
//	v.push_back(INT_MAX); // 这里可以理解为需要一个无限高的人挡住栈中的人，不然栈中元素最后无法完全出栈
//		stack<int> st;
//	int sum = 0;
//	for (int i = 0; i < (int)v.size(); i++)
//	{
//		if (st.empty() || v[st.top()] > v[i])//小于栈顶元素入栈
//		{
//			st.push(i);
//		}
//		else
//		{
//			while (!st.empty() && v[st.top()] <= v[i])
//			{
//				int top = st.top();//取出栈顶元素
//				st.pop();
//				sum += (i - top - 1);//这里需要多减一个1
//			}
//			st.push(i);
//		}
//	}
//	return sum;
//}
//int main()
//{
//	vector<int> v1{ 1,2,3,4,5 };
//	int x = FieldSum(v1);
//	cout << x << endl;
//}
//4.给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
//int shang(vector<int> heights);
//int maximalRectangle(vector<vector<char>>& matrix)
//{
//    int len1 = matrix.size();
//    int len2 = matrix[0].size();
//    int max1 = 0;
//    vector<int> v1(len2);
//    for (int i = 0;i < len1;i++)
//    {
//        for (int j = 0;j < len2;j++)
//        {
//            if (matrix[i][j] == '1')
//            {
//                v1[j]++;
//            }
//            else
//            {
//                v1[j] = 0;
//            }
//        }
//        max1 = max(shang(v1), max1);
//    }
//    return max1;
//}
//int shang(vector<int> heights)
//{
//    //构造递减栈
//    stack<int> s1;
//    int top = 0;
//    int sum = 0;
//    heights.push_back(-1);//保证最后所有元素均可pop出
//    for (int i = 0;i < heights.size();i++)
//    {
//        if (s1.empty() || heights[i] >= heights[s1.top()])
//        {
//            s1.push(i);
//        }
//        else
//        {
//            while (!s1.empty() && heights[i] < heights[s1.top()])
//            {
//                top = s1.top();
//                s1.pop();
//                int tmp = (i - top) * heights[top];
//                if (sum < tmp)
//                {
//                    sum = tmp;
//                }
//            }
//            s1.push(top);
//            heights[top] = heights[i];
//        }
//    }
//    return sum;
//}
//int main()
//{
//    vector<char> v2 = { '1','0' };
//    vector<char> v3 = { '1','0' };
//    vector<vector<char>> v1 = {v2,v3};
//    int x = maximalRectangle(v1);
//    cout << x << endl;
//}
//5.设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类 :
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。
//class MinStack {
//public:
//    stack<int> s1;
//    stack<int> s2;//辅助栈
//    MinStack()
//    {
//        //清空
//        while (!s1.empty())
//        {
//            s1.pop();
//        }
//        while (!s2.empty())
//        {
//            s2.pop();
//        }
//        s2.push(INT_MAX);
//    }
//
//    void push(int val)
//    {
//        s1.push(val);
//        int minval = min(s2.top(), val);
//        s2.push(minval);
//    }
//
//    void pop()
//    {
//        s1.pop();
//        s2.pop();
//    }
//
//    int top()
//    {
//        return s1.top();
//    }
//
//    int getMin()
//    {
//        return s2.top();
//    }
//};
//6.给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回 滑动窗口中的最大值 。
//struct MyQueue
//{
//public:     //利用双端队列实现单调队列
//    deque<int> deq;
//    void pop1(int val);
//    void push(int val);
//    int front();
//};
//void MyQueue::pop1(int val)
//{
//    if (!deq.empty() && val == deq.front())
//    {
//        deq.pop_front();
//    }
//}
//void MyQueue::push(int val)
//{
//    while (!deq.empty() && val >= deq.back())
//    {
//        deq.pop_back();
//    }
//    deq.push_back(val);
//}
//int MyQueue::front()
//{
//    return deq.front();
//}
//vector<int> maxSlidingWindow(vector<int>& nums, int k)
//{
//    MyQueue dq;
//    vector<int> v1;
//    for (int i = 0;i < k;i++)
//    {
//        dq.push(nums[i]);
//    }
//    v1.push_back(dq.front());
//    for (int i = k;i < nums.size();i++)
//    {
//        dq.pop1(nums[i - k]);
//        dq.push(nums[i]);
//        v1.push_back(dq.front());
//    }
//    return v1;
//}
//int main()
//{
//    vector<int> v1{ 1,3,-1,-3,5,3,6,7 };
//    vector<int> v2 = maxSlidingWindow(v1, 3);
//    for (int i = 0;i < v2.size();i++)
//    {
//        cout << v2[i] << " ";
//    }
//}
//7.给定一个经过编码的字符串，返回它解码后的字符串。
//编码规则为 : k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
//class Solution {
//public:
//    string decodeString(string s)
//    {
//        string s11 = "";
//        int nums = 0;
//        stack<int> s1;//记录数字
//        stack<string> s2;//记录字母和]
//        for (int i = 0;i < s.size();i++)//入栈
//        {
//            if (s[i] >= '0' && s[i] <= '9')
//            {
//                nums = nums * 10 + (s[i] - 48);
//            }
//            else if (s[i] >= 'a' && s[i] <= 'z')
//            {
//                s11 += s[i];
//            }
//            else if (s[i] == '[')
//            {
//                s1.push(nums);
//                nums = 0;
//                s2.push(s11);
//                s11 = "";
//            }
//            else
//            {
//                //遇到]
//                int x = s1.top();
//                s1.pop();
//                for (int i = 0;i < x;i++)
//                {
//                    s2.top() += s11;//s1是还未入栈的元素
//                }
//                s11 = s2.top();
//                s2.pop();
//            }
//        }
//        return s11;
//    }
//};
//8.给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures)
//    {
//        vector<int> v1(temperatures.size(), 0);
//        deque<int> d1;
//        int length = 0;
//        //递减的队列
//        for (int i = 0;i < temperatures.size();i++)
//        {
//            if (d1.empty() || temperatures[i] <= temperatures[d1.back()])//与队尾元素进行比较
//            {
//                d1.push_back(i);
//            }
//            else
//            {
//                //大于
//                while (!d1.empty() && temperatures[i] > temperatures[d1.back()])
//                {
//                    int x = d1.back();
//                    v1[x] = i - d1.back();
//                    d1.pop_back();
//                }
//                d1.push_back(i);
//            }
//        }
//        return v1;
//    }
//};
//9.给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        //创建桶(数组)，设定128个元素对应0-127ASCII码值，全部赋0
//        vector<int> m(128, 0);
//        //存最大长度
//        int maxlen = 0;
//        //head表示窗口最左边的字母序号：如果出现重复的，比如两个相同的字母a，上一个a在桶里存的m[s[i]]是a+1表示a的下一个位置
//        //那么第二个a出现时，head就=a+1也就是max(head,m[s[i]])，去除了窗口里上一个a，保证窗口里无重复字母
//        int head = 0;
//        //遍历字符串
//        for (int i = 0; i < s.size(); i++) {
//            //修改最左边的字母序号head
//            head = max(head, m[s[i]]);
//			//比如说此时已经存储了abc,无重复,如果有元素重复，那么head值就会改变，相应的计算字符串的长度也就会变化
//            //当前字母对应的ASCII码桶里存下一个位置(i+1)，用于更新head
//            m[s[i]] = i + 1;
//            //更新长度
//            maxlen = max(maxlen, i - head + 1);
//        }
//        return maxlen;
//    }
//};