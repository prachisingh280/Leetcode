class Solution {
public:
    int answer(vector<int>&nums,int mid)
{
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + ceil((double)nums[i]/mid);
    }
    
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold)
{
    int n = nums.size();
    int l = 1;
    int h = *max_element(nums.begin(), nums.end());
    int ans = 0;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        int sum = answer(nums,mid);
        if(sum<=threshold)
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