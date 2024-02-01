#include <bits/stdc++.h>
using namespace std;
//recursive solution
// int func(int idx,vector<int>& cost,int n)
//     {
//         if(idx == n)
//             return 0;
        
//         if(idx >= n)
//             return 1000;
        
//         int f = func(idx+1,cost,n)+cost[idx];
//         int s = func(idx+2,cost,n)+cost[idx];

//         return min(f,s);
        
//     }
// int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int an1 = func(0,cost,n);
//         int an2 = func(1,cost,n);
//         return min(an1,an2);
//     }
// DP solution
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n+1,0);
        for(int i = 2;i <=n;i++)
        {
            int f = dp[i-1]+cost[i-1];
            int s = dp[i - 2] + cost[i - 2];
            dp[i] = min(f, s);
        }
        return dp[n];
    }
int main()
{
    vector <int> cost = {1,100,1,1,1,100,1,1,100,1};
    int ans = minCostClimbingStairs(cost);
    cout<<ans<<endl;
}