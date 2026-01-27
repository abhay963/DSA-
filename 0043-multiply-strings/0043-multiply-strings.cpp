class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>arr(n+m,0);
        for(int i=n-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
            int num=(num2[j]-'0')*(num1[i]-'0');
          int pos2=i+j+1;
          int pos1=i+j;
          int sum=num+arr[pos2];
          arr[pos2]=sum%10;
          arr[pos1]+=sum/10;

          }
        }
        string ans="";
int i=0;
while(i<arr.size() && arr[i]==0 )i++;
        for(;i<arr.size();i++){
          if(arr[i]>=0){
ans+=to_string(arr[i]);
          }
        }


        return ans;
    }
};