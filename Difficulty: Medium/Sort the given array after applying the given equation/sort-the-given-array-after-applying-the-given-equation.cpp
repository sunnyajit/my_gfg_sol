//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
public: // code written by sunny
    int transform(int x, int A, int B, int C) {
        return A * x * x + B * x + C;
    }
    vector<int> sortArray(vector<int>& arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;  

        while (left <= right) {
            int leftVal = transform(arr[left], A, B, C);
            int rightVal = transform(arr[right], A, B, C);
            
            if (A >= 0) {
                if (leftVal > rightVal) {
                    result[index--] = leftVal;
                    left++;
                } else {
                    result[index--] = rightVal;
                    right--;
                }
            } else {
                if (leftVal < rightVal) {
                    result[index++] = leftVal;
                    left++;
                } else {
                    result[index++] = rightVal;
                    right--;
                }
            }
        }

        return result;
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

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends