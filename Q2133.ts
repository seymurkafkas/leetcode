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

function swapPairs(head: ListNode | null): ListNode | null {
  let prev = null;

  const result = head?.next || head;

  while (true) {
    const first_pair = prev ? prev.next : head;
    const second_pair = first_pair?.next;
    const right_most = second_pair?.next;

    if (!first_pair || !second_pair) break;

    if (prev) prev.next = second_pair;
    second_pair.next = first_pair;
    first_pair.next = right_most;

    prev = first_pair;
  }

  return result;
}
