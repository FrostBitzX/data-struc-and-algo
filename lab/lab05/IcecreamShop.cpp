#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    int close;

    cin >> n >> close;

    priority_queue<int, vector<int>, greater<int> > wait_q;

    for(int i=0; i<n; i++){
        int wait;
        cin >> wait;
        wait_q.push(wait);
    }
    
    int can_sell = 0;

    while(!wait_q.empty() && close > 0){
        int wait = wait_q.top();
        wait_q.pop();

        if(wait <= 0){
            continue;
        } else {
            can_sell++;
            close--;

            priority_queue<int, vector<int>, greater<int> > temp_q;
            
            while(!wait_q.empty()){
                int current_wait = wait_q.top();
                wait_q.pop();
                if(current_wait > 1){
                    temp_q.push(current_wait - 1);
                }
            }
            
            while(!temp_q.empty()){
                wait_q.push(temp_q.top());
                temp_q.pop();
            }
        }
    }
    
    cout << can_sell;

    return 0;
}
