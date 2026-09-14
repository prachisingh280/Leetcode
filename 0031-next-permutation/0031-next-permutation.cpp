class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    bool didfind = false;
    
    for(int i=n-1; i>0; i--)
    {
        if(nums[i]>nums[i-1])
        {
            int ans = i;
            for(int j = i; j<n; j++)
            {
                if(nums[j]>nums[i-1] && nums[j]<=nums[ans])
                {
                    ans = j;
                }
            }
            didfind = true;
            swap(nums[i-1],nums[ans]);
            sort(nums.begin()+i, nums.end());
            break;
        }
    }
    
    if(!didfind)
    {
        sort(nums.begin(),nums.end());
    }
    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }
    return;
    }
};