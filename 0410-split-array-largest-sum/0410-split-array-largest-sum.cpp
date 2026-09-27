class Solution {
public:
    bool possibility(vector<int>&nums, int mid, int k)
{
    int n = nums.size();
    int sum = 0;
    int cnt = 1;
    
    for(int i=0; i<n; i++)
    {
        if(sum + nums[i]<=mid)
        {
            sum += nums[i]; 
        }
        else
        {
            cnt++;
            sum = nums[i];
        }
    }
    
    if(cnt<=k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int splitArray(vector<int>& nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int anss = low;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int ans = possibility(nums,mid,k);
        
        if(ans == true)
        {
            anss = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return anss;
}
};