#include <iostream>
using namespace std;

int main() {
    string word;
    getline(cin, word);

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            i+=2;
        }
            cout << word[i];
    }

    return 0;
}
