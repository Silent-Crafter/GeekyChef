#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


class Solution
{
public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node* new_head = head_ref;
        Node* temp = NULL;
        Node* prev = new_head;
        Node* curr = new_head->next;

        // Theoretical element that comes before the head
        // Useful for inserting elements before the head node
        Node* begin = new Node(0);
        begin->next = head_ref;
        Node* smaller;

        while ( curr != NULL ) {
            smaller = begin;
            while (smaller->next->data < curr->data && smaller->next != curr)
                smaller = smaller->next;

            // Already in correct position
            if ( smaller == prev ) {
                prev = prev->next;
                curr = curr->next;
                continue;
            }

            prev->next = curr->next;
            temp = curr;

            curr = curr->next;

            temp->next = smaller->next;
            smaller->next = temp;

            // check if we inserted before head
            // thus update the new_head accordingly
            if ( temp->next == new_head ) {
                new_head = temp;
            }
        }

        return new_head;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        cout << "\nStarting sort...." << endl;

        Solution ob;

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}