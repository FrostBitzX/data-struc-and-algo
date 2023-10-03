#include <iostream>
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int degree[n];

    for(int i=0; i<n; i++){
        degree[i] = 0;
    }

    for(int i=0; i<m; i++){
        int u,v;
        std::cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    std::cout << degree[k];
    return 0;
}
