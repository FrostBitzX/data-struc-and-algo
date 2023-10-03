#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){
    int n,k;
    long long int ans=0;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    
    int x = a[0];
    for(int i=0;i<n;i++)
    x = gcd(x,a[i]);
    
    set<int> factors;
    
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            factors.insert(i);
            factors.insert(x/i);
            }
    }

while(k--){
    int l,r,p;
    long long int sum=0;
    cin >> l >> r >> p;
// Maximum number not exceed r -> prev of upper bound
    int size = *(--factors.upper_bound(r));
// size requirement not satisfied -> skip
    if(size<l) continue;
    for(int i=0;i<n;i++)
    sum += a[i]/size*p;
    
    ans = max(ans,sum);
}

    cout << ans;
}