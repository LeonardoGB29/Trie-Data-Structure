#ifndef TRIENODE_H
#define TRIENODE_H

#include <memory>
#include <unordered_map>

class TrieNode {
public:
    TrieNode(char key_char);
    TrieNode(TrieNode&& other_trie_node);
    virtual ~TrieNode();

    bool HasChild(char key_char) const;
    bool HasChildren() const;
    bool IsEndNode() const;
    char GetKeyChar() const;
    std::unique_ptr<TrieNode>* InsertChildNode(char key_char, std::unique_ptr<TrieNode>&& child);
    std::unique_ptr<TrieNode>* GetChildNode(char key_char);
    void RemoveChildNode(char key_char);
    void SetEndNode(bool is_end);

protected:
    char key_char_;
    bool is_end_{ false };
    std::unordered_map<char, std::unique_ptr<TrieNode>> children_;
};

#endif 