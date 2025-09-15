#include <iostream>
#include <vector>

using namespace std;
// Current solution: O(n^2) using vector
// Later we will optimize using unordered_map for O(n)

class Solution{
    public:

    // Function to find indices of two numbers that add up to target
    vector<int> twoSum(vector<int> &nums, int target){

        int first=-1, second=-1; // Indices of the two numbers
        bool found=false;        // Flag to indicate if a pair is found
        vector<int> output;      // Output vector to store result

        // Iterate through each pair of elements
        for (int i = 0; i < nums.size(); i++){

            for (int j = 0; j < nums.size(); j++){

                // Check if the sum equals target and indices are different
                if ((nums[i] + nums[j] == target) && (i != j)){
                    
                    first = i;       // Store first index
                    second = j;      // Store second index
                    found = true;    // Mark as found
                    break;           // Exit inner loop
                }
            }
            if (found) break;        // Exit outer loop if pair is found
        }
        output.push_back(first);     // Add first index to output
        output.push_back(second);    // Add second index to output
        return output;               // Return result
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,4};     // Input array
    int target = 6;                 // Target sum
    vector<int> result = s.twoSum(nums, target); // Call twoSum

    // Print output indices
    cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
