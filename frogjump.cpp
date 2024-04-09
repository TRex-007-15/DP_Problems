
// Recursive Solution

#include <bits/stdc++.h> 
using namespace std;

// int helper(int i,vector<int> &h)
// {
//     if(i == 0) return 0;
//     int left = helper(i-1,h)+abs(h[i]-h[i-1]);
//     int right = INT_MAX;
//     if(i > 1) right = helper(i-2,h)+abs(h[i]-h[i-2]);
//     return min(left,right);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     int e = helper(n-1,heights);
//     return e;
// }




//DP Solution now we'll see
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(h[i] - h[i - 1]);
        int right = (i > 1) ? dp[i - 2] + abs(h[i] - h[i - 2]) : INT_MAX;

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int result = frogJump(n, heights);
    cout << "Minimum energy required: " << result << endl;
    return 0;
}
