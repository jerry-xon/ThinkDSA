#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Huffman Tree node
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to sort nodes by frequency (Bubble Sort for simplicity)
void sortNodes(struct Node* nodes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                struct Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

// Function to build a Huffman Tree using a greedy approach
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* nodes[size];

    // Create initial nodes
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    // Construct Huffman Tree
    while (size > 1) {
        sortNodes(nodes, size); // Sort nodes based on frequency

        // Pick two smallest nodes
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        // Create a new node merging them
        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Shift nodes and insert new node 
        nodes[0] = newNode;
        for (int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        size--;
    }

    return nodes[0]; // Return the root of the Huffman Tree
}

// Function to print Huffman codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to calculate frequencies of characters in a string
void calculateFrequencies(char *str, char *arr, int *freq, int *size) {
    int count[256] = {0}; // Array to store frequency of characters
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    *size = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            arr[*size] = (char)i;
            freq[*size] = count[i];
            (*size)++;
        }
    }
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character if present

    char arr[256];
    int freq[256], size;
    calculateFrequencies(str, arr, freq, &size);

    struct Node* root = buildHuffmanTree(arr, freq, size);
    int huffmanCode[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, huffmanCode, top);

    return 0;
}
