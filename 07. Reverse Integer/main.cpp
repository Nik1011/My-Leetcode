#include <iostream>
#include <cmath>
#include <string>


class Solution{
public:
    int reverse(int x){

        std::string int_to_string = std::to_string(x);
        std::string result = {};
        if(int_to_string[0] == '-'){
            // negativ number 
            result += "-";
        }
        for (int i = int_to_string.size() -1; i >= 0 ; i--)
        {
            result += int_to_string[i];
        }

        
        return (int)std::stoi(result);
    }

    int bitSize(int x){

        int size = 0;
        for (int i = 0; i < 33; i++)
        {
            int zweierPotenz = 1 << i;
            int division = x / zweierPotenz;
            //std::cout << division << std::endl;

            if( division >= 1){
                size += 1;
            }
            else{
                break;
            }
        }
        return size;   
    }
};


int main(){

    Solution sol;
    int test = 1534236469;
    //std::cout << "Reverse the number Result: " << sol.reverse(test) << std::endl; 
    sol.bitSize(test);
    return 0;
}