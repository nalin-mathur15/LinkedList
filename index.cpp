#include <iostream>
#include <stdlib.h>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

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

    void delList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node *nextNode = (*temp).next;
            free(temp);
            temp = nextNode;
        }
        head = nullptr;
    }
};

//example usage
int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    LinkedList ll2;
    ll2.append(3);
    ll2.appendList(ll);
    ll2.displayLL();
    return 0;
}