class Solution {
public:
    long long countt(vector<int>&weights,long long days, long long mid)
{
    int n = weights.size();
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if((sum + weights[i])<=mid)
        {
            sum += weights[i];
        }
        else
        {
            cnt++;
            sum = weights[i];
        }
    }
    if(sum<=mid)
    {
        cnt++;
    }
    return cnt;
}
int shipWithinDays(vector<int>& weights, int days)
{
    int n = weights.size();
    int l = *max_element(weights.begin(),weights.end());
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += weights[i];
    }
    int h = sum;
    
    long long ans = 0;

    while(l<=h)
    {
        long long mid = (l+h)/2;
        int answer = countt(weights,days,mid);
        if(answer<=days)
        {
            ans = mid;
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    
    return ans;
}
};