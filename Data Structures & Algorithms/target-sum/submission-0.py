class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo = {}

        def backtrack(i, curr_sum):
            if curr_sum == target and i == len(nums):
                return 1
            if i == len(nums):
                return 0
            if (i, curr_sum) in memo:
                return memo[(i, curr_sum)]
            take = backtrack(i+1, curr_sum + nums[i])
            skip = backtrack(i+1, curr_sum - nums[i])
            memo[(i, curr_sum)] = take + skip
            return take + skip  
        return backtrack(0, 0)             
            

