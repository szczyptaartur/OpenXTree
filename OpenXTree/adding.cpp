#include "stdafx.h"
#include "adding.h"
#include <iostream>
#include <conio.h>

using namespace std;

void adding::addNode(vector<int>& numbers, TreeRoot & root){//glowna funkcja dodajaca wezel do drzewa
														//root jest adresem korzenia, a numbers wektorem indeksow zaimplementowanych wezlow,
		int value, number;								//ktore wykorzystuje do testu poprawnosci wprowadzenia nowego numbera.
		int k, j;


		cout << "Podaj wartosc wezla: ";
		cin >> value;//zmienna odpowiadajaca za wartosc 

		while (cin.fail()) //test sprawdzajacy czy podany numer jest rzeczywiscie numerem (intem)
		{
			cin.clear();
			cin.sync();
			cin.ignore(1000, '\n');
			cout << "Podaj poprawna liczbe calkowita jako wartosc wezla: ";
			cin >> value;

		}



		do { //warunek sprawdzajacy czy numer ktory podalismy jest odpowiedni i czy mozemy tam zaimplementowac wezel
			k = 0, j = 0;
			cin.clear();
			std::cin.ignore(1000, '\n');
			cin.sync();
			cout << "Podaj poprawny indeks nowego wezla: ";
			cin >> number;

			while (cin.fail()) //test sprawdzajacy czy podany numer jest rzeczywiscie numerem (intem)
			{
				cin.clear();
				cin.sync();
				cin.ignore(1000, '\n');
				cout << "Nie mozesz dodac takiego indeksu! Podaj poprawna liczbe: ";
				cin >> number;
			}

			for (int i = 0; i < numbers.size(); i++) { //sprawdzenie czy podany numer jest poprawny i czy mozna go dodac do drzewa
				if (number == numbers[i]) k++;
			}
			if (k == 0) {
				for (int i = 0; i < numbers.size(); i++) {
					if (number == 2 * numbers[i]) { j = 1; }
					if (number == 2 * numbers[i] + 1) { j = 1; }
				}
			}

			if (numbers.size() == 0) {
				if (number == 1) {
					k = 0;//wartosci zmiennych "k" i "j" odpowiadaja za pozytywne albo negatywne przejscie testu poprawnosci
					j = 1;
				}
			}


		} while ((!((k == 0) && (j > 0))));

		numbers.push_back(number); //dodanie wektora numbera to globalnego wektora wszystkich wprowadzonych numberow

		TreeNode *new_node = new TreeNode; //stworzenie dynamicznego obiektu typu TreeNode ktory bedzie nam pozniej potrzebny
		new_node->value = value; //nadanie obiektowi wartosci wezla ktorym jest korzen


		if (number == 1) {//jesli number = 1 inicjalizujemy drzewo, wiec to tez jest adres poczatku drzewa.
			root.rootAdress = new_node;
		}

		vector <int> previousValues; //stworzenie wektora ktorego wartosci sa numerami wezla sciezki ktora dojdziemy do naszego wezla
									 //przykladowo jesli number=11 to previousValues =(2,5,11) <- droga po ktorej idziemy
		if (number != 1) { //w warunku nizej wektor jest uzupelniany odpowiednimi wartosciami
			previousValues.push_back(number);
			while (1) {
				if (previousValues[previousValues.size() - 1] / 2 != 1) { previousValues.push_back(previousValues[previousValues.size() - 1] / 2); }
				else break;
			}
		}

		for (int i = 0; i < previousValues.size() / 2; i++) { //wektor jest wartosciami malejacy, a chcemy rosnacy, wiec tu nastepuje jego 
			int k;									//odwrocenie (jest to zrobione tylko i wylacznie na wygody)
			k = previousValues[i];
			previousValues[i] = previousValues[previousValues.size() - i - 1];
			previousValues[previousValues.size() - i - 1] = k;
		}


		TreeNode *temp = new TreeNode; //tymczasowy obiekt dynamiczny
		temp = root.rootAdress; //nadanie mu watosci korzenia
		if (number == 1) { ; }//sama inicjalizacja drzewa bez nadawania wartosci wskaznikom left i right
		else if (number == 2) { temp->left = new_node; }//jesli number=2 idziemy na lewo od naszego korzenia
		else if (number == 3) { temp->right = new_node; }//jesli number=3 idziemy na prawo od korzenia
		else {//w tym wypadku potrzebujemy sciezki dzieki ktorej dostaniemy sie do wezla (previousValues)
			for (int i = 0; i < previousValues.size() - 1; i++) {
				if (previousValues[i] % 2 == 1) temp = temp->right; //w tym miejscu previousValues sie przydaje, jesli wartosci na i-tym
				else temp = temp->left;	//miejscu jest nieparzysta posuwamy sie w prawo (right), a jesli parzysta to w lewo

			}
			if (number % 2 == 1)temp->right = new_node; //przypisanie wartosci wskaznika prawego jesli numer wezla jest nieparzysty
			else temp->left = new_node; //przypisanie wartosci wskaznika lewego jesli numer wezla jest parzysty
		}


		cout << endl << "Wezel zostal dodany poprawnie!";


		_getch();
		system("cls");
	}