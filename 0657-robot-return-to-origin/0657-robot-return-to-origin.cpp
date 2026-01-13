class Solution {
public:
    bool judgeCircle(string moves) {
        int cntU=0,cntD=0,cntL=0,cntR=0;
        for(int i=0;i<moves.size();i++){
          if(moves[i]=='U')cntU++;
          else if(moves[i]=='D')cntD++;
          else if(moves[i]=='L')cntL++;
          else{
            cntR++;
          }
        }

        if(cntU!=cntD)return false;
        if(cntL!=cntR)return false;
        return true;
    }
};