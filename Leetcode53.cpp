class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int sm = 0, maxy = - 1e18 + 7;
        // kadane's agorithm
        for(int i = 0; i < nums.size(); i++)
        {
            sm += nums[i];
            if(sm < nums[i])
            {
                sm = nums[i];
            }
            if(sm > maxy)
            {
                maxy = sm;
            }
        }
        
        return maxy;
    }
};