/// @file 		QuadLinkedTrieNode.h
/// @author		Alberto García-García <albertgg93@gmail.com>
/// @version	1.0
/// @date		03/05/2014
///
///	@section	License
///
/// The MIT License (MIT)
/// 
/// Copyright (c) 2014 Alberto García-García
/// 
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in all
/// copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#ifndef QUADLINKEDTRIENODE_H_
#define QUADLINKEDTRIENODE_H_

#include <iostream>

using namespace std;

/// @brief		Single node for a Quad Linked TRIE data structure.
///
/// @details	This class represents a quad linked TRIE single node which holds 
///				a character key and a certain type value for that node. Moreover, 
///				the node contains some references to its parent, the left and right 
/// 			brothers and its first child. In addition, the node can be marked 
///				as an actual word in the data structure.
///
///				The node offers some functionality to navigate through other related 
///				nodes and also obtaining and modifying its value, key and word marker.
template <class T>
class QuadLinkedTrieNode
{
	public:

		QuadLinkedTrieNode();
		~QuadLinkedTrieNode();

		/// @brief		<b>Value getter</b>
		/// @details	Gets the value of the current node.
		/// @return		A pointer to the value which is stored in the current node.
		T* value() const;
		/// @brief		<b>Key getter</b>
		/// @details	Gets the key of the current node.
		/// @return		The character that represents the key of the node.
		char key() const;
		/// @brief		<b>Word marker getter</b>
		///	@details	Gets the state of the word marker of the node.
		/// @return		True if the node represents a word, false otherwise.
		bool isWord() const;
		/// @brief		<b>Parent getter</b>
		///	@details 	Gets the parent node of the current one.
		/// @return 	A node pointer to the parent of the current node.
		QuadLinkedTrieNode<T>* parent() const;
		/// @brief		<b>Left brother getter</b>
		///	@details 	Gets the left brother node of the current one.
		/// @return 	A node pointer to the left brother of the current node.
		QuadLinkedTrieNode<T>* left() const;
		/// @brief		<b>Right brother getter</b>
		///	@details 	Gets the right brother node of the current one.
		/// @return 	A node pointer to the right brother of the current node.
		QuadLinkedTrieNode<T>* right() const;
		/// @brief		<b>Child getter</b>
		///	@details 	Gets the child node of the current one.
		/// @return 	A node pointer to the child of the current node.
		QuadLinkedTrieNode<T>* child() const;

		/// @brief		<b>Value value setter</b>
		/// @details	Sets the value's value to the specified one.
		/// @param 		pValue A value to set the node value's value to.
		void value(const T & pValue);
		/// @brief		<b>Value pointer setter</b>
		/// @details	Sets the value's pointer to the specified one.
		/// @param		pValue A pointer to the new value.
		void value(T * pValue);
		/// @brief		<b>Key setter</b>
		/// @details	Sets the key of the current node.
		/// @param		pKey A character representing the new key.
		void key(const char & pKey);
		/// @brief		<b>Word marker setter</b>
		/// @details	Sets the word marker state of the current node.
		/// @param		pIsWord A boolean representing the new word marker state.
		void isWord(const bool & pIsWord);
		/// @brief		<b>Parent pointer setter</b>
		/// @details	Sets the pointer to the parent node.
		/// @param		pParent The pointer to the new parent node.
		void parent(QuadLinkedTrieNode<T> * pParent);
		/// @brief		<b>Left brother pointer setter</b>
		/// @details	Sets the pointer to the left brother node.
		/// @param		pLeft The pointer to the new left brother node.
		void left(QuadLinkedTrieNode<T> * pLeft);
		/// @brief		<b>Left brother pointer setter</b>
		/// @details	Sets the pointer to the right brother node.
		/// @param		pRight The pointer to the new right brother node.
		void right(QuadLinkedTrieNode<T> * pRight);
		/// @brief		<b>Left brother pointer setter</b>
		/// @details	Sets the pointer to the child node.
		/// @param		pChild The pointer to the new child node.
		void child(QuadLinkedTrieNode<T> * pChild);

	private:

		/// @brief		Word marker.
		bool mIsWord;
		/// @brief		Node's key.
		char mKey;
		/// @brief		Pointer to the value.
		T* mValue;

		/// @brief		Pointer to the parent node.
		QuadLinkedTrieNode<T>* mParent;
		/// @brief		Pointer to the left brother node.
		QuadLinkedTrieNode<T>* mLeft;
		/// @brief		Pointer to the right brother node.
		QuadLinkedTrieNode<T>* mRight;
		/// @brief		Pointer to the child node.
		QuadLinkedTrieNode<T>* mChild;
};

#endif