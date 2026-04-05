class Solution {
public:
    bool judgeCircle(string moves) {
        int cntu=0,cntd=0,cntl=0,cntr=0;
        for(int i=0;i<moves.size();i++){
          if(moves[i]=='U')cntu++;
          else if(moves[i]=='D')cntd++;
          else if(moves[i]=='L')cntl++;
          else cntr++;
        }

        return (cntu==cntd) &&(cntl==cntr);
    }
};