#include "stdafx.h"
#include "check.h"
#include <iostream>
#include "TreeRoot.h"
#include <vector>
#include <conio.h>

using namespace std;

void vectorRest(TreeRoot root, vector <int>& vectors) {//funkcja rekurencyjna wyznaczajaca wektor wartosci wezlow podanego poddrzewa
	TreeNode *temp = new TreeNode(0, 0);			//root to adres korzenia, vectors to pusty wektor w ktorym zapiszemy potrzebne wartosci
	temp = root.rootAdress;//nadanie dynamicznemu obiektowi wartosci poczatkowych
	vectors.push_back(temp->value);
	if (temp->left != 0) { //lewy wskaznik nie jest rowny 0 => jest tam jakas wartosc
		root.rootAdress = temp->left; //odpowiednie przestawienie wskaznika
		vectorRest(root, vectors);//wywolanie funkcji
	}
	if (temp->right != 0) {//prawy wskaznik nie jest rowny 0 => jest tam jakas wartosc
		root.rootAdress = temp->right; //odpowiednie przestawienie wskaznika
		vectorRest(root, vectors); //wywolanie funkcji
	}

}


void check::SSM(TreeRoot & root, vector<int>& numbers) //SSM -suma, srednia, mediana
{
	int nodeNumber;//numer wezla
	vector <int> previousValues;//jak wyzej, wektor wartosci sciezki
	
start:

	cout << "Podaj numer wezla ktory bedzie korzeniem poddrzewa: ";
	cin >> nodeNumber;

	while (cin.fail()) //test sprawdzajacy czy podany numer jest rzeczywiscie numerem (intem)
	{
		cin.clear();//czyszczenie bufora
		cin.sync();
		cin.ignore(1000, '\n');
		cout << "Podaj poprawna liczbe calkowita jako numer wezla: ";
		cin >> nodeNumber;
	}
	
	int k = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == nodeNumber) k = 1;
	}
	if (k == 0) {
		cout << "Taki wezel nie istnieje!   ";
		cin.clear();//czyszczenie bufora
		cin.sync();
		cin.ignore(1000, '\n');
		goto start;
	}


	if (nodeNumber != 1) {//implementacja wektora previousValues odpowiednimi wartosciami
		previousValues.push_back(nodeNumber);
		while (1) {
			if (previousValues[previousValues.size() - 1] / 2 != 1) { previousValues.push_back(previousValues[previousValues.size() - 1] / 2); }
			else break;
		}
	}


	for (int i = 0; i < previousValues.size() / 2; i++) {//jak wyzej z wektora z wartosciami malejacymi, robimy wektor z wartosciami
		int k;													//rosnacymi (dla wygody)
		k = previousValues[i];
		previousValues[i] = previousValues[previousValues.size() - i - 1];
		previousValues[previousValues.size() - i - 1] = k;
	}

	TreeNode *temp = new TreeNode(0, 0);
	temp = root.rootAdress; //stworzenie nowego obiektu dynamicznego i nadanie mu wartosci korzenia


	for (int i = 0; i < previousValues.size(); i++) {//dostanie sie do naszego wezla ktore bedzie wyznaczalo poddrzewo
		if (previousValues[i] % 2 == 1) temp = temp->right;
		else temp = temp->left;
	}

	TreeRoot val;
	val.rootAdress = temp;//stworzenie obiektu i nadanie mu poczatkowych wartosci

	vector <int> vectors;//pusty wektor
	vectorRest(val, vectors);//nasza funkcja rekurencyjna ktora zwraca wektor "vectors" wartosci wezlow naszego poddrzewa.


	for (int i = 0; i < vectors.size(); i++) {//sortowanie babelkowe wartosci wezlow, potrzebne jest to do wyznaczenia mediany
		for (int j = 1; j < vectors.size() - i; j++) {
			if (vectors[j - 1] > vectors[j]) swap(vectors[j - 1], vectors[j]);
		}
	}

	int sumVectors = 0;
	float average, median;

	for (int i = 0; i < vectors.size(); i++) {//suma poddrzewa
		sumVectors += vectors[i];
	}

	if (vectors.size() % 2 == 1)median = float(vectors[vectors.size() / 2]);
	else median = float((vectors[(vectors.size() + 1) / 2] + vectors[(vectors.size() - 1) / 2]) / 2);//mediana poddrzewa

	average = (float)sumVectors / vectors.size(); //srednia poddrzewa

												  //wypisanie tego wszystkiego na ekran
	cout << "\n\nSuma wartosci wezlow w wybranym poddrzewie wynosi: " << sumVectors << endl;
	cout << "Srednia wartosc w wybranym poddrzewie wynosi: " << average << endl;
	cout << "Mediana w wybranym poddrzewie wynosi: " << median;

	_getch();
}

