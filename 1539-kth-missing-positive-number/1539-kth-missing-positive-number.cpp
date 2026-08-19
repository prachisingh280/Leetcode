class Solution {
public:
    int solve(vector<int>&arr,int mid, int max_len, int k)
{
    int n = arr.size();
    int cnt = 0;
    int i = 0;
    for(int j=1; j<max_len; j++)
    {
        if(arr[i]!=j)
        {
            cnt++;
        }
        else
        {
            i++;
        }
        if(cnt == k)
        {
            return j;
        }
    }
    
    return max_len+k-cnt;
}
int findKthPositive(vector<int>& arr, int k)
{
    int n = arr.size();
    int l = 1;
    int max_len = *max_element(arr.begin(),arr.end());
    int h = max_len + k;
    int mid = (l+h)/2;
    int ans = solve(arr,mid,max_len,k);
    return ans;
}
};