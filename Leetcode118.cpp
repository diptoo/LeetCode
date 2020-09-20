class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i < numRows; i++)
        {
            result[i].resize(i + 1);
            
            result[i][0] = 1;
            result[i][i] = 1;

            int loop_till = i - 1;
            result[i][0] = 1;
            for(int j = 0; j< loop_till; j++)
            {
                int fi = result[i - 1][j];
                int sc = result[i - 1][j + 1];
                //cout<<fi<<" "<<sc<<endl;
                result[i][j+1] = fi + sc;
            }            
        }
        
        return result;
    }
};