#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Book.h"
#include "Node.h"
#include "Tree.h"

using namespace std;

void readFile(const string filename, BinaryTree &tree){
    //Account account; 
    //ifstream inFS(filename);     // Input file stream
    string year;
    string title;
    string lastName;
    string firstName;
    string genre;
    string rating;
    
    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return;
    }
    while(getline(din, year, ','))
    {
        getline(din, title, ',');
        getline(din, lastName, ','); 
        getline(din, firstName, ','); 
        getline(din, genre, ','); 
        getline(din, rating);
        Book object(stoi(year), title, lastName, firstName, genre, stof(rating)); 
        //object.print(); 
        tree.Insert(object);
        //tree.push_back(temp);
    }
 
    din.close();
}

int main() {
    vector<Book> books;
    BinaryTree tree; 
    //readFile("books.txt", books);
    int userInput; 
    string userInputTitle; 
    
    bool quit = false; 
    while(quit == false){
        cout << endl << "Menu " << endl;
        cout << "1. Load " << endl; 
        cout << "2. Search "<< endl; 
        cout << "3. Insert " << endl; 
        cout << "4. Delete "<< endl; 
        cout << "5. Print " << endl; 
        cout << "6. Quit " << endl; 
        cin >> userInput; 
        
        switch (userInput){
            case 1: 
                readFile("books.txt", tree); 
                break; 
            case 2: 
                cin.ignore(); 
                cout << "What is the title of the book you want to search for? " << endl; 
                getline(cin, userInputTitle); 
                if(tree.Search(userInputTitle)){
                    cout << "Book found!" << endl; 
                }
                else{
                    cout << "Book was not found. " << endl; 
                }
                break; 
            case 3: {
                cin.ignore(); 
                string year; 
                string title; 
                string lastName; 
                string firstName; 
                string genre; 
                string rating; 
                cout << "Insert year: "; 
                getline(cin, year); 
                cout << "Insert title: "; 
                getline(cin, title); 
                cout << "Insert last name: "; 
                getline(cin, lastName); 
                cout << "Insert firstName: "; 
                getline(cin, firstName); 
                cout << "Insert genre: "; 
                getline(cin, genre); 
                cout << "Insert rating: "; 
                getline(cin, rating); 
                Book object(stoi(year), title, lastName, firstName, genre, stof(rating)); 
                if(tree.Insert(object)){
                    cout << "Insert was successful!" << endl; 
                } 
                else{
                    cout << "Insert failed. " << endl; 
                }
                break; }
            case 4: 
                cin.ignore(); 
                cout << "Please insert the title of the book you want to delete: "; 
                getline(cin, userInputTitle); 
                if(tree.Delete(userInputTitle)){
                    cout << "Book deleted! " << endl; 
                } 
                else{
                    cout << "Deletion failed" << endl; 
                }
                break; 
            case 5: 
                    tree.balance(); 
                    tree.Print(); 
                    break;
            case 6: 
                    quit = true; 
                    break; 
            default: 
                    cout << "This is not an option! Try again! " << endl; 
                    break; 
        }
    }
    return 0;
}
