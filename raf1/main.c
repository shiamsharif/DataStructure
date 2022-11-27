
#include <stdio.h>
int max;
int ctr=0;
int frt=0;
void enque(int arr[]){
    if(ctr==max){
        printf("Queue full\n");
        return;
    }
    printf("enter data:");
    scanf("%d",&arr[ctr++]);
}

void dequeue(int arr[]){
    if(frt==ctr){
        printf("Queue Empty");
        return;
    }
    printf("Removed element: %d\n",arr[frt]);
    ctr--;

    // comming 1 step forward
    // 5 8 7 9, frt=0, ctr= 4 ( koyta element)
    // 0 1 2 3 4 

    // 5 8 7 9  , frt=0, ctr =4
    // _ 8 7 9  , frt=0, ctr=3
    // 8 8 7 9 

    // 8 7 9 5  , frt=0, ctr= 4
    // 0 1 2 3 4 

    for(int i=0; i<ctr ; i++){
        arr[i] = arr[i+1];
    }
}

void display(int arr[]){
    printf("Elements: ");
    for(int i=frt ; i<ctr ; i++)
        printf("%d ",arr[i]);
    
}

void menu(){
    printf("\n0. Exit\n");
    printf("1. Enque\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
}

int main(){
    printf("Enter the maximum size of the queue: ");
    scanf("%d",&max);
    int queue[max];

    int choice;
    do{
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            enque(queue);
        else if(choice==2)
            dequeue(queue);
        else if(choice==3)
            display(queue);
        else if(choice!=0)
            printf("Enter a valid choice\n");
        }while(choice!=0);
    return 0;
}