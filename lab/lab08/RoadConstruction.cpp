#include <iostream>
#include <vector>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
        visited.resize(n + 1, false);
    }

    void addEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int begin) {
        visited[begin] = true;

        for (int i : adj[begin]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    int findConnAll() {
        int count = -1;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }

        return count;
    }
};

int main() {
    int n,m;
    std::cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int a,b;
        std::cin >> a >> b;
        graph.addEdge(a,b);
    }
    
    std::cout << graph.findConnAll();

    return 0;
}
