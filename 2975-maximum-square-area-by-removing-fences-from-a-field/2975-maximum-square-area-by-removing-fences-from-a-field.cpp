class Solution {
public:
const long long mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

      sort(hFences.begin(),hFences.end());
      sort(vFences.begin(),vFences.end());

        unordered_set<int>h;
        unordered_set<int>w;
        for(int i=0;i<hFences.size();i++){
          for(int j=i+1;j<hFences.size();j++){
            h.insert(hFences[j]-hFences[i]);
          }
        }

int maxi=0;
        for(int i=0;i<vFences.size();i++){
          for(int j=i+1;j<vFences.size();j++){
            int x=vFences[j]-vFences[i];
            if(h.find(x)!=h.end()){
              maxi=max(maxi,x);
            }
            w.insert(x);
          }
        }

        return maxi==0?-1: (1ll * maxi*maxi)%mod;
    }
};