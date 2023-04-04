//1.给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n)
//    {
//        ListNode* curr = head;
//        int count = 0;
//        while (curr) {
//            count++;
//            curr = curr->next;
//        }
//        int m = count - n + 1;
//        curr = head;
//        for (int i = 1;i < m - 1;i++) {
//            curr = curr->next;
//        }
//        if (n == 1) {
//            if (count == 1) {
//                //为了防止head->next为NULL
//                head = NULL;
//                return head;
//            }
//        }
//        if (n == count)
//        {
//            //删除第一个元素
//            head = head->next;
//            return head;
//        }
//        curr->next = curr->next->next;
//        return head;
//    }
//};
//2.给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//class Solution {
//public:
//    ListNode* sortList(ListNode* head)
//    {
//        int len = 0;
//        ListNode* r = head;
//        while (r)
//        {
//            len++;
//            r = r->next;
//        }
//        if (!len)
//        {
//            return NULL;
//        }
//        vector<int> v1;
//        ListNode* p = head;
//        for (int i = 0;i < len;i++)
//        {
//            v1.push_back(p->val);
//            p = p->next;
//        }
//        sort(v1.begin(), v1.end());
//        ListNode* q = new ListNode;
//        q->val = v1[0];
//        q->next = NULL;
//        ListNode* s = q;
//        for (int i = 1;i < len;i++)
//        {
//            ListNode* f = new ListNode;
//            f->val = v1[i];
//            f->next = NULL;
//            s->next = f;
//            s = f;
//        }
//        return q;
//    }
//};
//3.给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//图示两个链表在节点 c1 开始相交：
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//    {
//        while (headA)
//        {
//            ListNode* b = headB;
//            while (b)
//            {
//                if (b == headA)
//                {
//                    return b;
//                }
//                if (b->next)
//                {
//                    b = b->next;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            if (headA->next)
//            {
//                headA = headA->next;
//            }
//            else
//            {
//                break;
//            }
//        }
//        return NULL;
//    }
//};
//4.给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head)
//    {
//        if (!head)
//        {
//            return NULL;
//        }
//        vector<int> v1;
//        ListNode* p = head;
//        int len = 0;
//        for (int i = 0;p;i++)
//        {
//            len++;
//            v1.push_back(p->val);
//            p = p->next;
//        }
//        ListNode* q = new ListNode;
//        ListNode* s = new ListNode;
//        q->val = v1[len - 1];
//        q->next = NULL;
//        s = q;
//        for (int i = len - 2;i >= 0;i--)
//        {
//            ListNode* g = new ListNode;
//            g->val = v1[i];
//            g->next = NULL;
//            s->next = g;
//            s = g;
//        }
//        return q;
//    }
//};
