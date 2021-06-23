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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 1;
        ListNode* returnhead = head;
        while(pos < left)
        {
            head = head->next;
            pos++;
        }
        stack<int> reverseelements;
        ListNode* copyhead = head;
        int copypos = pos;
        while(copypos <= right)
        {
            reverseelements.push(copyhead->val);
            copyhead = copyhead->next;
            copypos++;
        }
        while(pos <= right)
        {
            head->val = reverseelements.top();
            reverseelements.pop();
            head = head->next;
            pos++;
        }
        return returnhead;
    }
};
