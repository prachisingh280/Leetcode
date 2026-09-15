class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
    unordered_map<int,int>mpp;
    mpp[0] = 1;
    int sum = 0;
    int cnt = 0;
    
    for(int i=0; i<n; i++)
    {
        sum = sum + nums[i];
        int req_sum = sum - k;
        
        if(mpp.find(req_sum)!=mpp.end())
        {
            cnt = cnt + mpp[req_sum];
        }
        mpp[sum]++;
    }
    
    return cnt;
    }
};