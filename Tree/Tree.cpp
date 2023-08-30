#ifndef Tree_CPP
#define Tree_CPP
#include "Tree.h"


template <typename D, typename K>

Tree<D, K>::Node::Node() :info(D()), key(K()), left(nullptr), right(nullptr) {}


template <typename D, typename K>
Tree<D, K>::Node::Node(const D&_info, const K&_key, Node *_left, Node *_right) : info(_info), key(_key), left(_left), right(_right) {}

template <typename D, typename K>
Tree<D, K>::Tree() : root(nullptr) {}


template <typename D, typename K>
void Tree<D, K>::Add(const D&_info, const K&_key)//key = symbol
{


	if (root == nullptr)

		root = new Node(_info, _key, nullptr, nullptr);
	else {/* cout << "S"; cout << root->key<<_key;*/ Add(root, _info, _key); }

}

template <typename D, typename K>
void Tree<D, K>::Add(Node*_root, const D&_info, const K&_key)
{
	if (_key == _root->key)
	{

		_root->info++;

		/*cout << "SS";*/
		/*cout << root->info << endl;*/
	}
	else
	{
		/*cout << "SSSSS";*/
		if (_key < _root->key)
			if (_root->left == nullptr)
				_root->left = new Node(_info, _key, nullptr, nullptr);
			else
				Add(_root->left, _info, _key); //рекурсивно викликаєм функцію Add
		if (_key > _root->key)
			if (_root->right == nullptr)
				_root->right = new Node(_info, _key, nullptr, nullptr);
			else Add(_root->right, _info, _key);//рекурсивно викликаєм функцію Add
	}
}

template <typename D, typename K>
bool Tree<D, K>::Exist(const K&_key)
{

	return Exist(root, _key);



}
template <typename D, typename K>
bool Tree<D, K>::Exist(Node* _root, const K&_key)
{
	if (_root == nullptr)return false;
	if (_root->key == _key)return true;
	if (_key < _root->key)
		return Exist(_root->left, _key);
	/*else return false;*/
	if (_key > _root->key)
		return Exist(_root->right, _key);
	/*else return false;*/
}

template <typename D, typename K>
D* Tree<D, K>::Find(const K&_key)
{

	return &((Find(root, _key))->info);

}





template <typename D, typename K>
void Tree<D, K>::Print()
{
	Print(root);
}

template <typename D, typename K>
void Tree<D, K>::Print(Node*_root)
{
	if (_root != nullptr)
	{
		Print(_root->left);
		/*cout << _root->key;*/
		char tmp;
		cout << "This is the key: \t";
		tmp = _root->key;
		cout << tmp << "\t" << _root->info; (_root->info == 1) ? cout << " time\n" : cout << " times " << endl;
		Print(_root->right);

	}
}

#endif