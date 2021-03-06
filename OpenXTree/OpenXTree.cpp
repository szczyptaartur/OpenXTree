// OpenXTree.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "TreeNode.h"
#include <vector>
#include <windows.h>
#include <string>
#include "TreeRoot.h"
#include "check.h"
#include "adding.h"


using namespace std;


void gotoxy(const int x, const int y) //funkcja ktora ustawia kursor na odpowiednich wspolrzednych
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Instrukcja() {
	cout << "Pierwsza opcja w menu jak nazwa wskazuje dodaje wezel do drzewa, drzewo jest inicjalizowane wezlem o indeksie \n";
	cout << "nastepnie w kolejnym rzedzie wezly sa o indeksach 2 i 3, w kolejnym 4, 5 wychodzace z wezla nr. 2 i 6, 7 \nwychodzace z wezla nr.3";
	cout << "itd. Wartosci w wezlach moga byc tylko liczbami calkowitymi, wiec po wpisaniu \nnp wartosci 3.14 zostanie ona obcieta do liczby";
	cout << "calkowitej. Podobnie jest z indeksami, po wpisaniu 4.5 zostanie \non obciety do 4, i jesli jest mozliwe dodanie takiego takiego";
	cout << "indeksu program zrobi to. Natomiast po wpisaniu \njakichs literek typu 'dadad' zostanie wyrzucony blad i trzeba bedzie wpisac";
	cout << "wartosc ponownie.\n\n\n\n";

	cout << "Druga opcja wypisuje na ekran sume, srednia oraz mediane wybranego poddrzewa. Nie wiem czy dobrze zrozumialem, \nale jako";
	cout << "poddrzewo mam na mysli drzewo generowane przez wybrany wierzcholek. Dlatego po wybraniu tej opcji \nwyskakuje mozliwosc wyboru";
	cout << "indeksu wezla. Przykladowo po wybraniu indeksu 5, o ile istnieje zostana policzone \nsuma, srednia i mediana dla drzewa, ktore";
	cout << "jest generowane przez przez ten wierzcholek nr. 5, bedzie on traktowany \njako korzen.";

	_getch();

}

void Exit()
{
	exit(0);
}

int main()
{
	vector <int> numbersArray;
	TreeRoot root;
	vector <int> numbers; //wektor z zapisanymi juz miejscami 
	vector <TreeNode> Nodes;
	check checkFunction;
	adding add;

	int wybor;
	int poprzedniWybor;
	bool wykonujPetle;

start:

	///pętla główna programu
	while (1)
	{
		wybor = 0;
		poprzedniWybor = wybor;
		wykonujPetle = true;

		///rysowanie menu
		system("cls");
		gotoxy(3, 1);
		cout << "Dodaj wezel";
		gotoxy(3, 3);
		cout << "Srednia, suma, mediana";
		gotoxy(3, 5);
		cout << "Instrukcja";
		gotoxy(3, 7);
		cout << "Wyjscie";
		gotoxy(46, 10);
		cout << "Artur Szczypta " << char(1);
		gotoxy(46, 11);
		cout << "Kontakt: szczypta.artur@gmail.com";

		//ponizszy kod jest moim menu, ktorego kod mozna znalezc na githubie, w bardziej zaawansowej wersji

		///przesuwanie strzalki
		while (wykonujPetle)
		{
			///rysowanie strzalki wyboru
			gotoxy(1, wybor * 2 + 1);
			cout << static_cast < char >(1);

			///obsługa klawiatury
			poprzedniWybor = wybor;
			switch (_getch())
			{
			case 224: //STRZAŁKI
				switch (_getch())
				{
				case 72: ///strzałka w gore
					if (0 < wybor) wybor--;
					else wybor = 3;

					break;

				case 80: ///strzalka w dol
					if (wybor < 3) wybor++;
					else wybor = 0;

					break;
				}
				break;
			case 13: ///strzalka w prawo
					 ///jeżeli wcisnieto strzalke w prawo, sprawdz wybrana opcje i wykonaj odpowiednia akcje
				switch (wybor)
				{
				case 0:
					system("cls");
					add.addNode(numbers, root);
					goto start;

				case 1:
					system("cls");
					checkFunction.SSM(root, numbers);
					goto start;

				case 2:
					system("cls");
					Instrukcja();
					goto start;
				case 3:
					return 0;

				}
				break;
			}


			///czyszczenie strzałki wyboru
			gotoxy(1, poprzedniWybor * 2 + 1);
			cout << " ";
		}
	}
	return 0;
}
