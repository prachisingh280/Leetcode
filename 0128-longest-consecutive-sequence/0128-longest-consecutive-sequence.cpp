class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    if(n==0)
    {
        return 0;
    }
    int max_len = 1;
    sort(nums.begin(),nums.end());
    int comp = nums[0];
    int cnt = 1;
    
    for(int i=1; i<n; i++)
    {
        if(nums[i]==comp)
        {
            continue;
        }
        else if(nums[i]==comp+1)
        {
            cnt++;
            comp = nums[i];
        }
        else
        {
            max_len = max(cnt,max_len);
            cnt = 1;
            comp = nums[i];
        }
    }
    max_len = max(max_len,cnt);
    
    return max_len;
    
    return 1;
    }
};