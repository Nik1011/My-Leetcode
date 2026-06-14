#include <iostream>
#include <string>
#include <stdexcept>

class Solution{
public:
    int reverse(int x){

        if(x == 0){
            return 0;
        }

        std::string int_to_string = std::to_string(x);
        std::string current_String = {};
        int result = 0;

        if(int_to_string[0] == '-'){
            // negativ number 
            current_String += "-";
        }
        for (int i = int_to_string.size() -1; i >= 0 ; i--)
        {
            current_String += int_to_string[i];
        }
        // check if number is Overflow of 32Bit
        try{
            result = std::stoi(current_String);
        }catch (const std::invalid_argument& e){
            return 0;
        }catch (const std::out_of_range& e){
            return 0;
        }

        return result;
    }
};


int main(){

    Solution sol;
    int test = 1534236469;
    std::cout << "Erwarte Overflow, also 0 als Ergebnis: " << sol.reverse(test) << std::endl;
    return 0;
}