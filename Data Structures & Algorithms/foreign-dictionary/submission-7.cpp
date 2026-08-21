class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for (const string& word : words)
        {
            for (char c : word)
            {
                adj[c];
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            string& word1 = words[i];
            string& word2 = words[i+1];
            
            int min_length = min(word1.size(), word2.size());
            bool diff = false;

            for (int j = 0; j < min_length; j++)
            {
                if (word1[j] != word2[j])
                {
                    diff = true;
                    break;
                }
            }
            if (!diff && word1.size() > min_length)
            {
                return "";
            }

            for (int j = 0; j < min_length; j++)
            {
                if (word1[j] != word2[j] )
                {
                    if (!adj[word1[j]].contains(word2[j]))
                    {
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
            
        }
        queue<char> q;
        for (auto& [key, val] : indegree)
        {
            if (val == 0)
            {
                q.push(key);
            }
        }

        string res = "";
        while (!q.empty())
        {
            char curr = q.front(); q.pop();

            res += curr;

            for (auto& nei : adj[curr])
            {
                indegree[nei]--;
                if (indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }
        return res.size() == indegree.size() ? res : "";      
}

};