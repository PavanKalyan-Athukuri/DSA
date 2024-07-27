/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode res = null;
        ListNode res1 = null;
        while(list1!=null||list2!=null){
            if(list1==null&&list2!=null){
                if(res==null){
                    res = list2;
                    res1 = res;}
                else
                res.next = list2;
                break;
            }
            if(list2==null&&list1!=null){
                if(res==null){
                    res = list1;
                    res1 = res;
                }
                else
                res.next = list1;
                break;
            }
            if(list1.val<list2.val){
                if(res==null){
                    res = new ListNode(list1.val);
                    res1 = res;
                }
                else{
                    res.next = new ListNode(list1.val);
                    res = res.next;
                }
                list1 = list1.next;
            }
            else{
                if(res==null){
                    res = new ListNode(list2.val);
                    res1 = res;
                }
                else{
                    res.next = new ListNode(list2.val);
                    res = res.next;
                }
                list2 = list2.next;
            }
        }
        return res1;
    }
}