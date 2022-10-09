
#include <iostream>
#include"Tree.h"
#include<random>
#include<iomanip>
void print_menu() {

}

void menu() {
	

}
int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> rand(0, 99);
	Tree tree;
	/*tree.add(88);
	tree.add(89);
	tree.add(87);
	tree.add(86);
	tree.add(90);*/

	//tree.add(67);
	//tree.add(35);
	//tree.add(34);
	//tree.add(20);
	//tree.add(29);
	//tree.add(19);
	//tree.add(48);
	//tree.add(55);
	//tree.add(40);
	//tree.add(13);
	//tree.add(67);

	//tree.add(88);
	//tree.add(73);
	//tree.add(44);
	//tree.add(52);
	//tree.add(66);
	//tree.add(85);
	//tree.add(39);
	//tree.add(25);
	//tree.add(10);
	//tree.add(21);
	
	//tree.add(82);
	//tree.add(26);
	//tree.add(28);
	//tree.add(69);
	//tree.add(46);
	//tree.add(47);
	//tree.add(41);
	//tree.add(70);
	//tree.add(49);
	//tree.add(98);

	//tree.add(68);
	//tree.add(76);
	//tree.add(51);
	//tree.add(18);
	//tree.add(65);
	//tree.add(69);
	//tree.add(82);
	//tree.add(40);
	//tree.add(77);
	//tree.add(32);

	//tree.add(84);
	//tree.add(53);
	//tree.add(40);
	//tree.add(42);
	//tree.add(34);
	//tree.add(45);
	//tree.add(62);
	//tree.add(57);
	//tree.add(67);
	//tree.add(45);


	for (int i = 0; i <50;i++)
	{
		int random = rand(mt);
		std::cout << i << ")" << random << std::endl;
		tree.add(random);
	}
	tree.print();
	std::cout << std::endl;
	std::cout << std::endl;
	//tree.clear();
	tree.full_tree();
	tree.print();
	//std::cout <<std::boolalpha << tree.search(10,1) << std::endl;
	//tree.bypass();

}
