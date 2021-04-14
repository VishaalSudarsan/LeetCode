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
    ListNode* partition(ListNode* temphead, int x) {
        
        ListNode* head = new ListNode(-101, temphead);
        ListNode* pivot, *start = head;
        
        if(head == nullptr || head->next == nullptr)
            return start->next;
        
        while(head->next != nullptr && head->next->val < x)
            head = head->next;
        
        pivot = head;
        
        while(head->next != nullptr)
        {
            if(head->next->val < x)
            {
                ListNode *node1 = head->next->next;
                ListNode *node2 = pivot->next;
                pivot->next = head->next;
                pivot = pivot->next;
                pivot->next = node2;
                head->next = node1;
            }
            else
                head = head->next;
        }
        
        return start->next;
    }
};
