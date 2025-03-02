#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <unordered_map>

typedef struct TrieNode {
	char c;
	bool leaf;
	std::unordered_map<char, TrieNode *> children;
} TrieNode;

class TrieTree {
  public:
	TrieTree();
	~TrieTree();
	void add(const char *str);
	bool contains(const char *str);

  private:
	TrieNode *root;
	TrieNode *create(const char *c);
	void deleteTree(TrieNode *node);
};

#endif
