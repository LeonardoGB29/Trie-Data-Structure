#include "TrieNode.h"

TrieNode::TrieNode(char key_char) : key_char_(key_char) {
}

TrieNode::TrieNode(TrieNode&& other_trie_node) {
}

TrieNode::~TrieNode() = default;

bool TrieNode::HasChild(char key_char) const { //buscando en mi map
    return children_.find(key_char) != children_.end();
}

bool TrieNode::HasChildren() const { 
    return !children_.empty();
}

std::unique_ptr<TrieNode>* TrieNode::GetChildNode(char key_char) {
    if (!HasChild(key_char)) { 
        return nullptr;    // nullptr if child node does not exist
    }
    return &children_[key_char];
}

bool TrieNode::IsEndNode() const {
    return is_end_;
}

std::unique_ptr<TrieNode>* TrieNode::InsertChildNode(char key_char, std::unique_ptr<TrieNode>&& child) { 
    // If insertion fails, return nullptr.
    if (child == nullptr || HasChild(key_char)) { // que no sea nulo, ni que ya exista la letra a insertar
        return nullptr;
    }
    children_[key_char] = std::move(child);
    return &children_[key_char];
}

void TrieNode::RemoveChildNode(char key_char) {
    children_.erase(key_char);
}

void TrieNode::SetEndNode(bool is_end) {
    is_end_ = is_end;
}

char TrieNode::GetKeyChar() const {
    return key_char_;
}