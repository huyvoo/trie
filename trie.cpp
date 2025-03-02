#include "trie.hpp"
#include <cstring>
#include <iostream>
#include <unordered_map>

TrieTree::TrieTree() { root = create(""); }

TrieNode *TrieTree::create(const char *c) {
	TrieNode *newNode = new TrieNode();
	newNode->c = *c;
	newNode->leaf = false;
	return newNode;
}

TrieTree::~TrieTree() { deleteTree(root); }

void TrieTree::deleteTree(TrieNode *node) {

	for (std::unordered_map<char, TrieNode *>::iterator it =
	         node->children.begin();
	     it != node->children.end(); ++it) {
		char key = it->first;
		TrieNode *value = it->second;
		deleteTree(value);
	}

	delete node;
}

void TrieTree::add(const char *str) {
	int n = strlen(str);
	TrieNode *current = this->root;

	for (int i = 0; i < n; i++) {
		char ch = str[i];
		if (current->children.find(ch) != current->children.end()) {
			current = current->children[ch];
		} else {
			current->children[ch] = create(&ch);
			current = current->children[ch];
		}

		if (i == n - 1) {
			current->leaf = true;
		}
	}
}

bool TrieTree::contains(const char *str) {
	int n = strlen(str);

	TrieNode *current = this->root;
	for (int i = 0; i < n; i++) {
		char ch = str[i];

		if (current->children.find(ch) != current->children.end()) {
			current = current->children[ch];
		} else {
			return false;
		}

		if (i == n - 1 && current->c == ch) {
			return true;
		}
	}
	return false;
}
