function isPalindrome(x: number): boolean {
  const convertedNumber: string = x.toString(10);
  const digitCount = convertedNumber.length;

  for (let i = 0; i <= Math.floor(digitCount / 2) - 1; i++) {
    if (convertedNumber[i] !== convertedNumber[digitCount - 1 - i])
      return false;
  }

  return true;
}
