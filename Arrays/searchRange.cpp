#include <iostream>
#include <vector>

using namespace std;

// Solution class to find the first and last position of a target in a sorted array
class Solution{
    public:
    // Function to search for the first and last occurrence of target
    vector<int> searchRange(vector<int> &nums, int target){
        int first = -1, last = -1; // Initialize positions to -1 (not found)
        vector<int> output = {};
        int s = 0, e = nums.size() - 1; 

        // Binary search for the first occurrence
        while(s <= e){
            int mid = (s+e) / 2;
            if (nums[mid] == target){
                first = mid;      // Update first position
                e = mid - 1;      // Continue searching left half
            }
            else if (nums[mid] > target){
                e = mid - 1;      // Search left half
            }
            else{
                s = mid + 1;      // Search right half
            }  
        }

        // Reset search boundaries for last occurrence
        s = 0, e = nums.size() - 1;
        
        // Binary search for the last occurrence
        while(s <= e){
            int mid = (s+e) / 2;
            if (nums[mid] == target){
                last = mid;       // Update last position
                s = mid + 1;      // Continue searching right half
            }
            else if (nums[mid] < target){
                s = mid + 1;      // Search right half
            }
            else{
                e = mid - 1;      // Search left half
            }  
        }

        // Store results in output vector
        output.push_back(first);
        output.push_back(last);
        return output;
    }
};

// Example test code for your searchRange function
int main() {
    Solution s;

    // Test case 1: Target appears twice
    vector<int> nums1 = {1, 2, 3, 4, 4, 5};
    vector<int> result1 = s.searchRange(nums1, 4);
    cout << "Test 1: {1,2,3,4,4,5}, target=4 -> {" << result1[0] << "," << result1[1] << "}" << endl; // Expected: {3,4}

    // Test case 2: Target appears once
    vector<int> nums2 = {1, 2, 3, 4, 4, 5};
    vector<int> result2 = s.searchRange(nums2, 2);
    cout << "Test 2: {1,2,3,4,4,5}, target=2 -> {" << result2[0] << "," << result2[1] << "}" << endl; // Expected: {1,1}

    // Test case 3: Target not present
    vector<int> nums3 = {1, 2, 3, 4, 4, 5};
    vector<int> result3 = s.searchRange(nums3, 6);
    cout << "Test 3: {1,2,3,4,4,5}, target=6 -> {" << result3[0] << "," << result3[1] << "}" << endl; // Expected: {-1,-1}

    // Test case 4: Empty array
    vector<int> nums4 = {};
    vector<int> result4 = s.searchRange(nums4, 1);
    cout << "Test 4: {}, target=1 -> {" << result4[0] << "," << result4[1] << "}" << endl; // Expected: {-1,-1}

    // Test case 5: All elements are target
    vector<int> nums5 = {2,2,2,2,2};
    vector<int> result5 = s.searchRange(nums5, 2);
    cout << "Test 5: {2,2,2,2,2}, target=2 -> {" << result5[0] << "," << result5[1] << "}" << endl; // Expected: {0,4}

    return 0;
}
