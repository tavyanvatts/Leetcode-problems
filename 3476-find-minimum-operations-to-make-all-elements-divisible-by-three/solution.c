int minimumOperations(int* nums, int numsSize) 
{
    int counter = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i]%3 == 0)
        {
            continue;
        }
        else if(nums[i]%3 != 0)
        {
            if((nums[i] + 1)%3 == 0)
            {
                nums[i] = nums[i] + 1;
                counter += 1;
            }
            else if((nums[i] - 1)%3 == 0)
            {
                nums[i] = nums[i] - 1;
                counter += 1;
            }
        }

    }
    return counter;
}
