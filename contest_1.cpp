#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0; 
    
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int l, r;
    while (std::cin >> l >> r) {
        if (l == 0 && r == 0) {
            break;
        }
        std::reverse(a.begin() + (l - 1), a.begin() + r);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}
