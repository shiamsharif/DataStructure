#include <stdio.h>
#include <unistd.h>
#define max 4

int arr[max] = {0};

int front = 0;
int end = 0;

void enqueue(int data)
{
    if(end>=max)
    {
        return;
    }
    else
    {
        arr[end] = data;
        end++;
    }
}

void dequeue()
{
    if(front==end)
    {
        return;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;
    if(front == end)
    {
        return;
    }
    else
    {
        for(i=front; i<end; i++)
        {
            printf("%d ",arr[i]);
        }
    }
}

void banner() {
    printf("╭━━╮╱╱╱╱╱╭━━━╮\n");
    printf("╰┫┣╯╱╱╱╱╱┃╭━╮┃\n");
    printf("╱┃┃╭━━┳━━┫┃╱╰╋━┳━━┳━━┳╮╭╮\n");
    printf("╱┃┃┃╭━┫┃━┫┃╱╭┫╭┫┃━┫╭╮┃╰╯┃\n");
    printf("╭┫┣┫╰━┫┃━┫╰━╯┃┃┃┃━┫╭╮┃┃┃┃\n");
    printf("╰━━┻━━┻━━┻━━━┻╯╰━━┻╯╰┻┻┻╯\n");
}

void take_order(int total_order) {
    int flavour_choice;
    int flavour_quantity;
    int order_count = 0;
    int next_order = total_order;
    int ice_cream_one_count;
    int ice_cream_two_count;
    int ice_cream_three_count;
    int buffer[max] = {0};

    while(next_order > 0) {
        printf("Select flavor and quantity for each item. Your options are:\n");
        printf("1. Chocolate\n");
        printf("2. Vanila\n");
        printf("3. Butterschoch\n");
        ice_cream_one_count = 0;
        ice_cream_two_count = 0;
        ice_cream_three_count = 0;
        while(order_count < 4 && order_count < next_order) {  
            printf("=========================\n");
            printf("Next Order: %d\n", next_order);
            printf("Order Count: %d\n", order_count);
            printf("=========================\n");
            printf("Choose flavour: ");
            scanf("%d", &flavour_choice);
            printf("Enter quantity: ");
            scanf("%d", &flavour_quantity);
            if(flavour_quantity > 3 || flavour_quantity < 1) {
                printf("Wrong Quantity\n");
                continue;
            }
            switch (flavour_choice)
            {
            case 1:
                ice_cream_one_count += flavour_quantity;
                break;
            case 2:
                ice_cream_two_count += flavour_quantity;
                break;
            case 3:
                ice_cream_three_count += flavour_quantity;
                break;
            default:
                break;
            }
            for(int i = 0; i < flavour_quantity; i++) {
                buffer[order_count] = flavour_choice;
                order_count++;
            }
            if(order_count > 4 || order_count > next_order) {
                printf("Wrong Quantity\n");
                order_count = 0;
                continue;
            }
        }

        printf("Thanks! wait before enter other order info\n\n");
        printf("Order description:\n");
        if(ice_cream_one_count > 0)
            printf("%d Chocolate flavored Ice Cream\n", ice_cream_one_count);
        if(ice_cream_two_count > 0)
            printf("%d Butter Schoch flavored Ice Cream\n", ice_cream_two_count);
        if(ice_cream_three_count > 0)
            printf("%d Vanilla flavored Ice Cream\n", ice_cream_three_count);
        printf("Serving...\n\n");
      
        for(int i = 0; i < order_count; i++) {
            enqueue(buffer[i]);
        }

        printf("Queue status: ");   
        display();
        printf("\n\n");
        
        next_order = next_order - 4;
        
        while(order_count != 0) {
            dequeue();
            order_count--;
        }

        if(ice_cream_one_count > 0)
            printf("%d Chocolate flavored Ice Cream served\n", ice_cream_one_count);
        if(ice_cream_two_count > 0)
            printf("%d Butter Schoch flavored Ice Cream served\n", ice_cream_two_count);
        if(ice_cream_three_count > 0)
            printf("%d Vanilla flavored Ice Cream served\n", ice_cream_three_count);
        
        printf("\n\n");

        if(next_order <= 0) {
            printf("Order is served\n");
        } else {
            printf("Enter %d more flavour now\n", next_order > 4 ? 4 : next_order);
        }
    }
   

    
}

int main() {
    int total_ice_cream_count;
    int ice_cream_one_count;
    int ice_cream_two_count;
    int ice_cream_three_count;
    int current_ice_cream_count = 0;
    int queue_count = 0;

    int flavour_choice;
    int flavour_quantity;

    banner();

    printf("Enter total Ice Cream count: ");
    scanf("%d", &total_ice_cream_count);

    take_order(total_ice_cream_count);

    return 0;
}
