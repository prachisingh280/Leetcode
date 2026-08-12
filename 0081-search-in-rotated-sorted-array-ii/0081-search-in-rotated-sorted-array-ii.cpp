class Solution {
public:
    bool search(vector<int>& nums, int target) {
        long long n = nums.size();
    long long l = 0;
    long long h = n-1;
    
    while(l<=h)
    {
        long long mid = (l+h)/2;
        if(nums[mid]==target)
        {
            return true;
        }
        if(nums[mid]==nums[l] && nums[l]==nums[h])
        {
            l++;
            h--;
            continue;
        }
        else if(nums[l]<=nums[mid])
        {
            if(nums[l]<=target && target<=nums[mid])
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        else if(nums[mid]<=nums[h])
        {
            if(nums[mid]<=target && target<=nums[h])
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
    }
    
    return false;
    }
};