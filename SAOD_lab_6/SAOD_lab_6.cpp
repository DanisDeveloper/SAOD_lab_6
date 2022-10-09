

#include <iostream>
#include"Tree.h"
#include<random>
#include<iomanip>
#include<conio.h>

const int ASCII_COEFF = 48;

void print_menu() {
	std::cout << "=======MENU=======" << std::endl;
	std::cout << "0 - Print" << std::endl;
	std::cout << "1 - Generate" << std::endl;
	std::cout << "2 - Add" << std::endl;
	std::cout << "3 - Remove" << std::endl;
	std::cout << "4 - Full tree" << std::endl;
	std::cout << "5 - Direct bypass" << std::endl;
	std::cout << "6 - Search" << std::endl;
	std::cout << "7 - Clear" << std::endl;
	std::cout << "8 - Exit" << std::endl;
}

void menu(Tree tree) {
	while (true)
	{
		system("cls");
		print_menu();
		switch (_getch()) {
			case 0 + ASCII_COEFF: {
				system("cls");
				tree.print();
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 1 + ASCII_COEFF: {
				system("cls");
				std::cout << "Enter amount of numbers:";
				int number;
				std::cin >> number;

				std::random_device rd;
				std::mt19937 mt(rd());
				std::uniform_int_distribution<> rand(0, 999);
				for (int i = 0; i < number; i++)
				{
					int random = rand(mt);
					std::cout << i << ")" << random << std::endl;
					tree.add(random);
				}
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 2 + ASCII_COEFF: {
				system("cls");
				std::cout << "Enter number to add:";
				int number;
				std::cin >> number;
				tree.add(number);
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 3 + ASCII_COEFF: {
				system("cls");
				std::cout << "Enter number to remove:";
				int number;
				std::cin >> number;
				tree.remove(number);
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 4 + ASCII_COEFF: {
				system("cls");
				tree.full_tree();
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 5 + ASCII_COEFF: {
				system("cls");
				tree.bypass();
				std::cout << std::endl;
				tree.print();
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 6 + ASCII_COEFF: {
				system("cls");
				std::cout << "Enter number to search:";
				int number;
				std::cin >> number;
				bool result = tree.search(number,true);
				if (!result)
					std::cout << number << " is not found!" << std::endl;
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 7 + ASCII_COEFF: {
				system("cls");
				tree.clear();
				std::cout << "Enter any key to get back" << std::endl;
				_getch();
				break;
			}
			case 8 + ASCII_COEFF: {
				exit(0);
				break;
			}
		}
	}

}
int main()
{
	Tree tree;
	menu(tree);
}
