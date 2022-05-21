function removeDuplicates(nums: number[]): number {
  const arrayLength = nums.length;

  let previous = null;
  let current = null;
  let displacement = 0;

  for (let i = 0; i < arrayLength; i++) {
    current = nums[i];

    if (current === previous) displacement++;
    else nums[i - displacement] = current;

    previous = current;
  }
  return arrayLength - displacement;
}
