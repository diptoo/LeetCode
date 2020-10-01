class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        int row = matrix.size(), col = matrix[0].size();
        
        for(int i = 1; i<= row/2; i++)
        {
            int swap_up = i - 1;
            int swap_down = row - i;
            swap(matrix[swap_up], matrix[swap_down]);
        }
        
        for(int i = 0;i<row;i++)
        {
            for(int j = i+1;j<col;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
            
    }
};