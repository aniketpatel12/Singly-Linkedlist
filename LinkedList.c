#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node * link;
};

struct node * head = NULL,*temp;
int ch,a;

struct node* createNode(int x){

    struct node * y;
    y=(struct node *)malloc(sizeof(struct node));
    y->data=x;
    y->link=NULL;
    return y;
};

void Insert(int x){

    if(head == NULL){
        temp = createNode(x);
        head = temp;
    }
    else{
        struct node * t = createNode(x);
        temp->link=t;
        temp=t;
    }
}

void display(){

    temp=head;
    if(temp == NULL){
        printf("List is Empty");
    }
    else{
        printf("\nList is: ");
        while(temp!=NULL)
        {
            printf("| %d |-",temp->data);
            temp=temp->link;
        }

    }
}

void main(){

    do{
        printf("\n1.Insert node\n2.Display List\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter data: ");
            scanf("%d",&a);
            Insert(a);
            break;
        case 2:
            display();
            break;
        }
    }while(ch<=3);

}

