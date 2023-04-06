#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//1.给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> res;
//        int sub = 0;  //结果vector的下标值
//        string tmp; //临时string
//        unordered_map<string, int> work; //判断排序后单词是否存在，即字母组成是否一致
//        for (auto str : strs)
//        {
//            tmp = str;
//            sort(tmp.begin(), tmp.end());//对字符串进行排序
//            if (work.count(tmp))//查找元素是否存在
//            {
//                res[work[tmp]].push_back(str);//存在则添加到
//            }
//            else
//            {
//                //只要添加过元素，就不会进入到这一步，也就是不会改变同一个work[tmp]的值，也就是说排序后相同的字符会放到相同的下标位置存储
//                vector<string> vec(1, str);
//                res.push_back(vec);
//                work[tmp] = sub++;//
//            }
//        }
//        return res;
//    }
//};
//2.给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
//int longestConsecutive(vector<int>& nums)
//{
//    if (nums.empty())
//    {
//        return 0;
//    }
//    int max = 0;
//    sort(nums.begin(), nums.end());
//    unordered_map<int, int> m1;
//    int len = 0;
//    for (int i = 0;i < nums.size();i++)
//    {
//        if (m1.empty() || len == 0)
//        {
//            len++;
//            m1[nums[i]]++;
//        }
//        else if (nums[i] == nums[i - 1] + 1 && !m1.count(nums[i]))
//        {
//            m1[nums[i]]++;
//            len++;
//        }
//        else if (nums[i] == nums[i - 1])
//        {
//            continue;
//        }
//        else
//        {
//            i--;
//            max = max > len ? max : len;
//            len = 0;
//        }
//
//    }
//    max = max > len ? max : len;
//    return max;
//}
//int main()
//{
//    vector<int> v1{ -1,-1,0,1,3,4,5,6,7,8,9 };
//    int a = longestConsecutive(v1);
//    cout << a << endl;
//
//}
//3.给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
//class Solution {
//public:
//    bool hasCycle(ListNode* head)
//    {
//        if (!head)
//        {
//            return false;
//        }
//        ListNode* fast = head->next;
//        ListNode* low = head;
//        while (true)
//        {
//            if (!fast || !fast->next)
//            {
//                return false;
//            }
//            else if (fast == low || fast->next == low)
//            {
//                return true;
//            }
//            else
//            {
//                fast = fast->next->next;
//                low = low->next;
//            }
//        }
//    }
//};
//4.请你设计并实现一个满足  LRU(最近最少使用) 缓存 约束的数据结构。
//实现 LRUCache 类：
//LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
//int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 - 1 。
//void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key - value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
//函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
//class LRUCache {
//public:
//
//    //定义双链表
//    struct Node {
//        int key, value;
//        Node* left, * right;
//        Node(int _key, int _value) : key(_key), value(_value), left(NULL), right(NULL) {}
//    }*L, * R;//双链表的最左和最右节点，不存贮值。
//    int n;
//    unordered_map<int, Node*>hash;
//
//    void remove(Node* p)
//    {
//        p->right->left = p->left;
//        p->left->right = p->right;
//    }
//    void insert(Node* p)
//    {
//        p->right = L->right;
//        p->left = L;
//        L->right->left = p;
//        L->right = p;
//    }
//    LRUCache(int capacity) {
//        n = capacity;
//        L = new Node(-1, -1), R = new Node(-1, -1);
//        L->right = R;
//        R->left = L;
//    }
//
//    int get(int key) {
//        if (hash.count(key) == 0) return -1; //不存在关键字 key 
//        auto p = hash[key];
//        remove(p);
//        insert(p);//将当前节点放在双链表的第一位
//        return p->value;
//    }
//
//    void put(int key, int value) {
//        if (hash.count(key)) //如果key存在，则修改对应的value
//        {
//            auto p = hash[key];
//            p->value = value;
//            remove(p);
//            insert(p);
//        }
//        else
//        {
//            if (hash.size() == n) //如果缓存已满，则删除双链表最右侧的节点
//            {
//                auto  p = R->left;
//                remove(p);
//                hash.erase(p->key); //更新哈希表
//                delete p; //释放内存
//            }
//            //否则，插入(key, value)
//            auto p = new Node(key, value);
//            hash[key] = p;
//            insert(p);
//        }
//    }
////};
//5.给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int sum = 0, ans = 0;
//        unordered_map<int, int> mp;
//        mp[0] = 1;
//        for (int i : nums) {
//            sum += i;
//            if (mp.find(sum - k) != mp.end()) ans += mp[sum - k];
//            mp[sum] ++;
//        }
//        return ans;
//    }
//};