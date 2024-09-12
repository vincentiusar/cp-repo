// C++ program to find minimum time required to
// send people on other side of bridge
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* Global dp[2^20][2] array, in dp[i][j]--
   'i' denotes mask in which 'set bits' denotes
   total people standing at left side of bridge
   and 'j' denotes the turn that represent on
   which side we have to send people either
   from left to right(0) or from right to
   left(1)  */
ll dp[1 << 20][2];
 
/* Utility function to find total time required
   to send people to other side of bridge */
ll findMinTime(ll leftmask, bool turn, ll arr[], ll& n)
{
 
    // If all people has been transferred
    if (!leftmask)
        return 0;
 
    ll& res = dp[leftmask][turn];
 
    // If we already have solved this subproblem,
    // return the answer.
    if (~res)
        return res;
 
    // Calculate mask of right side of people
    ll rightmask = ((1 << n) - 1) ^ leftmask;
 
    /* if turn == 1 means currently people are at
     right side, thus we need to transfer
     people to the left side */
    if (turn == 1) {
        ll minRow = INT_MAX, person;
        for (ll i = 0; i < n; ++i) {
 
            // Select one people whose time is less
            // among all others present at right
            // side
            if (rightmask & (1 << i)) {
                if (minRow > arr[i]) {
                    person = i;
                    minRow = arr[i];
                }
            }
        }
 
        // Add that person to answer and recurse for next turn
        // after initializing that person at left side
        res = arr[person] + findMinTime(leftmask | (1 << person),
                                        turn ^ 1, arr, n);
    }
    else {
 
        // __builtin_popcount() is inbuilt gcc function
        // which will count total set bits in 'leftmask'
        if (__builtin_popcount(leftmask) == 1) {
            for (ll i = 0; i < n; ++i) {
 
                // Since one person is present at left
                // side, thus return that person only
                if (leftmask & (1 << i)) {
                    res = arr[i];
                    break;
                }
            }
        }
        else {
 
            // try for every pair of people by
            // sending them to right side
 
            // Initialize the result with maximum value
            res = INT_MAX;
            for (ll i = 0; i < n; ++i) {
 
                // If ith person is not present then
                // skip the rest loop
                if (!(leftmask & (1 << i)))
                    continue;
 
                for (ll j = i + 1; j < n; ++j) {
                    if (leftmask & (1 << j)) {
 
                        // Find maximum integer(slowest
                        // person's time)
                        ll val = max(arr[i], arr[j]);
 
                        // Recurse for other people after un-setting
                        // the ith and jth bit of left-mask
                        val += findMinTime(leftmask ^ (1 << i) ^ (1 << j),
                                                       turn ^ 1, arr, n);
                        // Find minimum answer among
                        // all chosen values
                        res = min(res, val);
                    }
                }
            }
        }
    }
    return res;
}
 
// Utility function to find minimum time
ll findTime(ll arr[], ll n)
{
    // Find the mask of 'n' peoples
    ll mask = (1 << n) - 1;
 
    // Initialize all entries in dp as -1
    memset(dp, -1, sizeof(dp));
 
    return findMinTime(mask, 0, arr, n);
}
 
// Driver program
int main()
{
    ll n; cin >> n;
    ll arr[n] = {0};

    for (ll i = 0; i < n; i++) cin >> arr[i];
    cout << findTime(arr, n);
    return 0;
}