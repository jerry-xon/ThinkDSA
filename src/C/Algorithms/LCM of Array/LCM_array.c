#include <stdio.h>


int gcd(int a, int b)
{

    int result = ((a < b) ? a : b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }

    return result;
}
// int gcd(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
int getLCM(int n, int arr[n]){
    int result = arr[0];
    for(int i = 1 ; i < n ; i++){
        result = lcm(result,arr[i]);
    }
    return result;
}
int main() {
    int n;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and display the LCM of the array
    int result = getLCM(n, arr);
    printf("LCM of the array: %d\n", result);

    return 0;
}