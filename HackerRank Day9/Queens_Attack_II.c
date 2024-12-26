#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
} Obstacle;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, k, r_q, c_q;
    scanf("%d %d", &n, &k);
    scanf("%d %d", &r_q, &c_q);

    int north = n - r_q;
    int south = r_q - 1;
    int east = n - c_q;
    int west = c_q - 1;
    int north_east = min(n - r_q, n - c_q);
    int north_west = min(n - r_q, c_q - 1);
    int south_east = min(r_q - 1, n - c_q);
    int south_west = min(r_q - 1, c_q - 1);

    for (int i = 0; i < k; i++)
    {
        int r, c;
        scanf("%d %d", &r, &c);

        if (c == c_q)
        {
            if (r > r_q)
            {
                north = min(north, r - r_q - 1);
            }
            else
            {
                south = min(south, r_q - r - 1);
            }
        }
        else if (r == r_q)
        {
            if (c > c_q)
            {
                east = min(east, c - c_q - 1);
            }
            else
            {
                west = min(west, c_q - c - 1);
            }
        }
        else if (abs(r - r_q) == abs(c - c_q))
        {
            if (r > r_q && c > c_q)
            {
                north_east = min(north_east, r - r_q - 1);
            }
            else if (r > r_q && c < c_q)
            {
                north_west = min(north_west, r - r_q - 1);
            }
            else if (r < r_q && c > c_q)
            {
                south_east = min(south_east, r_q - r - 1);
            }
            else if (r < r_q && c < c_q)
            {
                south_west = min(south_west, r_q - r - 1);
            }
        }
    }

    int total_attacks = north + south + east + west +
                        north_east + north_west + south_east + south_west;

    printf("%d\n", total_attacks);
    return 0;
}
