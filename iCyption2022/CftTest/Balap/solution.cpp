#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
    ll finish, start_a, start_b, speed_a, speed_b;
    cin >> finish >> start_a >> start_b >> speed_a >> speed_b;

    ll step_a = ((finish - start_a) / speed_a) + ((finish - start_a) % speed_a != 0);
    ll step_b = ((finish - start_b) / speed_b) + ((finish - start_b) % speed_b != 0);

    if (step_a < step_b) {
        cout << "okawai koto" << endl;
    } else if (step_a > step_b) {
        cout << "like a man" << endl;
    } else {
        cout << "dokoisho" << endl;
    }
}