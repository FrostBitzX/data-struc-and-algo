#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tmp;
    int ary[100000];
    int count = 0;
    while(true) {
        cin >> tmp;
        if(tmp == -1){
            break;
        }
        ary[count] = tmp;
        count++;
    }

    sort(ary,ary+count);
    for(int i=0; i<count; i++){
        cout << ary[i] << endl;
    }
}