class Solution {
public:
    int answer(vector<int>&nums, int mid)
{
    int n = nums.size();
    int sum = 0;
    int cnt = 1;
    int max_sub_sum = 0;
    
    for(int i=0; i<n; i++)
    {
        if(sum+nums[i]<=mid)
        {
            sum += nums[i];
        }
        else
        {
            cnt++;
            sum = nums[i];
        }
    }
    
    return cnt;
}
int splitArray(vector<int>& nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(),nums.end());
    int sum = 0;
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        sum += nums[i];
    }
    
    int high = sum;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int cnt = answer(nums,mid);
        if(cnt==k)
        {
            ans = mid;
            high = mid-1;
        }
        else if(cnt<k)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return low;
}
};