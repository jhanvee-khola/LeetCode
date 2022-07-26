class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, 1e8);
        cost[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> price(cost);
            for(auto city:flights){
                price[city[1]]=min(price[city[1]],cost[city[0]]+city[2]);
            }
            cost=price;
        }
        return cost[dst]==1e8?-1:cost[dst];
    }
};