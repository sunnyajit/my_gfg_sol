//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++


#include <iostream>
#include <vector>
using namespace std; 
class TrieNode {
public:// code written by sunny
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();  
    }

    void insert(string &word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a'; 
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();  
            }
            node = node->children[index];
        }
        node->isEnd = true;  
    }

    bool search(string &word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return node->isEnd;  
    }

    bool isPrefix(string &word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return true;  
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends