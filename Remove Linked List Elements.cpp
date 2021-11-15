/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while(head != nullptr && head->val == val)
            head = head->next;
        if(head == nullptr) return head;
        ListNode* back = head;
        ListNode* front = back->next;
        while(front != nullptr)
        {
            while(front != nullptr && front->val == val)
                front = front->next;
            back->next = front;
            back = back->next;
            if(front != nullptr)
                front = front->next;
        }
        return head;
    }
};
