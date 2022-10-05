
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
	tree.add(20);
	tree.add(22);
	tree.add(23);
	tree.add(70);
	tree.add(80);
	tree.add(90);
	//tree.add(91);
	//tree.add(65);
	tree.add(55);
	tree.add(54);
	tree.add(57);
	tree.add(58);
	tree.add(56);


	
	//tree.add(48);
	//tree.add(11);
	//tree.add(5);
	/*for (int i = 0; i < 10; i++)
	{
		int random = rand(mt);
		std::cout << i << ")" << random << std::endl;
		tree.add(random);
	}*/
	//std::cout <<std::boolalpha << tree.search(10) << std::endl;
	//tree.bypass();
	tree.print();
}
