// TrieNodeWithValue.h
#ifndef TRIENODEWITHVALUE_H
#define TRIENODEWITHVALUE_H

#include "TrieNode.h"

template <typename T>
class TrieNodeWithValue : public TrieNode {
private:
    T value_;

public:
    TrieNodeWithValue(TrieNode&& trieNode, T value);
    TrieNodeWithValue(char key_char, T value);
    ~TrieNodeWithValue();
    T GetValue() const;
};

// Implementación de la plantilla de clase debe estar en el archivo de cabecera

template <typename T>
TrieNodeWithValue<T>::TrieNodeWithValue(TrieNode&& trieNode, T value)
    : TrieNode(std::move(trieNode)), value_(value) {
    this->SetEndNode(true);
}

template <typename T>
TrieNodeWithValue<T>::TrieNodeWithValue(char key_char, T value)
    : TrieNode(key_char), value_(value) {
    this->SetEndNode(true);
}

template <typename T>
TrieNodeWithValue<T>::~TrieNodeWithValue() = default;

template <typename T>
T TrieNodeWithValue<T>::GetValue() const {
    return value_;
}

#endif // TRIENODEWITHVALUE_H
