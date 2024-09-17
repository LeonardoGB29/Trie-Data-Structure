#include "TrieNode.h"
#include "TrieNodeWithValue.h"
#include "Trie.h"

Trie::Trie() {
    root_ = std::make_unique<TrieNode>('\0');
}


bool Trie::Remove(const std::string& key) {
    return false;
}
