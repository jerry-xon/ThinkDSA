#include <stdio.h>

int equalStacks(int h1, int h2, int h3, int stackH1[], int stackH2[], int stackH3[]) {
  
    int sum1 = 0, sum2 = 0, sum3 = 0;


    for (int i = 0; i < h1; i++) sum1 += stackH1[i];
    for (int i = 0; i < h2; i++) sum2 += stackH2[i];
    for (int i = 0; i < h3; i++) sum3 += stackH3[i];


    int i = 0, j = 0, k = 0;

    while (!(sum1 == sum2 && sum2 == sum3)) {
       
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stackH1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stackH2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= stackH3[k++];
        }

        if (i == h1 || j == h2 || k == h3) return 0;
    }

    return sum1;
}

int main() {
    int h1, h2, h3;

   
    scanf("%d %d %d", &h1, &h2, &h3);

    int stackH1[h1], stackH2[h2], stackH3[h3];


    for (int i = 0; i < h1; i++) scanf("%d", &stackH1[i]);
    for (int i = 0; i < h2; i++) scanf("%d", &stackH2[i]);
    for (int i = 0; i < h3; i++) scanf("%d", &stackH3[i]);

   
    int height = equalStacks(h1, h2, h3, stackH1, stackH2, stackH3);
    printf("%d\n", height);

    return 0;
}
