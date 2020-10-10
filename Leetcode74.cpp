class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int selected_row = -1;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][col-1] >= target)
            {
                selected_row = i;
                break;
            }
        }
        if(selected_row == -1) return false;
        bool res = false;
        for(int i=0;i<col;i++)
        {
            if(matrix[selected_row][i] == target)
            {
                res = true;
                break;
            }
        }
        
        return res;
    }
};