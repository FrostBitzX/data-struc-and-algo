#include <stdio.h>
#include <string.h>

int main(){
    char stu_name[5][100];
    float score[5];
    float sum = 0, avg = 0;

    for(int i=0; i<5; i++)
    {
        printf("\nEnter %d name: ", i+1);
        scanf("%s", stu_name[i]);
        printf("\nEnter %d score: ", i+1);
        scanf("%f", &score[i]);
        sum += score[i];
    }
    
    avg = sum / 5;

    printf("Average of Score is %.2f.\n",avg);

    for(int i=0;i<5;i++){
        if(score[i] > avg)
        {
            printf("Student who score above average is %s %.2f\n", stu_name[i], score[i]);
        }
    }

}