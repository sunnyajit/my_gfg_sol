//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
public: // code written by sunny
    Node* sortedInsert(Node* head, int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr) return newNode;
        if (head->data >= x) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;   
        }
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data < x) {
            previous = current;
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = previous;
        if (previous != nullptr) {
            previous->next = newNode;
        }
        if (current != nullptr) {
            current->prev = newNode;
        }
        return head;   
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends