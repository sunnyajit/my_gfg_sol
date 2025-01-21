//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

 

class Solution {
  public: // code written by sunny
    Node* reverseKGroup(Node* head, int k) { 
        int length = getLength(head);
        
        Node* newHead = nullptr;
        Node* newTail = nullptr;
        Node* groupHead = nullptr;
        Node* groupTail = nullptr;
        Node* current = head;

        while (length > 0) {
            int groupSize = k;
            groupSize = std::min(groupSize, length);
            
            while (groupSize > 0) {
                Node* nextNode = current->next;
                
                if (groupHead == nullptr) {
                    groupHead = current;
                    groupTail = current;
                } else {
                    current->next = groupHead;
                    groupHead = current;
                }
                
                current = nextNode;
                groupSize--;
                length--;
            }

            if (newHead == nullptr) {
                newHead = groupHead;
                newTail = groupTail;
            } else {
                newTail->next = groupHead;
                newTail = groupTail;
            }

            groupHead = nullptr;
            groupTail = nullptr;
        }

        if (newTail != nullptr) {
            newTail->next = nullptr;
        }

        return newHead;
    }

    int getLength(Node* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }
};







//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends