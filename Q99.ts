class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function recoverTree(root: TreeNode | null): void {
  let LAST_VALUE: number | null = null;
  let LAST_NODE: TreeNode | null = null;
  let FOUND_ERROR_COUNT = 0;
  let LOWER_INCORRECT_NODE: TreeNode | null = null;
  let GREATER_INCORRECT_NODE: TreeNode | null = null;

  function traverseAndFillMetadata(node: TreeNode | null) {
    if (node === null) return;
    traverseAndFillMetadata(node.left);

    const inorderPredecessor = LAST_VALUE;
    const currentValue = node.val;

    if (inorderPredecessor !== null && inorderPredecessor > currentValue) {
      if (FOUND_ERROR_COUNT === 0) {
        FOUND_ERROR_COUNT++;
        LOWER_INCORRECT_NODE = LAST_NODE;
        GREATER_INCORRECT_NODE = node;
      } else {
        GREATER_INCORRECT_NODE = node;
        return;
      }
    }
    LAST_VALUE = node.val;
    LAST_NODE = node;

    traverseAndFillMetadata(node.right);
  }

  traverseAndFillMetadata(root);

  const tempValue = LOWER_INCORRECT_NODE!.val;
  LOWER_INCORRECT_NODE!.val = GREATER_INCORRECT_NODE!.val;
  GREATER_INCORRECT_NODE!.val = tempValue;
}
