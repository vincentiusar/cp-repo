#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

vector<ll> parent, ranked;

void make_set(ll v) {
    parent[v] = v;
    ranked[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranked[a] < ranked[b])
            swap(a, b);
        parent[b] = a;
        if (ranked[a] == ranked[b])
            ranked[a]++;
    }
}

struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() { 
    ll n, v; cin >> n;
    v = (n*(n-1))/2;
    vector<Edge> edges(v);

    ll cost = 0;
    vector<Edge> result;
    parent.resize(n);
    ranked.resize(n);

    for (ll i = 0; i < v; i++) {
        ll a, b; cin >> a >> b; a--; b--;
        edges[i].u = a;
        edges[i].v = b;
        cin >> edges[i].weight;
    }

    for (int i = 0; i < n; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    cout << cost << endl;
}
