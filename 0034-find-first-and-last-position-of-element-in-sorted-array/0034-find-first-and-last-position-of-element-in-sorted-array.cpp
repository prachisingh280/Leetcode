class Solution {
public:
    int lowerbound(vector<int>&arr, int x)
{
    int n = arr.size();
    int l = 0;
    int h = n-1;
    int ans = n;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(x>arr[mid])
        {
            l = mid+1;
        }
        else 
        {
            ans = mid;
            h = mid-1;
        }
        
    }
    return ans;
}
int upperbound(vector<int>&arr, int x)
{
    int n = arr.size();
    int l = 0;
    int h = n-1;
    int ans = n;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid]<=x)
        {
            l = mid+1;
        }
        else if(arr[mid]>x)
        {
            ans = mid;
            h = mid-1;
        }
    }
    return ans;
    
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
    int lb = lowerbound(nums,target);
    int ub = upperbound(nums,target);
    vector<int>ans(2,-1);
    
    if(lb == ub)
    {
        return ans;
    }
    else
    {
        ans[0] = lb;
        ans[1] = ub-1;
        return ans;
    }
    }
};