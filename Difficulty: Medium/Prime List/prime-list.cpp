//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
// */
class Solution {
  public: // code written by sunny
    vector<bool> isPrime;
    vector<int> nearestPrimeMap;

    void sieve(int maxVal) {
        isPrime.assign(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    void buildNearestPrimeMap(int limit) {
        nearestPrimeMap.resize(limit + 1);

        for (int i = 1; i <= limit; ++i) {
            if (isPrime[i]) {
                nearestPrimeMap[i] = i;
                continue;
            }

            int offset = 1;
            while (true) {
                int lower = i - offset;
                int upper = i + offset;

                if (lower >= 2 && isPrime[lower]) {
                    nearestPrimeMap[i] = lower;
                    break;
                }
                if (upper <= limit * 10 && isPrime[upper]) {
                    nearestPrimeMap[i] = upper;
                    break;
                }
                ++offset;
            }
        }
    }

    Node* primeList(Node* head) {
        int LIMIT = 10000;
        sieve(LIMIT * 10);  
        buildNearestPrimeMap(LIMIT);

        Node* current = head;
        while (current) {
            current->val = nearestPrimeMap[current->val];  
            current = current->next;
        }
        return head;
    }
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

//{ Driver Code Starts.

int main() {

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
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends