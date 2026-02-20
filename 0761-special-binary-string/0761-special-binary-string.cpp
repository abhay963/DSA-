class Solution {
public:
    string makeLargestSpecial(string s) {
         vector<string> mountains;
        int count = 0;
        int start = 0;
        
        // Step 1: Split into balanced special substrings
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '1') count++;
            else count--;
            
            // When count becomes 0 → found one mountain
            if(count == 0) {
                
                // Step 2: Recursively solve inside part
                string inner = s.substr(start + 1, i - start - 1);
                
                mountains.push_back("1" + makeLargestSpecial(inner) + "0");
                
                start = i + 1;
            }
        }
        
        // Step 3: Sort in descending order
        sort(mountains.begin(), mountains.end(), greater<string>());
        
        // Step 4: Combine
        string result = "";
        for(string &str : mountains) {
            result += str;
        }
        
        return result;
    }
};