class Solution {
public:
   int possibility(vector<int>&nums, int mid, int k)
{
    int n = nums.size();
    int sum = 0;
    int cnt = 1;
    
    for(int i=0; i<n; i++)
    {
        if((sum+nums[i])<=mid)
        {
            sum += nums[i];
        }
        else
        {
            sum = nums[i];
            cnt++;
        }
    }
    return cnt;
}

int splitArray(vector<int>& nums, int k)
{
    int n = nums.size();
    int l = *max_element(nums.begin(),nums.end());
    int sum = 0;
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        sum = sum + nums[i];
    }
    int h = sum;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        int cnt = possibility(nums,mid,k);
        if(cnt<=k)
        {
            ans = mid;
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ans;
}
};