#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		/*Sorting time: O(NlogN) space: O(logN)*/
		auto ans = 0;
		sort(begin(points), end(points));
		for (auto i = 1U; i < points.size(); i++){
			ans = max(ans, points[i][0] - points[i - 1][0]);
		}
        return ans;
    }
};

void runTest(vector<vector<int>>& points, int expected) {
    Solution solution;
    int result = solution.maxWidthOfVerticalArea(points);
    assert(result == expected);
    cout << "Test Passed!" << endl;
}

int main() {
    // Test Case 1
    vector<vector<int>> points1 = {{8,7},{9,9},{7,4},{9,7}};
    runTest(points1, 1);

    // Test Case 2
    vector<vector<int>> points2 = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    runTest(points2, 3);

    return 0;
}