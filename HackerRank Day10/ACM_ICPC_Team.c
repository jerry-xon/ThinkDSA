#include <stdio.h>
#include <string.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char topics[n][m + 1];

    for (int i = 0; i < n; i++) {
        scanf("%s", topics[i]);
    }

    int maxTopics = 0, teamCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int topicCount = 0;
            for (int k = 0; k < m; k++) {
                if (topics[i][k] == '1' || topics[j][k] == '1') {
                    topicCount++;
                }
            }

            if (topicCount > maxTopics) {
                maxTopics = topicCount;
                teamCount = 1;
            } else if (topicCount == maxTopics) {
                teamCount++;
            }
        }
    }

    printf("%d\n%d\n", maxTopics, teamCount);

    return 0;
}
