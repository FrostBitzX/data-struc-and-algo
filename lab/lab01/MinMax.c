#include <stdio.h>

int main(){

    int count;
    int min = 10010;
    int max = -10010;
    int temp;
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        scanf("%d", &temp);

        if(temp > max){
            max = temp;
        }
        if(temp < min){
            min = temp;
        }
    }

    printf("%d\n%d",min,max);
}