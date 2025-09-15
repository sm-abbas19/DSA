#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
    // Function to find the longest common prefix among a vector of strings
    string longestCommonPrefix(vector<string> &strs){
        if (strs.size() == 0){
            // Handle empty input vector
            cout << "Please give a non empty vector.";
            return "";
        }
        
        string output = ""; // Stores the common prefix

        // Iterate over each character of the first string
        for (int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i]; // Current character to check

            // Compare with the same position in all other strings
            for (int j = 1; j < strs.size(); j++){
                // If mismatch or index out of bounds, return current prefix
                if (i >= strs[j].size() || c != strs[j][i]){
                    return output;
                }          
            }
            
            output.push_back(c); // Add character to prefix if all match
        }
        return output; // Return the longest common prefix
    }
};

int main(void){
    Solution s;
    vector<string> stringvec = {"cat", "dog", "flight"}; // Input vector of strings
    string output = s.longestCommonPrefix(stringvec);    // Call function
    cout << output << endl;                              // Print result
}