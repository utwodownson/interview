/* Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers = { 2, 7, 11, 15 }, target = 9
 * Output: index1 = 1, index2 = 2
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void two_sum(int *numbers, int target, int n)
{
    int index1, index2;
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum < target)
            i++;
        else if (target < sum)
            j--;
        else {
            index1 = i + 1;
            index2 = j + 1;
            break;
        }
    }
    printf("index1 = %d, index2 = %d\n", index1, index2);
}

int main()
{
    int numbers[] = { 2, 7, 11 ,15 }, n = 4, target = 9;
    int test1[] = { 3, 4, 9, 10, 11, 24 }, n1 = 6, target1 = 15;
    int test2[] = { 3, 4, 9, 10, 11, 24 }, n2 = 6, target2 = 21;
    two_sum(numbers, target, n);
    two_sum(test1, target1, n1);
    two_sum(test2, target2, n2);
}
