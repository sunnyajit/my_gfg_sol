//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
    int lastIndex = str.length() - 1;
    if (str[lastIndex] <= '5') {
        str[lastIndex] = '0'; 
        return str;
    }
    str[lastIndex] = '0'; 
    lastIndex--; 
    while (lastIndex >= 0 && str[lastIndex] == '9') {
        str[lastIndex] = '0'; 
        lastIndex--; 
    }
    if (lastIndex == -1) {
        return '1' + str;
    }
    str[lastIndex]++;
    return str;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends