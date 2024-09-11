#pragma once
#include <vector>
#include <iostream>



template <typename T>
class deque
{
private:
	static const int sizeBlock = 3;
	struct block {
		std::array<T, sizeBlock> data;
	};
	std::vector<block*>blocuri;
	int frontI, backI;// iterator array
	int poz_incep = 0, poz_sf = 0;// iterator vect
	int sizeB = 0;

	void erroare(int x); 


public:
	deque() : frontI(sizeBlock - 1), backI(0) {
		blocuri.emplace(blocuri.end(), new block);
		poz_incep = 0;
		blocuri.emplace(blocuri.end(), new block);// cele 2 blocuri de la inceput
		poz_sf = 1;
	}
	~deque()
	{
		for (auto bloc : blocuri)
		{
			delete bloc;
		}
	}


	void push_front(T val);
	void pop_front();
	void push_back(T val);
	void pop_back();
	T& front();
	T& back();
	bool empty();
	void clear();
	T& operator[](size_t index);
	void insert(T elem, int poz);
	void stergere(int poz);
	int size();
	void display();

};

template<typename T>
inline void deque<T>::erroare(int x)
{
	if (x == 1) {
		std::cout << "Nu se poate afisa, coada este vida" << std::endl;
	}
	else if (x == 2) {
		std::cout << "Coada este vida" << std::endl;
	}
	else if (x == 3) {
		std::cout << "Nu se incadreaza aceasta pozitie în blocuri" << std::endl;
	}
}

template<typename T>
inline void deque<T>::push_front(T val)
{
	if (frontI == -1)
	{
		blocuri.emplace(blocuri.begin(), new block);
		frontI = sizeBlock - 1;
		poz_incep = 0;
		poz_sf++;
	}
	sizeB++;
	blocuri[poz_incep]->data[frontI--] = val;
	std::cout << "push front" << std::endl;

}

template<typename T>
inline void deque<T>::pop_front()
{
	if (frontI == sizeBlock - 2)
	{
		frontI = -2;
		delete blocuri.front();  // sterge array
		blocuri.erase(blocuri.begin());   // sterge adresa din vect
		poz_incep = 0;
		poz_sf--;
	}
	sizeB--;
	frontI++;
	std::cout << "pop front" << std::endl;
}

template<typename T>
inline void deque<T>::push_back(T val)
{
	if (backI == sizeBlock)
	{
		blocuri.emplace(blocuri.end(), new block);
		backI = 0;
		poz_sf++;
	}
	sizeB++;
	blocuri[poz_sf]->data[backI++] = val;
	std::cout << "push_back" << std::endl;
}

template<typename T>
inline void deque<T>::pop_back()
{
	int cnt = 0;
	if (backI == 0)
	{	
		if (blocuri.size() - poz_sf > 1)
		{
				delete blocuri.back();  // sterge array
				blocuri.pop_back();   // sterge adresa din vect
		}
		backI = sizeBlock;
		poz_sf--;
	}
	sizeB--;
	backI--;
	std::cout << "pop back" << std::endl;
}

template<typename T>
inline T& deque<T>::front()
{
	if (sizeB != 0)
		return blocuri.front()->data[frontI + 1];
	else
		erroare(2);
}

template<typename T>
inline T& deque<T>::back()
{
	if (sizeB != 0)
		return blocuri[poz_sf]->data[backI - 1];
	else
		erroare(2);
		//throw std::runtime_error("deque is empty");
}

template<typename T>
inline bool deque<T>::empty()
{
	return sizeB == 0;
}

template<typename T>
inline void deque<T>::clear()
{
	for (auto& bloc : blocuri)
		delete bloc;
	blocuri.clear();// goleste vectorul
	sizeB = 0;
	frontI = 0;
	backI = 0;
	poz_incep = 0;
	poz_sf = 0;
	std::cout << "s-au distrus toate blocurile" << std::endl;
}

template<typename T>
inline T& deque<T>::operator[](size_t index)
{
	index += frontI + 1;
	// fiind array, spatiul imi este deja alocat , astfel indexii vor fi mereu cu frontI +1 elem in minus 
	size_t descifrare_bloc = index / sizeBlock;
	size_t descifrare_poz = index % sizeBlock;
	return blocuri[descifrare_bloc]->data[descifrare_poz];

}

template<typename T>
inline void deque<T>::insert(T elem, int poz)
{
	int copie_p = poz;
	if (poz >= 0 && poz <= sizeB)
	{
		if (poz == 0)
			push_front(elem);
		else
			if (poz == sizeB)
				push_back(elem);
			else
			{
				// mutare
					poz += frontI + 1;			// pt a descifra poz si blocul corect;
					size_t descifrare_bloc = poz / sizeBlock;
					size_t descifrare_poz = poz % sizeBlock;
					size_t sf = backI;
					size_t blcSf = poz_sf;
						// realocare bloc
						if (backI % sizeBlock == 0)
						{
							blocuri.emplace(blocuri.end(), new block);
							backI = 0;
							poz_sf++;
							blcSf++;
						}
					for (int i = sizeB; i > copie_p; i--)	// pt a incepe de la numaratoarea corecta ( ramaneau ultimele elemente inafara for-ului si se dubla ultimul nr care era in for 
					{
						if (sf % sizeBlock == 0)
						{
							blocuri[blcSf]->data[0] = blocuri[blcSf - 1]->data[sizeBlock - 1];
							sf = sizeBlock;
							blcSf--;
						}
						else
						{
							blocuri[blcSf]->data[sf] = blocuri[blcSf]->data[sf-1];

						}
						sf--;
					}
				// adaugare
					(*this)[copie_p] = elem;
					sizeB++;
					backI++;
			}
		std::cout << "s-a inserat elementul "<< elem << " la pozitia "<< copie_p << std::endl;

	}
	else
		erroare(3);
}


template<typename T>
inline void deque<T>::stergere(int poz)
{
	int copie_p= poz;
	if (poz >= 0 && poz <= sizeB)
	{
		poz += frontI + 1;			// pt a descifra poz si blocul corect;
		size_t descifrare_bloc = poz / sizeBlock;
		size_t descifrare_poz = poz % sizeBlock;
		for (int i = copie_p; i < sizeB - 1; i++)	// pt a incepe de la numaratoarea corecta ( ramaneau ultimele elemente inafara for-ului si se dubla ultimul nr care era in for 
		{
			if (descifrare_poz != sizeBlock - 1)
				blocuri[descifrare_bloc]->data[descifrare_poz] = blocuri[descifrare_bloc]->data[descifrare_poz + 1];
			else
			{
				if (descifrare_bloc + 1 <= poz_sf) // daca exista array-ul urmator 
					blocuri[descifrare_bloc]->data[descifrare_poz] = blocuri[descifrare_bloc + 1]->data[0];
				descifrare_poz = -1;
				descifrare_bloc++;
			}
			descifrare_poz++;
		}
		sizeB--;
		backI--;
		std::cout << "s-a sters elementul de pe pozitia " << copie_p << std::endl;

	}
	else
		erroare(3);
}

template<typename T>
inline int deque<T>::size()
{
	return sizeB;
}

template<typename T>
inline void deque<T>::display()
{
	if (sizeB != 0)
		for (int i = 0; i < blocuri.size(); i++)
		{
			std::cout << "in blocul " << i << " sunt elementele: " << std::endl;
			if(i<= poz_sf)
			{
				if (i == 0) {
					for (int j = frontI + 1; j <= sizeBlock - 1; j++)
						std::cout << blocuri[i]->data[j] << " ";
				}
				else
					if (i == poz_sf)
					{
						for (int j = 0; j < backI; j++)
							std::cout << blocuri[i]->data[j] << " ";
					}
					else
					{

						for (int j = 0; j <= sizeBlock - 1; j++)
							std::cout << blocuri[i]->data[j] << " ";
					}
				std::cout << std::endl;
			}
			
		}
	else
		erroare(1);

	std::cout << std::endl;
}







// insert primeste deja containere construite, emplace contruieste direct la iterator
