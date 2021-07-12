/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        //迭代
        ListNode *tmp;
        ListNode *cur=head;
        ListNode *pre=NULL;

        while(cur)
        {
            //先存tmp
            tmp=cur->next;
            //转向
            cur->next=pre;
            //更新pre和cur位置
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};