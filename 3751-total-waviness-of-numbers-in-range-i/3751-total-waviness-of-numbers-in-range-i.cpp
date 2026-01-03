class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long ans = 0;
        for(long long i = num1; i <= num2; ++i){
            string s = to_string(i);
            for(int j = 1; j < s.size()-1; ++j){
                if((s[j] > s[j-1] && s[j] > s[j+1]) || (s[j] < s[j-1] && s[j] < s[j+1])){
                    ans++;
                }
            }
        }
        return ans;
    }
};