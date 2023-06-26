#include <vector>
#include <iostream>
using namespace std;
/*
 * Classic Two Sum leetcode problem
 * using HashMap to get O(N) time complexity
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> return_vector;

        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j --;
            }
            else if (numbers[i] + numbers[j] < target) {
                i ++;
            }
            else {
                return_vector.push_back(i+1);
                return_vector.push_back(j+1);
                break;
            }
        }
        return return_vector;
    }
};


int main() {
    Solution problem_1;
    vector<int> number {5,25,75};
    problem_1.twoSum(number, 100);
    return 0;
}
