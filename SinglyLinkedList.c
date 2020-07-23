#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{

int data;
struct node * link;
};

struct node *head,*temp;
int ch,a,b;
int cnt=0;

struct node * createNode(int x){

    struct node* y;
    y=(struct node *)malloc(sizeof(struct node));
    y->link=NULL;
    y->data=x;
    return y;
};


void Insert(int x){

    if(head == NULL){
        temp = createNode(x);
        head = temp;
        printf("\nNode inserted.\n");
    }
    else{
        struct node * t = createNode(x);
        temp->link=t;
        temp=t;
        printf("\nNode inserted.\n");
    }
}


void InsertAtFront(int a){

    temp = createNode(a);
    if(temp == NULL){
        printf("\nOverflow");
    }
    else{
        temp->link=head;
        head=temp;
        printf("\nNode Inserted at Front\n");
    }

}

void InsertAtLast(int a){

    struct node *new = createNode(a);
    if(new == NULL){
        printf("\nOverflow");
    }
    else{
        if(head==NULL){
            head=new;
            printf("\nNode Inserted at Last\n");
        }else{
        temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=new;
        printf("\nNode Inserted at Last\n");
        }
    }

}

void insertAtSpecific(int d,int loc){
    int i;
    struct node * new = createNode(d);
    //new=head;
    if(head==NULL){
        printf("\nOverflow");
    }
    else{
        temp=head;
        for(i=0;i<loc;i++){
            temp=temp->link;
            if(temp==NULL){
                printf("\n Can't Insert data !!!");
                return;
            }
        }
        new->link=temp->link;
        temp->link=new;
        printf("\n Node Inserted");
    }
}

void deleteAtfront(){

    temp=head;
    if(temp==NULL){
        printf("\nList is empty");
    }
    else{
        head=temp->link;
        free(temp);
        printf("\n Node deleted from Front\n");
    }
}


void deleteAtLast(){

    temp=head;
    struct node *t1;
    if(temp==NULL){
        printf("\nList is empty");
    }
    else if(head->link == NULL){
        head=NULL;
        free(head);
        printf("\n Only node which is present is deleted.");
    }
    else{
        while(temp->link!=NULL){
            t1=temp;
            temp=temp->link;
        }
       // printf("\n",t1->data);
        t1->link=NULL;
        free(temp);
        printf("\n Node deleted from last\n");
    }
}

void deleteatspecific(a){

    struct node * t1;
    temp=head;
    while(temp->data!=a){
        t1=temp;
        temp=temp->link;
    }
    t1->link=temp->link;
    free(temp);
    printf("\nSpecified node is deleted.\n");

}

void display(){

    temp=head;
    if(temp==NULL){
        printf("\n List is empty");
        exit(0);
    }
    else{
        printf("\nList is: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}

void reverseList(){

    temp=head;
    struct node * next=NULL;
    struct node * pre=NULL;
    while(temp!=NULL){
            next=temp->link;;
            temp->link=pre;
            pre=temp;
            temp=next;
    }
    head=pre;
    //printf("\nReversed !!!\n");
    display();
    printf("\n");
}

int countnode(){

    temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->link;
    }
     return cnt;
}

void main(){

    do{
        printf("\n1.Insert Data\n2.insert at front\n3.Insert at last\n4.Insert at specific position\n5.Delete from front\n6.Delete from last\n7.Delete specified node\n8.Display()\n9.Reverse the list\n10.Count Node\nSelect your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&a);
            Insert(a);
            break;
        case 2:
            printf("\nEnter data:");
            scanf("%d",&a);
            InsertAtFront(a);
            break;
        case 3:
            printf("\nEnter data:");
            scanf("%d",&a);
            InsertAtLast(a);
            break;
        case 4:
            printf("\n Where you want to insert data(index): ");
            scanf("%d",&b);
            printf("\nEnter data:");
            scanf("%d",&a);
            insertAtSpecific(a,b);
            break;
        case 5:
            deleteAtfront();
            break;
        case 6:
            deleteAtLast();
            break;
        case 7:
            printf("\nEnter the node that you want to delete: ");
            scanf("%d",&a);
            deleteatspecific(a);
            break;
        case 8:
            display();
            printf("\n");
            break;
        case 9:
            reverseList();
            break;
        case 10:
            a=countnode();
             printf("\nTotal no. of nodes: %d \n",a);
            break;
        default:
            printf("\n Invalid input");
            printf("\n");
            exit(0);

        }
    }while(ch<=10);

}
