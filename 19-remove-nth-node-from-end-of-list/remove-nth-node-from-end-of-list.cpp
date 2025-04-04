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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0; // length of the linked list
        // finding the length
        ListNode* h = head;
        while(h != nullptr) {
            l++;
            h = h->next;
        }

        if(l == 1) return nullptr;
        if(l == n) return head->next;

        int ni = l-n;
        h = head;
        for(int i=0; i<l-n-1; i++) {
            h = h->next;
        }
        h->next = h->next->next;

        return head;
    }
};