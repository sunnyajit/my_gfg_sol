//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution { // code written by sunny
  struct TrieNode {
      TrieNode* children[2];
      TrieNode() {
          children[0] = children[1] = nullptr;
      }
  };

  TrieNode* root;

  void insert(int num) {
      TrieNode* node = root;
      for (int i = 31; i >= 0; i--) {
          int bit = (num >> i) & 1;
          if (!node->children[bit]) {
              node->children[bit] = new TrieNode();
          }
          node = node->children[bit];
      }
  }

  int getMaxXOR(int num) {
      TrieNode* node = root;
      int maxXor = 0;
      for (int i = 31; i >= 0; i--) {
          int bit = (num >> i) & 1;
          int oppositeBit = 1 - bit;
          if (node->children[oppositeBit]) {
              maxXor |= (1 << i);
              node = node->children[oppositeBit];
          } else {
              node = node->children[bit];
          }
      }
      return maxXor;
  }

public:
    int maxXor(vector<int> &arr) {
        root = new TrieNode();
        int maxResult = 0;

        insert(arr[0]);
        for (int i = 1; i < arr.size(); ++i) {
            int currentXor = getMaxXOR(arr[i]);
            maxResult = max(maxResult, currentXor);
            insert(arr[i]);
        }

        return maxResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends