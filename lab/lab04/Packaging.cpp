#include <iostream>
#include <stack>

using namespace std;

int cal_pack_cost(int a, int b, int c, const string& items) {
    stack<int> cost;

    // calculate inside bracket
    for (char type : items) {
        if (type == '[' || type == '(' || type == '{') {
            cost.push(-1); 
        } else if (type == ']' || type == ')' || type == '}') {
            int groupCost = 0;
            while (cost.top() != -1) {
                groupCost += cost.top();
                cost.pop();
            }
            cost.pop(); 

            char openingBracket = (type == ']') ? '[' : (type == ')') ? '(' : '{';
            if (openingBracket == '[')
                groupCost = groupCost + (groupCost * 0.1);
            else if (openingBracket == '(')
                groupCost = groupCost + (groupCost * 0.07);
            else if (openingBracket == '{')
                groupCost = groupCost + (groupCost * 0.05);

            cost.push(groupCost); 
        } else {
            if (type == 'A') cost.push(a);
            else if (type == 'B') cost.push(b);
            else if (type == 'C') cost.push(c);
        }
    }

    // calculate outside bracket
    int totalCost = 0;
    while (!cost.empty()) {
        totalCost += cost.top();
        cost.pop();
    }

    return totalCost;
}

int main() {
    int a, b, c;
    string items;
    cin >> a >> b >> c >> items;

    int totalCost = cal_pack_cost(a, b, c, items);
    cout << totalCost;

    return 0;
}