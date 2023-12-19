#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxProductDifference(int* nums, int numsSize) {
	// Sorting the array using qsort
    qsort(nums, numsSize, sizeof(int), compare);
	return nums[numsSize - 1] * nums[numsSize - 2] - nums[0] * nums[1];
}

int maxProductDifference2(int* nums, int numsSize) {
	int max1 = 0, max2 = 0;
	int min1 = INT_MAX, min2 = INT_MAX;
	
	for (int i = 0; i < numsSize; i++) {
		int cur = nums[i];
		if (cur > max1) {
			max2 = max1;
			max1 = cur;
		} else if (cur > max2) {
			max2 = cur;
		}
		if (cur < min1) {
			min2 = min1;
			min1 = cur;
		} else if (cur < min2) {
			min2 = cur;
		}
	}

	return max1 * max2 - min1 * min2;
}

int main() {
    // Test Case 1
    int nums1[] = {5, 6, 2, 7, 4};
    int expected1 = 34;
    int result1_1 = maxProductDifference(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int result1_2 = maxProductDifference(nums1, sizeof(nums1) / sizeof(nums1[0]));
    
    printf("Test Case 1 Result: %s\n", (result1_1 == expected1) ? "true" : "false");
    printf("Test Case 1 Result: %s\n", (result1_2 == expected1) ? "true" : "false");

    // Test Case 2
    int nums2[] = {4, 2, 5, 9, 7, 4, 8};
    int expected2 = 64;
    int result2_1 = maxProductDifference(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int result2_2 = maxProductDifference(nums2, sizeof(nums2) / sizeof(nums2[0]));
    
    printf("Test Case 2 Result: %s\n", (result2_1 == expected2) ? "true" : "false");
    printf("Test Case 2 Result: %s\n", (result2_2 == expected2) ? "true" : "false");

    return 0;
}