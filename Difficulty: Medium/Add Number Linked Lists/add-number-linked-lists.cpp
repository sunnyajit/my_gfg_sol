//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

 
 
 
class Solution {
  public: // code written by sunny
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummyHead = new Node(0);
        Node* current = dummyHead;
        int carry = 0; 
        while (num1 != NULL || num2 != NULL || carry != 0) {
            int sum = carry;
            if (num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        } 
        Node* result = reverseList(dummyHead->next);
 
        delete dummyHead;
 
        while (result != NULL && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }
        if (result == NULL) {
            return new Node(0);
        }

        return result;
    }
};
 
 




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends