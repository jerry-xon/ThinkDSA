#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str1[MAX], str2[MAX];
    int dp[MAX][MAX];
    int i, j;

    // Taking user input
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Initializing dp table
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Length of LCS
    printf("Length of LCS: %d\n", dp[len1][len2]);

    // Reconstructing the LCS
    char lcs[MAX];
    int index = dp[len1][len2];
    lcs[index] = '\0'; // Null-terminate the string

    i = len1;
    j = len2;

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);

    return 0;
}
