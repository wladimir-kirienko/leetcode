#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
	int maxScore(string s) {
        auto ans = 0;
        for (auto i = 0; i < s.size() - 1; i++) {
            auto sum = 0;
            for (auto j = 0; j < s.size(); j++) {
                auto n = (j<=i) ? '0': '1';
                if (s[j] == n) {
                    sum++;
                }
            }
            ans = max(ans, sum);
        }

        return ans;
    }

	int maxScore2(string s) {
        int ones = count(begin(s), end(s), '1');

        int ans = 0;
        int zeros = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            ans = max(ans, zeros + ones);
        }

        return ans;
    }

    int maxScore3(string s) {
        auto ones = 0;
        auto zeros = 0;
        auto best = INT_MIN;

        for (auto i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }

            best = max(best, zeros - ones);
        }

        if (s[s.size() - 1] == '1') {
            ones++;
        }

        return best + ones;
    }

	// Function to test maxScore
	bool testMaxScore(const string& s, int expected) {
		return maxScore(s) == expected;
	}

	// Function to test maxScore2
	bool testMaxScore2(const string& s, int expected) {
		return maxScore2(s) == expected;
	}

	// Function to test maxScore3
	bool testMaxScore3(const string& s, int expected) {
		return maxScore3(s) == expected;
	}
};



int main() {
    Solution solution;

    // Test maxScore
    assert(solution.testMaxScore("011101", 5));
    assert(solution.testMaxScore("00111", 5));
    assert(solution.testMaxScore("1111", 3));

    // Test maxScore2
    assert(solution.testMaxScore2("011101", 5));
    assert(solution.testMaxScore2("00111", 5));
    assert(solution.testMaxScore2("1111", 3));

    // Test maxScore3
    assert(solution.testMaxScore3("011101", 5));
    assert(solution.testMaxScore3("00111", 5));
    assert(solution.testMaxScore3("1111", 3));

    cout << "All tests passed!" << endl;
    return 0;
}