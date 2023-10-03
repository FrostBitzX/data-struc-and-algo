#include <bits/stdc++.h>
using namespace std;

bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++)
    if(num%i==0)
    return false;
    
    return (num>=2)? true : false;
}

int makeprime(int num,int step=0){
    if(num<10) return (isprime(num))? step:INT_MAX;
    if(isprime(num)) return step;
    int minstep = INT_MAX;
    for(int i=1;i<num;i*=10){
        int temp = num/(10*i)*i+num%i;
        minstep = min(makeprime(temp, step+1),minstep);
        }
    
    return minstep;
}

int main(){
    int n;
    cin >> n;
    int ans = makeprime(n);
    (ans == INT_MAX)? cout << -1 : cout << ans;
}