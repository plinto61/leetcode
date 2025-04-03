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
private:
    int lll(ListNode* head) {
        int l = 0;
        while(head != nullptr) {
            l++;
            head = head->next;
        }
        return l;
    }
public:
    void reorderList(ListNode* head) {
        int l = lll(head);
        if(l < 3) {
            return;
        }
        stack<ListNode*> s;
        ListNode* curr = head;
        int i=0, j = (int)(l+1)/2;
        while(curr != nullptr) {
            if(i++ >= j) {
                s.push(curr);
            }
            curr = curr->next;
        }
        curr = head;
        while(s.size() > 0) {
            ListNode* pp = s.top();
            pp->next = curr->next;
            curr->next = pp;
            curr = pp->next;
            s.pop();
        }
        curr->next = nullptr;
        return;
    }
};