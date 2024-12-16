#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add_at_pos(struct node *head ,int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos != 0){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}
void add_at_end(struct node *head, int data){
    struct node *ptr ,*temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void print_data(struct node *head){
  if(head == NULL)
    printf("List is empty.\n");
  struct node *ptr = NULL;
  ptr = head;
  while(ptr != NULL){
    printf("%d\n",ptr->data);
    ptr = ptr->link;
}}

int main()
{   struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    
    add_at_end(head,50);
    add_at_end(head,30);
    add_at_end(head,69);

    int data = 34 , position = 4;
    add_at_pos(head, data, position);
    struct node *ptr = head;


    print_data(head);

  return 0;
}