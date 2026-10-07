class Solution {
public:
    int lrg_index(vector<vector<int>> &mat, int mid)
{
    int r = mat.size();
    int c = mat[0].size();
    int largest = mat[0][mid];
    int index = 0;
    
    for(int i=0; i<r; i++)
    {
        if(mat[i][mid]>=largest)
        {
            largest = mat[i][mid];
            index = i;
        }
    }
    
    return index;
}
vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int r = mat.size();
    int c = mat[0].size();
    
    int low = 0;
    int high = c-1;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int index = lrg_index(mat,mid);
        
        if(mid==0)
        {
            if(c!=1)
            {
            if(mat[index][mid]>mat[index][mid+1])
            {
                vector<int>ans = {index,mid};
                return ans;
            }
            else
            {
                low = mid+1;
            }
            }
            else
            {
                vector<int>ans = {index,0};
                return ans;
            }
        }
        
        else if(mid==c-1)
        {
            if(mat[index][mid-1]<mat[index][mid])
            {
                vector<int>ans = {index,mid};
                return ans;
            }
            else
            {
                high = mid-1;
            }
        }
        else 
        {
            if(mat[index][mid-1]<mat[index][mid] && mat[index][mid]>mat[index][mid+1])
            {
                vector<int>ans = {index,mid};
                return ans;
            }
            else if(mat[index][mid-1]<mat[index][mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
    }
    
    return {15,28};
}
};