#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>  // Requires OpenSSL library
#include <iomanip>
#include <sstream>

using namespace std;

// Compute SHA256 hash of input string and return hex string
string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class MerkleTree {
    vector<string> leaves;
    vector<vector<string>> treeLevels;

public:
    MerkleTree(const vector<string>& dataBlocks) {
        // Initialize leaves with hash of data blocks
        for (const string& block : dataBlocks) {
            leaves.push_back(sha256(block));
        }
        buildTree();
    }

    void buildTree() {
        treeLevels.clear();
        treeLevels.push_back(leaves);

        while (treeLevels.back().size() > 1) {
            const vector<string>& prevLevel = treeLevels.back();
            vector<string> currLevel;

            for (size_t i = 0; i < prevLevel.size(); i += 2) {
                if (i + 1 < prevLevel.size()) {
                    // Concatenate pair hashes and hash them
                    string combined = prevLevel[i] + prevLevel[i + 1];
                    currLevel.push_back(sha256(combined));
                } else {
                    // Odd number of nodes, duplicate last hash
                    string combined = prevLevel[i] + prevLevel[i];
                    currLevel.push_back(sha256(combined));
                }
            }
            treeLevels.push_back(currLevel);
        }
    }

    string getRootHash() const {
        if (treeLevels.empty()) return "";
        return treeLevels.back()[0];
    }

    void printTree() const {
        cout << "Merkle Tree Levels (bottom-up):" << endl;
        for (size_t level = 0; level < treeLevels.size(); level++) {
            cout << "Level " << level << " (" << treeLevels[level].size() << " nodes):" << endl;
            for (const string& hash : treeLevels[level]) {
                cout << hash << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> data = {
        "File chunk 1 data",
        "File chunk 2 data",
        "File chunk 3 data",
        "File chunk 4 data",
        "File chunk 5 data"
    };

    MerkleTree merkle(data);

    cout << "Root Hash: " << merkle.getRootHash() << endl << endl;
    merkle.printTree();

    return 0;
}
