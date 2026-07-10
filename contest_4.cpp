#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long binPow(long long base, long long exp, long long mod) {
    base %= mod;
    if (base < 0) base += mod;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum = (sum + x) % MOD;
    }
    sum = ((sum % MOD) + MOD) % MOD;

    long long power = binPow(2, n - 1, MOD);

    long long answer = (sum * power) % MOD;
    answer = (answer + MOD) % MOD;

    cout << answer << "\n";

    return 0;
}
