class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++)
        {
            vector<int>inres;
            if(i == 0) 
            {
                inres.push_back(1);
                result.push_back(inres);
            }
            else if(i == 1)
            {
                inres.push_back(1);
                inres.push_back(1);
                result.push_back(inres);
            }
            else
            {
                int loop_till = i - 1;
                inres.push_back(1);
                for(int j = 0; j< loop_till; j++)
                {
                    int fi = result[i - 1][j];
                    int sc = result[i - 1][j + 1];
                    //cout<<fi<<" "<<sc<<endl;
                    inres.push_back(fi + sc);
                }
                inres.push_back(1);
                result.push_back(inres);
            }
            
        }
        
        return result;
    }
};