#include <iostream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <ctime>

using namespace std;
/*
'''
You are given an array of integers. Write an algorithm that brings all nonzero elements to the left of the array, and returns the number of nonzero elements.

The algorithm should operate in place, i.e. shouldn't create a new array.
The order of the nonzero elements does not matter.
The numbers that remain in the right portion of the array can be anything. Example: given the array [ 1, 0, 2, 0, 0, 3, 4 ], a possible answer is [ 4, 1, 3, 2, ?, ?, ? ], 4 non-zero elements, where "?" can be any number.
Code should have optimal big-O time complexity and minimize the number of writes to the array.

Example:
Input: [1, 0, 2, 0, 4]
Answer: input modified to [1, 2, 4, ?, ?], return 3
'''

1 0 2 0 4
^
        ^
1 4 2 0 0
  ^
      ^
    ^
def removeZeroes(arr: List[int]) -> int:
    # TODO
*/
class Solution
{
public:
    int removeZeroes(vector<int>& vec)
    {
        if (vec.size() < 3)
        {
            return vec.size();
        }
        bool swapped = false;
        int left{}, right{ vec.size() - 1 }, counter{};
        while (left != right)
        {
            swapped = false;
            if (vec[left] == 0)
            {
                if (vec[right] != 0)
                {
                    swap(vec[left], vec[right]);
                    ++counter;
                    swapped = true;
                }
            }
            if (swapped)
                left++; right--;

        }
        return counter;
    }
};
// To execute C++, please define "int main()"
int main() {
    auto words = { "Hello, ", "World!", "\n" };
    for (const auto& word : words) {
        cout << word;
    }
    return 0;
}
