#include <stdio.h>
#define MAX 4
int Q[MAX];
int front, rear;
int P, O, R;
int t,T;
int DP,DO,DR,ctr;
int menu();
void insertQ(int);
void deleteQ();
void displayQ();
void takeOrder();
void order();
int Valid_invalid();
int main()
{
  // int t;
  printf("Enter quantity of ice cream : ");
  scanf("%d", &t);
  T=t;
  while(t>0){
  printf("Enter  %d more Item\n",t);
  takeOrder();
  if (Valid_invalid())
  {
    order();
    t=t-(DP+DO+DR);
    // DP=DO=DR=0;
  
  
  }
  else
  {
    printf("\nWrong Order!!\n");
  }
  int f = 4;
  while (f--)
  {
    deleteQ();
  }
  }
  printf("Order is Complete");
}

int menu()
{
  int ch;
  // printf("\nEnter %d more item  \t\n",t);
  printf("\n -----------**********-------------\n");
  printf("\n  Select Flavour And Quantity for each item . Your Option are :  ");
  printf("\n 1. Chocolate ");
  printf("\n 2. Vanilla  ");
  printf("\n 3. Butterscotch");
  printf("\n 4. Don't Want to Order More?\n press 4 to Confirm");
  printf("\n Enter your choice: ");
  scanf("%d", &ch);
  return ch;
}

void insertQ(int data)
{
  if (rear == MAX)
  {
     printf("Queue is Full\n");
    return;
  }
  else
 {
    // printf("Enter Data : ");
    // scanf("%d", &data);
    Q[rear++] = data;
    // printf("\n%d is added is queue \n", data);
  }
}

void deleteQ()
{
  if (rear == front)
  {
     printf("\nQueue is Empty\n");
    return;
  }
  else
  {

    for (int i = front; i < (rear - 1); i++)
    {
      Q[i] = Q[i + 1];
    }
    rear--;
  }
}

void displayQ()
{
  if (rear == front)
  {
    printf("\nQueue is Empty\n");
    return;
  }
  printf("\nQueue is Status : ");
  for (int i = front; i < rear; i++)
  {
    printf("%d \t", Q[i]);
  }
  printf("\n");
}

void order()
{
  printf("\nThanks wait before enter other order info\n");
  printf("Order Description : \n");
  if (DP > 0)
  {
    printf("%d Chocolate Flavored Ice cream\n", DP);
  }
  if (DO > 0)
  {
    printf("%d Vanilla Flavored Ice cream\n", DO);
  }
  if (DR > 0)
  {
    printf("%d Butterscotch Flavored Ice cream\n", DR);
  }

  printf("Serving......\n ");
  displayQ();
  if (DP > 0)
  {
    printf("%d Chocolate Flavored Ice cream served\n", DP);
  }
  if (DO > 0)
  {
    printf("%d Vanilla Flavored Ice cream served\n", DO);
  }
  if (DR > 0)
  {
    printf("%d Butterscotch Flavored Ice cream served\n", DR);
  }
}

void takeOrder()
{
  int ch;
    ctr=0;
  int checker = 4;
  if(checker==4)
  {
    DP = DO = DR = 0;
  }
  
  
  P=O=R=0;
  while (checker != 0)
  {
    
    ch = menu();
    switch (ch)
    {
    case 1:
      printf("Enter Quantity : ");
      scanf("%d", &P);
      checker -= P;
      //  DP=P;
      while (P--)
      {
        insertQ(1);
        DP++;
      }

      break;

    case 2:
      printf("Enter Quantity : ");
      scanf("%d", &O);
      checker -= O;
      //  DO = O;
      while (O--)
      {
        insertQ(2);
        DO++;
      }
      break;
    case 3:
      printf("Enter Quantity : ");
      scanf("%d", &R);
      checker -= R;
      //  DR = R;
      while (R--)
      {
        insertQ(3);
        DR++;
      }
      break;
    case 4:

      break;
    }
   
    
  }
  

}

int Valid_invalid()
{
    int Tck;
    int s = DP + DO + DR;
  
  
    if (s<=4 && s<=t)
    {
    Tck=1;
    }
    else
    {
    Tck=0;
    }
    return Tck;

}
