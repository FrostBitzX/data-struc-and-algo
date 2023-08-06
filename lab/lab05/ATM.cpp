#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, max;
    cin >> n >> max;
    queue<pair<int, int> > q; // index, amount

    for (int i = 1; i <= n; i++) {
        int amount;
        cin >> amount;
        q.push(make_pair(i, amount));
    }

    while (!q.empty()) {
        int index = q.front().first;
        int amount = q.front().second;
        if (amount - max <= 0){
            cout << index << " ";
            q.pop();
        } else{
            amount -= max;
            q.pop();
            q.push(make_pair(index, amount));
        }
    }

    return 0;
}