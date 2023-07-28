#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;
    string output;

    int n;
    int num;
    int command;
    int top = 0, count_top = 0;
    
    bool showLen = false;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == 1) {
            cin >> num;
            myStack.push(num);
        } else if (command == 2) {
            if (!myStack.empty()) { 
                myStack.pop();
            }
        } else if (command == 3) {
            if(myStack.empty()){
                output += "EMPTY\n";
            }else{
                output += to_string(myStack.top()) + '\n';
            }
        } else if (command == 4) {
            showLen = true;
        }
    }
    if(!output.empty()){
        cout << output;
    }
    if (showLen) {
        cout << myStack.size() << endl; // ใช้ฟังก์ชัน size() เพื่อหาความยาวของ Stack
    }
    return 0;
}
