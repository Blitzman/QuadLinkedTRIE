#ifndef QUADLINKEDTRIE_H_
#define QUADLINKEDTRIE_H_

#include <iostream>

#include "QuadLinkedTrieNode.h"

using namespace std;

template <class T>
class QuadLinkedTrie
{
	public:

		QuadLinkedTrie();
		~QuadLinkedTrie();

		T* & operator[](const string &);

		QuadLinkedTrieNode<T>* root() const;
		T& at(const string &) const; 
		void insert(const std::pair<string, T> &);
		bool find(const string &) const;
		QuadLinkedTrieNode<T>* search(const string &) const;
		void erase(const string &);
		void clear();

	private:

		QuadLinkedTrieNode<T>* mRoot;
};

#endif