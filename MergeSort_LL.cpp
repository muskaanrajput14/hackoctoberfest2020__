#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *Take_Input_2()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "NULL";
    }
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *finalTail = NULL;
    Node *finalHead = NULL;

    if (temp1->data <= temp2->data)
    {
        finalHead = temp1;
        finalTail = temp1;
        temp1 = temp1->next;
    }
    else
    {
        finalHead = temp2;
        finalTail = temp2;
        temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 -> data <= temp2 -> data)
        {
            finalTail -> next = temp1;
            finalTail = finalTail -> next;
            temp1 = temp1->next;
        }
        else
        {
            finalTail -> next = temp2;
            finalTail = finalTail -> next;
            temp2 = temp2 -> next;
        }
    }

    if(temp1 == NULL)
    {
        finalTail -> next = temp2;
    }

    if(temp2 == NULL)
    {
        finalTail -> next = temp1;
    }
    return finalHead;
}

int main()
{
    Node *head1 = Take_Input_2();
    Node *head2 = Take_Input_2();
    //print(head);
    Node* head3 = mergeTwoSortedLL(head1, head2);
    print(head3);
    return 0;
}
