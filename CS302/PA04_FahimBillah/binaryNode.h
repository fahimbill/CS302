#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class BinaryNode
{
  public:
    BinaryNode();
    BinaryNode(const int item);
    BinaryNode(const int item, BinaryNode* left, BinaryNode* right);
    ~BinaryNode();
    bool isLeaf() const;

  public:
    int data;
    BinaryNode* leftChild;
    BinaryNode* rightChild;
};

//Default Constructor
BinaryNode::BinaryNode(){
   data = -1;
   leftChild = NULL;
   rightChild = NULL;
}

//Sets item
BinaryNode::BinaryNode(const int item)
{
   // set data to parameter and set child pointers to NULL
   data  = item;
   leftChild = NULL;
   rightChild = NULL;
}

//Param Constructor
BinaryNode::BinaryNode(const int item, BinaryNode* left, BinaryNode* right){
  data = item;
  leftChild = left;
  rightChild = right;
}

//Destructor
BinaryNode::~BinaryNode(){
  leftChild = NULL;
  rightChild = NULL;
}

//Checks if node is a leaf
bool BinaryNode::isLeaf() const{
  if( leftChild == NULL && rightChild == NULL ){
    return true;
  }

  else{
    return false;
  }

}

#endif
