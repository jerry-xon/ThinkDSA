#include <stdio.h>
#define MAX_SIZE 10
int Queue[MAX_SIZE];
int front=0 ,raer = -1;

void Insert(){
    if(raer==MAX_SIZE-1){
        printf("\nQueue overflow.");
    }
    else{
            int n;
            printf("Enter the element to Insert: ");
            scanf("%d",&n);
            raer++;
            Queue[raer] = n;
            
        }
    
}

void delete1(){
    if(front>raer){
        printf("\nQueue is empty.\n");
    }else{
        printf("\nElement deleted is: %d",Queue[front]);
        front++;
        }
    
}

void Display(){
    if(front>raer){
        printf("\nQueue is empty.");
    }else{
        printf("\nQueue elements are:\n");
        for(int i=front;i>=raer;i++){
            printf("%d ",Queue[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n-------------Queue Operations--------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("-------------Enter you Choice-------------\n");
        scanf("%d",&choice);
        switch (choice)
    {
    case 1: Insert();
        break;
    case 2: delete1();
        break;
    case 3: Display();
        break;
    case 4: 
        break;
    
    default:printf("Invalid choice.");
        break;
    }
    } while (choice!=4);

    
    return 0;
}
