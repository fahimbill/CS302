//Fahim Billah
//proj6

#include <iostream>
#include <fstream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

enum COLOR { RED, BLACK };

class Node {
public:
  int value;
  COLOR color;
  Node *left, *right, *parent;

  Node(int value) : value(value) {
  parent = left = right = NULL;
  color = RED; // at insertion the node is red
  }

  Node *uncle() { // This returns the node pointer to the uncle
  if (parent == NULL || parent->parent == NULL)
      return NULL; // returns null if theres no parent or grandparent

  if (parent->isOnLeft())
    return parent->parent->right;
  else
    return parent->parent->left;
  }

  bool isOnLeft() { return this == parent->left; } // Checks if the node is on the left

  Node *sibling() {
  if (parent == NULL)
    return NULL;

  if (isOnLeft())
    return parent->right;

  return parent->left;
  }

  // moves node down and moves given node in its place
  void moveDown(Node *nParent) { // The node moves down and another node takes its place
  if (parent != NULL) {
    if (isOnLeft()) {
      parent->left = nParent;
    }
    else {
      parent->right = nParent;
    }
  }
  nParent->parent = parent;
  parent = nParent;
  }

  bool hasRedChild() { // checks for a red child
  return ((left != NULL && left->color == RED) || (right != NULL && right->color == RED));
  }
  };

class RBTree { // Class for the left leaning red black tree
  Node *root;

  void leftRotate(Node *x) { // rotates that node to the left
  Node *nParent = x->right; // sets a new parent to the right

  if (x == root) // updates the root
    root = nParent;

  x->moveDown(nParent);

  x->right = nParent->left;
  if (nParent->left != NULL)
    nParent->left->parent = x;

  nParent->left = x;
  }

  void rightRotate(Node *x) { // rotates the node to the right
  Node *nParent = x->left;

  if (x == root) // updates the root
    root = nParent;

  x->moveDown(nParent);

  x->left = nParent->right;

  if (nParent->right != NULL)
    nParent->right->parent = x;

  nParent->right = x;
  }

  void swapColors(Node *x1, Node *x2) { // This function swaps the colors of node 1 and node 2
  COLOR temp;
  temp = x1->color;
  x1->color = x2->color;
  x2->color = temp;
  }

  void swapvalues(Node *u, Node *v) { // This function swaps the values of node 1 and node 2
  int temp;
  temp = u->value;
  u->value = v->value;
  v->value = temp;
  }

  void fixRedRed(Node *x) {
  if (x == root) {
    x->color = BLACK;
    return;
  }

  Node *parent = x->parent, *grandparent = parent->parent,
     *uncle = x->uncle();

  if (parent->color != BLACK) {
    if (uncle != NULL && uncle->color == RED) { // This recolors
      parent->color = BLACK;
      uncle->color = BLACK;
      grandparent->color = RED;
      fixRedRed(grandparent);
    }
    else {
      if (parent->isOnLeft()) {
        if (x->isOnLeft()) {
          swapColors(parent, grandparent);
        }
        else {
          leftRotate(parent);
          swapColors(x, grandparent);
        }
        rightRotate(grandparent);
        }
        else {
          if (x->isOnLeft()) {
            rightRotate(parent);
            swapColors(x, grandparent);
          }
          else {
            swapColors(parent, grandparent);
          }
        leftRotate(grandparent);
      }
    }
  }
  }

  Node *successor(Node *x) { // checks for a left child in the subtree of the node
  Node *temp = x;

  while (temp->left != NULL)
    temp = temp->left;

  return temp;
  }

  Node *BSTreplace(Node *x) { // Replaces a deleted node in a binary search tree
  if (x->left != NULL && x->right != NULL)
    return successor(x->right);

  if (x->left == NULL && x->right == NULL) // if a leaf
    return NULL;

  if (x->left != NULL) // if a single child
    return x->left;

  else
    return x->right;
  }

  void deleteNode(Node *v) { // This function deletes the node
  Node *u = BSTreplace(v);

  bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
  Node *parent = v->parent;

  if (u == NULL) {
    if (v == root) {
      root = NULL;
    }
    else {
      if (uvBlack) {
        fixDoubleBlack(v);
      }
      else {
        if (v->sibling() != NULL)
          v->sibling()->color = RED;
      }
      if (v->isOnLeft()) {
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }
    }
    delete v;
    return;
  }

  if (v->left == NULL || v->right == NULL) {
    if (v == root) {
      v->value = u->value;
      v->left = v->right = NULL;
      delete u;
    }
    else {
      if (v->isOnLeft()) {
        parent->left = u;
      }
      else {
        parent->right = u;
      }
      delete v;
      u->parent = parent;
      if (uvBlack) {
        fixDoubleBlack(u);
      }
      else {
        u->color = BLACK;
      }
    }
    return;
  }

  swapvalues(u, v);
  deleteNode(u);
  }

  void fixDoubleBlack(Node *x) {
  if (x == root) // if the root is reached
    return;

  Node *sibling = x->sibling(), *parent = x->parent;
  if (sibling == NULL) { // checks if sibling is equal to null
    fixDoubleBlack(parent);
  }
  else {
    if (sibling->color == RED) {
      parent->color = RED;
      sibling->color = BLACK;
      if (sibling->isOnLeft()) {
        rightRotate(parent);
      }
      else {
        leftRotate(parent);
      }
      fixDoubleBlack(x);
    }
    else {
      if (sibling->hasRedChild()) {
        if (sibling->left != NULL && sibling->left->color == RED) {
          if (sibling->isOnLeft()) {
            sibling->left->color = sibling->color;
            sibling->color = parent->color;
            rightRotate(parent);
          }
          else {
            sibling->left->color = parent->color;
            rightRotate(sibling);
            leftRotate(parent);
          }
        }
         else {
          if (sibling->isOnLeft()) {
            sibling->right->color = parent->color;
            leftRotate(sibling);
            rightRotate(parent);
          }
          else {
            sibling->right->color = sibling->color;
            sibling->color = parent->color;
            leftRotate(parent);
          }
        }
        parent->color = BLACK;
      }
      else {
        sibling->color = RED;
        if (parent->color == BLACK)
          fixDoubleBlack(parent);
        else
          parent->color = BLACK;
      }
    }
  }
  }

  void levelOrder(Node *x) {
  if (x == NULL) // checks if the node is null
    return;

  queue<Node *> node_queue; // makes the queue named node_queue
  Node *curr;

  node_queue.push(x); // pushes x onto the queue

  while (!node_queue.empty()) {
    curr = node_queue.front();
    node_queue.pop();

    cout << curr->value << " ";

    if (curr->left != NULL)
      node_queue.push(curr->left);
    if (curr->right != NULL)
      node_queue.push(curr->right);
  }
  }

public:
  RBTree() { root = NULL; }

  Node *getRoot() { return root; }

  Node *search(int n) { // searches for the value
  Node *temp = root;
  while (temp != NULL) {
    if (n < temp->value) {
      if (temp->left == NULL)
        break;
      else
        temp = temp->left;
    }
    else if (n == temp->value) {
      break;
    }
    else {
      if (temp->right == NULL)
        break;
      else
        temp = temp->right;
    }
  }

  return temp;
  }

  void insert(int n) { // This inserts a value into the tree
  Node *newNode = new Node(n);
  if (root == NULL) {
    newNode->color = BLACK;
    root = newNode;
  }
  else {
    Node *temp = search(n);

    if (temp->value == n) {
      return;
    }

    newNode->parent = temp;

    if (n < temp->value)
      temp->left = newNode;
    else
      temp->right = newNode;

    fixRedRed(newNode);
  }
  }

  void deleteByvalue(int n) { // Gets the value that is deleted and deletes it
  if (root == NULL)
    return;

  Node *v = search(n), *u;

  if (v->value != n) {
    cout << "No node found to delete with valueue:" << n << endl;
    return;
  }

  deleteNode(v);
  }

  void printLevelOrder() {
  cout << "Level order: " << endl;
  if (root == NULL)
    cout << "Tree is empty" << endl;
  else
    levelOrder(root);
  cout << endl;
  }
  };

  int randomizer(int &number){
    number = rand() % 100;
    return number;
  };

int main() {

	int myints[10] = {0};
	int lowest = 1;
	int highest = 50;
	int range = (highest-lowest);
	int random_int = 0;

  //srand (time(NULL));
  RBTree tree;
  int random_num, delete_num;



  for (int counter = 0; counter < 10; counter++){
	    random_num = lowest+int(range*(rand()/(RAND_MAX + 1.0)));
    if (counter == 3){
      delete_num = random_num;
      cout << endl << "The fourth number inserted was " << delete_num << endl;
    }
    tree.insert(random_num);
  }

  tree.printLevelOrder();

  cout<<endl<<"Deleting the fourth number inserted"<<endl;

  tree.deleteByvalue(delete_num);

  tree.printLevelOrder();
  return 0;
}
