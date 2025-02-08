#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

    Node* split(Node *source) {
        Node* fast = source->next;
        Node* slow = source;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* middle = slow->next;
        slow->next = nullptr;
        return middle;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* mergeSort(Node* node) {
        if (!node || !node->next) return node;

        Node* middle = split(node);
        Node* left = mergeSort(node);
        Node* right = mergeSort(middle);

        return merge(left, right);
    }

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList(){
        delList();
    }

    Node* createNode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == nullptr) {
            std::cerr << "Memory allocation failed" << std::endl;
            exit(EXIT_FAILURE);
        }

        newNode->data = data;
        (*newNode).next = nullptr;
        return newNode;
    }

    void append(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while ((*temp).next != nullptr) {
            temp = (*temp).next;
        }
        (*temp).next = newNode;
    }

    void appendList(const LinkedList& ll) {
        if (ll.head == nullptr) {
            return;
        }

        if (head == nullptr) {
            Node* temp = ll.head;
            while (temp != nullptr) {
                append(temp->data);
                temp = temp->next;
            }
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }

        Node* otherTemp = ll.head;
        while (otherTemp != nullptr) {
            append(otherTemp->data);
            otherTemp = otherTemp->next;
        }
    }

    void displayLL() const {
        Node *temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void createList() {
        cout << "Enter integers to add to the linked list. Enter a non-integer value to end the list.\n";
        int val;
        while (true) {
            cout << "Enter number: ";
            cin >> val;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            append(val);
        }

        cout << "\nList Produced: \n";
        displayLL();
    }

    void delList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node *nextNode = (*temp).next;
            free(temp);
            temp = nextNode;
        }
        head = nullptr;
    }

    void sort() {
        head = mergeSort(head);
    }

    void removeDuplicates() {
        if (!head || !head->next) return;

        Node* cur = head;
        while (cur && cur->next) {
            if (cur->data == cur->next->data) {
                Node* dup = cur->next;
                cur->next = cur->next->next;
                free(dup);
            } else {
                cur = cur->next;
            }
        }
    }


};

//example usage
int main() {
    LinkedList ll;
    ll.createList();
    cout << "\nList after removing duplicates: \n";
    ll.removeDuplicates();
    ll.displayLL();
    return 0;
}