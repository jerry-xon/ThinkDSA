#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_beg(struct node *head, int data){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
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
    
    struct node *current = NULL;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    int data = 3;

    head = add_beg(head,data);
    



    print_data(head);

  return 0;
}