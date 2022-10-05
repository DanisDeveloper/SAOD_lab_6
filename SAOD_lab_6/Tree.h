#ifndef _TREE_
#define _TREE_
#include<string>
#include<iomanip>
//#define DEBAG
class Tree {

	class Node {
	public:
		int data;
		Node* right;
		Node* left;
		Node(int data, Node* right = nullptr, Node* left = nullptr) {
			this->data = data;
			this->right = right;
			this->left = left;
		}
	};
	Node* root = nullptr;
	int height = 0;

	void direct_bypass(Node* node) {
		if (node == nullptr) return;
		std::cout << node->data << " ";
		direct_bypass(node->left);
		direct_bypass(node->right);
	}
	void max_length_number(Node* node,int& length_number) {
		if (node == nullptr) return;
		if (std::to_string(node->data).length() > length_number)length_number = std::to_string(node->data).length();
		max_length_number(node->left,length_number);
		max_length_number(node->right,length_number);
	}
	void string_level(Node* node, int level, int height, std::string& str,int length_number) { // for print()
		int max_length = std::pow(2, this->height - 1);
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
			if(node==nullptr)
				str += this->space(length_number);
			else
				str += std::to_string(node->data);
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
				else
					str += std::to_string(node->data);
				str += this->space(interval);
			}
			return;
		}
		
		string_level(node->left, level + 1, height, str, length_number);
		string_level(node->right, level + 1, height, str, length_number);
	}
public:
	void add(int data) {
		if (!(this->search(data))) {
			if (root == nullptr) {
				root = new Node(data);
				height = 1;
			}
			else {
				int temp_height = 1;
				Node* temp = root;
				while (true) {
					if (data > temp->data) {
						if (temp->right == nullptr) {
							temp->right = new Node(data);
							temp_height++;
							if (height < temp_height) height = temp_height;
							break;
						}
						else {
							temp = temp->right;
							temp_height++;
						}

					}
					else {
						if (temp->left == nullptr) {
							temp->left = new Node(data);
							temp_height++;
							if (height < temp_height) height = temp_height;
							break;
						}
						else {
							temp = temp->left;
							temp_height++;
						}
					}
				}

			}
		}
		/*else
		{
			throw std::to_string(data) + std::string(" already exists!");
		}*/
		this->balance();
	}

	bool search(int data) {
		int step = 0;
		if (root != nullptr) {
			Node* temp = root;
			while (temp->data != data) {
				if (data > temp->data) {
					if (temp->right == nullptr) {
						step++;
#ifdef DEBAG
						std::cout << "Steps to find " << data << " = " << step << std::endl;
#endif
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
#ifdef DEBAG
						std::cout << "Steps to find " << data << " = " << step << std::endl;
#endif
						return false;
					}
					else {
						step++;
						temp = temp->left;
					}
				}
			}
#ifdef DEBAG
			std::cout << "Steps to find " << data << " = " << step << std::endl;
#endif
			return true;
		}
		else {
#ifdef DEBAG
			std::cout << "Steps to find " << data << " = " << step << std::endl;
#endif
			return false;
		}
	}
	void balance() {

	}

	void bypass() {
		direct_bypass(root);
	}

	void print() {
		
		int length_number = 2;
		max_length_number(root, length_number);
		for (int i = 1; i < this->height+1; i++)
		{
			std::string level = "";
			string_level(root, 1, i, level, length_number);
			std::cout << level << std::endl;
		}
	}
	std::string space(int number, char delimiter = ' ') {
		std::string str = "";
		for (int i = 0; i < number; i++)
		{
			str += delimiter;
			//std::cout << delimiter;
		}
		return str;
	}
};


#endif
