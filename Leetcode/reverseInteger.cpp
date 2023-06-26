#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if( x < -2147483648 || x > 2147483647) return 0;
        else{
            long n = 0;
            while(x != 0){
                int rem = x % 10;
                x /= 10;
                n = n*10 + rem;
            }
            return n;
        }
    }
};

int main() {
    Solution problem_1;
    cout << problem_1.reverse(-123);
    return 0;
}
