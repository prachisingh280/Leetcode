class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
    int sum = 0;
    vector<int>ans;
    unordered_map<int,int>mpp;
    
    for(int i=0; i<n; i++)
    {
        int req = target - nums[i];
        if(mpp.find(req)==mpp.end())
        {
            mpp[nums[i]] = i;
        }
        else
        {
            ans.push_back(mpp[req]);
            ans.push_back(i);
            return ans;
        }
    }
    
    return ans;
    }
};