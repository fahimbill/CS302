//Fahim Billah

#include "binarySearchTree.cpp"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>

void generateSet(const unsigned int numValues){
  ofstream fileOutput;
  unsigned int count = 0;
  vector<int> numbers;

  //create values
  unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
  auto gen = default_random_engine(seed);

  //push numbers 1-200 into vector
  for(count = 0; count < 200; count++){
    numbers.push_back(count + 1);
  }

  //randomize numbers
  shuffle(numbers.begin(), numbers.end(), gen);

  //clearing/opening the files for multiple test runs
  fileOutput.clear();
  fileOutput.open("input.txt");

  //output everytihng into a file
  for(count = 0; count < numValues; count++){

    if( count == numValues - 1 ){
      fileOutput << numbers.at( count );
    }

    else{
      fileOutput << numbers.at( count ) << endl;
    }
   }

   fileOutput.close();
}

void createBST(BinarySearchTree& tree)
{
  ifstream fileInput;
  int value;

  // clear and open input file stream
  fileInput.clear();
  fileInput.open( "input.txt" );

  // while there is still data in the file and add data to tree
  cout << "Adding values into the Binary Search Tree" << endl;
  cout << "-----------------------------------------" << endl;
  while(fileInput.eof() == false ){
    fileInput >> value;
    cout << value << " ";
    tree.add( value );
  }

   fileInput.close();
}



int main(){

  srand(time(NULL));
  generateSet(100);

  BinarySearchTree Tree;

  createBST(Tree); //Load up the tree

  //Printing out Inorder
  cout << endl << endl << endl << "Inorder Traversal" << endl;
  cout << "---------------------" << endl;
  Tree.inorderTraverse(Tree.root);
  cout << endl << endl;

  //Printing out Preorder
  cout << endl << endl << "Preorder Traversal" << endl;
  cout << "---------------------" << endl;
  Tree.preorderTraverse(Tree.root);
  cout << endl << endl;

  //Printing out Postorder
  cout << endl << endl << "Postorder Traversal" << endl;
  cout << "---------------------" << endl;
  Tree.postorderTraverse(Tree.root);
  cout << endl << endl;



  //Display height of Tree
  cout << endl << endl << "Height of Binary Search Tree: ";
  cout << Tree.getHeight(Tree.root);

  return 0;
}
