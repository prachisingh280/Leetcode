class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n-1;
    
    while(i<=m-1 && j>=0)
    {
        int position = matrix[i][j];
        
        if(position == target)
        {
            return true;
        }
        else if(position > target)
        {
            j = j-1;
        }
        else
        {
            i = i+1;
        }
    }
    
    return false;
    }
};