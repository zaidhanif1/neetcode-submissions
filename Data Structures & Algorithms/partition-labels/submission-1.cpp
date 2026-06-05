class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        std::unordered_map<char, int> freq;
        std::vector<int> res;
        for (char c : s)
        {
            freq[c]++;
        }

        //okay so what we'll do is have a count begin the first time we see a character
        int curr_count = 0;
        int curr_freq = 0;
        std::set<int> seen;
        for (char c : s)
        {
            if (!seen.contains(c))
            {
                curr_freq += freq[c] - 1; //account for seeing the character
                curr_count++;
                seen.insert(c);
                if (!curr_freq)
                {
                    res.push_back(curr_count);
                    curr_count = 0; 
                }
                continue;
            }
            curr_freq--;
            curr_count++;
            if (!curr_freq)
            {
                res.push_back(curr_count);
                curr_count = 0;
            }

        }
        return res;
    
        
    }
};