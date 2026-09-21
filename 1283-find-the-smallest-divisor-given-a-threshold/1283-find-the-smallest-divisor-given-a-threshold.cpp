class Solution {
public:
    int answer(vector<int>&nums, int mid)
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
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());
    int mid;
    int ans;
    
    while(low<=high)
    {
        mid = (low+high)/2;
        int poss_ans = answer(nums,mid);

        if(poss_ans<=threshold)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return ans;
}
};