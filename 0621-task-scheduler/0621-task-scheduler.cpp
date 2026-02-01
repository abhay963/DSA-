class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch:tasks)freq[ch-'A']++;

        sort(freq.begin(),freq.end(),greater<int>());
        int maxi=freq[0];
        int gadhe=maxi-1;
        int slots=gadhe*n;

        for(int i=1;i<26;i++){
          slots-=min(freq[i],gadhe);
        }

        if(slots>0)return tasks.size()+slots;
else return tasks.size();
    }
};