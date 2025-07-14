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
    int ans=0;
    int power=1;
    void dec(ListNode* head){
        if(head == NULL ){
            return;
        }
        dec(head->next);
        ans+=head->val*power;
        power*=2;
    }
    int getDecimalValue(ListNode* head) {
        dec(head);
        return ans;
    }
};