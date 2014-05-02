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

		T* value() const;
		char key() const;
		bool isWord() const;
		QuadLinkedTrieNode<T>* parent() const;
		QuadLinkedTrieNode<T>* left() const;
		QuadLinkedTrieNode<T>* right() const;
		QuadLinkedTrieNode<T>* child() const;

		void value(const T &);
		void value(T *);
		void key(const char &);
		void isWord(const bool &);
		void parent(QuadLinkedTrieNode<T>*);
		void left(QuadLinkedTrieNode<T>*);
		void right(QuadLinkedTrieNode<T>*);
		void child(QuadLinkedTrieNode<T>*);

	private:

		bool mIsWord;
		char mKey;
		T* mValue;

		QuadLinkedTrieNode<T>* mParent;
		QuadLinkedTrieNode<T>* mLeft;
		QuadLinkedTrieNode<T>* mRight;
		QuadLinkedTrieNode<T>* mChild;
};

#endif