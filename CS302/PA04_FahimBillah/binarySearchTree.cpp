//Fahim Billah

#include "binarySearchTree.h"
#include "binaryNode.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

//Default Constructor
BinarySearchTree::BinarySearchTree(){
  root = NULL;
}

//Param Construcotr
BinarySearchTree::BinarySearchTree(const int rootItem){
  root -> data = rootItem;
}

//Getters/Setters
int BinarySearchTree:: getRoot() const{
  return root -> data;
}

void BinarySearchTree::setRoot(const int item){
  root -> data = item;
}

//Adds values into the tree
bool BinarySearchTree::add( const int item ){
  BinaryNode* temp = new BinaryNode(item);

  // check if tree is empty
  if( root == NULL ){
    root = temp;
    return true;
  }
   //Else we keep filling the tree
  else{
    BinaryNode* current = root;
    BinaryNode* parent = root;

    //Check/Add left or right
    if(temp->data < current->data){
      current = current->leftChild;
    }

    else{
      current = current->rightChild;
    }

      // check whether to go right or left
      while(current != NULL){
         parent = current;

         if(temp->data < current->data){
            current = current->leftChild;
         }

         else{
           current = current->rightChild;
         }
      }

  // check whether to go right or left
  if(temp->data < parent->data)
  {
    parent->leftChild = temp;
  }

  else{
    parent->rightChild = temp;
  }

      // return successful add operation
  return true;
   }
}

//preorderTraverse Implementation
void BinarySearchTree::preorderTraverse(BinaryNode* subTree) const{
  //Safety Check
  if(subTree != NULL){
    cout << subTree->data << ' ';
    // traverse left and right children
    preorderTraverse(subTree->leftChild);
    preorderTraverse(subTree->rightChild);
   }
}

//inorderTraverse Implementation
void BinarySearchTree::inorderTraverse(BinaryNode* subTree) const{
  //Safety Check
  if(subTree != NULL)
  {
    // traverse left child
    inorderTraverse(subTree->leftChild);
    // output data at node
    cout << subTree->data << ' ';
    // traverse right right
    inorderTraverse(subTree->rightChild);
   }
}

//postorderTraverse Implementation
void BinarySearchTree::postorderTraverse(BinaryNode* subTree) const{
  //Safety Check
  if(subTree != NULL){
    // traverse left and right children
    postorderTraverse(subTree->leftChild);
    postorderTraverse(subTree->rightChild);
    cout << subTree->data << ' ';
   }
}

int BinarySearchTree::getHeight(BinaryNode* subTree) const{
  if( subTree == NULL )
  {
     return 0;
  }

  // find max between heights of left and right subtrees
  return (1 + (getHeight(subTree->leftChild) + getHeight(subTree->rightChild)));
}
