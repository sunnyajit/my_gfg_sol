//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public: // code written by sunny
   string topologicalSort(int k, unordered_map<char, unordered_set<char>>& adj) {
    vector<int> indegree(k, 0);
    string order;
    queue<char> q;
     
    for (auto& pair : adj) {
        for (char neighbor : pair.second) {
            indegree[neighbor - 'a']++;
        }
    }
 
    for (auto& pair : adj) {
        if (indegree[pair.first - 'a'] == 0) {
            q.push(pair.first);
        }
    }
    
    
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        order += node;
        
        for (char neighbor : adj[node]) {
            indegree[neighbor - 'a']--;
            if (indegree[neighbor - 'a'] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return order;
}

    string findOrder(string dict[], int n, int k) {
       
         unordered_map<char, unordered_set<char>> adj;
  
    for (int i = 0; i < n - 1; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        
        int minLen = min(word1.length(), word2.length());
        
        for (int j = 0; j < minLen; j++) {
            if (word1[j] != word2[j]) {
                adj[word1[j]].insert(word2[j]);
                break;
            }
        }
    }
    
    
    string order = topologicalSort(k, adj);
    
    return order;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends