link:https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    vector<vector<pair<int, bool>>> t;
    int next;
    Trie() {
        t.resize(100005, vector<pair<int, bool>>(26, {-1, false}));
        next = 1;
    }
    
    void insert(string word) {
        int v=0;
        for(int i=0;i<word.size();i++) {
            if(i==word.size()-1) {
                t[v][word[i]-'a'].second = true;
            }
            if(t[v][word[i]-'a'].first == -1) {
                t[v][word[i]-'a'].first = next++;
            }
            v=t[v][word[i]-'a'].first;
        }
    }
    
    bool search(string word) {
        int v=0;
        for(int i=0;i<word.size();i++) {
            if(i==word.size()-1 && t[v][word[i]-'a'].first!=-1 && t[v][word[i]-'a'].second == true) return true;
            if(t[v][word[i]-'a'].first == -1) {
                return false;
            } else {
                v=t[v][word[i]-'a'].first;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int v=0;
        for(int i=0;i<prefix.size();i++) {
            if(i==prefix.size()-1 && t[v][prefix[i]-'a'].first!=-1) return true;
            if(t[v][prefix[i]-'a'].first == -1) {
                return false;
            } else {
                v=t[v][prefix[i]-'a'].first;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
