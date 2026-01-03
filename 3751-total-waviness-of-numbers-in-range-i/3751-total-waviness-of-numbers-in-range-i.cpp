class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
          string str=to_string(i);
          if(str.size()<3)continue;
            if(str.size()==3){
              if((str[1]-'0')>(str[0]-'0') && (str[1]-'0')>(str[2]-'0'))ans+=1;
              else if((str[1]-'0')<(str[0]-'0') && (str[1]-'0')<(str[2]-'0'))
              ans+=1;
            }
if(str.size()>3){
            for(int j=1;j<str.size()-1;j++){
               if((str[j]-'0')>(str[j-1]-'0') && (str[j]-'0')>(str[j+1]-'0'))ans+=1;
              else if((str[j]-'0')<(str[j-1]-'0') && (str[j]-'0')<(str[j+1]-'0'))
              ans+=1;
            
            }
}
        }

        return ans;
    }
};