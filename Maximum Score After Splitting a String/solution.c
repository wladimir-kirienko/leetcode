#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxScore(char* s) {
    int ans = 0;

    for (int i = 0; i < strlen(s) - 1; i++) {
        int sum = 0;
        for (int j = 0; j < strlen(s); j++) {
            char n = (j <= i) ? '0' : '1';
            if (s[j] == n) {
                sum++;
            }
        }
        ans = MAX(ans, sum);
    }

    return ans;
}

int maxScore2(char* s) {
    int ans = 0, ones = 0, zeros = 0;
    
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == '1')
            ones++;
    
    for (int i = 0; i < strlen(s) - 1; i++){

        if (s[i] == '1') {
            ones--;
        } else {
            zeros++;
        }

        ans = MAX(ans, zeros + ones);
    }
    
    return ans;
}

int maxScore3(char* s) {
    int best = INT_MIN, ones = 0, zeros = 0;
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zeros++;
        }
        
        best = MAX(best, zeros - ones); 
    }
    
    if (s[len - 1] == '1') {
        ones++;
    }

    return best + ones;
}

void runTests() {
    // Example 1
    char s1[] = "011101";
    int result1 = maxScore(s1);
    int expected1 = 5;
    assert(result1 == expected1);

    // Example 2
    char s2[] = "00111";
    int result2 = maxScore2(s2);
    int expected2 = 5;
    assert(result2 == expected2);

    // Example 3
    char s3[] = "1111";
    int result3 = maxScore3(s3);
    int expected3 = 3;
    assert(result3 == expected3);

    printf("All tests passed successfully!\n");
}

int main() {
    runTests();

    return 0;
}