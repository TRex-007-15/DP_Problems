#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Recursive Method
// int func(int i,vector <int>& a)
// {
//     if(i==0)
//         return a[i];
//     if(i<0)
//         return 0;
//     int pick = a[i]+func(i-2,a);
//     int npick = func(i-1,a);
//     return max(pick,npick);
// }
//Memoization
// int func(int i,vector <int> &a,vector <int> &dp)
// {
//     if(i==0)
//         return a[i];
//     if(i<0)
//         return 0;
//     if(dp[i]!=-1)
//         return dp[i];
//     int pick = a[i]+func(i-2,a,dp);
//     int npick = func(i-1,a,dp);
//     dp[i] = max(pick,npick);
//     return dp[i];
// }
//Tabulation 
// int main()
// {
//     vector <int> a = {1,2,3,5,4};
//     int n = a.size();
//     vector <int> dp(n,-1);
//     dp[0] = a[0];
//     for(int i = 1; i < n;i++)
//     {
//         int pick = a[i];
//         if(i>1)
//             pick += dp[i-2];
//         int npick = dp[i-1];
//         dp[i] = max(pick,npick);
//     }
//     cout << dp[n-1]<<endl;
//     return dp[n-1];
// }
// Zyada chull machi to space opti bhi karunga
int main()
{
    vector <int> a = {1,2,3,5,4};
    int n = a.size();
    int prev1 = 0;
    int prev = a[0];
    int curri ;
    for(int i = 1; i < n;i++)
    {
        int pick = a[i];
        if(i>1)
            pick += prev1;
        int npick = curri;
        curri = max(pick,npick);
        prev1 = prev;
        prev =  curri;
    }
    cout << prev <<endl;
    return prev;
}