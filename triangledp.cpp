#include <bits/stdc++.h>
using namespace std;
// RECURSION
// int func(int i,int j,int n,vector<vector<int>> &t)
// {
//     if(i==n-1)
//     {
//         return t[n-1][j];
//     }
//     int down = INT_MAX;
//     int cross = INT_MAX;
//     down = t[i][j]+func(i+1,j,n,t);
//     cross = t[i][j]+func(i+1,j+1,n,t);
//     return min(down,cross);
// }
// int minimumTotal(vector<vector<int>>& triangle) {
//     int ans = func(0,0,triangle.size(),triangle);
//     return ans;
// }
// MEMOIZATION
int func(int i,int j,int n,vector<vector<int>> &t,vector<vector<int>> &dp)
{
    if(i==n-1)
    {
        return t[n-1][j];
    }
    int down = INT_MAX;
    int cross = INT_MAX;
    if(dp[i][j]==-1)
    {
            down = t[i][j]+func(i+1,j,n,t,dp);
            cross = t[i][j]+func(i+1,j+1,n,t,dp);
            return dp[i][j] = min(down,cross);
    }
    else return dp[i][j];
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> dp (n,vector<int>(m,-1));
    int ans = func(0,0,triangle.size(),triangle,dp);
    return ans;
}
int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotal(triangle)<<endl;
}