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
        int pos = 0;
        ListNode* dummyhead = new ListNode(0, head);
        head = dummyhead;
        ListNode* returnhead = head;
        while(pos < left - 1)
        {
            head = head->next;
            pos++;
        }
        ListNode* start_reverse = head;
        ListNode* end_reverse = head->next;
        ListNode *node, *node_l, *node_r;
        node = head->next;
        pos++;
        while(pos <= right)
        {
            node_r = node->next;
            node->next = node_l;
            node_l = node;
            node = node_r;
            pos++;
        }
        end_reverse->next = node_r;
        start_reverse->next = node_l;
        returnhead = returnhead->next;
        return returnhead;
    }
};
