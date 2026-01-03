class Solution {
public:
    int minimumFlips(int n) {
        string str="";
        while(n!=0){
          int num=n%2;
          str+=to_string(num);
          n=n/2;
        }
        string newstr=str;
        reverse(str.begin(),str.end());
        int cnt=0;
        for(int i=0;i<str.size();i++){
          if(str[i]!=newstr[i])cnt++;
        }
        return cnt;
    }
};