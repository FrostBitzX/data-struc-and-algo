#include <iostream>

int main() {
    long n, ans = 0;
    std::cin >> n;

    while (n >= 1) {
        ans += n;
        n /= 2;
    }

    std::cout << ans;
}