#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
};

void creat(node **head,int item){
    node *ptr = new node(item);
    if (*head == NULL){
        *head = ptr;
        ptr->link = ptr;
    }
    else{
        node *temp = *head;
        while (temp->link != *head){
            temp = temp->link;
        }
        temp->link = ptr;
        ptr->link = *head;
    }
}

void bin(node **head,int data,int item){
    node *ptr = new node(item);
    node *temp=*head, *prev;
    do{
        if (temp->data == data){
            if (temp == *head){
                ptr->link = *head;
                *head = ptr;
                while (temp->link!=NULL){
                    temp= temp->link;
                }
                temp->link = *head;
            }
            else{
                ptr->link = temp;
                prev->link = ptr;
            }
            return;
        }
        else{
            prev = temp;
            temp = temp->link;
        }
    }while (temp != *head);
}

void fin(node **head, int item){
    node *ptr = new node(item);
    node *temp = *head;
    ptr->link = *head;
    while (temp->link!=*head){
        temp = temp->link;
    }
    temp->link = ptr;
    *head = ptr;
}

void lin(node **head, int item){
    node *ptr = new node(item);
    node *temp = *head;
    while (temp->link!=*head){
        temp = temp->link;   
    }
    temp->link = ptr;
    ptr->link = *head;
}

void ain(node **head, int data,int item){
    node *ptr = new node(item);
    node *temp = *head;
    do{
        if (temp->data==data){
            if (temp->link==*head){
                temp->link = ptr;
                ptr->link = *head;
            }
            else{
                ptr->link = temp->link;
                temp->link = ptr;
            }
            return;
        }
        else {
            temp = temp->link;
        }
    }while (temp!=*head);
}
void display(node **head){
    node *temp  = *head;
    do{
        cout << temp->data << " ";
        temp = temp->link;
    }while (temp != *head);
}

int main()
{
    int n;cin >> n;
    node *head = NULL;
    for (int i=0;i<n;i++){
        int x;cin >> x;
        creat (&head,x);
    }
    fin(&head,8);
    display(&head);
}