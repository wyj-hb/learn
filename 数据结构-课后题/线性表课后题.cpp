#include<iostream>
using namespace std;
//（1）将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中不允许有重复的数据。
typedef struct Lnode
{
    float data;
    struct Lnode* next;
}Lnode,*LinkList;
//void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) 
//{
//    LinkList pa = La->next;  LinkList pb = Lb->next;
//    LinkList pc = Lc = La; //用La的头结点作为Lc的头结点 
//    while (pa && pb) {
//        if (pa->data < pb->data) { pc->next = pa;pc = pa;pa = pa->next; }
//        else if (pa->data > pb->data) { pc->next = pb; pc = pb; pb = pb->next; }
//        else {// 相等时取La的元素，删除Lb的元素
//            pc->next = pa;pc = pa;pa = pa->next;
//            LinkList q = pb->next;delete pb;pb = q;
//        }
//    }
//    pc->next = pa ? pa : pb;    //插入剩余段  
//    delete Lb;             //释放Lb的头结点}  
//}
//（2）将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中允许有重复的数据。
//void unionl(LinkList& La, LinkList& Lb, LinkList& Lc)
//{
//    LinkList pa = La->next;  LinkList pb = Lb->next;
//    LinkList pc = Lc = La; //用La的头结点作为Lc的头结点 
//    Lc->next = NULL;
//    while (pa || pb) {
//        LinkList q;
//        if (!pa) { q = pb;  pb = pb->next; }
//        else if (!pb) { q = pa;  pa = pa->next; }
//        else if (pa->data <= pb->data) { q = pa;  pa = pa->next; }
//        else { q = pb;  pb = pb->next; }
//        q->next = Lc->next;  Lc->next = q;    // 插入
//    }
//    delete Lb;             //释放Lb的头结点}  
//}
//（3）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出A与B的交集，并存放于A链表中。
//void Mix(LinkList& La, LinkList& Lb, LinkList& Lc) 
//{
//    LinkList pa = La->next;  LinkList pb = Lb->next;
//    LinkList pc = Lc = La; //用La的头结点作为Lc的头结点 
//    while (pa && pb)
//        if (pa->data == pb->data)//交集并入结果表中。
//        {
//            pc->next = pa;pc = pa;pa = pa->next;
//            LinkList u = pb;pb = pb->next; delete u;
//        }
//        else if (pa->data < pb->data) { LinkList u = pa;pa = pa->next; delete u; }
//        else { LinkList u = pb; pb = pb->next; delete u; }
//    while (pa) { LinkList u = pa; pa = pa->next; delete u; }//释放结点空间
//    while (pb) {
//        LinkList u = pb; pb = pb->next; delete u; //释放结点空间
//        pc->next = NULL;//置链表尾标记。
//        delete Lb;
//}
//（4）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B 的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素个数。
//void  Difference（LinkList A ,LinkList B, LinkList* n）
//{ p = A->next;                  //p和q分别是链表A和B的工作指针。
//    q = B->next;
//    LinkList pre = A;       //pre为A中p所指结点的前驱结点的指针。
// while（p != null && q != null)
//if（p->data < q->data）{pre = p；p = p->next;*n++；}//A链表中当前结点指针后移。
//else if（p->data > q->data）q = q->next; //B链表中当前结点指针后移。
//else {
//    pre->next = p->next;        //处理A，B中元素值相同的结点，应删除。
//    LinkList u = p； p = p->next; delete u;
//}  //删除结点
//（5）设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B、C，其中B表的结点为A表中值小于零的结点，而C表的结点为A表中值大于零的结点（链表A的元素类型为整型，要求B、C表利用A表的结点）。
//void fenjie(LinkList A, LinkList B, LinkList C)
//{
//    B = C = A;
//    LinkList q= A->next;
//    LinkList p =B->next;
//    LinkList r =C->next;
//    while (q)
//    {
//        if (q->data < 0)
//        {
//            p = q;
//            q = q->next;
//        }
//        else if (q->data > 0)
//        {
//            r = q;
//            q = q->next;
//        }
//        else
//        {
//            q = q->next;
//        }
//    }
//    B->next = NULL;
//    C->next = NULL;
//}
//（6）设计一个算法，通过一趟遍历在单链表中确定值最大的结点。
//int Max(LinkList L) {
//	if (L->next == NULL) return NULL;
//	LinkList pmax = L->next; //假定第一个结点中数据具有最大值
//	LinkList p = L->next->next;
//	while (p != NULL) {//如果下一个结点存在
//		if (p->data > pmax->data) pmax = p;
//		p = p->next;
//	}
//	return pmax->data;
//}
//（7）设计一个算法，通过遍历一趟，将链表中所有结点的链接方向逆转，仍利用原表的存储空间。
//void  inverse(LinkList& L) {
//    // 逆置带头结点的单链表 L
//    LinkList p = L->next;  L->next = NULL;
//    while (p) {
//        LinkList q = p->next;    // q指向*p的后继
//        p->next = L->next;
//        L->next = p;       // *p插入在头结点之后
//        p = q;
//    } 
//}
//（8）设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素（mink和maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同 ）。
//void de(LinkList& L, int mink, int maxk) {
//    LinkList p = L->next; //首元结点
//    LinkList pre;
//    while (p && p->data <= mink)
//    {
//        pre = p;  p = p->next;
//    } //查找第一个值>mink的结点
//    if (p) {
//        while (p && p->data < maxk)  p = p->next;
//        // 查找第一个值 ≥maxk 的结点
//        LinkList q = pre->next;  pre->next = p;  // 修改指针
//        while (q != p)
//        {
//           LinkList s = q->next;  delete q;  q = s;
//        } // 释放结点空间
//    }
//}
//9）已知p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，写出算法change(p), 交换p所指向的结点和它的前缀结点的顺序。
//void  Exchange（LinkedList p）//p是双向循环链表中的一个结点，本算法将p所指结点与其前驱结点交换。
//{ q = p->llink；
// q->llink->rlink = p；   
// p->llink = q->llink；  
// q->rlink = p->rlink；  
// q->llink = p；         
// p->rlink->llink = q；  
// p->rlink = q；     
//}
//（10）已知长度为n的线性表A采用顺序存储结构，请写一时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为item的数据元素。
//void  DE(int A[], int n,int item)
//{
//    int i = 0;int j = n;
//    while (i < j)
//    {
//        if (A[i] == n)
//        {
//            while (true)
//            {
//                if (A[j] != item)
//                {
//                    A[j] = A[i];
//                    break;
//                }
//                else
//                {
//                    j--;
//                }
//            }
//            i++;
//        }
//        else
//        {
//            i++;
//        }
//    }
//}

