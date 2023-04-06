#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;

    Node *nxt;
    Node *prev;
};
class DoublyLL
{
public:
    Node *head;
    int size;
    DoublyLL()
    {
        head = NULL;
        size = 0;
    }

    void InsertAtHead(int data)
    {
        size++;
        Node *newnode = CreatNewNode(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        newnode->nxt = head;
        temp->prev = newnode;
        head = newnode;
    }

    Node *CreatNewNode(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;
        newnode->prev = NULL;
        newnode->nxt = NULL;

        return newnode;
    }

    void Traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nxt;
        }
        cout << "\n";
    }

    void Delete(int index)
    {
        if (index >= size)
        {
            cout << "Index out of bound\n";
            return;
        }
        Node *a = head;
        int cur_index = 0;
        while (cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        Node *b = a->prev;
        Node *c = a->nxt;
        if (b != NULL)
        {
            b->nxt = c;
        }
        if (c != NULL)
        {
            c->prev = b;
        }
        delete a;
        if (index == 0)
        {
            head = c;
        }
        size--;
    }

    void Reverse()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        int cur_index = 0;
        while (cur_index != size - 1)
        {
            temp = temp->nxt;
            cur_index++;
        }
        Node *b = head;
        while (b != NULL)
        {
            swap(b->nxt, b->prev);
            b = b->prev;
        }
        head = temp;
    }

    int GetSize()
    {
        return size;
    }

    int getMax()
    {
        Node *a = head;
        int max = 0;
        while (a != NULL)
        {
            if (a->data > max)
            {
                max = a->data;
            }
            a = a->nxt;
        }
        return max;
    }

    void deleteMax()
    {
        // 3,2,6,4,5,6
        int max = getMax();
        if (head->data == max)
        {
            Node *temp = head;
            head = head->nxt;
            delete temp;
        }
        Node *a = head;
        while (a != NULL)
        {
            if (a->nxt == NULL && a->data == max)
            {
                a->prev->nxt = NULL;
                delete a;
            }
            if (a->data == max)
            {
                Node *del = a;
                Node *before = del->prev;
                Node *after = del->nxt;
                before ->nxt = after;
                after->prev = before;
                a = after;
                delete del;
            }
            a = a->nxt;
        }
    }
};
int main(void)
{
    DoublyLL l;
    // l.InsertAtHead(5);
    l.InsertAtHead(6);
    l.InsertAtHead(5);
    l.InsertAtHead(4);
    l.InsertAtHead(6);
    l.InsertAtHead(2);
    l.InsertAtHead(3);
    // l.Delete(0);
    // l.Delete(2);
    l.Traverse();
    // l.Reverse();
    // l.Traverse();
    // cout << l.GetSize() << "\n";
    // cout << l.getMax() << "\n";
    l.deleteMax();
    l.Traverse();
    return 0;
}
