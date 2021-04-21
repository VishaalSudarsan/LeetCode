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
    
    int findSize(ListNode *node, int size = 0)
    {
        if(node == nullptr)
            return size;
        return findSize(node->next, size+1);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *copy_head = head;
        int length = findSize(head);
        for(int i=0;i<length-n-1;i++)
            head = head->next;
        if(length == n)
            return copy_head->next;
        head->next = head->next->next;
        return copy_head;
    }
};
