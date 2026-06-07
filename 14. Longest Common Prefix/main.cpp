#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {

        std::string output = "";
        
        for (size_t i = 0; i < strs[0].size(); i++){
            char prefix = strs[0][i];

            for (size_t y = 0; y < strs.size(); y++){
                if(strs[y][i] != prefix || i >= strs[y].size()){
                    return output;
                }
            }
            output += prefix;
        }
        return output;

    }
};



int main(){


    std::vector<std::string> input = {"flower", "flow", "flight"};
    std::vector<std::string> input2 = {"dog", "racecar", "car"};
    std::vector<std::string> test = {""};
    Solution sol;

    // Testcases
    assert((sol.longestCommonPrefix(input) == "fl") && "Das Ergebnis muss fl sein");
    std::cout << "First Solution expected to be: fl and got:" << sol.longestCommonPrefix(input)<< std::endl;
    assert((sol.longestCommonPrefix(input2) == "") && "Das Ergebnis muss "" sein");
    std::cout << "Second Solution expected to be:  and got:" << sol.longestCommonPrefix(input2)<< std::endl;


    return 0;
}