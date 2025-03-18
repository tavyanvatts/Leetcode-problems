class Solution {
public:
int NoofBouquets(vector<int>& bloomDay, int m, int k, int day)
{
    int Nof = 0;
    int Nob = 0;
    for(int i = 0; i < bloomDay.size(); i++)
    {
        if(bloomDay[i] <= day)
        {
            Nof++;
            if(Nof == k)
            {
                Nob++;
                Nof = 0;
            }
        }
        else{Nof = 0;}
    }
    if(Nob >= m) return 1;
        else{return 0;}
}
int maxele(vector<int>& bloomDay)
{
    int maxi = INT_MIN;
    for(int i = 0; i < bloomDay.size(); i++)
    {
        if(bloomDay[i] > maxi)
        {
            maxi = bloomDay[i];
        }
    }
    return maxi;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int high = maxele(bloomDay);
        int low = 1;
        int ans;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int iird = NoofBouquets(bloomDay, m, k, mid);
            if(iird == 1)
            {
                high = mid - 1;
                ans = mid;
            }
            else{low = mid + 1;}
        }
        return ans;
    }
};
