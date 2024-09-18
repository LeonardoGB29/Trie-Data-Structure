#include "TrieNode.h"
#include "TrieNodeWithValue.h"
#include "Trie.h"

Trie::Trie() {
    root_ = std::make_unique<TrieNode>('\0');
}


bool Trie::Remove(const std::string& key) {
    TrieNode* current = root_.get();
    std::vector<TrieNode*> path; //camino a eliminar

    for (char k : key) {
        if (!current->HasChild(k)) {
            return false;
        }
        path.push_back(current); // vamos agregando
        current = current->GetChildNode(k)->get();
    }

    if (!current->IsEndNode()) {
        return false;
    }

    current->SetEndNode(false);

    for (int i = path.size() - 1; i >= 0; --i) {

        TrieNode* parent = path[i];
        char ch = key[i];
        TrieNode* child = parent->GetChildNode(ch)->get();

        if (!child->HasChildren() && !child->IsEndNode()) 
            parent->RemoveChildNode(ch);
    }
    return true;
}
