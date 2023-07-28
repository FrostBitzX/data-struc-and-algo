#include <iostream>
using namespace std;

int main() {
    int stu;
    cin >> stu;
    double sub1[stu];
    double sub2[stu];
    double sub3[stu];

    //คะแนนรวมแต่ละวิชา
    double sumSub1;
    double sumSub2;
    double sumSub3;


    for(int i=0;i<stu;i++){
        cin >> sub1[i];
        sumSub1 += sub1[i];
        cin >> sub2[i];
        sumSub2 += sub2[i];
        cin >> sub3[i];
        sumSub3 += sub3[i];
    }

    //ค่าเฉลี่ยรายวิชา
    double avgSub1 = sumSub1 / stu;
    double avgSub2 = sumSub2 / stu;
    double avgSub3 = sumSub3 / stu;

    //ค่าเฉลี่ยทั้งหมด
    double avgAll = (sumSub1+sumSub2+sumSub3) / stu;

    for(int i=0;i<stu;i++){
        int c = 0;
        bool avgMore2Sub = false;
        bool sumAllSubMoreAvg = false;
        bool noFali = false;

        if(sub1[i] >= avgSub1){
            c++;
        }
        if(sub2[i] >= avgSub2){
            c++;
        }
        if(sub3[i] >= avgSub3){
            c++;
        }

        if(c>=2){
            avgMore2Sub = true;
        }

        if((sub1[i]+sub2[i]+sub3[i]) >= avgAll){
            sumAllSubMoreAvg = true;
        }
        if(sub1[i]!=0 && sub2[i]!=0 && sub3[i]!=0){
            noFali = true;
        }

        if(avgMore2Sub && sumAllSubMoreAvg && noFali){
            cout << i+1 << " ";
        }
    }
}