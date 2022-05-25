class Stack<Type> {
  private top: Item<Type>;
  pop() {}
}

class Item<Type> {
  private value: Type;
  private next: Item<Type> | null;
}

function longestValidParentheses(s: string): number {
  let lastSolutionIndex = null;
  let result = 0;

  for (const char of s) {
  }

  return result;
}

function main() {
  const exampleString = "(()";

  const result = longestValidParentheses(exampleString);

  console.log(result);
}

main();
