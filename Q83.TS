class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function deleteDuplicates(head: ListNode | null): ListNode | null {
  const nodeSet = new Set<number>();
  let parentNode: ListNode | null = null;
  for (
    let currentNode = head;
    currentNode !== null;
    currentNode = currentNode.next
  ) {
    const currentValue = currentNode.val;
    const isDuplicate = nodeSet.has(currentValue);

    if (isDuplicate) {
      deleteNode(currentNode, parentNode);
    } else {
      nodeSet.add(currentValue);
      parentNode = currentNode;
    }
  }

  return head;
}

function deleteNode(node: ListNode, nodeParent: ListNode | null) {
  if (nodeParent !== null) nodeParent.next = node.next;
}
