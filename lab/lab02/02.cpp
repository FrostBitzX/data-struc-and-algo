#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int L[n], R[n];
    int index[n];
    int max_length = 0;
    
    map<int, set<int> > map_of_set;

    for (int i = 0; i < n; i++) {
        index[i] = i + 1;
        cin >> L[i] >> R[i];
    }

    for (int i = 0; i < n; i++) {
        int index_to_push = index[i];

        map_of_set[index_to_push].insert(index_to_push);
        if (L[i] > 0) {
            map_of_set[index_to_push].insert(L[i]);
            index[L[i] - 1] = index_to_push;
        }
        if (R[i] > 0) {
            map_of_set[index_to_push].insert(R[i]);
            index[R[i] - 1] = index_to_push;
        }

        int setLength = map_of_set[index_to_push].size();
        max_length = max(max_length, setLength);
    }

    cout << max_length;

    return 0;
}