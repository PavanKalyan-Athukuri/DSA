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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int arr[100001]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]] = 1;
        }
            ListNode *temp = head;
            ListNode *prev = nullptr;
            while(temp!=nullptr){
                //cout << temp->val <<"\n";
                if(arr[temp->val]==1&&prev==nullptr){
                    temp = temp->next;
                    head = temp;
                }
                else if(arr[temp->val]==1&&prev!=nullptr){
                    prev->next = temp->next;
                    temp = temp->next;
                    //break;
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
            }
            // while(temp!=nullptr){
            //     cout << temp->val <<" ";
            //     temp = temp->next;
            // }
            //  cout <<"\n";
        //}
        return head;
    }
};