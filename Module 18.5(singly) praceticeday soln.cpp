#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class SinglyLinkedlist
{
public:
    node *head;
    int size;

    SinglyLinkedlist()
    {
        head = NULL;
        size = 0;
    }

    node *CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void InsertAtHead(int data)
    {
        size++;
        node *a = CreateNewNode(data);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->next = head;
        head = a;
    }

    void PushBack(int data)
    {
        size++;
        node *newnode = CreateNewNode(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
        return;
    }

    void Traverse()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getValue(int index)
    {
        node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (idx == index)
            {
                return temp->data;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    void deleteZero()
    {
        while (head != NULL)
        {
            if (head->data == 0)
            {
                node *d = head;
                head = head->next;
                delete d;
            }
            else
            {
                break;
            }
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == 0)
            {
                node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    int getOddIndexSum()
    {
        int idx = 0, sum = 0;
        node *temp = head;
        while (temp != NULL)
        {
            if (idx % 2 != 0)
            {
                sum += temp->data;
            }
            temp = temp->next;
            idx++;
        }
        return sum;
    }

    bool hasDuplicate()
    {
        node *temp = head;
        while (temp != NULL)
        {
            node *temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->data == temp2->data)
                {
                    return true;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return false;
    }

};

int main(void)
{
    SinglyLinkedlist l;
    l.PushBack(0);
    l.PushBack(0);
    l.PushBack(1);
    l.PushBack(0);
    l.PushBack(2);
    l.PushBack(0);
    l.PushBack(0);
    // l.PushBack(3);
    // l.PushBack(2);
    // l.PushBack(6);
    // l.PushBack(4);
    // l.PushBack(5);

    l.Traverse();
    // cout << l.getValue(8)<<"\n";
    l.deleteZero();
    l.Traverse();
    // cout << l.getOddIndexSum() << "\n";
    // l.hasDuplicate()?cout<<"True\n":cout<<"False\n";

    return 0;
}
