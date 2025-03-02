#include "trie.hpp"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void load_dictionary(const char *str, TrieTree *trie) {
	ifstream file(str);
	std::string line;
	int count = 0;
	while (std::getline(file, line)) {
		trie->add(line.c_str());
		count++;
	}

	cout << "Loaded " << count << " words" << endl;
}

int main() {
	TrieTree *trie = new TrieTree();
	load_dictionary("words.txt", trie);

	while (1) {
		string input;
		cout << "Find word:";
		getline(cin, input);

		if (strcmp(input.c_str(), "q") == 0) {
			break;
		}

		if (trie->contains(input.c_str())) {
			cout << "Dictionary contain " << input << endl;
		} else {
			cout << "Dictionary did not contain " << input << endl;
		}
	}

	delete trie;

	return 0;
}
