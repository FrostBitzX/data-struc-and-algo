#include <iostream>
using namespace std;

int main() {
    string bracket;

    cin >> bracket;

    bool isParenthesis = true;

    int r_brac = 0;
    int l_brac = 0;
    for(int i = 0; i < bracket.size(); i++){
        if(i==0 && bracket[i]==')'){
            isParenthesis = false;
            break;
        }
        if(bracket[i]=='('){
            l_brac++;
        }else if(bracket[i]==')'){
            r_brac++;
        }
    }
        if(l_brac != r_brac){
            isParenthesis = false;
        }

    if(isParenthesis){
        cout << "YES";
    }else{
        cout << "NO";
    }
}