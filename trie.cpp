const int ALPHABET_SIZE = 26;
struct TrieNode {

	struct TrieNode *children[ALPHABET_SIZE];
	// isEndOfWord is true if the node
	// represents end of a word
	bool isEndOfWord;

};
// Returns new trie node (initialized to NULLs)

struct TrieNode *getNode(void) {

	struct TrieNode *pNode =  new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		pNode->children[i] = NULL;
	}
	return pNode;
}
//Given String me Traverse karo
void insert(struct TrieNode *root, string key) {

	struct TrieNode *curr_node = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		
		if (curr_node->children[index] == NULL) {
			//create New Node for key[i] character.
			curr_node->children[index] = getNode();
		}
		//Go on More Depth
		curr_node = curr_node->children[index];
	}
	// mark last node as leaf
	curr_node->isEndOfWord = true;
}
bool search(struct TrieNode *root, string key) {

	struct TrieNode *curr_node = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		if (curr_node->children[index] == NULL) {
			return false;
		}
		curr_node = curr_node->children[index];
	}
	return (curr_node->isEndOfWord);
}
