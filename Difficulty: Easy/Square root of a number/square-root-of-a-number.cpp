//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root

class Solution {
  public: // code written by sunny.
    long long int floorSqrt(long long int n) {
        if (n == 0 || n == 1) return n; // Handle special cases
    int left = 1, right = n;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long midSquare = (long long)mid * mid;  

        if (midSquare == n) {
            return mid;
        } else if (midSquare < n) {
            result = mid; 
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result; //
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends