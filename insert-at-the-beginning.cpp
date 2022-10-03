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

void insertAtTheBeginning(int x, Node** head){
    Node* temp = new Node(x);
    temp->next = *head;
    *head = temp;
}