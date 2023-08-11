#ifndef TREE_H
#define TREE_H
#include <vector>
#include "Node.h"
#include "Book.h"

class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string title);
   bool Insert(Book title);
   bool Delete(string title);
   //void Balance(Node* &Tree, string title, string low, string high); 
   void Print();
   int Count();
   int Height();
   //void balance(Node* &ptr, vector<Book> book, int low, int high); 
   //void balance_tree(); 
   void balance(); 
   
 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string title, Node * Tree);
   bool InsertHelper(Book title, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string title, Node * &Tree);
   void PrintHelper(Node * Tree);
   int CountHelper(Node * Tree);
   int HeightHelper(Node * Tree);
   //void extract(Node* ptr, Book data[], int &index); 
   //void balance(Node* &ptr, Book data[], int low, int high); 
   void tranversal(Node * tree, vector<Book>& values); 
   Node* balanceHelper(vector<Book>& values, int start, int end);

   // Tree pointer
   Node *Root;
};

#endif