//Fahim Billah
//CS302

#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define ASCII 17
using namespace std;
int TSP(int graph[][5], int s);

int main()
{
  int graph[][5] = {{0, 218, 518, 705, 439}, {218, 0, 736, 808, 570}, {518, 736, 0, 840, 421}, {705, 808, 840, 0, 1117}, {439, 570, 421, 1117, 0} };


  int a = 0;
  cout << "There are 24 possible routes to this traveling salesman problem" << endl;
  cout << "the brute force method:" << endl;
  cout<<"The optimum solution in miles traveled: " << TSP(graph, a) << "miles" << endl;




  return 0;

}

int TSP(int graph[][5], int s){

  vector <int> vertex;
  int a = 1;
  int convert = 0;

  for(int i = 0; i < 5; i++)
  {
    if(i != s){
      vertex.push_back(i);
    }
  }


  int min_path = INT_MAX;
  do{

    int current_weight = 0;
    int k = s;
    cout << "Route #" << a << endl;
    a++;
    convert = k + ASCII;
    printf("%c to ", convert + '0');
    for(int i = 0; i < vertex.size(); i++)
    {
      current_weight += graph[k][vertex[i]];

      k = vertex[i];
      convert = k + ASCII;
      printf("%c to ", convert + '0');
}

      current_weight += graph[k][s];
      convert = s + ASCII;
      printf("%c", convert + '0');
      cout<<"\nTotal Distance: " << current_weight << " Miles" << endl;
      min_path = min(min_path, current_weight);
    }
    while(next_permutation(vertex.begin(), vertex.end()));

    return min_path;
  }
