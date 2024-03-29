#include <bits/stdc++.h>
using namespace std;
//RECURSIVE SOLUTION
// int help(int i,int j,vector<vector<int>> &obstacleGrid)
// {
//     if(i==0 && j==0)
//     {
//         if(obstacleGrid[i][j]==0)
//             return 1;
//         return 0;
//     }
//     if(i==0 && j!=0)
//     {
//         if(obstacleGrid[i][j]==0)
//             return help(i,j-1,obstacleGrid);
//         return 0;
//     }
//     if(i!=0 && j==0)
//     {
//         if(obstacleGrid[i][j]==0)
//             return help(i-1,j,obstacleGrid);
//         return 0;
//     }
//     if(obstacleGrid[i][j]==0)
//         return help(i-1,j,obstacleGrid)+help(i,j-1,obstacleGrid);
//     return 0;
// }
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int m = obstacleGrid.size();
//     int n = obstacleGrid[0].size();
//     int ans  = help(m-1,n-1,obstacleGrid);
//     return ans;
// }


// MEMOIZATION
// int help(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>>& dp)
// {
//     if(i==0 && j==0)
//     {
//         if(obstacleGrid[i][j]==0)
//             return dp[i][j] = 1;
//         return dp[i][j]=0;
//     }
//     if(i==0)
//     {
//         if(obstacleGrid[i][j]==0)
//             if(dp[i][j]==-1)
//                return dp[i][j] = help(i,j-1,obstacleGrid,dp);
//             else
//                 return dp[i][j];
//         return 0;
//     }
//     if(j==0)
//     {
//         if(obstacleGrid[i][j]==0)
//             if(dp[i][j]==-1)
//                 return dp[i][j] = help(i-1,j,obstacleGrid,dp);
//             else
//                 return dp[i][j];
//         return 0;
//     }
//     if(obstacleGrid[i][j]==0)
//         if(dp[i][j]==-1)
//             return dp[i][j] = help(i-1,j,obstacleGrid,dp)+help(i,j-1,obstacleGrid,dp);
//         else
//             return dp[i][j];
//     return 0;
// }
//TABULATION
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector <vector<int>> dp(m,vector<int>(n,-1));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(obstacleGrid[i][j]==1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if (j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int fa = uniquePathsWithObstacles(obstacleGrid);
    cout<<fa<<endl;
}