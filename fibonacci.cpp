#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Memoization
// int fib(int n,vector<int>&dp)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     if(dp[n]==-1)
//     {
//         dp[n] = fib(n-1,dp)+fib(n-2,dp);
//     }
//     return dp[n];
// }
// int main()
// {
//     int n;
//     cout<<"Which term you wanna calculate for ? :";
//     cin>>n;
//     vector <int> dp(n+1,-1);
//     dp[0] = 0;
//     int ans = fib(n,dp);
//     cout<<"The term is: "<<ans;

// }

//Time Complexity = O(n)
//Space Complexity = O(n) + 0(n)


//Tabulation

int main()
{
    int n;
    cout<<"Which term of fibonacci series you want ?: ";
    cin>>n;
    vector <int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<"The term is :"<<dp[n];
}

//Time = O(n)
//Space = O(n)