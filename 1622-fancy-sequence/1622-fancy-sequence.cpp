class Fancy {
  const int mod=1e9+7;
 long long add,multiply;
  vector<long long>arr;
public:
    Fancy() {
        add=0;
        multiply=1;
    }
    
    long long power(int a,int b){
      if(b==0)return 1;
      long long half=power(a,b/2)%mod;
      long long val=(half*half)%mod;
      if(b%2==1)val=(val*a)%mod;
      return val;
    }
    void append(int val) {
     long long value = ((val - add) % mod + mod) % mod;
value = (value * power(multiply, mod-2)) % mod;
arr.push_back(value);
    }
    
    void addAll(int inc) {
        add=(add+inc)%mod;
    }
    
    void multAll(int m) {
        multiply=(multiply*m)%mod;
        add=(add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size())return -1;
       long long num=arr[idx];
       num=(num*multiply+add)%mod;
        return num;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */