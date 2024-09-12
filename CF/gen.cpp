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
typedef map<ll, ll> mll;
// using lll = __int128;
const ll M = 1e9 + 7;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define sc second
#define sz(x) (ll) (x).size()
#define all(x) (x).begin(),(x).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

const int MAX_SIDE = 50;
const double MAX_CLEARED_ZONE = 0.75;
const double MAX_X_COUNT_OF_CLEARED = 0.033333;
const pair<int,int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int n = random(3, MAX_SIDE), m = random(3, MAX_SIDE);
    vector<string> g(n, string(m, '#'));

    auto valid = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    const int MUST_CLEAR = random(3, MAX_CLEARED_ZONE*n*m);
    set<pair<int,int>> cleared;
    pair<int,int> pos = {random(0, n - 1), random(0, m - 1)};
    while (cleared.size() < MUST_CLEAR) {
        auto& [x, y] = pos;
        cleared.insert({x, y});
        g[x][y] = '.';

        int k;
        do {
            k = random(0, 3);
        } while (!valid(x + dirs[k].first, y + dirs[k].second));

        x += dirs[k].first, y += dirs[k].second;
    }

    int xCount = random(1, MAX_X_COUNT_OF_CLEARED * MUST_CLEAR);
    vector<bool> choose(MUST_CLEAR); // create all 0's, then fill `xCount` amount of 1's, then shuffle later
    for (int i = 0; i < xCount; i++)
        choose[i] = true;
    
    shuffle(choose.begin(), choose.end(), rng);

    vector<pair<int,int>> cleared_v(cleared.begin(), cleared.end());
    for (int i = 0; i < MUST_CLEAR; i++)
        if (choose[i])
            g[cleared_v[i].first][cleared_v[i].second] = 'X';
    
    cout << n << ' ' << m << '\n';
    for (auto& s : g)
        cout << s << '\n';
}