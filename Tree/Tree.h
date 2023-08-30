
#pragma once
#ifndef Tree_h 
#define Tree_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

template <typename D, typename K>
class Tree  //STL->map
{
	struct Node //node - вузол
	{
		D info;
		K key;
		Node *left;
		Node *right;
		Node();//Тут будуть використовуватись параметри того класу, який вставляється замість D(), приклад Book() - тут відбудеться ініціалізація всього класу;
		Node(const D&_info, const K&_key, Node *_left, Node *_right);

	};
	Node *root;//стартовий вказівник дерева
public:Tree(); /*:root(nullptr) {}*/

public:void Add(const D&_info, const K&_key);//key = symbol

private: void Add(Node*_root, const D&_info, const K&_key);

public:bool Exist(const K&_key);

private:bool Exist(Node* _root, const K&_key);

public:D* Find(const K&_key);

private: Node* Find(Node*_root, const K&_key)//не зміг перекинути в cpp, бо проблеми з сигнатурою
{
	if (_root == nullptr)return nullptr;
	if (_root->key == _key)return _root;
	if (_key < _root->key)
		return Find(_root->left, _key);
	if (_key > _root->key)
		return Find(_root->right, _key);
}
public:void Print();

private:void Print(Node*_root);


};
#include "Tree.cpp"
#endif