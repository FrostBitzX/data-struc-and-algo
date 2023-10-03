#include <iostream>
#include <vector>


#define MAX_N 200000

struct Node {
    int data;
    Node* parent;
    std::vector<Node*> children;
};

std::vector<Node*> tree(MAX_N);
std::vector<int> descendants(MAX_N, 0);

void initTree(int n) {
    for (int i = 0; i < n; i++) {
        tree[i] = new Node{ i + 1, nullptr, {} };
    }
}

void addEdge(int parent, int child) {
    tree[child - 1]->parent = tree[parent - 1];
    tree[parent - 1]->children.push_back(tree[child - 1]);
}

void calDes(Node* node) {
    for (Node* child : node->children) {
        calDes(child);
        descendants[node->data - 1] += 1 + descendants[child->data - 1];
    }
}

int main() {
    int n;
    std::cin >> n;

    initTree(n);

    for (int i = 2; i <= n; i++) {
        int p;
        std::cin >> p;
        addEdge(p, i);
    }

    calDes(tree[0]);

    for (int i = 0; i < n; i++) {
        std::cout << descendants[i] << ' ';
        delete tree[i];
    }

    return 0;
}