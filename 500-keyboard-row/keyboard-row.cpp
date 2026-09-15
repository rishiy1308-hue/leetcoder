class Solution {  
public:  
    vector<string> findWords(vector<string>& words) {  
        vector<string> ans;  
        string one = "qwertyuiop";  
        string two = "asdfghjkl";  
        string three = "zxcvbnm";  
 
        set<char> st1;  
        set<char> st2;  
        set<char> st3;  
 
        for(auto it : one){  
            st1.insert(it);  
        }  
         
        for(auto it : two){  
            st2.insert(it);  
        }  
 
        for(auto it : three){  
            st3.insert(it);  
        }  
 
        for(int i = 0; i < words.size(); i++){  
            bool flag1 = true;  
            bool flag2 = true;  
            bool flag3 = true;  
 
            for(int j = 0; j < words[i].size(); j++){  
                char ch = tolower(words[i][j]);  // CHANGE
 
                if(st1.find(ch) == st1.end()){  
                    flag1 = false;  
                    break;  
                }      
            }  
 
            for(int j = 0; j < words[i].size(); j++){  
                char ch = tolower(words[i][j]);  // CHANGE
 
                if(st2.find(ch) == st2.end()){  
                    flag2 = false;  
                    break;  
                }      
            }  
 
            for(int j = 0; j < words[i].size(); j++){  
                char ch = tolower(words[i][j]);  // CHANGE
 
                if(st3.find(ch) == st3.end()){  
                    flag3 = false;  
                    break;  
                }      
            }  
 
            if(flag1 || flag2 || flag3)  
                ans.push_back(words[i]);  
        }  
 
        return ans;  
    }  
};