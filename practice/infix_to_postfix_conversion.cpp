#include <iostream>
#include <stack>
#include <string>
#include <cctype> // เพิ่มการ include library สำหรับใช้ std::isalnum
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix;
    stack<char> s;

    for (size_t i = 0; i < infix.length(); i++) { // ใช้ลำดับดัชนีเพื่ออ่านข้อมูลแทน range-based 'for' loops
        char c = infix[i];
        if (c == ' ') continue; // ข้ามช่องว่าง
        if (isalnum(c)) { // ใช้ std::isalnum ในการตรวจสอบว่าเป็นตัวแปร (operand) หรือไม่
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // นำ '(' ออกจาก Stack
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "input infix: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "output postfix: " << postfix << endl;

    return 0;
}
