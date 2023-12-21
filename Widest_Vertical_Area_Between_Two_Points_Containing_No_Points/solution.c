#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Custom comparison function for qsort
int compare(const void* a, const void* b) {
    int x1 = (*(int**)a)[0];
    int y1 = (*(int**)a)[1];
    int x2 = (*(int**)b)[0];
    int y2 = (*(int**)b)[1];

    if (x1 != x2) {
        return x1 - x2;
    } else {
        return y1 - y2;
    }
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    qsort(points, pointsSize, sizeof(points[0]), compare);
    for (int i = 1; i < pointsSize; i++) {
        ans = MAX(ans, points[i][0] - points[i - 1][0]);
    }
    return ans;
}

int main() {
    // Test Case 1
    int arr1[][2] = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    int pointsSize1 = sizeof(arr1) / sizeof(arr1[0]);
    int pointsColSize1 = sizeof(arr1[0]) / sizeof(arr1[0][0]);
    int** points1 = (int**)malloc(pointsSize1 * sizeof(int*));
    for (int i = 0; i < pointsSize1; i++) {
        points1[i] = arr1[i];
    }

    int result1 = maxWidthOfVerticalArea(points1, pointsSize1, &pointsColSize1);
    assert(result1 == 1);
    free(points1);

    // Test Case 2
    int arr2[][2] = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    int pointsSize2 = sizeof(arr2) / sizeof(arr2[0]);
    int pointsColSize2 = sizeof(arr2[0]) / sizeof(arr2[0][0]);
    int** points2 = (int**)malloc(pointsSize2 * sizeof(int*));
    for (int i = 0; i < pointsSize2; i++) {
        points2[i] = arr2[i];
    }

    int result2 = maxWidthOfVerticalArea(points2, pointsSize2, &pointsColSize2);
    assert(result2 == 3);
    free(points2);

    printf("All tests passed successfully!\n");

    return 0;
}