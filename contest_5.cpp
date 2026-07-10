#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    long long ans;
    cin >> ans;
    
    for (int i = 1; i < n; ++i) {
        long long t;
        cin >> t;
        ans = std::lcm(ans, t);
    }
    
    cout << ans << "\n";
    
    return 0;
}
