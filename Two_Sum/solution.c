#include <stdio.h>

// Function to find indices of two numbers in the array that add up to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Result array to store the indices
    int* result = malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                // Found the indices, store them in the result array
                result[0] = i;
                result[1] = j;
                
                // Set the returnSize pointer to 2
                *returnSize = 2;
                
                return result;
            }
        }
    }
    
    // If no solution is found, return an empty array and set returnSize to 0
    *returnSize = 0;
    return result;
}


// Definition of a hash table node
struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

// Function to create a new hash table node
struct HashNode* createHashNode(int key, int value) {
    struct HashNode* node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to free the memory allocated for the hash table
void freeHashTable(struct HashNode** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        struct HashNode* current = hashTable[i];
        while (current != NULL) {
            struct HashNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(hashTable);
}

// Function to find indices of two numbers in the array that add up to the target
int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
    // Size of the hash table (can be adjusted based on the problem constraints)
    int hashTableSize = 1000;

    // Create a hash table
    struct HashNode** hashTable = (struct HashNode**)malloc(hashTableSize * sizeof(struct HashNode*));

    // Initialize the hash table
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = NULL;
    }

    // Result array to store the indices
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        // Calculate the complement for the current element
        int complement = target - nums[i];

        // Calculate the hash value for the complement
        int hash = (complement % hashTableSize + hashTableSize) % hashTableSize;

        // Check if the complement is in the hash table
        struct HashNode* current = hashTable[hash];
        while (current != NULL) {
            if (current->key == complement) {
                // Found the complement, store the indices in the result array
                result[0] = current->value;
                result[1] = i;

                // Set the returnSize pointer to 2
                *returnSize = 2;

                // Free the memory allocated for the hash table
                freeHashTable(hashTable, hashTableSize);

                return result;
            }
            current = current->next;
        }

        // If the complement is not in the hash table, add the current element to the hash table
        int hashIndex = (nums[i] % hashTableSize + hashTableSize) % hashTableSize;
        struct HashNode* newNode = createHashNode(nums[i], i);
        newNode->next = hashTable[hashIndex];
        hashTable[hashIndex] = newNode;
    }

    // If no solution is found, return an empty array and set returnSize to 0
    *returnSize = 0;

    // Free the memory allocated for the hash table
    freeHashTable(hashTable, hashTableSize);

    return result;
}

int main() {
    // Test Case 1
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, sizeof(nums1) / sizeof(nums1[0]), target1, &returnSize1);
    
    printf("Two Sum Test Case 1 Result: %d %d\n", result1[0], result1[1]);
    
    // Test Case 2
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, sizeof(nums2) / sizeof(nums2[0]), target2, &returnSize2);
    
    printf("Two Sum Test Case 2 Result: %d %d\n", result2[0], result2[1]);

    // Test Case 3
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* result3 = twoSum(nums3, sizeof(nums3) / sizeof(nums3[0]), target3, &returnSize3);
    
    printf("Two Sum Test Case 3 Result: %d %d\n", result3[0], result3[1]);

    // Free allocated memory
    free(result1);
    free(result2);
    free(result3);

    return 0;
}