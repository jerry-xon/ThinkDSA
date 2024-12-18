#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int *heights, int n)
{
    int maxArea = 0;
    int *stack = (int *)malloc(sizeof(int) * (n + 1));
    int top = -1;

    for (int i = 0; i <= n; i++)
    {

        int currentHeight = (i == n) ? 0 : heights[i];

        while (top != -1 && currentHeight < heights[stack[top]])
        {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = (maxArea > height * width) ? maxArea : height * width;
        }

        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main()
{
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }

    printf("%d\n", largestRectangleArea(heights, n));
    return 0;
}
