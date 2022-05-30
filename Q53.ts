function maxSubArray(nums: number[]): number {
  let current_partial_sum = nums[0];
  let maximum_partial_sum = nums[0];

  for (let i = 1; i <= nums.length - 1; i++) {
    if (current_partial_sum <= 0) current_partial_sum = 0;

    current_partial_sum += nums[i];
    maximum_partial_sum = Math.max(current_partial_sum, maximum_partial_sum);
  }

  return maximum_partial_sum;
}
