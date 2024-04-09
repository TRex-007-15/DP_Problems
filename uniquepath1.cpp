#include <bits/stdc++.h>
using namespace std;
// Recursion
// int help(int i,int j)
//     {
//         if(i==0 && j==0)
//         {
//             return 1;
//         }
//         if(i==0 && j!=0)
//         {
//             return help(i,j-1);
//         }
//         if(i!=0 && j==0)
//         {
//             return help(i-1,j);
//         }
//         return help(i-1,j)+help(i,j-1);
//     }
// Memoization
// int help(int i,int j,vector<vector<int>> &dp)
// {
//     if(i==0 && j==0)
//     {
//         return 1;
//     }
//     if(i==0 && j!=0)
//     {
//         if(dp[i][j]==-1)
//             return dp[i][j] = help(i,j-1,dp);
//         return dp[i][j];
//     }
//     if(i!=0 && j==0)
//     {
//         if(dp[i][j]==-1)
//             return dp[i][j] = help(i-1,j,dp);
//         return dp[i][j];
//     }
//     if(dp[i][j]==-1)
//         return dp[i][j] = help(i-1,j,dp)+help(i,j-1,dp);
//     return dp[i][j];
// }
// Tabulation
int uniquePaths(int m, int n) {
    vector <vector<int>> dp(m,vector<int>(n,-1));

    for (int i = 0; i < m; i++) 
    {
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    int fa = uniquePaths(3,7);
    cout << fa << endl;
}