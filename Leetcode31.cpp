class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(), decr_point = 0, cnt = 0;
        
        for(int i = size - 1; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                decr_point = i;
                break;
            }
        }
        if(decr_point == 0)
        {
            //cout<<"asdas"<<endl;
            sort(nums.begin(), nums.end());
        }
        else
        {
            int lri = decr_point - 1;
            int rri, maxy = nums[lri];
            bool flag = false;
            for(int i = decr_point; i < size; i++)
            {
                if(nums[i] > maxy && !flag)
                {
                    maxy = nums[i];
                    rri = i;
                    flag = true;
                }
                else if(nums[i] <= maxy && nums[i] > nums[lri] && flag)
                {
                    rri = i;
                }
            }
            swap(nums[lri], nums[rri]);
            reverse(nums.begin() + decr_point, nums.end());

            //partial_sort(nums.begin() + decr_point, nums.end(), nums.end());
        }
    }
};