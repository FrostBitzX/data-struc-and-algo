#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> stu;
    std::vector<std::vector<int>> rows;
    std::cin >> n;
    for(int i=0;i<n;i++){
        int student;
        std::cin >> student;
        stu.push_back(student);
        if(i==0){
            std::vector<int> first = {stu[0]};
            rows.push_back(first);
        }
    }

    // [[1, 2, 3],[4, 5]]
    int index = 0;
    for(int i=1;i<n;i++){

    if (stu[i] > rows[index].back())
    {
        /* code */
        rows[index].push_back(stu[i]);
    }
    else if (stu[i] < rows[index].front())
    {
        rows[index].insert(rows[index].begin(), stu[i]);
    }
    else {
        std::vector<int> newRow = {stu[i]};
        rows.push_back(newRow);
        index++;
    }
    
        
    }

    for(auto & row : rows) {
        for(auto & student : row) {
            std::cout << student << " ";
        }
        std::cout << "\n";
    }
    return 0;
}