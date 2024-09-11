#include <iostream>
#include <list>
#include <array>
#include <vector>
#include "deque.h"

int main()
{
	int x;
	deque<int> bloc;
	// testare 
	// 
	//std::vector<int> vect = { 0,1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20 };
	//int incerc;
	//int i = 0;
	//while (i < vect.size())
	//{
	//	bloc.push_front(vect[i]);
	//	i++;
	//}
	//i = 0;
	//while (i < vect.size())
	//{
	//	bloc.push_back(vect[i]);
	//	i++;
	//}
	//bloc.push_back(21);
	//bloc.push_back(22);
	//bloc.push_back(23);
	//bloc.display();

	////bloc.insert(55555, 20);
	////bloc.stergere(12);

	////bloc.display();
	//std::cout << "nr elem este: " << bloc.size() << std::endl;
	//
	//std::cout << "primul element este: " << bloc.front() << std::endl;
	//std::cout<<"ultimul element este: "<<bloc.back()<<std::endl;

	//if (bloc.empty())
	//		std::cout << "este gol"<<std::endl;
	//	else
	//		std::cout << "nu este gol"<<std::endl;

	//bloc.clear();
	//bloc.display();
	//if (bloc.empty())
	//std::cout << "este gol" << std::endl;
	//else
	//std::cout << "nu este gol" << std::endl;
	///*std::cout << "introduceti un index: ";
	//int index;
	//std::cin >> index;
	//if(index< bloc.size())
	//	std::cout << "elementul din index-ul introdus este: " << bloc[index]<<std::endl;
	//else
	//	std::cout << "nu este index-ul precizat in blocuri/ nu sunt suficiente elemente"<<std::endl;*/



	// adaugare in bloc rapid;

	/*std::vector<int> vect1 = {0,1,2,3,4,5};
	int incerc;
	int i = 0;
	while (i < vect1.size())
	{
		bloc.push_front(vect1[i]);
		i++;
	}
	i = 0;
	std::vector<int> vect2 = { 14,15,16,17,18,19,20, 21, 22, 23, 24, 25, 26, 27, 28, 29 , 30, 17,18,19,20, 21, 22, 23, 24, 25, 26, 27, 28, 29 , };
	while (i < vect2.size())
	{
		bloc.push_back(vect2[i]);
		i++;
	}
	*/

	std::cout << " ordinea afisari este 0-> 8" << std::endl;
		std::cout << "1. adaugare la inceput: " << std::endl;
		std::cout << "2. adaugare la final: " << std::endl;
		std::cout << "3. stergere la inceput: " << std::endl;
		std::cout << "4. stergere la final: " << std::endl;
		std::cout << "5. returneaza primul elem: " << std::endl;
		std::cout << "6. returneaza ultimul elem: " << std::endl;
		std::cout << "7. verifica daca este vida structura: " << std::endl;
		std::cout << "8. goleste structura: " << std::endl;
		std::cout << "9. returneaza numarul de elemente stocate: " << std::endl;
		std::cout << "10. returneaza elementul de pe o pozitie data: " << std::endl;
		std::cout << "11. adauga un element pe o pozitie data: " << std::endl;
		std::cout << "12. sterge un element de pe o pozitie data: " << std::endl;
		std::cout << "13. afisare: " << std::endl;
		std::cout << std::endl;
		std::cout << std:: endl;
	while (std::cin>>x)
	{
		switch (x)
		{
		case 1:
			int elem1;
			std::cin >> elem1;
			bloc.push_front(elem1);
			break;
		case 2:
			int elem;
			std::cin >> elem;
			bloc.push_back(elem);
			break;
		case 3:
			bloc.pop_front();
			break;
		case 4:
			bloc.pop_back();
			break;
		case 5:
			if (!bloc.empty())
				std::cout << "primul element este: " << bloc.front() << std::endl;
			else
				std::cout << "coada este vida, nu are un prim element"<<std::endl;
			break;
		case 6:
			if(!bloc.empty())
				std::cout << "ultimul element este: " << bloc.back() << std::endl;
			else
				std::cout << "coada este vida, nu are un ultim element" << std::endl;

			break;
		case 7:
			if (bloc.empty())
			std::cout << "este gol" << std::endl;
			else
			std::cout << "nu este gol" << std::endl;
			break;
		case 8:
			bloc.clear();
			break;
		case 9:
			std::cout << "numarul elementelor este: " << bloc.size() << std::endl;
			break;
		case 10:
			std::cout << "introduceti pozitia dorita: ";
			int poz;
			std::cin >> poz;
			std::cout << std::endl << "Elementul de pe pozitia data este: " << bloc[poz] << std::endl;
			break;
		case 11:
			std::cout << "introduceti elementul dorit: ";
			int elem3;
			std::cin >> elem3;
			std::cout << "introduceti pozitia dorita: ";
			int poz1;
			std::cin >> poz1;
			bloc.insert(elem3, poz1);
			break;
		case 12:
			std::cout << "introduceti pozitia dorita: ";
			int poz2;
			std::cin >> poz2;
			bloc.stergere(poz2);
			break;
		case 13:
			bloc.display();
			break;
		default:
			std::cout << "nu este comanda";
			break;
		}
	}

	return 0;
}