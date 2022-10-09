#ifndef _TREE_
#define _TREE_
#include<string>
#include<iomanip>
#include"Arr.h"
#include<random>
//#define DEBAG
class Tree {

	class Node {
	public:
		int data;
		int height_node;
		Node* right;
		Node* left;
		Node* previous;
		Node(int data, Node* right = nullptr, Node* left = nullptr, Node* previous = nullptr, int height_node = 1) {
			this->data = data;
			this->right = right;
			this->left = left;
			this->height_node = height_node;
			this->previous = previous;
		}
	};
	Node* root = nullptr;

	void direct_bypass(Node* node) {
		if (node == nullptr) return;
		std::cout << node->data << " ";
		direct_bypass(node->left);
		direct_bypass(node->right);
	}
	void max_length_number(Node* node, int& length_number) {
		if (node == nullptr) return;
		if (std::to_string(node->data).length() > length_number)length_number = std::to_string(node->data).length();
		max_length_number(node->left, length_number);
		max_length_number(node->right, length_number);
	}
	void string_level(Node* node, int level, int height, std::string& str, int length_number) { // for print()
		int max_length = std::pow(2, root->height_node - 1);
		max_length = (2 * max_length - 1) * length_number;

		if (level == height + 1) return;
		if (level == height) {

			int spaces = (max_length / 2 - 1);
			int interval = spaces;
			for (int i = 0; i < level - 1; i++)
			{
				spaces = (spaces / 2 - 1);
			}
			for (int i = 0; i < level - 2; i++)
			{
				interval = (interval / 2 - 1);
			}
			if (str == "")
				str += this->space(spaces);
			if (node == nullptr)
				str += this->space(length_number);
			else {
				str += this->space(length_number - std::to_string(node->data).length());
				str += std::to_string(node->data);
			}
				
			str += this->space(interval);
		}
		if (node == nullptr) {
			int temp_level;
			if (height - level >= 1)
				temp_level = height;
			else
				return;
			int spaces = (max_length / 2 - 1);
			int interval = spaces;
			for (int i = 0; i < temp_level - 1; i++)
			{
				spaces = (spaces / 2 - 1);
			}
			for (int i = 0; i < temp_level - 2; i++)
			{
				interval = (interval / 2 - 1);
			}
			int iter = std::pow(2, height - level);
			for (int i = 0; i < iter; i++)
			{
				if (str == "")
					str += this->space(spaces);
				if (node == nullptr)
					str += this->space(length_number);
				else{
					str += this->space(length_number - std::to_string(node->data).length());
					str += std::to_string(node->data);
				}
				str += this->space(interval);
			}
			return;
		}

		string_level(node->left, level + 1, height, str, length_number);
		string_level(node->right, level + 1, height, str, length_number);
	}
	std::string space(int number, char delimiter = ' ') {
		std::string str = "";
		for (int i = 0; i < number; i++)
		{
			str += delimiter;
		}
		return str;
	}

	int get_height(Node* node) {
		return node ? node->height_node : 0;
	}
	int difference(Node* node) {
		return get_height(node->right) - get_height(node->left);
	}
	void fix_height(Node* node) {
		int height_left = get_height(node->left);
		int height_right = get_height(node->right);
		node->height_node = (height_left > height_right ? height_left : height_right) + 1;
	}
	void right_rotate(Node* high) {
		Node* low = high->left;
		high->left = low->right;
		if (low->right != nullptr)
			low->right->previous = high;
		low->right = high;
		low->previous = high->previous;
		high->previous = low;
		if (low->previous != nullptr) {
			if (low->previous->data < low->data) {
				low->previous->right = low;
			}
			if (low->previous->data > low->data) {
				low->previous->left = low;
			}
		}

		fix_height(high);
		fix_height(low);
	}
	void left_rotate(Node* high) {
		Node* low = high->right;
		high->right = low->left;
		if (low->left != nullptr)
			low->left->previous = high;
		low->left = high;
		low->previous = high->previous;
		high->previous = low;
		if (low->previous != nullptr) {
			if (low->previous->data < low->data) {
				low->previous->right = low;
			}
			if (low->previous->data > low->data) {
				low->previous->left = low;
			}
		}
		fix_height(high);
		fix_height(low);
	}

	void balance(Node* node) {
		while (true) {
			fix_height(node);
			if (difference(node) >= 2) {
				if (difference(node->right) == 1 || difference(node->right) == 0) {
					left_rotate(node);
				}
				else
				{
					//BigLeftRotate
					right_rotate(node->right);
					left_rotate(node);
				}
			}
			else if (difference(node) <= -2) {
				if (difference(node->left) == -1 || difference(node->left) == 0) {
					right_rotate(node);
				}
				else
				{
					//BigRightRotate
					left_rotate(node->left);
					right_rotate(node);
				}
			}
			if (node->previous)
				node = node->previous;
			else {
				root = node;
				break;
			}
			root = node;
		}
	}



public:
	void add(int data) {
		if (!(this->search(data))) {
			if (root == nullptr) {
				root = new Node(data);
			}
			else {

				Node* temp = root;
				while (true) {
					if (data > temp->data) {
						if (temp->right == nullptr) {
							temp->right = new Node(data);
							temp->right->previous = temp;

							break;
						}
						else {
							temp = temp->right;

						}

					}
					else {
						if (temp->left == nullptr) {
							temp->left = new Node(data);
							temp->left->previous = temp;
							break;
						}
						else {
							temp = temp->left;
						}
					}
				}
				balance(temp);

			}
		}
		else
		{
			//std::cerr << data << "already exists!" << std::endl;
			//throw std::to_string(data) + std::string(" already exists!");
		}

	}
	void remove(int data) {
		if (this->search(data)) {
			////Node* temp = root;
			////while (true) {
			////	if (data == temp->data) {
			////		if (get_height(temp) == 1) {
			////			if (temp->previous != nullptr) {
			////				if (data < temp->previous->data)
			////					temp->previous->left = nullptr;
			////				if (data > temp->previous->data)
			////					temp->previous->right = nullptr;
			////			}
			////			else
			////			{
			////				root = nullptr;
			////			}
			////			break;
			////		}
			////		if (get_height(temp) == 2 && (temp->right == nullptr || temp->left == nullptr)) {
			////			if (temp->previous != nullptr) {
			////				if (data < temp->previous->data)
			////					if (temp->right != nullptr) {
			////						temp->previous->left = temp->right;
			////						temp->right->previous = temp->previous;
			////					}
			////					else {
			////						temp->previous->left = temp->left;
			////						temp->left->previous = temp->previous;
			////					}
			////				if (data > temp->previous->data)
			////					if (temp->right != nullptr) {
			////						temp->previous->right = temp->right;
			////						temp->right->previous = temp->previous;
			////					}
			////					else {
			////						temp->previous->right = temp->left;
			////						temp->left->previous = temp->previous;
			////					}
			////			}
			////			else
			////			{
			////				if (temp->right != nullptr) {
			////					root = temp->right;
			////					temp->right->previous = temp->previous;
			////				}
			////				else{
			////					root = temp->left;
			////					temp->left->previous = temp->previous;
			////				}
			////			}
			////			break;
			////		}
			////		else {
			////			Node* most_right = temp->left;
			////			
			////			while (most_right->right != nullptr) {
			////				most_right = most_right->right;
			////			}
			////			if (most_right == temp->left) {
			////				most_right->right = temp->right;
			////				most_right->previous = temp->previous;
			////				most_right->height_node = temp->height_node;
			////				if (temp->previous != nullptr) {
			////					if (data < temp->previous->data)
			////						temp->previous->left = most_right;
			////					else
			////						temp->previous->right = most_right;
			////					balance(most_right);
			////				}
			////				if(temp->right!=nullptr)
			////				{
			////					temp->right->previous = most_right;
			////				}
			////				
			////			}
			////			else {
			////				Node* prev = most_right->previous;
			////				prev->right = most_right->left;
			////				
			////				if(most_right->left!=nullptr)
			////					most_right->left->previous = prev;
			////				most_right->right = temp->right;
			////				most_right->left = temp->left;
			////				
			////				most_right->previous = temp->previous;
			////				if(temp->right!=nullptr)
			////					temp->right->previous = most_right;
			////				if (temp->left != nullptr)
			////					temp->left->previous = most_right;
			////				if (temp->previous != nullptr) {
			////					if (data < temp->previous->data)
			////						temp->previous->left = most_right;
			////					else
			////						temp->previous->right = most_right;
			////				}
			////				most_right->height_node = temp->height_node;
			////				temp->previous = prev;
			////			}
			////				
			////			
			////			/*if (most_right->previous == nullptr) {
			////				root = most_right;
			////				balance(most_right);
			////			}*/
			////			
			////			
			////			break;
			////		}
			////	}
			////	else if(data<temp->data) {
			////		temp = temp->left;
			////	}
			////	else if (data > temp->data) {
			////		temp = temp->right;
			////	}
			////}
			////if (temp->previous != nullptr)
			////	balance(temp->previous);
			////delete temp;
			////temp = nullptr;
			////
			////

			Node* temp = root;
			while (true) {
				if (data == temp->data) {
					if (get_height(temp) == 1) {
						if (temp->previous == nullptr) {
							delete temp;
							temp = nullptr;
							root = nullptr;
						}
						else {
							if (data < temp->previous->data) {
								temp->previous->left = nullptr;
							}
							else {
								temp->previous->right = nullptr;
							}
							Node* another_temp = temp->previous;
							delete temp;
							temp = nullptr;
							this->balance(another_temp);
						}
						break;
					}

					if (temp->right == nullptr || temp->left == nullptr) {
						if (temp->previous == nullptr) {
							if (temp->right != nullptr) {
								root = temp->right;
								temp->right->previous = nullptr;
							}
							else if (temp->left != nullptr) {
								root = temp->left;
								temp->left->previous = nullptr;
							}
							delete temp;
							temp = nullptr;
							this->balance(root);
						}
						else {
							if (data < temp->previous->data) {
								if (temp->right != nullptr) {
									temp->right->previous = temp->previous;
									temp->previous->left = temp->right;
								}
								else if (temp->left != nullptr) {
									temp->left->previous = temp->previous;
									temp->previous->left = temp->left;
								}
							}
							else {
								if (temp->right != nullptr) {
									temp->right->previous = temp->previous;
									temp->previous->right = temp->right;
								}
								else if (temp->left != nullptr) {
									temp->left->previous = temp->previous;
									temp->previous->right = temp->left;
								}
							}
							Node* another_temp = temp->previous;
							delete temp;
							temp = nullptr;
							this->balance(another_temp);
						}

						break;
					}
					if (temp->right != nullptr && temp->left != nullptr) {
						Node* most_right = temp->left;
						while (most_right->right != nullptr) {
							most_right = most_right->right;
						}
						if (most_right == temp->left) {
							most_right->previous = temp->previous;
							if (temp->previous != nullptr) {
								if (data < temp->previous->data)
									temp->previous->left = most_right;
								else
									temp->previous->right = most_right;
							}
							most_right->right = temp->right;
							temp->right->previous = most_right;
							delete temp;
							temp = nullptr;
							this->balance(most_right);
							break;
						}
						else {
							Node* prev = most_right->previous;
							prev->right = most_right->left;
							if (most_right->left != nullptr) {
								most_right->left->previous = prev;
							}
							most_right->right = temp->right;
							most_right->left = temp->left;
							temp->right->previous = most_right;
							temp->left->previous = most_right;
							most_right->previous = temp->previous;
							if (temp->previous != nullptr) {
								if (data < temp->previous->data) {
									temp->previous->left = most_right;
								}
								else {
									temp->previous->right = most_right;
								}
							}
							delete temp;
							temp = nullptr;
							this->balance(prev);
							break;
						}



					}
				}
				else if (data < temp->data) {
					temp = temp->left;
				}
				else if (data > temp->data) {
					temp = temp->right;
				}
			}
		}
		else
		{
			//std::cerr << data << " is not found!" << std::endl;
			//throw std::to_string(data) + std::string(" is not found!");
		}
	}
	bool search(int data, bool print_steps = 0) {
		int step = 0;
		if (root != nullptr) {
			Node* temp = root;
			while (temp->data != data) {
				if (data > temp->data) {
					if (temp->right == nullptr) {
						step++;
						if (print_steps)
							std::cout << "Steps to find " << data << " = " << step << std::endl;

						return false;
					}
					else {
						step++;
						temp = temp->right;
					}
				}
				else {
					if (temp->left == nullptr) {
						step++;
						if (print_steps)
							std::cout << "Steps to find " << data << " = " << step << std::endl;

						return false;
					}
					else {
						step++;
						temp = temp->left;
					}
				}
			}
			if (print_steps)
				std::cout << "Steps to find " << data << " = " << step << std::endl;

			return true;
		}
		else {
			if (print_steps)
				std::cout << "Steps to find " << data << " = " << step << std::endl;

			return false;
		}
	}



	void bypass() {
		direct_bypass(root);
	}

	void print() {
		if (root != nullptr) {
			int length_number = 2;
			max_length_number(root, length_number);
			for (int i = 1; i < root->height_node + 1; i++)
			{
				std::string level = "";
				string_level(root, 1, i, level, length_number);
				std::cout << level << std::endl;
			}
		}
	}
	//int current_level(int data) {
	//	Node* temp = root;
	//	int level = 1;
	//	while (true) {
	//		if (temp == nullptr) return level - 1;
	//		if (temp->data == data) return level;
	//		else if (data < temp->data) { 
	//			temp = temp->left; 
	//			level++; 
	//		}
	//		else if (data > temp->data) {
	//			temp = temp->right;
	//			level++;
	//		}
	//	}
	//}
	//void full(Node* node, int level, int max_height) {
	//	if (node->right == nullptr && node->left == nullptr && current_level(node->data) == max_height) return;
	//	/*this->print();
	//	std::cout << std::endl;
	//	std::cout << std::endl;*/
	//	if (node->left == nullptr) { // исправить

	//		if (this->search(node->data - 1)) {
	//			if (difference(node->previous) == 1) {
	//				node = node->previous;
	//				while (node->right != nullptr) node = node->right;
	//				node->right = new Node(node->data + 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//			else if (difference(node->previous) == -1) {
	//				node = node->previous;
	//				while (node->left != nullptr) node = node->left;
	//				node->left = new Node(node->data - 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//			else if (abs(difference(node->previous)) == 0) {
	//				while (node->right != nullptr) node = node->right;
	//				node->right = new Node(node->data + 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//		}
	//		else
	//			this->add(node->data - 1);
	//	}
	//	/*this->print();
	//	std::cout << std::endl;
	//	std::cout << std::endl;*/
	//	if (node->right == nullptr) { // исправить
	//		if (this->search(node->data + 1)) {
	//			if (difference(node->previous) >= 1) {
	//				node = node->previous;
	//				while (node->right != nullptr) node = node->right;
	//				node->right = new Node(node->data + 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//			else if (difference(node->previous) <= -1) {
	//				node = node->previous;
	//				while (node->left != nullptr) node = node->left;
	//				node->left = new Node(node->data - 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//			else if (difference(node->previous) == 0) {
	//				while (node->left != nullptr) node = node->left;
	//				node->left = new Node(node->data - 1, nullptr, nullptr, node);
	//				this->balance(node);
	//			}
	//		}
	//		else
	//			this->add(node->data + 1);
	//	}
	//	/*this->print();
	//	std::cout << std::endl;
	//	std::cout << std::endl;*/
	//	if (node->left != nullptr)
	//		full(node->left, level + 1, max_height);
	//	if (node->right != nullptr)
	//		full(node->right, level + 1, max_height);
	//}
	//void check(Node* node, int level, int max_level,bool& is_full) {
	//	if (node == nullptr && level != max_level + 1) is_full = false;
	//	if (node == nullptr) 
	//		return;
	//	check(node->left,level+1,max_level,is_full);
	//	check(node->right, level + 1, max_level, is_full);
	//}
	//void full_tree() {
	//	bool is_full = true;
	//	while (is_full) {
	//		check(root, 1, root->height_node, is_full);
	//		if (!is_full)
	//			full(root, 1, root->height_node);
	//		else
	//			break;
	//		is_full = true;
	//		//this->print();
	//	}
	//	
	//	/*full(root, 1, root->height_node);
	//	full(root, 1, root->height_node);
	//	full(root, 1, root->height_node);*/
	//	/*	if (root->left->height_node > root->right->height_node) {
	//			right_rotate(root);
	//			this->balance(root);
	//		}
	//		else {
	//			left_rotate(root);
	//			this->balance(root);
	//		}*/
	//}
	void to_arr(Node* node,Arr& arr) {
		if (node == nullptr) return;
		arr.push_back(node->data);
		to_arr(node->left, arr);
		to_arr(node->right, arr);
	}
	void full_tree() {
		int number_of_elements = 0;
		for (int i = 0; i < root->height_node; i++)
		{
			int temp = std::pow(2, i);
			number_of_elements += temp;
		}
		Arr arr;
		to_arr(root, arr);

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<> rand(0, 99);
		while (arr.size()!=number_of_elements) {
			int random = rand(mt);
			if(!arr.contains(random))
				arr.push_back(random);
		}
		arr.sort();
		this->clear();
		while (arr.size() != 0) {
			int index_element = arr.size() / 2;
			this->add(arr[index_element]);
			arr.remove(index_element);
		}
	}
	void clear_rec(Node* node) {
		if (node == nullptr) return;
		clear_rec(node->left);
		clear_rec(node->right);
		delete node;
	}
	void clear() {
		clear_rec(root);
		root = nullptr;
	}
	~Tree() {
		this->clear();
	}
};


#endif
