#include<iostream>
#include<string.h>
using namespace std;

int main() {

int row;
int column;

cin >> row >> column;

int dimension[row][column];

for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
        cin >> dimension[i][j];
    }
}

for(int i=1; i<row; i++){
    int temp[column];
    for(int j=0;j<column; j++){
        int previous = dimension[i-1][j];
        temp[j] = dimension[i][previous-1];
    }

    memcpy(dimension[i],temp,column*sizeof(int));
}

for(int i=0;i<column;i++){
    cout << dimension[row-1][i] << " ";
}

}