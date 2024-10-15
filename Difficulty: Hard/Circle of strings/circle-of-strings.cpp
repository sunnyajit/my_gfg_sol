//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

 class Solution {
public:  // code written by sunny
    int isCircle(vector<string> &arr) {
        unordered_map<char, int> inDegree, outDegree;
        unordered_map<char, unordered_set<char>> graph;
        unordered_set<char> nodes;
  
        for (const string& s : arr) {
            char start = s[0];
            char end = s[s.length() - 1];
            outDegree[start]++;
            inDegree[end]++;
            graph[start].insert(end);
            nodes.insert(start);
            nodes.insert(end);
        }
  
        for (const auto& node : nodes) {
            if (inDegree[node] != outDegree[node]) {
                return 0;  
            }
        }
        
         
        unordered_set<char> visited;
        
      
        auto startNode = nodes.begin();
        if (startNode != nodes.end()) {
            dfs(graph, *startNode, visited);
        }
        
        for (const auto& node : nodes) {
            if (inDegree[node] > 0 && visited.find(node) == visited.end()) {
                return 0;  
            }
        }
        
        return 1;   
    }
    
private:
    void dfs(const unordered_map<char, unordered_set<char>>& graph, char start, unordered_set<char>& visited) {
        stack<char> s;
        s.push(start);
        while (!s.empty()) {
            char node = s.top();
            s.pop();
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (const auto& neighbor : graph.at(node)) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends