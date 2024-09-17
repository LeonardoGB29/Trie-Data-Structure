#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include "TrieNodeWithValue.h"
#include <memory>
#include <string>

class Trie {

private:
    std::unique_ptr<TrieNode> root_;
        
public:

    Trie();

    template <typename T>
    bool Insert(const std::string& key, T value);
    bool Remove(const std::string& key);
    template <typename T>
    T GetValue(const std::string& key, bool* success);
};

template <typename T>
bool Trie::Insert(const std::string& key, T value) {

    TrieNode* current = root_.get();

    for (char k : key) {
        if (!current->HasChild(k)) {
            auto new_node = std::make_unique<TrieNode>(k); // creando nodo
            current->InsertChildNode(k, std::move(new_node)); // lo inserto
        }
        current = current->GetChildNode(k)->get(); // me muevo a la sgt pos
    }

    if (current->IsEndNode()) { // la clave ya existe
        return false;
    }

    auto terminal_node = std::make_unique<TrieNodeWithValue<T>>(current->GetKeyChar(), value); // creacion del nodo final TrieNodeWithValue
    return true;
}

template <typename T>
T Trie::GetValue(const std::string& key, bool* success) {
    return {};
}

#endif 