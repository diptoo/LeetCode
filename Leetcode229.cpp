class Solution {
public:
    // Boyer Moore voting algo 
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = -1, el2 = -1, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //cout<<c1<<endl;
            if(el1 == nums[i])
            {
                c1++;
            }
            else if(el2 == nums[i])
            {
                c2++;
            }
            else if(c1 == 0)
            {
                el1 = nums[i];
                c1++;
            }
            else if(c2 == 0)
            {
                el2 = nums[i];
                c2++;
            }
            else
            {
                cout<<nums[i]<<endl;
                c1--;
                c2--;
            }
        }
        
        int cnt = 0;
        vector<int> res;
        for(int i=0; i< nums.size();i++)
        {
            if(nums[i] == el1) cnt++;
        }
        if(cnt > nums.size()/3) res.push_back(el1);
        cnt = 0;
        for(int i=0; i< nums.size();i++)
        {
            if(nums[i] == el2 && el1 != el2) cnt++;
        }
        if(cnt > nums.size()/3) res.push_back(el2);
        
        return res;
    }
};