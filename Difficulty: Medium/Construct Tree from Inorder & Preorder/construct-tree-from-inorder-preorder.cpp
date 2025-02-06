//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/




class Solution {
public: // code written by sunny
    int preorderIndex = 0;
    unordered_map<int, int> inorderMap; 
    Node* constructTree(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL; 
        int rootValue = preorder[preorderIndex++];
        Node* root = new Node(rootValue); 
        int inIndex = inorderMap[rootValue]; 
        root->left = constructTree(inorder, preorder, inStart, inIndex - 1);
        root->right = constructTree(inorder, preorder, inIndex + 1, inEnd);

        return root;
    } 
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size(); 
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }

        return constructTree(inorder, preorder, 0, n - 1);
    }
}; 
void postOrder(Node* root, vector<int>& postorder) {
    if (!root) return;
    postOrder(root->left, postorder);
    postOrder(root->right, postorder);
    postorder.push_back(root->data);
}









































//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends