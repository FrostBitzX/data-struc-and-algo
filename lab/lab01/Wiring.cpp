#include <iostream>
using namespace std;

int main(){

    int count;
    int temp;
    cin >> count;
    int pole[count];
    int wire = 0;

    for(int i=0; i<count; i++){
        cin >> pole[i];
    }

    for(int i=0; i<count-1; i++){
        for(int j=i+1; j<count; j++){
            bool connect = true;
            for(int k=i+1; k<j; k++){
                if(pole[k] >= pole[i] || pole[k] >= pole[j]){
                    connect = false;
                    break;
                }
            }
            if(connect){
                wire += 1;
            }
        }
    }

    cout << wire;
}