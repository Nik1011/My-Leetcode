#include <iostream>
#include <string>

class Solution{
public:
    bool isPalindrome(int x){

        std::string string_Forward = {};
        std::string string_Backwords = {};
        std::string current_string = std::to_string(x);

        for (int i = 0; i < (int)current_string.size(); i++)
        {
            string_Forward += current_string[i];
        }
        for (int i = (int)current_string.size() -1; i >= 0; i--)
        {
            string_Backwords += current_string[i];
        }
        if(string_Backwords == string_Forward){
            return true;
        }else{
            return false;
        }
        
    }

};

int main(){

    Solution sol;
    int palindrom = 1011;

    std::cout << "Das Ergebis ist: " << sol.isPalindrome(palindrom) << std::endl; 

    return 0;
}