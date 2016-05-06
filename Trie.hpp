// Trie.h

#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>

#include "TrieNode.hpp"

template <typename Identifier, typename Variable>
class Trie {
public:
  using NodeType = TrieNode<Identifier, Variable>;

  Trie(): _root(new NodeType) {}

  ~Trie() {
    if (nullptr != _root) {
      delete _root;
    }
  }

  void Add(const Identifier& id, const std::vector<Variable>& data) {
    NodeType* cursor = _root;
    for (const Variable& v : data) {
      auto it = cursor->_children.find(v);
      if (it == cursor->_children.end()) cursor->_children[v] = new NodeType;
      cursor = cursor->_children[v];
    }
    cursor->_terminates.insert(id);
  }

  std::vector<Identifier> Superset(const std::vector<Variable>& data) {
    std::vector<Identifier> result;
    NodeType* cursor = _root;
    result.insert(result.end(),
		  cursor->_terminates.begin(),
		  cursor->_terminates.end());
    
    for (const Variable& v : data) {
      auto it = cursor->_children.find(v);
      if (it == cursor->_children.end()) break;
      cursor = cursor->_children[v];
      result.insert(result.end(),
		    cursor->_terminates.begin(),
		    cursor->_terminates.end());
    }
    return result;
  }

private:
  NodeType* _root;
};

#endif // __TRIE_H__
