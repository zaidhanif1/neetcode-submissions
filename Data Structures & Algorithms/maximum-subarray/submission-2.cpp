class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        int res = nums[0];
        int curr = 0;


        for (int i = 0; i < n; i ++)
        {
            if (curr < 0)
            {
                curr = 0;
            }
            curr += nums[i];
            res = max(curr, res);
        }
        return res;

    }
};