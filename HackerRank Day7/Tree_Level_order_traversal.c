#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

void levelOrder(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left) {
            queue[rear++] = current->left;
        }

        if (current->right) {
            queue[rear++] = current->right;
        }
    }
}



int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	levelOrder(root);
    return 0;
}
