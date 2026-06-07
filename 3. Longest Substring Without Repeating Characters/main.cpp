#include <iostream>
#include <unordered_set>

class Solution{
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> subString = {}; 
        int biggestSubStringSize = 0;
        int currentSize = 0;

        for (size_t i = 0; i < s.length(); i++){
            for (size_t y = i; y < s.length(); y++)
            {
                if(currentSize > biggestSubStringSize){
                    biggestSubStringSize = currentSize;
                }
                if((s.length()-i) <= biggestSubStringSize){
                    break;
                }
                if(s.length() == 1){
                    return 1;
                }
                

                char currentChar = s[y];
                if(!subString.count(currentChar)){
                    subString.insert(currentChar);
                    currentSize += 1;
                    std::cout << currentChar <<  " and Size: " << biggestSubStringSize << std::endl;
                }else{
                    subString.clear();
                    currentSize = 0;
                    break;
                }        
            }
        }
        return biggestSubStringSize;
    }

};

int main(){

    Solution sol;
    std::string test = "bcabca";
    // std::cout << "Ergebnis: " << sol.lengthOfLongestSubstring(test) << std::endl; 
    sol.lengthOfLongestSubstring(test); 
    return 0;
}