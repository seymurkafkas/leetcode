const dictionary = {
  2: ["a", "b", "c"],
  3: ["d", "e", "f"],
  4: ["g", "h", "i"],
  5: ["j", "k", "l"],
  6: ["m", "n", "o"],
  7: ["p", "q", "r", "s"],
  8: ["t", "u", "v"],
  9: ["w", "x", "y", "z"],
};

function getCartesianProduct(arr1: string[], arr2: string[]): string[] {
  const result: string[] = [];
  const arr1Length = arr1.length;
  const arr2Length = arr2.length;

  if (arr1Length === 0) return arr2;
  if (arr2Length === 0) return arr1;

  for (let i = 0; i < arr1Length; i++) {
    for (let j = 0; j < arr2Length; j++) {
      const currentPartialElement = arr1[i] + arr2[j];
      result.push(currentPartialElement);
    }
  }

  return result;
}

function letterCombinations(digits: string): string[] {
  const digitLength = digits.length;

  let combinations = [];
  for (const digit of digits) {
    const currentAvailableLetter = dictionary[digit];
    combinations = getCartesianProduct(combinations, currentAvailableLetter);
  }

  return combinations;
}

function main() {
  const digits: string = "23";

  const result = letterCombinations(digits);
  console.log(result);
}

main();
