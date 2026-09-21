class Solution {
public:
    bool possibility(vector<int>&bloomDay, int mid, int m, int k)
{
    int n = bloomDay.size();
    int cnt = 0;
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        if(bloomDay[i]<=mid)
        {
            cnt++;
            if(cnt==k)
            {
                ans++;
                cnt = 0;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    
    if(cnt>=k)
    {
        ans++;
        cnt = 0;
    }
    if(ans>=m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int minDays(vector<int>& bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if((long long)n<((long long)m*k))
    {
        return -1;
    }
    
    int low = *min_element(bloomDay.begin(),bloomDay.end());
    int high = *max_element(bloomDay.begin(),bloomDay.end());
    int ans;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        int poss_ans = possibility(bloomDay,mid,m,k);
        
        if(poss_ans==1)
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