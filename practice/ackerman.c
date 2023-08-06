#include <stdio.h>
#include <string.h>

int Ack(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return Ack(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return Ack(m - 1, Ack(m, n - 1));
    }
}


int main() {
    int m,n;
    printf("input m and n into Ackermann: ");
    scanf("%d %d",&m,&n);


    printf("A(%d, %d) is %d\n", m, n, Ack(m, n));
    
    return 0;
}