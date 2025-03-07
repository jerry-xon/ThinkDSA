#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x, y;
} Point;

// Function to find the orientation of three points
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to find the upper and lower tangents and merge two convex hulls
void mergeHulls(Point hull1[], int size1, Point hull2[], int size2, Point result[], int *size)
{
    int left = 0, right = 0;
    for (int i = 1; i < size1; i++)
    {
        if (hull1[i].x > hull1[left].x)
            left = i;
    }
    for (int i = 1; i < size2; i++)
    {
        if (hull2[i].x < hull2[right].x)
            right = i;
    }
    int upperLeft = left, upperRight = right;
    while (orientation(hull2[upperRight], hull1[upperLeft], hull1[(upperLeft + 1) % size1]) == 2 ||
           orientation(hull1[upperLeft], hull2[upperRight], hull2[(upperRight - 1 + size2) % size2]) == 1)
    {
        while (orientation(hull2[upperRight], hull1[upperLeft], hull1[(upperLeft + 1) % size1]) == 2)
            upperLeft = (upperLeft + 1) % size1;
        while (orientation(hull1[upperLeft], hull2[upperRight], hull2[(upperRight - 1 + size2) % size2]) == 1)
            upperRight = (upperRight - 1 + size2) % size2;
    }
    int lowerLeft = left, lowerRight = right;
    while (orientation(hull2[lowerRight], hull1[lowerLeft], hull1[(lowerLeft - 1 + size1) % size1]) == 1 ||
           orientation(hull1[lowerLeft], hull2[lowerRight], hull2[(lowerRight + 1) % size2]) == 2)
    {
        while (orientation(hull2[lowerRight], hull1[lowerLeft], hull1[(lowerLeft - 1 + size1) % size1]) == 1)
            lowerLeft = (lowerLeft - 1 + size1) % size1;
        while (orientation(hull1[lowerLeft], hull2[lowerRight], hull2[(lowerRight + 1) % size2]) == 2)
            lowerRight = (lowerRight + 1) % size2;
    }
    int index = 0;
    for (int i = upperLeft; i != lowerLeft; i = (i + 1) % size1)
        result[index++] = hull1[i];
    result[index++] = hull1[lowerLeft];
    for (int i = lowerRight; i != upperRight; i = (i + 1) % size2)
        result[index++] = hull2[i];
    result[index++] = hull2[upperRight];
    *size = index;
}

// Recursive function to find the convex hull using Divide and Conquer
void convexHullDC(Point points[], int n, Point result[], int *size)
{
    if (n <= 3)
    {
        for (int i = 0; i < n; i++)
            result[i] = points[i];
        *size = n;
        return;
    }
    int mid = n / 2;
    Point leftHull[mid], rightHull[n - mid];
    int leftSize, rightSize;
    convexHullDC(points, mid, leftHull, &leftSize);
    convexHullDC(points + mid, n - mid, rightHull, &rightSize);
    mergeHulls(leftHull, leftSize, rightHull, rightSize, result, size);
}

int main()
{
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    Point points[n];
    printf("Enter %d points (x y):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    Point result[n];
    int size;
    convexHullDC(points, n, result, &size);
    printf("Convex Hull:");
    for (int i = 0; i < size; i++)
        printf(" (%d, %d)", result[i].x, result[i].y);
    printf("\n");
    return 0;
}