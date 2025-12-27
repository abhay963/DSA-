class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(string s:wordList)st.insert(s);
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
          auto top=q.front();
          q.pop();
          string word=top.first;
          int steps=top.second;
          if(word==endWord)return steps;

          for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
              word[i]=ch;
              if(st.find(word)!=st.end()){
                st.erase(word);
                q.push({word,steps+1});
              }
            }
            word[i]=original;
          }
        }
        return 0;
    }
};