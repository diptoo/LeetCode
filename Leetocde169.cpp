class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mp;
        int op, maxy = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > nums.size()/2)
            {
                op = nums[i];
                break;
                //maxy = mp[nums[i]];
                //op = nums[i];
            }
        }
        
        return op;
    }
};