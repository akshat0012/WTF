#include <iostream>
#include <cctype>
using namespace std;

/*
 * Time Complexity O(N)
 * Space Complexity O(1)
 * Using Two pointers approach
 */

class Solution {
public:

    string removeAlphaNumericChar(string s) {
        string result;
        for (char& c:s) if (!isspace(c)) {
            if (iswalnum(c)){
                c = tolower(c);
                result += c;
            }
        }
        s = result;
        return s;
    }

    bool isPalindrome(string s) {
        s = removeAlphaNumericChar(s);
        int i = 0;
        int j = s.length() - 1;

        while (j-i-1 >= 0) {
            if (s[i] != s[j]) {
                return false;
            }
            else {
                i ++;
                j --;
            }
        }
        return true;
    }
};

int main() {
    Solution problem_1;
    cout << problem_1.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << problem_1.isPalindrome("race a car") << endl;
}