#include <iostream>
#include <vector>

#include "Trie.hpp"

using std::cout;
using std::endl;
using std::vector;

int main() {
  Trie<int, int> t;
  vector<int> v1 {1, 2, 3, 4};
  vector<int> v2 {1, 2, 3};
  vector<int> v3 {1, 2, 3, 5};
  vector<int> v4 {1, 2};
  
  t.Add(1, v1);
  t.Add(2, v2);
  t.Add(3, v3);
  t.Add(4, v4);

  auto s1 = t.Superset(v1);
  auto s2 = t.Superset(v2);
  auto s3 = t.Superset(v3);
  auto s4 = t.Superset(v4);

  cout << "v1 is a superset of: ";
  for (auto& i : s1)
    cout << i << ", ";
  cout << endl;
  
  cout << "v2 is a superset of: ";
  for (auto& i : s2)
    cout << i << ", ";
  cout << endl;
  
  cout << "v3 is a superset of: ";
  for (auto& i : s3)
    cout << i << ", ";
  cout << endl;
  
  cout << "v4 is a superset of: ";
  for (auto& i : s4)
    cout << i << ", ";
  cout << endl;
  
  return 0;
}
