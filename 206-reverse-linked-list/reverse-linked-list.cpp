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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        bool flag = true;
        while(current!=NULL){
            ListNode* nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        return prev;
    }
};