class Solution {
public:
char solve(char op,vector<char>arr){
if(op=='!'){
  return arr[0]=='f'?'t':'f';
}
else if(op=='&'){
  for(int i=0;i<arr.size();i++){
    if(arr[i]=='f')return 'f';
  }
  return 't';
}
else{
  for(int i=0;i<arr.size();i++){
    if(arr[i]=='t')return 't';
  }
  return 'f';
}
}
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.size();i++){
          if(expression[i]==',')continue;
         else if((expression[i]=='(')||
          (expression[i]=='t')||
          (expression[i]=='f')||
          (expression[i]=='&')||
          (expression[i]=='|')||
          (expression[i]=='!'))st.push(expression[i]);
          else{
            vector<char>arr;
            while(!st.empty() && st.top()!='('){
                arr.push_back(st.top());
                st.pop();
            }
            st.pop();
            char val=solve(st.top(),arr);
            st.pop();
            st.push(val);
          }
        }
       if(st.top()=='t')return true;
       else return false;
    }
};