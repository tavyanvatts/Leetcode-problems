class Solution {
public:
void reverse(vector<int> &arr , int low , int high)
{
    if(low >= high) return;
    swap(arr[low],arr[high]);
    low++;
    high--;
    reverse(arr, low, high);
}
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        if (nums.size() <= 1) return;
        else
        {
        reverse(nums , 0 , nums.size() - k - 1);
        reverse(nums , nums.size() - k , nums.size() - 1);
        reverse(nums , 0 , nums.size() - 1);
        }
    }
};
