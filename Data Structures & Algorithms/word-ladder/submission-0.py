class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        wordList.append(beginWord)
        #create an adjaceny list for each word that contains all words that differ by one letter
        n = len(wordList)   #length of the list of words
        z = len(beginWord)  #length of every single word in the problem space
        word_map = {word: [] for word in wordList} # create initial adjacency list
        q = deque( [ (beginWord, 1) ] ) #create queue for the bfs
        seen = {beginWord} #seen set for bfs (although I don't think this is completely necessary but we'll see)
        
        for i in range(n): #for every word in the wordList
            word1 = wordList[i]
            for j in range(n): #for every word in the wordList
                word2 = wordList[j]
                count = 0
                for k in range(z):
                    if word1[k] != word2[k]:
                        count+=1
                if count == 1:
                    word_map[word1].append(word2)
                    word_map[word2].append(word1)
        
        

        while q:
            q_size = len(q)
            for _ in range(q_size):
                curr_word, dist = q.popleft()

                if curr_word == endWord:
                    return dist

                for word in word_map[curr_word]:
                    if word not in seen:
                        seen.add(word)
                        q.append( (word, dist + 1) )
        return 0
                
                


