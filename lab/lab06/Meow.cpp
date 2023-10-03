#include <iostream>
#include <string>

using namespace std;

int main() {
    int count;
    cin >> count;

    while (count--) {
        int len;
        cin >> len;

        string str = "";
        char prev = '\0';

        while (len--) {
            char c;
            cin >> c;
            if (toupper(c) != prev) {
                str += toupper(c);
                prev = toupper(c);
            }
        }

        cout << (str == "MEOW" ? "YES" : "NO") << endl;
    }

    return 0;
}