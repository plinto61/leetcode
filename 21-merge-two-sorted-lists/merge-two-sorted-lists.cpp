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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        if(ptr1 == nullptr) return ptr2;
        if(ptr2 == nullptr) return ptr1;
        ListNode* head;
        if(ptr1->val < ptr2->val) {
            head = ptr1;
            ptr1 = head->next;
        } else {
            head = ptr2;
            ptr2 = head->next;
        }
        ListNode* curr = head;

        while(ptr1 != nullptr && ptr2 != nullptr) {
            if(ptr1->val < ptr2->val) {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }
        if(ptr1 == nullptr) {
            curr->next = ptr2;
        } else {
            curr->next = ptr1;
        }
        return head;
    }
};