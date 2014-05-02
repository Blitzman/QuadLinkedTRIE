#include "QuadLinkedTrie.h"

template <class T>
QuadLinkedTrie<T>::QuadLinkedTrie()
{
	mRoot = new QuadLinkedTrieNode<T>();
	mRoot->key('@');
}

template <class T>
QuadLinkedTrie<T>::~QuadLinkedTrie()
{
	QuadLinkedTrieNode<T> *nodoActual = mRoot;
	QuadLinkedTrieNode<T> *aux = mRoot;

	while (nodoActual)
	{
		while(nodoActual->child())
			nodoActual = nodoActual->child();

		if (nodoActual->left() && nodoActual->right())
		{
			aux = nodoActual;
			nodoActual->right()->left(nodoActual->left());
			nodoActual->left()->right(nodoActual->right());
			delete aux;
		}
		else if (nodoActual->left() && !nodoActual->right())
		{
			aux = nodoActual;
			nodoActual->left()->right(NULL);
			delete aux;
		}
		else if (!nodoActual->left() && nodoActual->right())
		{
			aux = nodoActual;
			nodoActual->parent()->child(nodoActual->right());
			nodoActual->right()->left(NULL);
			nodoActual->right()->parent(nodoActual->parent());
			nodoActual = nodoActual->right();
			delete aux;
		}
		else
		{
			aux = nodoActual;
			if (nodoActual->parent() == NULL)
			{
				delete aux;
				return;
			}

			nodoActual = nodoActual->parent();
			nodoActual->child(NULL);
			delete aux;
		}
	}
}

template <class T>
T& QuadLinkedTrie<T>::at(const string &s) const
{
	return *search(s)->value();
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrie<T>::root() const
{
	return mRoot;
}

template <class T>
void QuadLinkedTrie<T>::insert(const std::pair<string, T> &p)
{
	QuadLinkedTrieNode<T> *nodoActual = mRoot->child();

	if (nodoActual == NULL)
	{
		nodoActual = mRoot;

		string::const_iterator it;
		for (it = p.first.begin(); it != p.first.end(); ++it)
		{
			QuadLinkedTrieNode<T> *nodo = new QuadLinkedTrieNode<T>();
			nodo->key(*it);
			nodo->parent(nodoActual);

			nodoActual->child(nodo);

			nodoActual = nodo;
		}

		nodoActual->isWord(true);
		nodoActual->value(p.second);
	}
	else
	{
		QuadLinkedTrieNode<T> *nodoAnterior = nodoActual;

		string::const_iterator it;
		for (it = p.first.begin(); it != p.first.end(); ++it)
		{
			if (nodoActual == NULL)
			{
				QuadLinkedTrieNode<T> *nodo = new QuadLinkedTrieNode<T>();
				nodo->key(*it);
				nodo->parent(nodoAnterior);

				nodoAnterior->child(nodo);

				nodoAnterior = nodo;
				nodoActual = nodo->child();
			}
			else if (nodoActual->key() == *it)
			{
				nodoAnterior = nodoActual;
				nodoActual = nodoActual->child();
			}
			else
			{
				QuadLinkedTrieNode<T> *nodoHermano = nodoActual->right();
				while (nodoHermano)
				{
					if (nodoHermano->key() == *it)
					{
						nodoAnterior = nodoHermano;
						nodoActual = nodoHermano->child();
						break;
					}
					else
					{
						nodoActual = nodoHermano;
						nodoHermano = nodoHermano->right();
					}
				}

				if (nodoHermano == NULL)
				{
					QuadLinkedTrieNode<T> *nodo = new QuadLinkedTrieNode<T>();
					nodo->key(*it);
					nodo->parent(nodoActual->parent());
					nodo->left(nodoActual);

					nodoActual->right(nodo);

					nodoAnterior = nodo;
					nodoActual = nodo->child();
				}
			}
		}

		nodoAnterior->isWord(true);
		nodoAnterior->value(p.second);
	}
}

template <class T>
bool QuadLinkedTrie<T>::find(const string &s) const
{
	bool encontrado = false;

	QuadLinkedTrieNode<T> *nodoActual = mRoot->child();

	if (nodoActual != NULL)
	{
		string::const_iterator it;
		for (it = s.begin(); it != s.end() && nodoActual != NULL && !encontrado; ++it)
		{
			if (nodoActual->key() == *it)
			{
				if (it == s.end()-1 && nodoActual->isWord())
					encontrado = true;

				nodoActual = nodoActual->child();
			}
			else
			{
				nodoActual = nodoActual->right();
				while (nodoActual)
				{
					if (nodoActual->key() == *it)
					{
						if (it == s.end()-1 && nodoActual->isWord())
							encontrado = true;

						nodoActual = nodoActual->child();
						break;
					}

					nodoActual = nodoActual->right();
				}
			}
		}
	}

	return encontrado;
}

template <class T>
QuadLinkedTrieNode<T>* QuadLinkedTrie<T>::search(const string &s) const
{
	QuadLinkedTrieNode<T> *nodoActual = mRoot->child();

	if (nodoActual != NULL)
	{
		string::const_iterator it;
		for (it = s.begin(); it != s.end() && nodoActual != NULL; ++it)
		{
			if (nodoActual->key() == *it)
			{
				if (it == s.end()-1 && nodoActual->isWord())
					return nodoActual;

				nodoActual = nodoActual->child();
			}
			else
			{
				nodoActual = nodoActual->right();
				while (nodoActual)
				{
					if (nodoActual->key() == *it)
					{
						if (it == s.end()-1 && nodoActual->isWord())
							return nodoActual;

						nodoActual = nodoActual->child();
						break;
					}

					nodoActual = nodoActual->right();
				}
			}
		}
	}

	return NULL;
}

template <class T>
void QuadLinkedTrie<T>::erase(const string &s)
{
	QuadLinkedTrieNode<T> *nodoActual = search(s);

	if (nodoActual != NULL)
	{
		do
		{
			QuadLinkedTrieNode<T> *aux;

			if (nodoActual->child())
			{
				nodoActual->isWord(false);
				delete nodoActual->value();
				nodoActual->value(NULL);

				break;
			}
			else if (nodoActual->left() == NULL && nodoActual->right() == NULL)
			{
				aux = nodoActual->parent();

				delete nodoActual;
				aux->child(NULL);

				nodoActual = aux;
			}
			else if (nodoActual->left() != NULL && nodoActual->right() == NULL)
			{
				aux = nodoActual->left();

				delete nodoActual;
				aux->right(NULL);

				break;
			}
			else if (nodoActual->left() == NULL && nodoActual->right() != NULL)
			{
				aux = nodoActual->right();
				nodoActual->parent()->child(aux);
				aux->parent(nodoActual->parent());
				aux->left(NULL);

				delete nodoActual;

				break;
			}
			else
			{
				nodoActual->left()->right(nodoActual->right());
				nodoActual->right()->left(nodoActual->left());

				delete nodoActual;
				
				break;
			}
		}
		while(nodoActual != NULL && !nodoActual->isWord() && nodoActual != mRoot);
	}
}

template <class T>
void QuadLinkedTrie<T>::clear()
{
	if (mRoot)
		delete mRoot;

	mRoot = new QuadLinkedTrieNode<T>();
	mRoot->key('@');
}

template class QuadLinkedTrie<string>;