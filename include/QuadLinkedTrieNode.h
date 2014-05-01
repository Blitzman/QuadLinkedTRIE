#ifndef QUADLINKEDTRIENODE_H_
#define QUADLINKEDTRIENODE_H_

#include <iostream>

using namespace std;

template <class T>
class QuadLinkedTrieNode
{
	public:

		QuadLinkedTrieNode();
		~QuadLinkedTrieNode();

		T* Value() const;
		char Key() const;
		bool IsWord() const;
		QuadLinkedTrieNode<T>* Parent() const;
		QuadLinkedTrieNode<T>* Previous() const;
		QuadLinkedTrieNode<T>* Next() const;
		QuadLinkedTrieNode<T>* Child() const;

		void Value(const T &);
		void Value(T *);
		void Key(const char &);
		void IsWord(const bool &);
		void Parent(QuadLinkedTrieNode<T>*);
		void Previous(QuadLinkedTrieNode<T>*);
		void Next(QuadLinkedTrieNode<T>*);
		void Child(QuadLinkedTrieNode<T>*);

	private:

		bool isWord;
		char key;
		T* value;

		QuadLinkedTrieNode<T>* parent;
		QuadLinkedTrieNode<T>* previous;
		QuadLinkedTrieNode<T>* next;
		QuadLinkedTrieNode<T>* child;
};

#endif