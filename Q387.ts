function firstUniqChar(s: string): number {
  const frequencyMap = buildFrequencyMap(s);

  let index = 0;

  for (const char of s) {
    const occurrenceCount: number = frequencyMap[char]!;
    if (occurrenceCount === 1) return index;

    index++;
  }
  return -1;
}

function buildFrequencyMap(s: string) {
  const frequencyMap: { [char: string]: number | undefined } = {};

  for (const char of s) {
    const occurrenceCount = frequencyMap[char];

    if (occurrenceCount === undefined) frequencyMap[char] = 1;
    else frequencyMap[char] = occurrenceCount + 1;
  }

  return frequencyMap;
}

function main() {
  const input = "leetcode";
  const result = firstUniqChar(input);
  console.log(result);
}

main();
