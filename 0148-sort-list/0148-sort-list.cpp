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
    ListNode* sortList(ListNode* head) {
        vector<int>dummy;
        ListNode* curr=head;
        while(curr){
            dummy.push_back(curr->val);
            curr=curr->next;
        }
        sort(dummy.begin(), dummy.end());
        curr=head;
        int idx=0;
        while(curr){
            curr->val=dummy[idx];
            curr=curr->next;
            idx++;
        }
        return head;
    }
};