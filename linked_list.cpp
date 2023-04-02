#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *link;
};

void swp(int *a, int *b){
    if (a != b) {
        *a ^= *b ^= *a ^= *b;
    }
}

void creat(node **head,int data)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->link = NULL;
    if (*head == NULL){
        *head = ptr;
    }
    else{
        node *temp = *head;
        while (temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = ptr;
    }
}
void fin(node**head,int data)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->link = *head;
    *head = ptr;
}
void lin(node** head,int data)
{
    node *temp = *head;
    creat(&temp,data);
}

void bin(node **head,int data,int src)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->link = NULL;

    node *temp , *prev;
    temp = *head;
    while (temp!=NULL){
        if (temp->data==src){
            if (temp==*head) return fin(head,data);
            else {
                ptr->link = temp;
                prev->link = ptr;
                return;
            }
        }
        else{
            prev = temp;
            temp = temp->link;
        }
    }
}

void ain(node **head,int data,int src)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->link = NULL;
    node *temp = *head;
    while (temp!=NULL)
    {
        if (temp->data==src){
            ptr->link = temp->link;
            temp->link = ptr;
            return;
        }
        else{
            temp = temp->link;
        }
    }
}
void fdel(node **head)
{
    *head = (*head)->link;
}

void ldel(node **head)
{
    node *temp = *head;
    node *prev;
    while (temp->link!=NULL){
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
}
void anydel(node **head, int del)
{
    node *temp = *head;
    node *prev;
    while (temp!=NULL){
       if (temp->data==del){
          if (temp == *head) return fdel(head);
          else {
            prev->link=temp->link;
            return;
          }
       }
       else{
         prev = temp;
         temp = temp->link;
       }
    }
}

void smerg(node **head1, node **head2)
{
    node *t1 = *head1 , *t2 = *head2;
    node *t1n,*t2n;
    while (t1!=NULL && t2!=NULL){
        t1n = t1->link;
        t2n = t2->link;

        if (t1n != NULL){
          t2->link = t1->link;
        }
        t1->link = t2;

        t1 = t1n;
        t2 = t2n;
    }
    return;
}

void sortt(node **head){
    node *temp1 = *head, *temp2;
    while (temp1!=NULL){
        temp2 = temp1->link;
        while (temp2!=NULL){
            if (temp1->data>temp2->data){
                swp(&temp1->data,&temp2->data);
            }
            temp2 = temp2->link;
        }
        temp1=temp1->link;
    }
}

int ncount(node **head){
    node *temp = *head;
    int cnt =0;
    while (temp != NULL){
        cnt++;
        temp = temp->link;
    }
    return cnt;
}

void admid(node **head,int item){
    node *ptr = new node();
    ptr->data = item;
    ptr->link = NULL;
    int n = ncount(head);
    n = (n+1)/2;
    int i=1;
    node *temp = *head;
    while (i<n){
        temp = temp->link;
        i++;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

bool isSorted(node **head){
    node *temp = *head;
    while (temp->link != NULL){
        if (temp->data > temp->link->data) return false;
        temp = temp->link;
    }
    return true;
}

void rmvdup(node **head){
    sortt(head);
    node *temp = *head, *next=temp->link;
    while (next!=NULL){
        if (temp->data == next->data){
            temp->link = next->link;
            next = temp->link;
        }
        else{
            temp = temp->link;
            next = next->link;
        }
    }
}


void display(node **head)
{
    node *temp = *head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main()
{
    int n;cin >> n;
    node *head1 = NULL;
    for (int i=0;i<n;i++){
        int x;cin >> x;
        creat(&head1,x);
    }
    rmvdup(&head1);
    //admid(&head1,7);
    // int m;cin >> m;
    // node *head2 = NULL;
    // for (int i=0;i<m;i++){
    //     int x;cin >> x;
    //     creat(&head2,x);
    // }
    // smerg(&head1,&head2);
    //sortt(&head1);
    //int x,y;cin >> x>>y;
    //fin(&head,10);
    //lin(&head,20);
    //bin(&head,7,x);
    //ain(&head,8,y);
    //anydel(&head,1);
    //fdel(&head);
    //ldel(&head);
    display(&head1);
}
