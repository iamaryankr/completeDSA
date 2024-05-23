#include<bits/stdc++.h>

using namespace std;

int solve(int n, int key, vector < int > & v) {
    int start = 0;
    int end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == key) {
        res = mid;
        start = mid + 1;

        } else if (key < v[mid]) {
        end = mid - 1;
        } else {
        start = mid + 1;
        }
    }
    return res;
}