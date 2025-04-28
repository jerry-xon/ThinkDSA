#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 9


int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void shuffle(int *arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = getRandom(0, i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void printTicket(int ticket[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (ticket[i][j] == 0)
                printf("   \t");
            else
                printf("%2d\t", ticket[i][j]);
        }
        printf("\n");
    }
}


int main() {
    srand(time(NULL));
    // srand(time(0));
    int ticket[ROWS][COLS] = {0};
    int colRanges[COLS][2] = {
        {1, 9}, {10, 19}, {20, 29}, {30, 39}, {40, 49},
        {50, 59}, {60, 69}, {70, 79}, {80, 90}
    };


    int columnNumbers[COLS][3] = {0};
    int colCount[COLS] = {0};

    
    for (int c = 0; c < COLS; c++) {
        int count = getRandom(1, 3);
        colCount[c] = count;

        int nums[10];
        int n = 0;
        for (int i = colRanges[c][0]; i <= colRanges[c][1]; i++)
            nums[n++] = i;

        shuffle(nums, n);
        for (int i = 0; i < count; i++)
            columnNumbers[c][i] = nums[i];
    }

    
    int rowCounts[ROWS] = {0};

    for (int c = 0; c < COLS; c++) {
        int count = colCount[c];
        int rows[3] = {0, 1, 2};
        shuffle(rows, 3);

        for (int i = 0; i < count; i++) {
            for (int r = 0; r < ROWS; r++) {
                if (rowCounts[rows[r]] < 5 && ticket[rows[r]][c] == 0) {
                    ticket[rows[r]][c] = columnNumbers[c][i];
                    rowCounts[rows[r]]++;
                    break;
                }
            }
        }
    }


    for (int c = 0; c < COLS; c++) {
        int values[ROWS] = {0};
        int idx = 0;

        for (int r = 0; r < ROWS; r++) {
            if (ticket[r][c] != 0)
                values[idx++] = ticket[r][c];
        }

  
        for (int i = 0; i < idx - 1; i++) {
            for (int j = 0; j < idx - i - 1; j++) {
                if (values[j] > values[j + 1]) {
                    int temp = values[j];
                    values[j] = values[j + 1];
                    values[j + 1] = temp;
                }
            }
        }

        idx = 0;
        for (int r = 0; r < ROWS; r++) {
            if (ticket[r][c] != 0)
                ticket[r][c] = values[idx++];
        }
    }

    
    printf("\nGenerated Tambola Ticket:\n\n");
    printTicket(ticket);

    return 0;
}
