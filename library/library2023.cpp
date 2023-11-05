#include <iostream>
#include "library.h"
using namespace std;

int main()
{

    int choice;
    int size = 0;
    string fname = "db.txt";
    Item* library = readFile(fname,size);
    while (true)
    {
        cout << "\n\t 1 - Fill library;\n\t 2 - Print Library; \n\t 3 - Add new Item; \n\t 4 - Sort; \n\t 5 - Find; \n\t 6 - Select item; \n\t 7 - Number of category; \n\t 8 - Delete item; \n\t 0 - Exit; \n\t\t Enter ::  ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice)
        {
        case 1:{
            int number;
            cout << "Enter number :: ";
            cin >> number;
            fillLibrary(library, size, number);
            printLibrary(library,size);
            writeFile(fname,library,size);
            break;
        }
        case 2:{
            printLibrary(library, size);
            break;
        }
        case 3: {
            int category;
            cout << " 1 - Book ; \t 2 - Newspaper ; \t 3 - Journal ; \n\t Enter :: ";
            cin >> category;
            Type type;
            Item item;
            switch (category)
            {
            case 1: type = Type::BOOK; break;
            case 2: type = Type::NEWSPAPER; break;
            case 3: type = Type::JOURNAL; break;
            }
            cin.ignore();
            enterItem(item, type);
            writeItem(fname, item);
            delete[]library;
            library = readFile(fname, size);
            printLibrary(library, size);
            break;
        }
        /*case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 0:
        default:
            break;*/
        }
    }
   
}

//Item* readFile(string fname, int& size)
//{
//    ifstream file(fname);
//    if (!file.is_open()) {
//        cout << "Library is empty" << endl;
//        return nullptr;
//    }
//    file.seekg(0, ios_base::end);
//    size = file.tellg() / sizeof(Item);
//    //file.ignore() ??
//    file.seekg(0);
//    /*Item tmp;*/
//    Item* lib = new Item[size];
//    int counter = 0;
//    while (file.read((char*)&lib[counter++], sizeof(Item)));
//    {
// /*       lib[counter++] = tmp;*/
//    }
//    return lib;
//}
//
//void writeFile(string fname, Item* list, int size)
//{
//    ofstream file(fname);
//    if (!file.is_open()) {
//        cout << "Library is empty" << endl;
//        return ;
//    }
//    int counter = 0;
//    while (counter < size)
//    {
//        file.write((char*)&list[counter++], sizeof(Item));
//    }
//
//}
//
//void writeItem(string fname, Item item)
//{
//    ofstream file(fname, ios_base::app);
//    if (!file.is_open()) {
//        cout << "Error" << endl;
//        return;
//    }
//    file.write((char*)&item, sizeof(Item));
//
//}
//
//void printLibrary(Item* list, int size)
//{
//    cout << "========================= Print Library=================\n\n";
//    for (size_t i = 0; i < size; i++)
//    {
//        if (list[i].type == Type::BOOK) {
//            printBook(list[i]);
//        }
//        else if (list[i].type == Type::NEWSPAPER) {
//            printNewspaper(list[i]);
//        }
//        else if (list[i].type == Type::JOURNAL) {
//            printJournal(list[i]);
//        }
//    }
//}
//
//void enterItem(Item& item,Type type)
//{
//    if (type == Type::BOOK) {
//        enterBook(item);
//    }
//    else if (type == Type::NEWSPAPER) {
//        enterNews(item);
//    }
//    else if (type == Type::JOURNAL) {
//        enterJournal(item);
//    }
//}
//
//void printBook(Item item)
//{
//    cout << "===================" <<item.name << "=====================" << endl;
//    cout << "\t Category :: Book " << endl;
//    cout << "\t Author   :: "<<item.author << endl;
//    cout << "\t Genre    :: "<<item.genre << endl;
//}
//
//void printNewspaper(Item item)
//{
//    cout << "===================" << item.name << "=====================" << endl;
//    cout << "\tCategory  :: Newspaper " << endl;
//    cout << "\tYear      :: " << item.year << endl;
//    
//}
//
//void printJournal(Item item)
//{
//    cout << "===================" << item.name << "=====================" << endl;
//    cout << "\tCategory  :: Journal " << endl;
//    cout << "\tYear      :: " << item.year << endl;
//}
//
//void enterBook(Item& item)
//{
//    cout << "=================== New Item =====================" << endl;
//    item.type = Type::BOOK;
//    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
//    cout << "\t Author  :: "; cin.getline(item.author, SIZE);
//    cout << "\t Genre   :: "; cin.getline(item.genre, SIZE);
//}
//
//void enterNews(Item& item)
//{
//    cout << "=================== New Item =====================" << endl;
//    item.type = Type::NEWSPAPER;
//    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
//    cout << "\t Year  :: "; cin>>item.year;
//    cin.ignore();
//}
//void enterJournal(Item& item)
//{
//    cout << "=================== New Item =====================" << endl;
//    item.type = Type::JOURNAL;
//    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
//    cout << "\t Year  :: "; cin >> item.year;
//    cin.ignore();
//}
//
//void fillLibrary(Item*& list, int& size, int number)
//{
//    if (list == nullptr) {
//        size = number;
//        Item* tmp = new Item[size];
//        int choice;
//        for (size_t i = 0; i < size; i++)
//        {
//            while (true)
//            {
//                cout << " 1 - Book; \t 2 - Newspaper; \t 3 - Journal; \n\t Enter ::";
//                cin >> choice;
//                if (choice >= 1 && choice <= 3)break;
//            }
//            Type type;
//            switch (choice)
//            {
//            case 1: type = Type::BOOK; break;
//            case 2: type = Type::NEWSPAPER; break;
//            case 3: type = Type::JOURNAL; break;
//            default:
//                break;
//            }
//            cin.ignore();
//            enterItem(tmp[i], type);
//        }
//        return;
//    }
//}

