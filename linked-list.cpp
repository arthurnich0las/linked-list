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

void Print(Node* head){
    Node* temp = head;
    printf("\nLista atual: [");
    while(temp != NULL){
        if(temp->next == NULL) printf("%d", temp->data);
        else printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void insertAtTheBeginning(int x, Node** head){
    Node* temp = new Node(x);
    temp->next = *head;
    *head = temp;
}

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

void deleteN(Node **head, int key){
    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        delete temp;
        return;
    }

    else{
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            cout << "Element not present in the list" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
}

int main(){
    Node* head = NULL;

    int N;
    cout << "Insert the number of elements: ";
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cout << "Insert the element: ";
        cin >> x;
        cout << endl << "Where to put the new element?" << endl << "(1) Insert at the beginning of the list" << endl << "(2) Insert at the end of the list" << endl << "(3) Insert at nth position of the list" << endl << "(4) Delete the last element inserted" << endl;
        int choice;
        cout << "Do your choice: ";
        cin >> choice;
        
        if(choice == 1) insertAtTheBeginning(x, &head);
        else if(choice == 2) insertAtTheEnd(x, &head);
        else if(choice == 3){
            int pos;
            cout << "\nWhat position do you wanna insert the new element? ";
            cin >> pos;
            insertAtNth(&head, pos, x);
        }
        else if (choice == 4) deleteN(&head, x);
        Print(head);
    }
}