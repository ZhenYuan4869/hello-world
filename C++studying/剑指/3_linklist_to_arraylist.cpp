/*
题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* curr;
        curr=head;
        int length = 0;
        stack<int> temp_store;
        vector<int> ans;
        while(curr!=nullptr)
        {
            temp_store.push(curr->val);
            curr=curr->next;
            length++;
        }
        for(int i=0;i<length;i++)
        {
            ans.push_back(temp_store.top());
            temp_store.pop();
        }
        return ans;
    }
};