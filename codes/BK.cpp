#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// ------------------------------
// Levenshtein Distance Function
// ------------------------------
int levenshteinDistance(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }

    return dp[n][m];
}

// ------------------------------
// BK-Tree Node Definition
// ------------------------------
class BKNode {
public:
    string word;
    unordered_map<int, BKNode*> children;

    BKNode(const string& w) : word(w) {}
};

// ------------------------------
// BK-Tree Class
// ------------------------------
class BKTree {
private:
    BKNode* root;

public:
    BKTree() : root(nullptr) {}

    void insert(const string& word) {
        if (!root) {
            root = new BKNode(word);
            return;
        }

        BKNode* current = root;
        while (true) {
            int dist = levenshteinDistance(word, current->word);
            if (current->children.count(dist) == 0) {
                current->children[dist] = new BKNode(word);
                break;
            } else {
                current = current->children[dist];
            }
        }
    }

    void search(const string& target, int maxDist, vector<string>& result) {
        searchRecursive(root, target, maxDist, result);
    }

private:
    void searchRecursive(BKNode* node, const string& target, int maxDist, vector<string>& result) {
        if (!node) return;

        int dist = levenshteinDistance(node->word, target);
        if (dist <= maxDist) {
            result.push_back(node->word);
        }

        for (int i = dist - maxDist; i <= dist + maxDist; ++i) {
            if (node->children.count(i)) {
                searchRecursive(node->children[i], target, maxDist, result);
            }
        }
    }
};

// ------------------------------
// Main Function for Testing
// ------------------------------
int main() {
    BKTree tree;

    // Insert words into BK-Tree
    vector<string> dictionary = { "email", "edge", "editor", "emile", "eagle", "evil" };
    for (const string& word : dictionary) {
        tree.insert(word);
    }

    // Search for fuzzy matches
    string query = "emial";
    int tolerance = 2;
    vector<string> matches;

    tree.search(query, tolerance, matches);

    cout << "Fuzzy matches for \"" << query << "\" (tolerance: " << tolerance << "):\n";
    for (const string& match : matches) {
        cout << " - " << match << endl;
    }

    return 0;
}

