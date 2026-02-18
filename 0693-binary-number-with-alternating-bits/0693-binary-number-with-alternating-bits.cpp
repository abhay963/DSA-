class Solution {
public:
    bool hasAlternatingBits(int n) {
        string check="";
        while(n!=0){
          int num=n%2;
          check+=to_string(num);
          n=n/2;
        }

        for(int i=1;i<check.size();i++){
          if(check[i]==check[i-1])return false;
        }

        return true;
    }
};