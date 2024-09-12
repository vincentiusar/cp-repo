#include <iostream>

using namespace std;

int main() {
    int A, B, C, R, X, Y, Z, count = 0;

    cin >> R;
    cin >> X >> Y >> Z;

    while (cin >> A >> B >> C) if (((X - A) * (X - A)) + ((Y - B) * (Y - B)) + ((Z - C) * (Z - C)) <= (R * R)) count++;

    cout << count << endl;
}