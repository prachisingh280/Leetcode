class Solution {
public:
    bool search(vector<int>&matrix, int target, int n)
{
    int low = 0;
    int high = n-1;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(matrix[mid]==target)
        {
            return true;
        }
        else if(matrix[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    int low = 0;
    int high = m-1;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int first_ele = matrix[mid][0];
        int second_ele = matrix[mid][n-1];
        
        if(first_ele<=target && target<=second_ele)
        {
            int present = search(matrix[mid],target,n);
            if(present)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(first_ele>target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return false;
}
};