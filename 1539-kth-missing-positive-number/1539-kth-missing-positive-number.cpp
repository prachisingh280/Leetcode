class Solution {
public:
    int solve(vector<int>&arr, int max_len, int k)
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
    int max_len = *max_element(arr.begin(),arr.end());
    int ans = solve(arr,max_len,k);
    return ans;
}
};