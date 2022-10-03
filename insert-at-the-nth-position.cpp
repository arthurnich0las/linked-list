#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtNth(Node** current, int pos, int data){
    while(pos--){
        if(pos == 0){
            Node *temp = new Node(data);
            temp->next = *current;
            *current = temp;
        }
        else{
            current = &(*current)->next;
        }
    }
    return;
}