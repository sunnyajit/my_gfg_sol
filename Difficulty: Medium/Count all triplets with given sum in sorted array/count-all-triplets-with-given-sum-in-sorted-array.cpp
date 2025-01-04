//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public: // code written by sunny
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == target) {
                    if (arr[left] == arr[right]) {
                        int num = right - left + 1;
                        count += (num * (num - 1)) / 2;  
                        break;
                    } else {
                        int leftCount = 1;
                        while (left + 1 < right && arr[left] == arr[left + 1]) {
                            left++;
                            leftCount++;
                        } 
                        int rightCount = 1;
                        while (right - 1 > left && arr[right] == arr[right - 1]) {
                            right--;
                            rightCount++;
                        }
                         count += leftCount * rightCount; 
                        left++;
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }
};
















































//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends