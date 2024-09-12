#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution

struct Point {
    typedef Point P;
    int x, y;
    void read() { cin >> x >> y; }
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator < (P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator == (P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator + (P& p) { return P(x + p.x, y + p.y); }
    P operator - (P& p) { return P(x - p.x, y - p.y); }
    P operator * (int d) { return P(x*d, y*d); }
    P operator / (int d) { return P(x/d, y/d); }
    int dot(P p) { return x*p.x + y*p.y; }
    int cross(P p) { return x*p.y - y*p.x; }
    int dist2() { return x*x + y*y; }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;

    vector<Point> vs;
    map<Point, int> exist;
    for (int i = 0; i < n; i++) {
        Point a, b;
        a.read(), b.read();
        vs.push_back(b - a);
        exist[vs[i]] = i;
    }

    auto findThirdSegment = [&](array<Point, 2> segments) {
        // try every possibility of positive/negatives
        for (int bit = 0; bit < 4; bit++) {
            Point sum(0, 0);
            for (int i = 0; i < 2; i++) {
                if (bit & (1<<i)) sum = sum + segments[i];
                else sum = sum - segments[i];
            }

            if (exist.find(sum) != exist.end()) return exist[sum];
            if (exist.find(sum*-1) != exist.end()) return exist[sum*-1];
        }
        return -1;
    };

    int maxPerim = -1;
    array<int, 3> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // to rule out 0-area triangles
            if (vs[i].cross(vs[j]) == 0) continue;

            int thirdSegment = findThirdSegment({vs[i], vs[j]});
            if (thirdSegment != -1) {
                int perim = vs[i].dist2() + vs[j].dist2() + vs[thirdSegment].dist2();
                if (perim > maxPerim) {
                    maxPerim = perim;
                    ans = {i + 1, j + 1, thirdSegment + 1};
                }
            }
        }
    }

    if (maxPerim == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}
