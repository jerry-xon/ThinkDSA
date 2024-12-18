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


struct QueueNode {
    struct node* treeNode;
    int hd;
};


void topView(struct node* root) {
    if (root == NULL) return;


    int topViewMap[2001];
    int visited[2001] = {0};


    struct QueueNode queue[2001];
    int front = 0, rear = 0;


    queue[rear].treeNode = root;
    queue[rear].hd = 1000;
    rear++;

    while (front < rear) {
        struct node* current = queue[front].treeNode;
        int hd = queue[front].hd;
        front++;


        if (!visited[hd]) {
            visited[hd] = 1;
            topViewMap[hd] = current->data;
        }
        
        if (current->left) {
            queue[rear].treeNode = current->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

     
        if (current->right) {
            queue[rear].treeNode = current->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

  
    for (int i = 0; i < 2001; i++) {
        if (visited[i]) {
            printf("%d ", topViewMap[i]);
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
  
	topView(root);
    return 0;
}
