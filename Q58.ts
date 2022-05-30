function lengthOfLastWord(s: string): number {
  let lastLetterIndex, firstLetterPreIndex;
  let index = s.length - 1;

  for (; index >= 0; index--) {
    if (s[index] !== " ") break;
  }

  lastLetterIndex = index;

  for (; index >= 0; index--) {
    if (s[index] === " ") break;
  }

  firstLetterPreIndex = index;

  return lastLetterIndex - firstLetterPreIndex;
}
