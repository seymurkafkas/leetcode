function maxOperations(nums: number[], k: number): number {
  const frequencyTable = {};
  let result = 0;
  for (const num of nums) {
    const inverseOccurrenceCount = frequencyTable[k - num];

    if (inverseOccurrenceCount === undefined || inverseOccurrenceCount <= 0) {
      frequencyTable[num] === undefined
        ? (frequencyTable[num] = 1)
        : frequencyTable[num]++;
    } else {
      frequencyTable[k - num]--;
      result++;
    }
  }

  return result;
}
