
#include <iostream>
#include"Tree.h"
#include<random>
int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> rand(10, 99);
	Tree tree;

	tree.add(88);
	tree.print();
	tree.add(87);
	tree.print();
	tree.add(95);
	tree.print();
	tree.add(86);
	tree.print();

	tree.add(53);
	tree.print();
	tree.add(41);
	tree.print();
	tree.add(73);
	tree.print();
	tree.add(18);
	tree.print();
	tree.add(41);
	tree.print();
	tree.add(79);
	tree.print();
	tree.add(23);
	tree.print();
	tree.add(39);
	tree.print();
	tree.add(27);
	tree.print();
	tree.add(61);
	tree.print();
	tree.add(40);
	tree.print();
	tree.add(35);
	tree.print();
	tree.add(15);
	tree.print();
	tree.add(78);
	tree.print();
	tree.add(99);
	tree.print();
	tree.add(51);
	tree.print();
	tree.add(21);
	tree.print();
	tree.add(34);
	tree.print();
	tree.add(48);
	tree.print();
	tree.add(92);
	tree.print();
	tree.add(15);
	tree.print();
	tree.add(78);
	tree.print();
	tree.add(96);
	tree.print();
	tree.add(48);
	tree.print();
	tree.add(96);
	tree.print();
	tree.add(22);
	tree.print();
	tree.add(14);
	tree.print();
	tree.add(21);
	tree.print();
	tree.add(11);
	tree.print();
	tree.add(29);
	tree.print();
	tree.add(71);
	tree.print();

	//87 88 96 99 92 53 51 61 39 35 34 18 48 23 22 15 27
	//21 22 23 18 39 35 48 40 29 34 27 15 53

	//for (int i = 0; i <31; i++)
	//{
	//	int random = rand(mt);
	//	std::cout << i << ")" << random << std::endl;
	//	tree.add(random);
	//}
	//tree.print();
	//std::cout <<std::boolalpha << tree.search(10) << std::endl;
	//tree.bypass();
	while (true) {
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		int choice;
		std::cout << "Enter number:";
		std::cin >> choice;

		tree.remove(choice);
		tree.print();
	}
}
