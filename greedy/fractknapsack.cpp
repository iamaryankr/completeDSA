// Example:

// Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

// Output: 240.00

// Explanation: The first and second items  are taken as a whole  
//             while only 20 units of the third item is taken. 
//             Total value = 100 + 60 + 80 = 240.00

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}


double maximumValue(vector<pair<int,int>>& items, int n, int w){
    sort(items.begin(), items.end(), compare);

    double maxValue = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++){
        if (currWeight + items[i].first <= w){
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else{
            int remainingWeight = w - currWeight;

            // Pick a fraction of current item.
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }

    return maxValue;
}