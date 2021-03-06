#include "QuadLinkedTrieNode.h"

template <class T>
QuadLinkedTrieNode<T>::QuadLinkedTrieNode()
{
	mIsWord = false;
	mKey = ' ';
	mValue = NULL;

	mParent = NULL;
	mLeft = NULL;
	mRight = NULL;
	mChild = NULL;	
}

template <class T>
QuadLinkedTrieNode<T>::~QuadLinkedTrieNode()
{
	mIsWord = false;
	mKey = ' ';

	if (mValue)
	{
		delete mValue;
		mValue = NULL;
	}

	if (mChild)
	{
		delete mChild;
		mChild = NULL;
	}

	mParent = NULL;
}

template <class T>
T* QuadLinkedTrieNode<T>::value() const
{
	return mValue;
}

template <class T>
char QuadLinkedTrieNode<T>::key() const
{
	return mKey;
}

template <class T>
bool QuadLinkedTrieNode<T>::isWord() const
{
	return mIsWord;
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrieNode<T>::parent() const
{
	return mParent;
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrieNode<T>::left() const
{
	return mLeft;
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrieNode<T>::right() const
{
	return mRight;
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrieNode<T>::child() const
{
	return mChild;
}

template <class T>
void QuadLinkedTrieNode<T>::value(T * pValue)
{
	mValue = pValue;
}

template <class T>
void QuadLinkedTrieNode<T>::value(const T & pValue)
{
	if (mValue)
		delete mValue;
	else 
		mValue = new T();

	(*mValue) = pValue;
}

template <class T>
void QuadLinkedTrieNode<T>::key(const char & pKey)
{
	mKey = pKey;
}

template <class T>
void QuadLinkedTrieNode<T>::isWord(const bool & pIsWord)
{
	mIsWord = pIsWord;
}

template <class T>
void QuadLinkedTrieNode<T>::parent(QuadLinkedTrieNode<T> * pParent)
{
	mParent = pParent;
}

template <class T>
void QuadLinkedTrieNode<T>::left(QuadLinkedTrieNode<T> * pLeft)
{
	mLeft = pLeft;
}

template <class T>
void QuadLinkedTrieNode<T>::right(QuadLinkedTrieNode<T> * pRight)
{
	mRight = pRight;
}

template <class T>
void QuadLinkedTrieNode<T>::child(QuadLinkedTrieNode<T> * pChild)
{
	mChild = pChild;
}

template class QuadLinkedTrieNode<string>;