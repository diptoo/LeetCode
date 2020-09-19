class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_flag = false, col_flag = false;
        for(int r = 0; r < matrix.size(); r++)
        {
            for(int c = 0; c < matrix[r].size(); c++)
            {
                if(matrix[r][c] == 0)
                {
                    if(c !=0 && r == 0)
                    {
                        row_flag = true;
                    }
                    if(c == 0 && r !=0)
                    {
                        col_flag = true;
                    }
                    if(r == 0 && c == 0)
                    {
                        row_flag = true;
                        col_flag = true;
                    }
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        
        for(int r = matrix.size() - 1; r >= 0; r--)
        {
            for(int c = matrix[r].size() - 1; c >= 0; c--)
            {
                if(matrix[0][c] == 0 || matrix[r][0] == 0)
                {
                    if(c == 0)
                    {
                        if(!col_flag && row_flag) continue;
                    }
                    if(r == 0)
                    {
                        if(!row_flag && col_flag) continue;
                    }
                    matrix[r][c] = 0;
                }
            }
        }
    }
};