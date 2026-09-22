class Solution {
public:
    int possibility(vector<int>&weights, int mid)
{
    int n = weights.size();
    int cnt = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++)
    {
        if((sum + weights[i])==mid)
        {
            sum = 0;
            cnt++;
        }
        else if((sum + weights[i])<mid)
        {
            sum = sum + weights[i];
        }
        else
        {
            sum = weights[i];
            cnt++;
        }
    }
    
    if(sum>0)
    cnt++;
    
    return cnt;
}
int shipWithinDays(vector<int>& weights, int days)
{
    int n = weights.size();
    int sum = 0;
    
    for(int i=0; i<n; i++)
    {
        sum += weights[i];
    }
    int ans;
    int low = *max_element(weights.begin(),weights.end());
    int high = sum;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        int countt = possibility(weights,mid);
        
        if(countt<=days)
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