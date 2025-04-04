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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1_val = l1 != nullptr ? l1->val : 0;
            int l2_val = l2 != nullptr ? l2->val : 0;
            int sum = l1_val + l2_val + carry;

            carry = (int)sum / 10;
            int val = sum % 10;
            
            curr->next = new ListNode(val);
            curr = curr->next;

            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        return head->next;
    }
};