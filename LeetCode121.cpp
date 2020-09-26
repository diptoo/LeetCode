class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxy = 0,miny = 1e9 + 5, sz = prices.size(),result = 0;
        int mx_array[100001], min_array[100001];
        for(int i = sz - 1; i >= 0; i--)
        {
            if(prices[i] > maxy)
            {
                maxy = prices[i];
                mx_array[i] = prices[i];
            }
            else
            {
                mx_array[i] = maxy;
            }
        }
        
        for(int i = 0;i < sz;i++)
        {
            if(mx_array[i] - prices[i] > result)
            {
                result = mx_array[i] - prices[i];
            }
        }
        
        return result;
    }
};