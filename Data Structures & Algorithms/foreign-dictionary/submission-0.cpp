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

        for (int i = 0; i < words.size() - 1; i++ )
        {
            string& word1 = words[i];
            string& word2 = words[i+1];

            int min_length = min(word1.size(), word2.size());

            bool found_diff = false;

            for (int j = 0; j < min_length; j++)
            {
                if (word1[j] != word2[j])
                {
                    found_diff = true;
                    break;
                }
            }

            if (!found_diff && word1.size() > word2.size())
            {
                return "";
            }

            for (int j = 0; j < min_length; j++)
            {
                if (word1[j] != word2[j])
                {
                    char c1 = word1[j];
                    char c2 = word2[j];
                    if(!adj[c1].contains(c2))
                    {
                        adj[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;

        for (auto& [c, deg] : indegree)
        {
            if (deg == 0)
            {
                q.push(c);
            }
        }

        string res;

        while (!q.empty())
        {
            char c = q.front();
            q.pop();
            res += c;

            for (char nei : adj[c])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }


    return res.size() == indegree.size() ? res : "";
    }
};
