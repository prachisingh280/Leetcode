class Solution {
public:
    int possibility(vector<int>&bloomDay, int mid,int k)
{
    int n = bloomDay.size();
    int cnt = 0;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(bloomDay[i]<=mid)
        {
            cnt++;
        }
        else
        {
            ans += cnt/k;
            cnt = 0;
        }
    }
    ans += cnt/k;
    cnt = 0;
    return ans;
            
}

int minDays(vector<int>& bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long minn = *min_element(bloomDay.begin(),bloomDay.end());
    long long maxx = *max_element(bloomDay.begin(),bloomDay.end());
    if((1LL*m*k)>n)
    {
        return -1;
    }
    int ans = -1;
    while(minn<=maxx)
    {
        int mid = (minn+maxx)/2;
        int ans1 = possibility(bloomDay,mid,k);
        if(ans1>=m)
        {
            ans = mid;
            maxx = mid-1;
        }
        else
        {
            minn = mid+1;
        }
    }
    return ans;
}
};