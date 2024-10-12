#include "trie.h"
#include <iostream>

Trie::Trie()
{
	this->root = new TrieNode();
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	return this->root;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	TrieNode* acNode = root;
	if(!Trie::search(root,key)){
		bool found= true;
		int i = 0;
		int nxt_ind;
		TrieNode* nxt_node;
		while(key[i] != '\0'){
			if(root->children[CHAR_TO_INDEX(key[i])] == nullptr){
				nxt_ind = i;
				nxt_node = root;
				break;
			}
			else{
				root = root->children[CHAR_TO_INDEX(key[i])];
				i++;
			}
		}
		/*if(key[i] == '\0'){
			root = nullptr;
		}*/
		//else{
			while(key[nxt_ind] != '\0'){
				root->children[CHAR_TO_INDEX(key[i])] = Trie::getNode();
				nxt_ind++;
				root = root->children[CHAR_TO_INDEX(key[i])];
			}
			root->isWordEnd;
			root = acNode;
		//}
	}

}

bool Trie::search(struct TrieNode *root, std::string key)
{
	for(char c :key){
		if(root->children[CHAR_TO_INDEX(c)] == nullptr) return false;
		root = root->children[CHAR_TO_INDEX(c)];
	}
	if(root->isWordEnd) return true;
	else return false;
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	for(int i = 0; i < ALPHABET_SIZE; i++){
		if(!(root->children[i])->isWordEnd) return 0;
	}
	return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void Trie::suggestionsRec(struct TrieNode* root,
					std::string currPrefix)
{
	if (root->isWordEnd) {
        std::cout << currPrefix << std::endl;
    }

    // Recur for all possible children (a to z)
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            // Append the current character to the prefix and recurse
            suggestionsRec(root->children[i], currPrefix + char(i + 'a'));
        }
    }// found a std::string in Trie with the given prefix
}

// print suggestions for given query prefix.
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{
	TrieNode* currNode = root;

    // Traverse the Trie for the length of the query
    for (char c : query) {
        int index = c - 'a';
        
        // If the character does not exist in the Trie, return 0 (no suggestions)
        if (!currNode->children[index]) {
            std::cout << "No suggestions found for the given prefix.\n";
            return 0;
        }
        
        currNode = currNode->children[index];
    }

    // If we find the node corresponding to the prefix, print suggestions
    suggestionsRec(currNode, query);
    
    return 1;  // Indicate success
}