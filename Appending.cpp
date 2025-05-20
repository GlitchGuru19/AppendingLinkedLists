#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;
    string sin;
    Person* next;

public:
    // Constructor
    Person(string n, int a, string s)
    {
        this->name = n;
        this->age = a;
        this->sin = s;
        this->next = nullptr;
        cout << "Object created" << endl<< endl;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getSIN() { return sin; }
    Person* getNext() { return next; }

    // Setters
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setSIN(string s) { sin = s; }
    void setNext(Person* n) { next = n; }

    void display()
    {
        cout << "Name: " << name << "\nAge: " << age << "\nSIN: " << sin << endl;
    }
};

class PersonList
{
private:
    Person* head;

public:
    PersonList() : head(nullptr) {}

    // Add a new person at the end of the list
    void appendNode(string name, int age, string sin)
    {
        Person* newPerson = new Person(name, age, sin);

        if (head == nullptr)
        {
            head = newPerson;
        }
        else
        {
            Person* current = head;
            while (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
            current->setNext(newPerson);
        }
    }

    void displayAll()
    {
        Person* current = head;
        cout << "\n\nNames in the List" << endl << endl;
        while (current != nullptr)
        {
            current->display();
            cout << "------------------" << endl;
            current = current->getNext();
        }
    }

    ~PersonList()
    {
        Person* current = head;
        while (current != nullptr)
        {
            Person* next = current->getNext();
            delete current;
            current = next;
            cout << "Object deleted" << endl;
        }
    }
};

int main()
{
    PersonList* list = new PersonList(); // Dynamic allocation

    int choice = 0;
    string name = "";
    int age = 0;
    string sin = "";
    while (true)
    {
        cout << "1. Add Name" << endl;
        cout << "2. Display Names" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice => ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice)
        {
            case 1:
            {
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter SIN: ";
                getline(cin, sin);
                list->appendNode(name, age, sin); // Use -> operator
                break;
            }
            case 2:
            {
                list->displayAll(); // Use -> operator
                break;
            }
            case 3:
            {
                delete list; // Clean up dynamic memory
                return 0;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }

    return 0;
}
