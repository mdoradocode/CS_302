#include <iostream>
#include <cstring>
#include "NodeList.h"
#include "Node.h"

using namespace std;
void menu();

int main(){
    int select = 1;
    NodeList<int> list;
    int data;
    while(select != 0){
        menu();
        cin >> select;
        switch(select){
            case 0:
            break;
            case 1:
            cout << "Please enter the item you would like to add to the list: ";
            cin >> data;
            list.push(data);
            cout << "The data has been added!" << endl;
            break;
            case 2: //If you look at my code this close check out my pop function cause im acutally really proud of how i tracked the nodes
            cout << "Please enter the data you would like to erase from the list: ";
            cin >> data;
            list.pop(data);
            cout << "The data has been deleted!" << endl;
            break;
            case 3:
            cout << "The number of nodes in this list is: " << list.count() << endl;
            break;
            case 4:
            cout << "Here is the whole list, enjoy!" << endl;
            cout << list;
        }
    }
    return 0;
}

void menu(){
    cout << "==============================\n"<<
    "Please make the number for the selection of what you would like to do: " << 
    " \n1) Add a new item to the list \n2) Delete every instance of an item in the list \n3) Count the number of items in the list\n4) Display the list\n"  <<
    "Or enter 0 (zero) to exit the program\n" << 
    "============================== "<< endl;
}