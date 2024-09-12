#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

typedef pair<ll, ll> pll;

bool cmp(vector <ll>& a, vector <ll>& b) {
    return a[0] < b[0];
}

void maxEvents(vector<vector<ll>>& events) {
    ll n = events.size();
    sort(events.begin(), events.end(), cmp);
    ll ret = 0;
    ll itr = 0;
    ll arr[n] = {0};
    priority_queue <pll, vector <pll>, greater<pll>> pq;
    ll j = 0;
    for(ll i = 1; i <= 1e5; i++){
        while(itr < n && events[itr][0] == i){
            pq.push({events[itr][1], events[itr][2]});
            itr++;
        }
        while(!pq.empty() && pq.top().first < i) pq.pop();
        if(!pq.empty()){
            arr[j++] = pq.top().second;
            pq.pop();
            ret++;
        }
    }
    if (ret < n) cout << "impossible";
    else {
        for (ll j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
    }
    cout << endl;
}

int main(){
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<vector<ll>> v;
        for (ll i = 1; i <= n; i++) {
            ll a, b; cin >> a >> b;
            v.push_back({a, b, i});
        }
        maxEvents(v);
    }
}
