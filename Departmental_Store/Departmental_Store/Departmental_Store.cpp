#include<iostream>
#include<cstring>
using namespace std;
//this is for tile only
void departmentalStore()
{
    cout << "\n\n\t\tDepartmental Store Management System\n\n" << endl;
}
//this is for displaying menu only
void DisplayMenu()
{
    cout << "\n\n **********   Menu   **********\n" << endl;
    cout << " 1) Press 1 for Inserting an item." << endl;
    cout << " 2) Press 2 for Displaying items in a shelf." << endl;
    cout << " 3) Press 3 for Remove an item." << endl;
    cout << " 4) Press 4 for Remove all items." << endl;
    cout << " 5) Press 5 for Return total number of items in specified shelf." << endl;
    cout << " 6) Press 6 for Return total number of items in all shelves." << endl;
    cout << " 7) Press 7 for Find an item." << endl;
    cout << " 8) Press 8 for Updating an item." << endl;
    cout << " 9) Press 9 to check if a shelf is empty." << endl;
    cout << " 10) Press 10 to check if a shelf is full." << endl;
    cout << " 11) Press 0 to Quit.\n\n" << endl;
}
//for validity of shelves
void correctInputShelve(int numOfShelves, int k)
{
    //will run till it get shelve k value within range entered
    while (k < 1 || k > numOfShelves)
    {
        cout << "You entered shelf that dont exist:" << endl;
        cout << "Enter shelf number again between (" << 1 << "-" << numOfShelves << "): \n" << endl;
        cout << "Enter Shelf:";
        cin >> k;
    }
    cout << endl;
}
//for validty of positions
void correctInputPositions(int numOfPositions, int p)
{
    //will run till it get position p value within range entered
    while (p < 1 || p > numOfPositions)
    {
        cout << "You entered Position that dont exist:" << endl;
        cout << "Enter Position number again between (" << 1 << "-" << numOfPositions << "): \n" << endl;
        cout << "Enter Position: ";
        cin >> p;
    }
}
//for checking if specific shelf is empty
bool emptyShelve(char*** storeManage, int shelf, int numOfPositions)
{
    int counter = 0;
    bool empty = false;
    for (int b = 0; b < numOfPositions; b++)
    {
        if (storeManage[shelf - 1][b][0] != '\0')
        {
            counter++;
        }
    }
    if (counter == 0)
    {
        empty = true;
    }
    return empty;
}
//for getting number of items stored in a specific shelf 
int NumberOfItemInShelf(char*** storeManage, int shelf, int numOfPositions)
{
    int TotalItemsInShelf = 0;
    for (int a = 0; a < numOfPositions; a++)
    {
        if (storeManage[shelf - 1][a][0] != '\0')
        {
            TotalItemsInShelf++;
        }
    }
    return TotalItemsInShelf;
}
//for getting number of items stored in all shelves
int NumberOfItemInAllShelves(char*** storeManage, int numOfShelves, int numOfPositions)
{
    int TotalItems = 0;
    for (int a = 0; a < numOfShelves; a++)
    {
        for (int b = 0; b < numOfPositions; b++)
        {
            if (storeManage[a][b][0] != '\0')
            {
                TotalItems++;
            }
        }
    }
    return TotalItems;
}
//for checking wether the shelf is full or not
bool fullShelve(char*** storeManage, int shelf, int numOfPositions)
{
    int counter = 0;
    bool full = false;
    for (int b = 0; b < numOfPositions; b++)
    {
        if (storeManage[shelf - 1][b][0] != '\0')
        {
            counter++;
        }
    }
    if (counter == numOfPositions)
    {
        full = true;
    }
    return full;
}
//for storing item in specific shelf and specific position
void insertItem(char*** storeManage, int shelf, int position, int numOfPositions)
{
    // Check if shelf is full
    if (fullShelve(storeManage, shelf, numOfPositions))
    {
        cout << "The shelf is full. Cannot place item." << endl;
    }
    else
    {
        // Check if the specified position is empty
        if (storeManage[shelf - 1][position - 1][0] == '\0')
        {
            cout << "Enter Item: ";
            cin.ignore();
            cin.getline(storeManage[shelf - 1][position - 1], 20);
            cout << "Item added successfully. " << endl;
            return;
        }
        else
        {
            // Find the first available empty position in the shelf
            for (int a = 0; a < numOfPositions; a++)
            {
                if (storeManage[shelf - 1][a][0] == '\0')
                {
                    cout << "Enter Item: ";
                    cin.ignore();
                    cin.getline(storeManage[shelf - 1][a], 20);
                    cout << "Item stored at position " << a + 1 << " because your entered position was already occupied." << endl;
                    cout << "Item added successfully." << endl;
                    break;
                }
            }
        }
    }
}
//for removing all items from all shelves
void RemoveAllItems(char*** storeManage, int numOfShelves, int numOfPositions)
{
    for (int a = 0; a < numOfShelves; a++)
    {
        for (int b = 0; b < numOfPositions; b++)
        {
            storeManage[a][b][0] = '\0';
        }
    }
    cout << "All items removed successfully.\n" << endl;
}
//for removing specified shelf items 
void RemoveAnItem(char*** storeManage, int shelf, int Position)
{
    storeManage[shelf - 1][Position - 1][0] = '\0';
    cout << "Item removed successfully.\n" << endl;
}
//for displaying all items in a specified shelf
void DisplayItem(char*** storeManage, int shelf, int numPositions)
{
    cout << "\n\nItems in Shelf " << shelf << ":\n" << endl;

    for (int b = 0; b < numPositions; b++)
    {
        if (storeManage[shelf - 1][b][0] != '\0')
        {
            cout << "Position: " << b + 1 << " : " << storeManage[shelf - 1][b] << endl;
        }
    }
    if (emptyShelve(storeManage, shelf, numPositions))
    {
        cout << "Shelf " << shelf << " is empty. " << endl;
    }
}
void toLowerCase(char* arr)
{
    for (int a = 0; a < strlen(arr); a++)
    {
        if (arr[a] >= 'A' && arr[a] <= 'Z')
        {
            arr[a] += 32;
        }
    }
}
//for checking if two cstrings are equal
bool equalArrays(char*** storeManage, int shelf, int position, char* item)
{
    int counter;
    if (strlen(storeManage[shelf][position]) == strlen(item))
    {
        toLowerCase(storeManage[shelf][position]);
        toLowerCase(item);
        counter = 0;
        for (int c = 0; c < strlen(item); c++)
        {
            if (storeManage[shelf][position][c] == item[c])
            {
                counter++;
            }
        }
        if (counter == strlen(item))
        {
            return true;
        }
    }
    return false;
}
//for find specific item with name in all shelf
void findItem(char*** storeManage, int numOfShelves, int numOfPositions)
{
    char item[20];
    bool found = false;
    cout << "Enter item name to find: ";
    cin.ignore();
    cin.getline(item, 20);
    for (int a = 0; a < numOfShelves; a++)
    {
        for (int b = 0; b < numOfPositions; b++)
        {
            if (equalArrays(storeManage, a, b, item))
            {
                cout << item << " found At : " << endl;
                cout << "Shelf: " << a + 1 << endl;
                cout << "Position: " << b + 1 << endl;
                found = true;
                return;
            }
        }
    }
    if (!found)
    {
        cout << "Item " << item << " not found" << endl;
        return;
    }
}
//for updating specific item at specific position with other
void updateItemAtPosition(char*** storeManage, int shelve, int position)
{
    cout << "Enter item to update with : ";
    cin.ignore();
    cin.getline(storeManage[shelve - 1][position - 1], 20);
    cout << "Shelf updated!" << endl;
}
int main()
{
    //here compiler will start compiling
    int numOfShelves, numOfPositions;
    bool quit = false;
    int choice, k, p;
    //this is for title only not much
    departmentalStore();

    cout << "Enter the number of shelves: ";
    cin >> numOfShelves;
    cout << "Enter the number of positions on each shelf: ";
    cin >> numOfPositions;
    //declaring 3d array with tripple pointers
    //reason here to use tripple pointers is dimension 1 represents number of shelves
    //dimension two represents shelves as we know there for two dimension
    //there is a 1d array at each element of 1d array
    //So if we want to store item name at in 2d array we cant by cstring because cstring
    //is itself an array we can only store 1 character in 2d array at each element 
    //if 2d array is used we can only store a first character of item
    //to tackle this we will create 3d array by tripple pointers one will represent 
    //shelves, 2nd will represent position, and 3rd will represent item name complete
    //In simple words we can say that 3d array is just 1d array with its each element
    //present 2d array
    char*** storeManage = new char** [numOfShelves];
    for (int a = 0; a < numOfShelves; a++)
    {
        storeManage[a] = new char* [numOfPositions];
        for (int b = 0; b < numOfPositions; b++)
        {
            storeManage[a][b] = new char[20];
            storeManage[a][b][0] = '\0';
        }
    }
    while (!quit)
    {
        DisplayMenu();
        choice = -1;
        while (choice < 0 || choice > 10)
        {
            cout << "Enter Choice: ";
            cin >> choice;

            if (choice < 0 || choice > 9)
            {
                cout << "Invalid choice. Enter a choice between 0 and 9." << endl;
            }
        }
        switch (choice)
        {
        case 0:
            //for exiting program
            quit = true;
            cout << "Thank you! for using this application." << endl;
            break;
        case 1:
            //for storing items
            cout << "Enter Shelf: ";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            cout << "Enter Position: ";
            cin >> p;
            correctInputPositions(numOfPositions, p);
            insertItem(storeManage, k, p, numOfPositions);
            break;
        case 2:
            //for displaying all items in specified shelf
            cout << "Enter Shelf: ";
            cin >> k;
            DisplayItem(storeManage, k, numOfPositions);
            break;
        case 3:
            //for removing an item from specific shelf and position
            cout << "Enter Shelf: ";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            cout << "Enter Position: ";
            cin >> p;
            correctInputPositions(numOfPositions, p);
            RemoveAnItem(storeManage, k, p);
            break;
        case 4:
            //for removing all items from all shelves and positions
            RemoveAllItems(storeManage, numOfShelves, numOfPositions);
            break;
        case 5:
            //for displaying total number of items store in a shelf
            cout << "Enter Shelf: ";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            cout << "total Items In Shelf " << k << " : " << NumberOfItemInShelf(storeManage, k, numOfPositions) << endl;
            break;
        case 6:
            //for displaying total number of items store in all shelves 
            cout << "total Items In All Shelves: " << NumberOfItemInAllShelves(storeManage, numOfShelves, numOfPositions) << endl;
            break;
        case 7:
            //for finding a specific item
            findItem(storeManage, numOfShelves, numOfPositions);
            break;
        case 8:
            //for updating item at specific shelf and position
            cout << "Enter shelf no to update :";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            cout << "Enter position: ";
            cin >> p;
            correctInputPositions(numOfPositions, p);
            updateItemAtPosition(storeManage, k, p);
            break;
        case 9:
            //for checking if specific shelf is empty or not
            cout << "Enter Shelf: ";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            if (emptyShelve(storeManage, k, numOfPositions))
            {
                cout << "Shelf " << k << " is empty. " << endl;
            }
            else
            {
                cout << "Shelf " << k << " is not empty. " << endl;
            }
            break;
        case 10:
            //for checking if specific shelf is full or not
            cout << "Enter Shelf: ";
            cin >> k;
            correctInputShelve(numOfShelves, k);
            if (fullShelve(storeManage, k, numOfPositions))
            {
                cout << "Shelf " << k << " is full. " << endl;
            }
            else
            {
                cout << "Shelf " << k << " is not full. " << endl;
            }
            break;
        }
    }
    //dynamically 3d array deleted
    for (int i = 0; i < numOfShelves; i++)
    {
        for (int j = 0; j < numOfPositions; j++)
        {
            delete[] storeManage[i][j];
        }
        delete[] storeManage[i];
    }
    delete[] storeManage;

    return 0;
}
