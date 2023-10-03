#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> an(n);
    int output = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> an[i];
    }

    int k;
    std::cin >> k;

    for (int i = 0; i < n; i++) {
        if (an[i] == k) {
            output += 1;
        }
    }

    std::cout << output << std::endl;
}
