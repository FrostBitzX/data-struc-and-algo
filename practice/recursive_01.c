#include <stdio.h>

int a_n(int n){
    if(n <= 1){
        return 2;
    }else{
        return a_n(n-1) + 3;
    }
}

int main(){
    int n = 5;
    int output = a_n(5);
    printf("%d ",output);
    return 0;
}