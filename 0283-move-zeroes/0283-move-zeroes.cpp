class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    int n = nums.size();
    int j = -1;
    
    for(int i=0; i<n; i++)
    {
        if(j==-1)
        {
            if(nums[i]==0)
            {
                j = i;
            }
            else
            {
                continue;
            }
        }
        
        if(nums[i] != 0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }


    }
};