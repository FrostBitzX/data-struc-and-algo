#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin >> n >> e;
    vector<int> graph1[n];
    int graph2[n][n] = {0};
    
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        graph1[x-1].push_back(y-1);
        graph1[y-1].push_back(x-1);
        graph2[x-1][y-1] = 1;
        graph2[y-1][x-1] = 1;
    }
    
    int count5=0,count6=0;
    for(int i=0;i<n;i++){
        for(int ii=0;ii<graph1[i].size();ii++){
            for(int j=0;j<n;j++){
                for(int jj=0;jj<graph1[j].size();jj++){
                    int member[] = {i,graph1[i][ii],j,graph1[j][jj]};
                    if(member[0]>member[1] || member[2]>member[3]) continue;
                    if(member[0]==member[2] || member[0]==member[3]) continue;
                    if(member[1]==member[2] || member[1]==member[3]) continue;
                    int friends = 0;
                    
                    for(int i=0;i<4;i++)
                    for(int j=i+1;j<4;j++)
                    friends += graph2[member[i]][member[j]];
                    if(friends == 5) count5++;
                    if(friends == 6) count6++;
                }
            }
        }
    }
    
cout << count5/4 + count6/6;
}