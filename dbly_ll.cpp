#include<bits/stdc++.h>
using namespace std;


class node
{
public:
    int info;
    node *prev;
    node *next;
    node(int val)
    {
        info = val;
        prev = NULL;
        next = NULL;
    }
};

void creat(node **head,int item)
{
    node *ptr = new node(item);
    if (*head == NULL){
        *head = ptr;
    }
    else{
        node *temp = *head;
        while (temp->next!= NULL)temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void reverse(node **head)
{
    node *temp = *head;
    node *ptr = NULL;
    while (temp!=NULL){
        ptr = temp->prev;
        temp->prev = temp->next;
        temp->next = ptr;
        temp=temp->prev;
    }
    *head = ptr->prev;
}

void display (node **head)
{
    node *temp = *head;
    while (temp!=NULL){
        cout <<temp->info <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int isPal(node **head)
{
    node *temp1 = *head , *temp2 = *head;
    while (temp2->next!=NULL) temp2 = temp2->next;
    while (temp1!=NULL){
        if (temp1->info != temp2->info){
            return 0;
        }
        temp1= temp1->next;
        temp2= temp2->prev;
    }
    return 1;
}

void dataIn(node **head, int data, int item)
{
    node *ptr = new node(item);
    node *temp = *head;
    while (temp!=NULL){
        if (temp->info == data){
            ptr->prev = temp;
            ptr->next = temp->next;
            temp->next = ptr;
            ptr->next->prev = ptr;
            return;
        }
        temp = temp->next;
    }
}

void insortt(node **head)
{
    node *ptr;
    node *temp = *head;
    for (ptr = temp->next; ptr!=NULL; ptr = ptr->next){
        int key = ptr->info;
        node *pre = ptr->prev;
        while (pre != NULL && pre->info > key){
            swap(pre->info,pre->next->info);
            pre = pre->prev;
        }
    }
}

int main()
{
    int n;cin>> n;
    node *head = NULL;
    for (int i=0;i<n;i++){
        int x;cin >> x;
        creat(&head,x);
    }
    reverse(&head);
    display(&head);
}
