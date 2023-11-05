#pragma once
#include <iostream>
#include <fstream>
using namespace std;


enum Type
{
	BOOK, NEWSPAPER,JOURNAL,NONE
};
const int SIZE = 100;
struct Item
{
	Type type = NONE;
	char name[SIZE];
	char author[SIZE];
	char genre[SIZE];
	int year;
};

Item* readFile(string fname, int& size);
void writeFile(string fname, Item* list, int size);
void writeItem(string fanme, Item item);
void printLibrary(Item* list, int size);
void enterItem(Item& item,Type type);
void printBook(Item item);
void printNewspaper(Item item);
void printJournal(Item item);
void enterBook(Item& item);
void enterNews(Item& item);
void enterJournal(Item& item);
void fillLibrary(Item*& list, int& size, int number);

