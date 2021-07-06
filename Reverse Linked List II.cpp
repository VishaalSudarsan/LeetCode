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
        //count number of steps traversed using the variable pos
        //used to identify the node from which reversing needs to happen
        int pos = 0;
        
        //create a dummy head so that the edge cases where the reversal begins
        //are easily handled
        ListNode* dummyhead = new ListNode(0, head);
        head = dummyhead;
        
        //since we need to traverse using the head variable we need 
        //to store the address of the head somewhere which we can return
        //after the reversal
        ListNode* returnhead = head;
        
        //traverse ahead until the point of reversal
        while(pos < left - 1)
        {
            head = head->next;
            pos++;
        }
        
        //now save the current node and the node from which reversal would start
        //because these would be mapped to the reversed nodes
        //for example the current node would be mapped to the node in the position right
        //and the node next to the current node would be mapped to the node next to the 
        //node in the position right
        ListNode* start_reverse = head;
        ListNode* end_reverse = head->next;
        
        //instantiate variables so that the links for each nodes between left and right 
        //are reversed. node would represent the node who's like we want to reverse
        ListNode *node, *node_l, *node_r;
        node = head->next;
        pos++;
        
        //we save the node that points to the current node(node_l) and then also save the node
        //which the current node points(node_r). then we make the current node point to node_l
        //and save the current node in the variable node_l. now the current node points to the
        //previous node.
        while(pos <= right)
        {
            node_r = node->next;
            node->next = node_l;
            node_l = node;
            node = node_r;
            pos++;
        }
        
        //now the reversed part of the list is tied to the original node as explained above
        end_reverse->next = node_r;
        start_reverse->next = node_l;
        
        //we return the node next to the copy of the head node because we added a dummy node
        //to avoid edge cases.
        returnhead = returnhead->next;
        return returnhead;
    }
};
