class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, long long need1, long long need2) {
        long long tc = 0;
        long long tc2 = 0;
        long long temp1 = need1;
        long long temp2 = need2;
        if(need1 < need2){
            tc2 += temp1*costBoth;
            temp2 -= temp1;
            tc2 += temp2*min(cost2, costBoth);
            if(cost1 < costBoth){
                tc += cost1*need1;
                need1 = 0;
            }
            else{
                tc += need1*costBoth;
                need2 -= need1;
                need1 = 0;
            }
        if(cost2 < costBoth) tc += need2*cost2;
        else tc += need2*costBoth;
        }
        else{
            tc2 += temp2*costBoth;
            temp1 -= temp2;
            tc2 += temp1*min(cost1, costBoth);
            if(cost2 < costBoth){
                tc += cost2*need2;
                need2 = 0;
            }
            else{
                tc += need2*costBoth;
                need1 -= need2;
                need2 = 0;
            }
            if(cost1 < costBoth) tc += need1*cost1;
        else tc += need1*costBoth;
        }
        return min(tc, tc2);
    }
};
