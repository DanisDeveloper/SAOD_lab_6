
#include <iostream>
#include"Tree.h"
#include<random>
int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> rand(10, 99);
	Tree tree;

	tree.add(50);
	tree.add(70);
	tree.add(20);
	tree.add(10);
	tree.add(30);
	
	//tree.add(86);
	tree.print();
	//tree.remove(50);
	//tree.add(53);
	//tree.add(41);
	//tree.add(73);
	//tree.add(18);
	//tree.add(41);
	//tree.add(79);
	//tree.add(23);
	//tree.add(39);
	//tree.add(27);
	//tree.add(61);
	//tree.add(40);
	//tree.add(35);
	//tree.add(15);
	//tree.add(78);
	//tree.add(99);
	//tree.add(51);
	//tree.add(21);
	//tree.add(34);
	//tree.add(48);
	//tree.add(92);
	//tree.add(15);
	//tree.add(78);
	//tree.add(96);
	//tree.add(48);
	//tree.add(96);
	//tree.add(22);
	//tree.add(14);
	//tree.add(21);
	//tree.add(11);
	//tree.add(29);
	//tree.add(71);

	//87 88 96 99 92 53 51 61 39 35 34 18 48 23 22 15 27
	//21 22 23 18 39 35 48 40 29 34 27 15 53

	//for (int i = 0; i <31; i++)
	//{
	//	int random = rand(mt);
	//	std::cout << i << ")" << random << std::endl;
	//	tree.add(random);
	//}
	/*std::cout << std::endl;
	tree.print();*/
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
