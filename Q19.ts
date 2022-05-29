function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  if (head === null) return null;

  const deltaPointer = n;
  let traverserFirst = head;
  let traverserSecond = head;

  for (let i = 0; i <= n - 1; i++) traverserFirst = traverserFirst.next;

  if (traverserFirst === null) return head.next;

  while (true) {
    if (traverserFirst === null || traverserFirst.next === null) break;

    traverserFirst = traverserFirst.next;
    traverserSecond = traverserSecond.next;
  }

  traverserSecond.next = traverserSecond.next.next;
  return head;
}
