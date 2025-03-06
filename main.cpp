/*
  Copyright (c) 2025 Nizar Souit | nsPlan14
*/

#include <iostream>
#include <string>

/*
  IMPLEMENTATION OF A DYNAMIC STRUCTURE WITH FIFO (FIRST IN FIRST OUT) TECHNIQUE
*/

// DO NOT USE this evil line: using namespace std;
using std::cout, std::cin, std::string, std::getline;

// node structure for my dynamic struct
struct Node {
  // structure variables
  // some people
  string name;
  int height;

  // pointer to the next structure to concat them
  Node* pNext = nullptr;  // pointer-next
};

bool isEmpty(Node* pRoot) {
  // function to check if the dynamic structure is emplty
  if (pRoot == nullptr)
    return true;
  return false;
}

int countNodes(Node* pRoot) {
  // function to count how many "nodes" are there
  int i = 0;
  // this for-cycle increments the i variable while pRoot points at something
  for (pRoot; pRoot != nullptr; pRoot = pRoot->pNext)
    i++;
  return i;
}

void printTallerThan(Node* pRoot, int target) {
  // function to print all people taller than the input given by the user in input
  if (isEmpty(pRoot))
    return;

  // while pRoot points at something, it prints it data
  for (pRoot; pRoot != nullptr; pRoot = pRoot->pNext)
    if (pRoot->height >= target)
      cout << "Name: " << pRoot->name << "\tHeight: " << pRoot->height << '\n';
}

void printFirstWithName(Node* pRoot, string name) {
  // function to print the first person (i order of entry) with the name given in input by the user
  if (isEmpty(pRoot))
    return;

  // it continues to search for the first person with the same name
  for (pRoot; pRoot != nullptr; pRoot = pRoot->pNext)
    if (pRoot->name == name) {
      cout << "Name found!\nName: " << pRoot->name << "\tHeight: " << pRoot->height << '\n';
      break;  // breack fhe for-loop once found
    }
    return;
}

void pushNode(Node* &pRoot, Node* pNew) {
  // push a new node inside the structure
  if (pRoot == nullptr) {
    pRoot = pNew;
    return;
  }

  // recursive function: it calls itself until if finds the last saved element and it adds the new one at the bottom
  pushNode(pRoot->pNext, pNew);
  return;
}

void popNode(Node* &pRoot) {
  if (pRoot == nullptr)
    return;   // if the dynamic structure is already empty then it can't be any pop

  Node* pTemp = pRoot->pNext;   // Saving the address of the second element (it can be also null)

  delete(pRoot);  // deleting the old root from the ram

  pRoot = pTemp;  // the new root is the second element
  return;
}

int main() {
  Node* pRoot = nullptr;    // poiter at the head of the dynamic structure
  Node* pNew = new Node;    // node to be passed to function and be added to the dynamic structure

  // variables for the usage of the menu
  int menu;
  int targetHeight;
  string name;

  do {
    cout << "=============== MAIN MENU ===============" << '\n';
    cout << "1. Push Node" << '\n';
    cout << "2. Pop Node" << '\n';
    cout << "3. Check if Node is empty" << '\n';
    cout << "4. Count Nodes" << '\n';
    cout << "5. Count taller than X" << '\n';
    cout << "6. Find name" << '\n';
    cout << "0. Exit" << '\n';
    cout << "User> ";
    cin >> menu;
    cin.ignore();

    switch (menu) {
      case 1:
        // push
        // creates everytime a new Node to save inside the dynamic structure
        pNew = new Node;
        cout << "Insert the name: ";
        getline(cin, pNew->name);

        cout << "Insert the height: ";
        cin >> pNew->height;

        pushNode(pRoot, pNew);
        break;
      case 2:
        // pop
        popNode(pRoot);
        break;
      case 3:
        // Check if Node is empty
        cout << "The dynamic structure is ";
        if (!isEmpty(pRoot))
          cout << "NOT ";
        cout << "empty." << '\n';
        break;
      case 4:
        // Count Nodes
        cout << "There are " << countNodes(pRoot) << " Nodes." << '\n';
        break;
      case 5:
        // Count taller than X
        cout << "Insert the minimun height: ";
        cin >> targetHeight;
        printTallerThan(pRoot, targetHeight);
        break;
      case 6:
        // Find name
        cout << "Insert the name to search: ";
        getline(cin, name);
        printFirstWithName(pRoot, name);
        break;
      case 0:
        // user decides to end the program
        cout << "See you next time!" << '\n';
        break;
      default:
        // user inserted the wrong menu value
        cout << "ERROR! You inserted the wrong value!" << '\n';
        break;
    }

    system("pause");  // works only in windows
    system("cls");    // works only in windows
  } while (menu != 0);

  return 0;
}