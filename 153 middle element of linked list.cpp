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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int l=0;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        temp=head;
        int m;
        for(m=0;m<l/2;m++)
        {
            temp=temp->next;
        }
        return temp;
    }
};
