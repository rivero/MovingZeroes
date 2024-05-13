#include <iostream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <assert.h>
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
  ^   ^
    ^
        */
class Solution
{
public:
    int removeZeroes(vector<int> vec)
    {
		printvec(vec);
        int left{}, right{ int(vec.size()) - 1 };
        while (left < right)
        {
            if (vec[left] == 0)
            {
                if (vec[right] != 0)
                {
					swap(vec[left++], vec[right--]);
				}
            }
            else
            {
				left++;
            }
            if (left < right && vec[right] != 0)
            {
                if (vec[left] == 0)
                {
					swap(vec[left++], vec[right--]);
                }
            }
            else
				right--;

        }
        printvec(vec);
        return left;
    }

    void printvec(const vector<int>& vec) const
    {
        for (auto elem : vec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

};

int main() 
{
    Solution sol;
    if (false)
    {
		auto res = sol.removeZeroes({ 1, 0, 2, 0, 4 });
		cout << res << endl;
		assert(res == 3);

		res = sol.removeZeroes({ 0, 0, 0, 1, 0, 2, 0, 4 });
		cout << res << endl;
		assert(res == 3);

		res = sol.removeZeroes({ 0, 0, 0, 0, 0, 0, 0, 4 });
		cout << res << endl;
		assert(res == 1);

		res = sol.removeZeroes({ 0, 0, 0, 0, 0, 0, 0 });
		cout << res << endl;
		assert(res == 0);

		res = sol.removeZeroes({ 0, 0, 0, 0, 1, 1, 1, 1 });
		cout << res << endl;
		assert(res == 4);

		res = sol.removeZeroes({ 0 });
		cout << res << endl;
		assert(res == 0);
    }

	if (true)
	{
		vector<int> vec{ 0, 1, 2, 0, 0, 3,4 };
		cout << sol.removeZeroes(vec) << endl;
		cout << endl;

	}
	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		cout << sol.removeZeroes(vec) << endl;
		cout << endl;

	}

    return 0;
}
