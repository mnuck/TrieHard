// TrieNode.h

#ifndef __TRIENODE_H__
#define __TRIENODE_H__

#include <vector>
#include <map>

template <typename Identifier, typename Variable>
class TrieNode {
public:
  TrieNode() {}
  ~TrieNode() {
    for (auto& kv : _children) {
      if (nullptr != kv.second) delete kv.second;
    }
  }

  std::vector<Identifier> _terminates;
  std::map<Variable, TrieNode*> _children;
};


#endif // __TRIENODE_H__
