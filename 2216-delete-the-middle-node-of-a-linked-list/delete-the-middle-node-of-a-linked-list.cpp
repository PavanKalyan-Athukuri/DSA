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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        ListNode* prevptr = NULL;
        int length = 0;
        while(fastptr!=NULL&&fastptr->next!=NULL){
            fastptr = fastptr->next->next;
            prevptr = slowptr;
            slowptr = slowptr->next;
            length++;
        }
        //cout << length <<"\n";
        //if(length%2)
        if(length>0)
        prevptr->next = slowptr->next;
        else return head->next;
        //else
          //  slowptr->next = slowptr->next->next;
        return head;
    }
};