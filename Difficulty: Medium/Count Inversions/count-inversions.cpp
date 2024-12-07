//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 

class Solution {
public: // code written by sunny
    int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        int i = left;    
        int j = mid + 1;  
        int k = left;     
        int inv_count = 0; 
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i + 1);
            }
        } 
        while (i <= mid) {
            temp[k++] = arr[i++];
        } 
        while (j <= right) {
            temp[k++] = arr[j++];
        } 
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inv_count;
    } 
    int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right) {
        int inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2; 
            inv_count += mergeSortAndCount(arr, temp, left, mid); 
            inv_count += mergeSortAndCount(arr, temp, mid + 1, right); 
            inv_count += mergeAndCount(arr, temp, left, mid, right);
        }
        return inv_count;
    } 
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }
};




//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends