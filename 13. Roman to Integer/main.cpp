#include <iostream>
#include <unordered_map>
#include <algorithm>


class Solution{
public:
    int romanToInt(std::string s, std::unordered_map<char, int> map){
        int result = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            if(i + 1 < s.size() && (map[s[i]] < map[s[i+1]] )){
                result -= map[s[i]];
            }else{
                result += map[s[i]];

            }
        }   
        
        return result;
    }
};



int main(){

    std::unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    std::string input = "III";
    std::string input2 = "LVIII";
    std::string input3 = "MCMXCIV";


    Solution sol;
    std::cout << "Ergebnis:" << sol.romanToInt(input, map) << std::endl;
    std::cout << "Ergebnis:" << sol.romanToInt(input2, map) << std::endl;
    std::cout << "Ergebnis:" << sol.romanToInt(input3, map) << std::endl;



    return 0;
}