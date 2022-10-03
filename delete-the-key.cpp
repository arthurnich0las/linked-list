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
    Node* head;

void deleteN(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp->next != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) return; //não achou nenhum elemento == key

        prev->next = temp->next;
        delete temp;
    }
}