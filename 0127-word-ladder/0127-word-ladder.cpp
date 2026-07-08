class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        if(dict.find(endWord)==dict.end()) return 0;

        q.push({beginWord, 1});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string word=it.first;
            int steps=it.second;

            if(word==endWord) return steps;

            for(int i=0; i<word.size(); i++){
                char letter=word[i];
                for(char c='a'; c<='z'; c++){
                    if(c==letter) continue;
                    word[i]=c;
                    if(dict.find(word)!=dict.end()){
                        dict.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i]=letter;
            }
        }
        return 0;
    }
};