#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector< vl > vll;
typedef vector<bool> vb;
typedef vector< vb > vbb;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define sc second
#define sz(x) (ll) (x).size()
#define all(x) (x).begin(),(x).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

struct people {
    ll id;
    string name;
    ll birth;
    string par;
};

bool vis[5005] = {0};

people splitGen(string str, char x) {
    string tmp = "";

    ll id = 0;
    people p; p.id = 0;
    for(int i = 0; i < (int)str.size(); i++){

        if (str[i] != x) {
            tmp += str[i];
        } else {
            if (id == 0) {
                p.name = tmp;
            } else if (id == 1) {
                ll res = 0;
                string haha = "";
                ll cur = 0;
                tmp += '-';
                for (ll j = 0; j < (int)tmp.size(); j++) {
                    if (tmp[j] != '-') haha += tmp[j];
                    else {
                        if (cur == 0) {
                            res += stoi(haha);
                        } else if (cur == 1) {
                            ll month = 0;
                            if (haha == "JAN") month = 1;
                            if (haha == "FEB") month = 2;
                            if (haha == "MAR") month = 3;
                            if (haha == "APR") month = 4;
                            if (haha == "MEI") month = 5;
                            if (haha == "JUN") month = 6;
                            if (haha == "JUL") month = 7;
                            if (haha == "AGU") month = 8;
                            if (haha == "SEP") month = 9;
                            if (haha == "OKT") month = 10;
                            if (haha == "NOV") month = 11;
                            if (haha == "DES") month = 12;

                            res += month * 100;
                        } else {
                            res += stoi(haha) * 10000;
                        }
                        haha = "";
                        cur++;
                    }
                }
                p.birth = res;
            } else {
                p.par = tmp;
            }
            id++;
            tmp = "";
        }
    }

    return p;
}

bool compOldtoYoung(people a, people b) {
    return a.birth < b.birth;
}

bool compYoungtoOld(people a, people b) {
    return a.birth > b.birth;
}

vl result;

void dfs(vll g, ll cur, ll d, ll gen) {
    vis[cur] = 1;
    if (d == gen) result.push_back(cur);
    for (ll adj : g[cur]) {
        dfs(g, adj, d+1, gen);
    }
}

void solve() {
    ll n; cin >> n;
    vector < people > arr;
    memset(vis, 0, 5005);

    ll mins = 1e18; vl root;
    for (ll i = 0; i < n; i++) {
        string tmp;
        if (i == 0) cin.ignore();
        getline(cin, tmp);
        tmp += ';';
        
        people p = splitGen(tmp, ';');
        p.id = i;
        if (p.par == "") {
            root.push_back(i);
        }

        arr.push_back(p);
    }

    vll g;
    g.resize(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (arr[i].par == arr[j].name) {
                g[arr[j].id].push_back(arr[i].id);
                break;
            }
        }
    }

    // cout << root << endl;
    // for (ll i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (ll item : g[i]) {
    //         cout << item << " ";
    //     }
    //     cout << endl;
    // }

    ll t; cin >> t;
    for (ll i = 0; i < t; i++) {
        string str;
        if (i == 0) cin.ignore();
        getline(cin, str);

        ll howMany = -1;
        bool reverse = 1;
        ll gen = -1;

        ll cur = 0;
        string tmp = "";
        for (ll j = 0; j < (int)str.size(); j++) {
            if (str[j] != ' ') {
                tmp += str[j];
            } else {
                if (cur == 0) {
                    howMany = stoi(tmp);
                } else if (cur == 3) {
                    if (tmp == "tertua") {
                        reverse = 0;
                    } else {
                        reverse = 1;
                    }
                }
                cur++;
                tmp = "";
            }
        }

        gen = stoi(tmp);

        result.clear();
        for (ll item : root) {
            dfs(g, item, 1, gen);
        }

        if (result.size() == 0) {
            cout << "NIHIL" << endl;
            continue;
        }

        vector < people > lastRes;
        for (ll k = 0; k < result.size(); k++) {
            // cout << result[i] << " ";
            lastRes.push_back(arr[result[k]]);
        }

        if (!reverse) sort(lastRes.begin(), lastRes.end(), compOldtoYoung);
        else sort(lastRes.begin(), lastRes.end(), compYoungtoOld);

        if (!reverse) {
            string pr = "";
            for (ll j = 0; j < howMany && j < result.size(); j++) {
                // pr = (j != howMany - 1 && j != result.size()-1 ? "," : "") + lastRes[j].name + pr;
                cout << lastRes[j].name;
                if (j != howMany - 1 && j != result.size()-1) cout << ",";
                else cout << endl;
            }
            // cout << pr << endl;
        } else {
            for (ll j = (howMany-1 > result.size()-1 ? result.size()-1 : howMany-1); j >= 0; j--) {
                cout << lastRes[j].name;
                if (j != 0) cout << ",";
                else cout << endl;
            }
        }

        for (ll j = 0; j < 5005; j++) vis[j] = 0;
    }
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}