#include <bits/stdc++.h>
  
using namespace std;
typedef long long ll;

struct Item {
    ll quanty, weight;
};

bool compare(Item i1, Item i2) {
    return (i1.weight > i2.weight);
}

int main() {
    ll W; cin >> W;
    ll x; cin >> x;
    Item arr[x];
    
    ll total = 0;
    for (ll i = 0; i < x; i++) {
        cin >> arr[i].quanty;
        cin >> arr[i].weight;
        total += arr[i].quanty * arr[i].weight;
    }

    if (W == 0) {
        cout << 0;
        return 0;
    }

    if (total < W) {
        cout << "kaerimashou!";
        return 0;
    }

    sort(arr, arr+x, compare);
    ll i = 0, res = 0;
    while (W > 0) {
        ll count = arr[i].quanty * arr[i].weight;
        if (count <= W) {
            res += arr[i].quanty;
            W -= count;
        } else {
            if (W % arr[i].weight == 0) {
                res += W/arr[i].weight;
                W -= (W/arr[i].weight) * arr[i].weight;
            } else {
                res += W/arr[i].weight + 1;
                W -= (W/arr[i].weight + 1) * arr[i].weight;
            }
        }
        i++;
    }
    cout << res;
    return 0;
}