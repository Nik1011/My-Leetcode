#include <iostream>
#include <vector>


class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> arr;
        arr.push_back(1); // index 0
        arr.push_back(1); // index 1
        if(n == 1){
            return 1;
        }

        for (size_t i = 2; i <= n; i++)
        {
            arr.push_back(arr[i-2] + arr[i-1]);
            std::cout << arr[i] << " ";
        }

        return arr[n];
        
    }
};

int main(){

    Solution sol;
    int number = 13;
    sol.climbStairs(number);


    return 0;
}