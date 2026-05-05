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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        ListNode* temp = head;
        if(head==nullptr||head->next==nullptr)
            return head;
        while(temp!=nullptr){
            size++;
            temp = temp->next;
        }
        k = k%size;
        ListNode* temp1 = head;
        while(k--){
            
            ListNode* prev=nullptr;
            while(temp1->next!=nullptr){
                prev = temp1;
                temp1 = temp1->next;
            }
            prev->next = nullptr;
            temp1->next = head;
            head = temp1;

        }
        return head;
    }
};