#include <iostream>
#include <vector>

using namespace std;

/* 
 * example move
 * move up (dx[0], dy[0]) = (-1, 0)
 * move down (dx[1], dy[1]) = (1, 0)
 */
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y, int size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

// backtracking path using depth first search
bool find_path(vector<vector<int> > &grid, int x, int y, int size) {
    if (x == size - 1 && y == size - 1) {
        return true;
    }

    grid[x][y] = 1; // 1 = visited

    for (int dir = 0; dir < 4; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if (is_valid(new_x, new_y, size) && grid[new_x][new_y] == 0 && find_path(grid, new_x, new_y, size)) {
            return true;
        }
    }

    return false;
}

int main() {
    int size;
    cin >> size;

    vector<vector<int> > grid(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> grid[i][j];
        }
    }

    if (find_path(grid, 0, 0, size)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
