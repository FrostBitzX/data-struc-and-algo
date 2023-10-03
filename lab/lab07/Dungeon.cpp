#include <iostream>
#include <vector>

int main(){
    int n; //จำนวน monster
    std::cin >> n;

    std::vector<int> x(n); //พลังชีวิต monster
    for(int i=0; i<n; i++){
        std::cin >> x[i];
    }

    int q; //จำนวนอาวุธ
    std::cin >> q;
    std::vector<int> Q(q);
    for(int i=0; i<q; i++){
        std::cin >> Q[i];
    }

    std::vector<int> output(q);
    for(int i=0; i<n; i++){
        for(int j=0;j<q; j++){
            if(x[i] - Q[j] <= 0){
                output[j] += 1;
            }
        }

    }

    for(int i=0; i<q; i++){
        std::cout << output[i] << std::endl;
    }
}