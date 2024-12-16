#include <stdio.h>

void climbingLeaderboard(int leaderboard[], int n, int player[], int m)
{
    int ranks[n];
    int rank = 1;

    ranks[0] = rank;
    for (int i = 1; i < n; i++)
    {
        if (leaderboard[i] != leaderboard[i - 1])
        {
            rank++;
        }
        ranks[i] = rank;
    }

    int i = n - 1;
    for (int j = 0; j < m; j++)
    {
        while (i >= 0 && player[j] >= leaderboard[i])
        {
            i--;
        }
        if (i < 0)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", ranks[i] + 1);
        }
    }
}

int main()
{
    int n, m;

    // printf("Enter the number of leaderboard scores: ");
    scanf("%d", &n);
    int leaderboard[n];
    // printf("Enter the leaderboard scores: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &leaderboard[i]);
    }

    // printf("Enter the number of player scores: ");
    scanf("%d", &m);
    int player[m];
    // printf("Enter the player scores: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &player[i]);
    }

    climbingLeaderboard(leaderboard, n, player, m);

    return 0;
}
