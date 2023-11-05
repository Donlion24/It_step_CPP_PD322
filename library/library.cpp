#include "library.h"

Item* readFile(string fname, int& size)
{
    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Library is empty" << endl;
        return nullptr;
    }
    file.seekg(0, ios_base::end);
    size = file.tellg() / sizeof(Item);
    //file.ignore() ??
    file.seekg(0);
    /*Item tmp;*/
    Item* lib = new Item[size];
    int counter = 0;
    while (file.read((char*)&lib[counter++], sizeof(Item)));
    {
        /*       lib[counter++] = tmp;*/
    }
    return lib;
}

void writeFile(string fname, Item* list, int size)
{
    ofstream file(fname);
    if (!file.is_open()) {
        cout << "Library is empty" << endl;
        return;
    }
    int counter = 0;
    while (counter < size)
    {
        file.write((char*)&list[counter++], sizeof(Item));
    }

}

void writeItem(string fname, Item item)
{
    ofstream file(fname, ios_base::app);
    if (!file.is_open()) {
        cout << "Error" << endl;
        return;
    }
    file.write((char*)&item, sizeof(Item));

}

void printLibrary(Item* list, int size)
{
    cout << "========================= Print Library=================\n\n";
    for (size_t i = 0; i < size; i++)
    {
        if (list[i].type == Type::BOOK) {
            printBook(list[i]);
        }
        else if (list[i].type == Type::NEWSPAPER) {
            printNewspaper(list[i]);
        }
        else if (list[i].type == Type::JOURNAL) {
            printJournal(list[i]);
        }
    }
}

void enterItem(Item& item, Type type)
{
    if (type == Type::BOOK) {
        enterBook(item);
    }
    else if (type == Type::NEWSPAPER) {
        enterNews(item);
    }
    else if (type == Type::JOURNAL) {
        enterJournal(item);
    }
}

void printBook(Item item)
{
    cout << "===================" << item.name << "=====================" << endl;
    cout << "\t Category :: Book " << endl;
    cout << "\t Author   :: " << item.author << endl;
    cout << "\t Genre    :: " << item.genre << endl;
}

void printNewspaper(Item item)
{
    cout << "===================" << item.name << "=====================" << endl;
    cout << "\tCategory  :: Newspaper " << endl;
    cout << "\tYear      :: " << item.year << endl;

}

void printJournal(Item item)
{
    cout << "===================" << item.name << "=====================" << endl;
    cout << "\tCategory  :: Journal " << endl;
    cout << "\tYear      :: " << item.year << endl;
}

void enterBook(Item& item)
{
    cout << "=================== New Item =====================" << endl;
    item.type = Type::BOOK;
    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
    cout << "\t Author  :: "; cin.getline(item.author, SIZE);
    cout << "\t Genre   :: "; cin.getline(item.genre, SIZE);
}

void enterNews(Item& item)
{
    cout << "=================== New Item =====================" << endl;
    item.type = Type::NEWSPAPER;
    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
    cout << "\t Year  :: "; cin >> item.year;
    cin.ignore();
}
void enterJournal(Item& item)
{
    cout << "=================== New Item =====================" << endl;
    item.type = Type::JOURNAL;
    cout << "\t Name    :: "; cin.getline(item.name, SIZE);
    cout << "\t Year  :: "; cin >> item.year;
    cin.ignore();
}
void fillLibrary(Item*& list, int& size, int number)
{
    if (list == nullptr) {
        size = number;
        list = new Item[size];
        int choice;
        for (size_t i = 0; i < size; i++)
        {
            while (true)
            {
                cout << " 1 - Book; \t 2 - Newspaper; \t 3 - Journal; \n\t Enter :: ";
                cin >> choice;
                if (choice >= 1 && choice <= 3)break;
            }
            Type type;
            switch (choice)
            {
            case 1: type = Type::BOOK; break;
            case 2: type = Type::NEWSPAPER; break;
            case 3: type = Type::JOURNAL; break;
            }
            cin.ignore();
            enterItem(list[i], type);
        }
        return;
    }
        Item* tmp = new Item[size + number];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = list[i];
        }
        int choice;
        for (size_t i = size; i < size + number; i++)
        {
            while (true)
            {
                cout << " 1 - Book; \t 2 - Newspaper; \t 3 - Journal; \n\t Enter :: ";
                cin >> choice;
                if (choice >= 1 && choice <= 3)break;
            }
            Type type;
            switch (choice)
            {
            case 1: type = Type::BOOK; break;
            case 2: type = Type::NEWSPAPER; break;
            case 3: type = Type::JOURNAL; break;
            }
            cin.ignore();
            enterItem(tmp[i], type);
        }
        delete[]list;
        size += number;
        list = tmp;
    }
