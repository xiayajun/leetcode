#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define test_xx(...) 0

int** threeSum(int* nums, int numsSize, int* returnSize, int* returnColumnSizes){
    int i, j, k;
    int index = 0;
    int **array;

    array = (int**)malloc(numsSize* sizeof(int*));
    for (i=0; i<numsSize; i++) {
      array[i] = (int*)malloc(3);
      for (j=i+1; j<numsSize; j++) {
          for (k=j+1; k<numsSize; k++) {
              if (nums[i]+nums[j]+nums[k] == 0) {
                array[index] = (int*)malloc(sizeof(int) * 3);
                array[index][0] = nums[i];
                array[index][1] = nums[j];
                array[index][2] = nums[k];
                index++;
              }
          }
      }
    }
    *returnSize = index * sizeof(int) * 3;
    *returnColumnSizes = index;
    return array;
}

int main() {
  int tarray[] = {-1, 0, 1, 2, -1, -4};
  int rsize, rcsize;
  int **array;

  array = threeSum(tarray, sizeof(tarray)/sizeof(int), &rsize, &rcsize);

  printf("rsize = %d, rcsize: %d\r\n",rsize, rcsize);

  return 0;
}

