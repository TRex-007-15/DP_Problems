#include <bits/stdc++.h> 
using namespace std;
// bool help(int idx, vector<int> &a, int k, vector<vector<int>>& dp) {
//     if (k == 0) return true;
//     if (idx == 0) return (a[0] == k);
//     if (dp[idx][k] != -1) return dp[idx][k];
//     bool a1 = false;
//     bool a2 = help(idx - 1, a, k, dp);
//     if (k >= a[idx]) {
//         a1 = help(idx - 1, a, k - a[idx], dp);
//     }
//     return dp[idx][k] = (a1 || a2);
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    vector<bool>prev(k+1),curr(k+1);
    prev[0]=curr[0]=true;
    prev[arr[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int t =1; t <=k; t++)
        {
            int take = 0;
            int nottake = prev[t];
            if(t >= arr[i])
            {
                take = prev[t-arr[i]];
            }
            curr[t] = take || nottake;
        }
        prev = curr;
    }
    return prev[k];
}
int main() {
    vector<int> arr = {2, 4, 6, 8};
    int k = 10;
    int n = arr.size();
    if (subsetSumToK(n, k, arr)) {
        cout << "Subset with sum " << k << " exists." << endl;
    } else {
        cout << "Subset with sum " << k << " does not exist." << endl;
    }
    return 0;
}