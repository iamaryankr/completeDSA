#include<bits/stdc++.h>
using namespace std;

class minsumpositive{
    //using our tabulation from subset =k
    int minSubsetSumDifference(vector < int > & arr, int n) {
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }
        vector < vector < bool >> dp(n, vector < bool > (totSum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= totSum)
            dp[0][totSum] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= totSum; target++) {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
            }
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) {
            if (dp[n - 1][i] == true) {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
            }
        }
        return mini;
}

    //using memoized code
    bool subsetSumUtil(int ind, int target, vector < int > & arr, vector < vector< int >> & dp) {
        if (target == 0)
            return dp[ind][target]=true;

        if (ind == 0)
            return (dp[ind][target] = arr[0])==target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        bool taken = false;
        if (arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;
}

    int minSubsetSumDifference(vector<int>& arr, int n) {

        int totSum = 0;

        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

        for (int i = 0; i <= totSum; i++) {
            bool dummy = subsetSumUtil(n - 1, i, arr, dp);
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) {
            if (dp[n - 1][i] == true) {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
            }
        }
        return mini;

}
};