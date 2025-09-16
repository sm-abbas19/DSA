#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // Removes duplicates from a sorted vector in-place and returns the number of unique elements
    int removeDuplicates(vector<int> &nums){
        // If the input vector is empty, return 0
        if (nums.empty()) return 0;

        // last_unique keeps track of the index of the last unique element found
        int last_unique = 0;

        // Start scanning from the second element
        for (int scan = 1; scan < nums.size(); scan++){
            // If the current element is different from the last unique element
            if (nums[last_unique] != nums[scan]){
                // Move the unique element forward and update last_unique
                nums[++last_unique] = nums[scan]; 
            }
        }

        // The number of unique elements is last_unique + 1
        return last_unique + 1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> testCases = {
        {1,2,2,2,3,3,3,4,4,5},
        {1,1,1,1,1},
        {1,2,3,4,5},
        {},
        {1}
    };

    for (auto& nums : testCases) {
        int result = s.removeDuplicates(nums);
        cout << "{";
        for (int i = 0; i < result; i++) {
            cout << nums[i];
            if (i < result - 1) cout << ",";
        }
        cout << "}" << endl;
    }
    return 0;
}