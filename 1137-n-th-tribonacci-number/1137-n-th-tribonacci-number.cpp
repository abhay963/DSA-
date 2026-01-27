class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1 )return n;
        if(n==2)return 1;
        int t0=0,t1=1,t2=1;
        long long sum=0;
        for(int i=3;i<=n;i++){
            sum=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=sum;
        }
        return (int)sum;
    }
};