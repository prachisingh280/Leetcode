class Solution {
public:
    int total_time(vector<int>&piles, int mid)
{
    int n = piles.size();
    int sum = 0;
    
    for(int i=0; i<n; i++)
    {
        sum = sum + ceil((double)piles[i]/mid);
    }
    
    return sum;
}
int minEatingSpeed(vector<int>& piles, int h)
{
    int n = piles.size();
    long long sum = 0;
    
    for(int i=0; i<n; i++)
    {
        sum += piles[i];
    }
    
    int low = ceil((double)sum/h);
    int high = *max_element(piles.begin(),piles.end());
    int ans;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int poss_ans = total_time(piles,mid);
        
        if(poss_ans<=h)
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