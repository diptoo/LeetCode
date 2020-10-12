class Solution {
public:
    // moore's voting algorithm
    int majorityElement(vector<int>& nums) {
       int el = nums[0], cnt = 1;
        
        for(int i = 1; i< nums.size(); i++)
        {
            if(cnt == 0)
            {
                el = nums[i];
            }
            if(el == nums[i])
            {
                cnt++;
            }
            else cnt--;
            
        }
        return el;
    }
};