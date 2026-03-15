class Solution {
public:
    bool squareIsWhite(string coordinates) {
        unordered_map<char,int>mp;
        int num=1;
        for(char ch='a';ch<='h';ch++){
          mp[ch]=num;
          num++;
        }

        int row=mp[coordinates[0]];
        int col=coordinates[1]-'0';
        if((row+col)%2==0)return false;
        return true;
    }

};