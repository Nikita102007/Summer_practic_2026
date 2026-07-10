#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    queue<long long> q1;
    queue<long long> q2;

    for (int i = 0; i < n; ++i) {
        q1.push(a[i]);
    }

    auto get_min = [&]() {
        long long val;
        if (q1.empty()) {
            val = q2.front();
            q2.pop();
        } else if (q2.empty()) {
            val = q1.front();
            q1.pop();
        } else if (q1.front() <= q2.front()) {
            val = q1.front();
            q1.pop();
        } else {
            val = q2.front();
            q2.pop();
        }
        return val;
    };

    for (int i = 0; i < n - 1; ++i) {
        long long first = get_min();
        long long second = get_min();

        cout << first << " " << second << "\n";

        q2.push(first + second);
    }

    return 0;
}
