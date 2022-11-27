#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack * below;
};
int ctr = 0;
int node;// total nodes//3

typedef struct stack item;
item* base=NULL;// similar to start-node
item* top = NULL;// top node

item* getNode(){
    item* newNode=(item*)malloc(sizeof(item));
    printf("Enter data: ");
    scanf("%d",&newNode->data);
    newNode->below=NULL;
    return newNode;
}
void display(){
    item *temp = top;
    if (top == NULL){
        printf("\nEmpty List");
        return;
    }
    printf("\nStack items: \n");
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->below;
    }
}

void printReverse(item * node){
    if(node == NULL){
        return;
    }else{
        printReverse(node->below);
        printf("%d\n", node->data);
    }
}

void push(){
    if(ctr==node){
        printf("Stack overflow.\n");
        return;
    }
    item *newnode;
    newnode = getNode();
    if (base == NULL)
        base = newnode;
    else
        newnode->below = top;
    top = newnode;
    ctr++;
}

void pop(){
    item *temp;
    if (top == NULL) {
        printf("\nStack UnderFlow..\n");
        return;
    }
    else {
        printf("\nDeleted item: %d\n",top->data);
        temp = top;//15
        top = temp->below;//10
        free(temp);
        ctr--;
    }
}

void menu(){
    printf("\n0. Exit.\n");
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Display.\n");
    printf("4. Display Reverse.\n");
}

int main(){
    printf("How many items do you want to store?\n");
    scanf("%d",&node);
    int choice =1;
    while (choice)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            push();
        else if (choice==2)
            pop();
        else if(choice ==3)
            display();
        else if(choice ==4)
            printReverse(top);
        else if(choice!=0)
            printf("Enter a valid choice: ");    
    }    
    return 0;
    // printf("%d", top->data);
}

/*

ctr = 3
________
2-> 15  <- temp
1-> 10  <-top
0-> 5  <- base  
    
*/
