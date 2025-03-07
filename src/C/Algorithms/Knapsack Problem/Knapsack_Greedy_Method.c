#include <stdio.h>

// Structure to store items
struct Item {
    int weight;
    int value;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value-to-weight ratio (Descending Order)
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)arr[j].value / arr[j].weight;
            double ratio2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to calculate maximum value using the greedy method
double knapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n); // Sort items based on value/weight ratio

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

// Main function
int main() {
    int n, capacity;
    
    // Get user input for number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    // Get user input for items
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    // Get user input for knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    // Calculate maximum profit
    double maxProfit = knapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxProfit);
    
    return 0;
}
