#include "Tree.h"
#include <cstdlib> 


//CONSTRUCTOR
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//DESTRUCTOR
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

BinaryTree::~BinaryTree()
{
   DestroyHelper(Root);
}

//SEARCH
bool BinaryTree::SearchHelper(string title, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->title.getTitle() == title)
      return true;

   // Recursively search for data value
   else if (Tree->title.getTitle() > title)
      return (SearchHelper(title, Tree->Left));
   else 
      return (SearchHelper(title, Tree->Right));
}

bool BinaryTree::Search(string title)
{
   // Call tree searching function
   return (SearchHelper(title, Root));
}

//INSERT
bool BinaryTree::InsertHelper(Book title, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->title = title;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->title.getTitle() > title.getTitle())
      return (InsertHelper(title, Tree->Left));
   else 
      return (InsertHelper(title, Tree->Right));
}

bool BinaryTree::Insert(Book title)
{
   // Call tree insertion function
   return (InsertHelper(title, Root));
}

//DELETE NODE
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->title.getTitle() = Temp->title.getTitle();
   }

   // Delete node
   delete Temp;
   return true;
}

//DELETE
bool BinaryTree::DeleteHelper(string title, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->title.getTitle() == title)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->title.getTitle() > title)
      return (DeleteHelper(title, Tree->Left));
   else 
      return (DeleteHelper(title, Tree->Right));
}

bool BinaryTree::Delete(string title)
{
   // Call tree deletion function
   return (DeleteHelper(title, Root));
}

//PRINT
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << Tree->title.getTitle() << " \t";

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   
   cout << endl << endl; 
   cout << "Number of Nodes: " << Count() << endl; 
   cout << "Tree Height: " << Height() << endl; 
   cout << endl;
}

//COUNT NODES
int BinaryTree::CountHelper(Node * Tree)
{
    int left=0;
    int right=0;
    if(Tree->Right != NULL){
        right=CountHelper(Tree->Right);
    }
    if(Tree->Left != NULL){
        left=CountHelper(Tree->Left);
    }
    return 1+left+right;
}

int BinaryTree::Count()
{
    if(Root!=NULL){
        return CountHelper(Root);
    }
    
    return 0;
}

//TREE HEIGHT
int BinaryTree::HeightHelper(Node * Tree)
{
    int left=0;
    int right=0;
    
    if(Tree->Left != NULL){
        left=HeightHelper(Tree->Left);
    }
    if(Tree->Right != NULL){
        right=HeightHelper(Tree->Right);
    }
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}

int BinaryTree::Height()
{
    if(Root!=NULL){
        return HeightHelper(Root);
    }
    return 0;
}

//Tree Balance
/*void BinaryTree::extract(Node* ptr, vector<Book> data, int &index){
    // terminating condition
    if (ptr == NULL) return;
    // recursive calls to left and right
    extract(ptr->Left, data, index);
    data[index++] = ptr->title;
    extract(ptr->Right, data, index);
}

void BinaryTree::balance(Node* &ptr,
vector<Book> data, int low, int high)
{
    // terminating condition
    if (low > high) return;
    // insert middle value
    int mid = (low + high) / 2;
    InsertHelper(data[mid], ptr);
    balance(ptr->Left, data, low, mid-1);
    balance(ptr->Right, data, mid+1, high);
}
void BinaryTree::balance_tree(){
    // extract data in sorted order
    vector<Book> data;
    int count = 0;
    extract(Root, data, count);
    // call recursive function to insert data
    Root = NULL;
    count = 0;
    balance(Root, data, 0, count-1);
}
*/

void BinaryTree::tranversal(Node * tree, vector<Book>& values){
       if(tree == NULL){
           return; 
       }
       tranversal(tree->Left, values); 
       values.push_back(tree->title); 
       tranversal(tree->Right, values); 
   }
Node* BinaryTree::balanceHelper(vector<Book>& values, int start, int end){
    if(start>end){
        return NULL; 
    }
    
    int mid = (start + end) / 2; 
    Node* node = new Node(); 
    node->title = values[mid]; 
    node->Left = balanceHelper(values, start, mid-1); 
    node->Right = balanceHelper(values, mid+1, end); 
    return node; 
}
void BinaryTree::balance(){
    vector<Book> values; 
    tranversal(Root, values); 
    
    Root = balanceHelper(values, 0, values.size() - 1);
}

