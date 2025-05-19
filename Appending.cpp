#include <iostream>

using namespace std;

struct Node
{
    string name;
    Node *next;
};

void appendNode(Node *&head, string name)
{
    Node *newNode = new Node;
    Node *nodePtr = nullptr;

    newNode->name = name;
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

int main()
{
    Node *head = nullptr;

    int choice = 0;
    string name = "";
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
                appendNode(head, name);
                break;
            }
        case 2:
            {
                Node *current = nullptr;
                current = head;
                cout << "\n\nNames in the List" << endl << endl;
                while(current)
                {
                    cout << current->name << endl;
                    current = current->next;
                }
                break;
            }
        }
    }

    return 0;
}
