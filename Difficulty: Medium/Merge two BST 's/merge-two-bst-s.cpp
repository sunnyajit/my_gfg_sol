//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void inOrderTraversal(Node* root, std::vector<int>& result) {
        if (!root) return;
        inOrderTraversal(root->left, result);
        result.push_back(root->data);
        inOrderTraversal(root->right, result);
    }

    vector<int> merge(Node *root1, Node *root2) {
        // Your code written by sunny
         vector<int> bst1Values;
         vector<int> bst2Values;
        inOrderTraversal(root1, bst1Values);
        inOrderTraversal(root2, bst2Values);
        std::vector<int> merged;
        int i = 0, j = 0;
        
        while (i < bst1Values.size() && j < bst2Values.size()) {
            if (bst1Values[i] < bst2Values[j]) {
                merged.push_back(bst1Values[i]);
                i++;
            } else {
                merged.push_back(bst2Values[j]);
                j++;
            }
        }
        while (i < bst1Values.size()) {
            merged.push_back(bst1Values[i]);
            i++;
        }
        
        while (j < bst2Values.size()) {
            merged.push_back(bst2Values[j]);
            j++;
        }

        return merged;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends