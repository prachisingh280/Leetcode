class Solution {
public:
   long long findvalue(vector<int>&piles, int mid)
{
    long long n = piles.size();
    long long value = 0;
    for(long long i=0; i<n; i++)
    {
        value += ceil((double)piles[i]/mid);
    }
    return value;
}
int minEatingSpeed(vector<int>& piles, int h)
{
    long long n = piles.size();
    long long minn = 1;
    long long maxx = *max_element(piles.begin(),piles.end());
    long long low = 1;
    long long high = maxx;
    long long ans = 1;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        long long value = findvalue(piles,mid);
        
        if(value<=h)
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