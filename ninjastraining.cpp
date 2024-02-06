#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//RECURSIVE SOLUTION

// int help(int days,vector<vector<int>> &points,int task)
// {
//     if(days == 0)
//     {
//        int maxi = INT_MIN;
//        for(int i =0 ; i < 3;i++)
//        {
//         if(i!=task)
//         {
//             maxi = max(maxi,points[days][i]);
//         }
//        }
//        return maxi;
//     }
//     int maxi = INT_MIN;
//     for(int i =0 ; i < 3;i++)
//     {
//         if(i!=task)
//         {
//             maxi = max(maxi,points[days][i]+help(days-1,points,i));
//         }
//     }
//     return maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return help(n-1,points,3);
// }

//Memoization
// int help(int days,vector<vector<int>> &points,int task,vector<vector<int>> &dp)
// {
//     if(days == 0)
//     {
//        int maxi = INT_MIN;
//        for(int i =0 ; i < 3;i++)
//        {
//         if(i!=task)
//         {
//             maxi = max(maxi,points[days][i]);
//         }
//        }
//        return maxi;
//     }
//     if(dp[days][task]!=-1)
//         return dp[days][task];
//     int maxi = INT_MIN;
//     for(int i =0 ; i < 3;i++)
//     {
//         if(i!=task)
//         {
//             maxi = max(maxi,points[days][i]+help(days-1,points,i,dp));
//         }
//     }
//     return dp[days][task] = maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector <vector<int>> dp (n,vector<int>(4,-1));
//     return help(n-1,points,3,dp);
// }
// Tabulation
int help(int days,vector<vector<int>> &points,int task,vector<vector<int>> &dp)
{
    if(days == 0)
    {
       int maxi = INT_MIN;
       for(int i =0 ; i < 3;i++)
       {
        if(i!=task)
        {
            maxi = max(maxi,points[days][i]);
        }
       }
       return maxi;
    }
    if(dp[days][task]!=-1)
        return dp[days][task];
    int maxi = INT_MIN;
    for(int i =0 ; i < 3;i++)
    {
        if(i!=task)
        {
            maxi = max(maxi,points[days][i]+help(days-1,points,i,dp));
        }
    }
    return dp[days][task] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector <vector<int>> dp (n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][1],max(points[0][2],points[0][1]));

    for(int days = 1; days < n;days++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[days][last] = 0;
            for(int i = 0; i < 3; i++)
            {
                if(i != last)
                {
                    dp[days][last] = max(dp[days][last],points[days][i]+dp[days-1][i]);
                }
            }
        }
    }
    return dp[n-1][3];
}
int main()
{
    vector<vector <int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    int n = points.size();
    int ans = ninjaTraining(n,points);
    cout << ans << endl; 
}
