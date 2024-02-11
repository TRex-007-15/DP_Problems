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
// int func(int i,int j,int n,vector<vector<int>> &t,vector<vector<int>> &dp)
// {
//     if(i==n-1)
//     {
//         return t[n-1][j];
//     }
//     int down = INT_MAX;
//     int cross = INT_MAX;
//     if(dp[i][j]==-1)
//     {
//             down = t[i][j]+func(i+1,j,n,t,dp);
//             cross = t[i][j]+func(i+1,j+1,n,t,dp);
//             return dp[i][j] = min(down,cross);
//     }
//     else return dp[i][j];
// }
// int minimumTotal(vector<vector<int>>& triangle) {
//     int n = triangle.size();
//     int m = triangle[n-1].size();
//     vector<vector<int>> dp (n,vector<int>(m,-1));
//     int ans = func(0,0,triangle.size(),triangle,dp);
//     return ans;
// }
// Tabulation
// int main()
// {
//     vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
//     int n = triangle.size();
//     int m = triangle[n-1].size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     for(int j = 0;j < m; j++)
//     {
//         dp[n-1][j] = triangle[n-1][j];
//     }
//     for(int i = n-2; i >= 0; i--)
//     {
//         for(int j = i; j >= 0; j--)
//         {
//             int up = triangle[i][j] + dp[i+1][j];
//             int cross =  triangle[i][j] + dp[i+1][j+1];
//             dp[i][j] = min(up,cross);
//         }
//     }
//     cout << dp[0][0] << endl;
//     return dp[0][0];
// }
// SPACE OPTI
int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector <int> front (n,0);
    vector <int> curr (n,0);
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j = 0;j < m; j++)
    {
        front[j] = triangle[n-1][j];
    }
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int up = triangle[i][j] + front[j];
            int cross =  triangle[i][j] + front[j+1];
            curr[j] = min(up,cross);
        }
        front = curr;
    }
    cout << front[0] <<endl;
    return front[0];
}