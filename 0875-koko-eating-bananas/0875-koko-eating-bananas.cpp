class Solution {
public:
long long total_time(vector<int>&piles,int mid)
{
    int n = piles.size();
    long long value = 0;
    for(int i=0; i<n; i++)
    {
        value += ceil((double)piles[i]/mid);
    }
    return value;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
    int l = 1;
    int r = *max_element(piles.begin(),piles.end());
    int ans = 1;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        long long value = total_time(piles,mid);
       
        if(value<=h)
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ans;
    }
};