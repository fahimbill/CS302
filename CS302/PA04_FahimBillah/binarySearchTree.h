//Fahim Billah

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binaryNode.h"

class BinarySearchTree
{
  public:
    BinarySearchTree();
    BinarySearchTree(const int rootItem);
    int getHeight(BinaryNode* subTree) const;
    int getRoot() const;
    void setRoot(const int item);
    bool add(const int item);

    void preorderTraverse(BinaryNode* subTree) const;
    void inorderTraverse(BinaryNode* subTree) const;
    void postorderTraverse(BinaryNode* subTree) const;

   public:
      BinaryNode* root;
};

#endif
