#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTheEnd(int x, Node** head){
    Node* temp = new Node(x);
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    Node* temp1 = *head;

    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }

    temp1->next = temp;
    return;
}