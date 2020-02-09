//Fahim Billah

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

//helper print function
void print(std::vector<int> const &v){
  for(int i: v){
    std::cout << i << ' ';
  }
}


//fills the vector
int fillVector(){
  int n = rand() % 7;
    static int i = n;
     return i+=n;
}

int main(){

  std::vector<int> dataSet(100);

  srand(time(NULL));
  std::generate(dataSet.begin(), dataSet.end(), fillVector);
  std::random_shuffle(std::begin(dataSet), std::end(dataSet));

  int average = accumulate(dataSet.begin(), dataSet.end(), 0)/dataSet.size();

  std::cout << "Generating Data Set:" << std::endl;
  std::cout << "-----------" << std::endl;
  print(dataSet);
  std::cout << std::endl << std::endl;

  std::cout << "Converting to Heap" << std::endl;
  std::cout << "---------" << std::endl;
  make_heap(dataSet.begin(), dataSet.end());
  print(dataSet);
  std::cout << std::endl << std::endl;

  std::cout << "Average of the set:" << average;
  std::cout << std::endl << std::endl;

  std::cout << "Pushing avg into set" << std::endl;
  std::cout << "------" << std::endl;
  dataSet.push_back(average);
  print(dataSet);
  std::cout << std::endl << std::endl;

  std::cout << "Deleting max element" << std::endl;
  std::cout << "--------" << std::endl;
  pop_heap(dataSet.begin(), dataSet.end());
  dataSet.pop_back();
  print(dataSet);
  std::cout << std::endl << std::endl;

  std::cout << "Resorting Heap" << std::endl;
  std::cout << "-----" << std::endl;
  sort_heap(dataSet.begin(), dataSet.end());
  print(dataSet);

  return 0;



}
