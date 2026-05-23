class Solution:
    def coinChange(self, coins, amount):
        
        memo = {}

        def f(rem):
            if rem == 0:
                return 0
            if rem < 0:
                return float('inf')
            if rem in memo:
                return memo[rem]
            best = float('inf')
            for c in coins:
                best = min(best, f(rem - c) + 1)
            memo[rem] = best
            return best

        ans = f(amount)
        return ans if ans != float('inf') else -1
