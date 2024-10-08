class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(int i=0;i<logs.size();i++) {
            const string& log = logs[i];
            if(log == "../") {
                if(level != 0) {
                    level--;
                }
            }else if(log == "./") {
                continue;
            }else {
                level++;
            }
        }
        return level;
    }
};