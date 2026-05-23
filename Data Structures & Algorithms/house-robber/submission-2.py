class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        memo = {
            0: nums[0],
            1: max(nums[0], nums[1])
        }
        def backtrack(i):
            if i == len(nums):
                return 
            
            memo[i] = max(memo[i-2] + nums[i], memo[i-1])
            backtrack(i+1)

        backtrack(2)
        return memo[len(nums) - 1]


    