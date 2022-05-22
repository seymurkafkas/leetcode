function sumOfThree(num: number): number[] {
  let sum = num - 3;

  if (sum % 3 !== 0) return [];
  else {
    sum = sum / 3;
    return [sum, sum + 1, sum + 2];
  }
}
