class Solution { 
public: 
    string reverseWords(string s) { 
        int n = s.size(); 
        if(n == 1) return s; 

        vector<int> spaces; 
        for(int i = 0; i < n; i++){ 
            if(s[i] == ' ') spaces.push_back(i); 
        } 
        if(spaces.size() == 0){
            int l =0;
            int r = s.size()-1;
            while(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            return s;
        }

        int first = 0; 
        int last = spaces[0] - 1; 
        while(first < last){ 
            swap(s[first], s[last]); 
            first++; 
            last--; 
        }
        

        for(int i = 0; i < spaces.size(); i++){ 
 
            if(i == spaces.size() - 1){ 
                first = spaces[i] + 1; 
                last = s.size() - 1; 
            } 
            else { 
                first = spaces[i] + 1; 
                last = spaces[i + 1] - 1; 
            } 

            while(first < last){ 
                swap(s[first], s[last]); 
                first++; 
                last--; 
            } 
        } 

        return s; 
    }
};