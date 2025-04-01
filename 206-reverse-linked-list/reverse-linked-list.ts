/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
    if(head === null) return null;
    let l = head;
    let m = head.next;
    l.next = null;
    while(m !== null) {
        const n = m.next;
        m.next = l;
        l = m;
        m = n;
    }
    return l;
};