#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* pHead)
{
    if(!pHead||!pHead->next)return pHead;
    ListNode *pre=nullptr;
    ListNode *p=pHead;
    ListNode *next=pHead->next;
    while(p)
    {
        p->next=pre;   //真正换位这一行就够了
        pre=p;         //这三行都是在变换迭代条件
        p=next;
        if(next)
            next=next->next;
    }
    return pre;
}
