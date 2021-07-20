#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MyLinkedList
{
public:
    Node *head;
    int count;

    MyLinkedList()
    {
        this->head = nullptr;
        this->count = 0;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (this->head != nullptr)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
        }
        this->head = newNode;
        this->count++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            Node *t = this->head;
            while (t->next != nullptr)
            {
                t = t->next;
            }
            t->next = newNode;
            newNode->prev = newNode;
        }
        this->count++;
    }

    void addAtIndex(int index, int val)
    {
        if (this->head == nullptr || index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == this->count)
        {
            addAtTail(val);
            return;
        }
        else
        {
            Node *newNode = new Node(val);
            Node *t = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                t = t->next;
            }
            newNode->next = t->next;
            t->next->prev = newNode;

            t->next = newNode;
            newNode->prev = t;

            this->count++;
        }
    }

    int get(int index)
    {
        if (
            this->head == nullptr ||
            index < 0 || index >= this->count)
        {
            return -1;
        }
        Node *t = this->head;
        for (int i = 0; i < index; i++)
        {
            t = t->next;
        }
        return t->data;
    }

    void deleteAtIndex(int index)
    {
        if (
            this->head == nullptr ||
            index < 0 || index >= this->count)
        {
            return;
        }

        if (index == 0)
        {
            this->head = this->head->next;
            if (this->head != nullptr)
            {
                this->head->prev = nullptr;
            }
        }
        else
        {
            Node *pv = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                pv = pv->next;
            }
            Node *target = pv->next;
            pv->next = target->next;
            if (target->next != nullptr)
            {
                target->next->prev = pv;
            }

            target->next = nullptr;
            target->prev = nullptr;
        }

        this->count--;
    }
};

int main()
{

    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(0);
    obj->addAtIndex(1, 4);
    obj->addAtTail(8);
    obj->addAtHead(5);
    obj->addAtIndex(4, 3);
    obj->addAtTail(0);
    obj->addAtTail(5);
    obj->addAtIndex(6, 3);
    // cout << obj->get(1) << endl;
    obj->deleteAtIndex(7);
    obj->deleteAtIndex(5);
    obj->addAtTail(4);
    cout << obj->get(1) << endl;
    return 0;
}