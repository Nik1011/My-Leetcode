#include <iostream>
#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        size_t i = 0;
        int sign = 1;
        long long result = 0;

        // 1. Führende Leerzeichen überspringen
        while (i < s.size() && s[i] == ' ') i++;

        // 2. Vorzeichen
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Ziffern lesen, bei erstem Nicht-Ziffer-Zeichen stoppen
        while (i < s.size() && std::isdigit((unsigned char)s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Overflow-Clamping
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};

int main() {
    Solution sol;
    std::cout << sol.myAtoi("   -42") << "\n";        // -42
    std::cout << sol.myAtoi("4193 with words") << "\n"; // 4193
    std::cout << sol.myAtoi("words 987") << "\n";     // 0
    std::cout << sol.myAtoi("-91283472332") << "\n";  // -2147483648
    return 0;
}