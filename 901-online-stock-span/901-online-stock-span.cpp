class StockSpanner {
public:
    vector<int> price;
    vector<int> prefix;
    StockSpanner() {
        
    }
    
    int next(int p) {
        price.push_back(p);
        int i=price.size()-1;
        int count=0;
        while(i>=0 && price[i]<=p){
            count++;
            i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */