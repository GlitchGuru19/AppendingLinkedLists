#include <iostream>

using namespace std;

class Node
{
public:
    string name;
    string sin;
    Node *next;
};

void appendNode(Node *&head, string name, string sin)
{
    Node *newNode = new Node;
    Node *nodePtr = nullptr;

    newNode->name = name;
    newNode->sin = sin;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head =newNode;
    }
    else
    {
        nodePtr = head;
        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next =newNode;
    }

}

void displayDetails(Node *&head)
{
    Node *current = nullptr;
    current = head;
    cout << "\n\nNames in the List" << endl << endl;
    while(current)
    {
        cout << current->name << endl;
        cout << current->sin << endl;
        current = current->next;
    }
}

int main()
{
    Node *head = nullptr;

    int choice = 0;
    string name = "";
    string sin = "";
    while(true)
    {
        cout << "1. Add Name" << endl;
        cout << "2. Display Names" << endl;
        cout << "Choice => ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                cout<< "Enter name = ";
                cin >> name;
                cout << "Enter SIN = ";
                cin >> sin;
                appendNode(head, name, sin);
                break;
            }
        case 2:
            {
                displayDetails(head);
                break;
            }
        }
    }

    return 0;
}
