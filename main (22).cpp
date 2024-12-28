#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to find all neighbors of a word by changing one letter at a time
vector<string> getNeighbors(const string& word, const unordered_set<string>& wordList) {
    vector<string> neighbors;
    string temp = word;
    for (size_t i = 0; i < word.size(); ++i) {
        char originalChar = temp[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            temp[i] = c;
            if (temp != word && wordList.count(temp)) {
                neighbors.push_back(temp);
            }
        }
        temp[i] = originalChar; // Restore the original character
    }
    return neighbors;
}

// Backtracking function to construct paths from the BFS parent map
void constructPaths(const string& word, const string& beginWord, 
                    unordered_map<string, vector<string>>& parentMap, 
                    vector<string>& currentPath, vector<vector<string>>& result) {
    if (word == beginWord) {
        vector<string> path = currentPath;
        reverse(path.begin(), path.end());
        result.push_back(path);
        return;
    }

    for (const string& parent : parentMap[word]) {
        currentPath.push_back(parent);
        constructPaths(parent, beginWord, parentMap, currentPath, result);
        currentPath.pop_back(); // Backtrack
    }
}

// Function to find all shortest transformation sequences
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) {
        return {}; // If endWord is not in the dictionary, return an empty result
    }

    unordered_map<string, vector<string>> parentMap; // Stores parent nodes for backtracking
    unordered_set<string> visited;                  // Keeps track of visited words
    unordered_set<string> currentLevel;             // Tracks current level words in BFS

    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);

    bool found = false;

    while (!q.empty() && !found) {
        int levelSize = q.size();
        currentLevel.clear();

        for (int i = 0; i < levelSize; ++i) {
            string word = q.front();
            q.pop();

            for (const string& neighbor : getNeighbors(word, wordSet)) {
                if (!visited.count(neighbor)) {
                    if (neighbor == endWord) {
                        found = true;
                    }

                    if (!currentLevel.count(neighbor)) {
                        q.push(neighbor);
                        currentLevel.insert(neighbor);
                    }

                    parentMap[neighbor].push_back(word);
                }
            }
        }

        for (const string& word : currentLevel) {
            visited.insert(word);
        }
    }

    vector<vector<string>> result;
    if (found) {
        vector<string> currentPath = {endWord};
        constructPaths(endWord, beginWord, parentMap, currentPath, result);
    }

    return result;
}

int main() {
    string beginWord, endWord;
    int n;
    cout << "Enter the begin word: ";
    cin >> beginWord;
    cout << "Enter the end word: ";
    cin >> endWord;
    cout << "Enter the number of words in the word list: ";
    cin >> n;

    vector<string> wordList(n);
    cout << "Enter the word list:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);

    cout << "Shortest transformation sequences:" << endl;
    if (result.empty()) {
        cout << "No sequence found." << endl;
    } else {
        for (const auto& path : result) {
            for (const string& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
