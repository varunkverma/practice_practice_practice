#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    Node *head;
    int count;

    MyLinkedList()
    {
        this->head = nullptr;
        this->count = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index > this->count - 1 || this->count == 0)
        {
            return -1;
        }
        Node *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->count++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        this->count++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > this->count)
        {
            return;
        }

        if (index == 0)
        {
            this->addAtHead(val);
        }
        else if (index == this->count)
        {
            this->addAtTail(val);
        }
        else
        {
            Node *newNode = new Node(val);
            Node *temp = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            this->count++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index > this->count - 1 || this->count == 0)
        {
            return;
        }
        Node *nodeToDelete = nullptr;
        if (index == 0)
        {
            nodeToDelete = this->head;
            this->head = this->head->next;
        }
        else
        {
            Node *temp = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            nodeToDelete = temp->next;

            temp->next = nodeToDelete->next;
        }
        this->count--;
        delete nodeToDelete;
    }
};

// * Your MyLinkedList object will be instantiated and called as such:
//*/

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);
    cout << obj->get(5);
    obj->deleteAtIndex(6);
    obj->deleteAtIndex(4);
    return 0;
}