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
    return help(n-1,points,3,dp);
}
int main()
{
    vector<vector <int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    int n = points.size();
    int ans = ninjaTraining(n,points);
    cout << ans << endl; 
}
