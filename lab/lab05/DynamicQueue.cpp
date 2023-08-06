#include <iostream>
#include <queue>

using namespace std;

int main(){
    int x;
    cin >> x;
    string result;
    queue<int> q;

    for(int i=0;i<x;i++){
        int command;
        cin >> command;
        int num;

        if(command == 1){
            cin >> num;
            q.push(num);
        } else if(command == 2 && !q.empty()){
            q.pop();
        } else if(command == 3){
            if(q.empty()){
                result += "EMPTY\n";
            }else{
                result += to_string(q.front())+'\n';
            }
        } else if(command == 4){
            result += to_string(q.size())+'\n';
        }
    }

    cout << result;
    return 0;
}
