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
    
    int findSize(ListNode *head)
    {
        int size = 0;
        while(head != nullptr)
        {
            head = head->next;
            size++;
        }
        return size;
    }
    
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(k==0 || head ==  nullptr) return head;
        int size = findSize(head);
        k = k%size;
        if(k==0) return head;
        
        ListNode *newhead = head;
        int current_pos = 1;
        while(current_pos != size-k)
        {
            newhead = newhead->next;
            current_pos++;
        }
        ListNode *copyhead = newhead, *tail = newhead;
        newhead = newhead->next;
        while(copyhead->next != nullptr)
            copyhead = copyhead->next;
        copyhead->next = head;
        tail->next = nullptr;
        return newhead;
    }
};
