class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
       long long maxgain=0,actual=0;
        int i=0,j=0;
        int n=prices.size();
        vector<long long>profit(n);
        for(int i=0;i<prices.size();i++){
          profit[i]=(prices[i]*strategy[i]*1ll);
          actual+=profit[i];
        }
long long orgprofit=0,modified=0;
        while(j<prices.size()){
          orgprofit+=profit[j];

          
          if(j-i+1>k/2){
              modified+=prices[j];
            }

             if(j-i+1>k){
             
              orgprofit-=profit[i];
              modified-=prices[i+k/2];
              i++;
            }
            if(j-i+1==k){
              maxgain=max(maxgain,(modified-orgprofit));
             
            }
           
            
            
j++;
        }
        return actual+maxgain;
    }
};