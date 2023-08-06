#include <stdio.h>

int a(int n, int d) {
    if (n == 1) {
        return d;
    } else {
        return a(n - 1, d) + 3;
    }
}

int main() {
    int result = a(5, 2);
    printf("a(5, 2) = %d\n", result);
    return 0;
}