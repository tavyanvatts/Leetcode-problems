/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* A = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(i != j)
            {
                if(nums[i] + nums[j] == target)
                {
                    A[0] = i;
                    A[1] = j;
                    return A;
                }
            }
        }
    }
    free(A);
    *returnSize = 0;
    return NULL;
}
