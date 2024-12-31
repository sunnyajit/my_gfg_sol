//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends





class Solution {
  public: // code written by sunny
    int longestConsecutive(vector<int>& arr) {
         unordered_set<int> elements(arr.begin(), arr.end());
         int longest = 0;
          for(int num : arr){
            if(elements.find(num-1) == elements.end()){
                int currentNum = num;
                int currentStreak = 1;
                while(elements.find(currentNum + 1) != elements.end()){
                    currentNum++;
                    currentStreak++;
                }
              longest = max(longest, currentStreak);
            }
        }
      return longest;
    }
};


































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends