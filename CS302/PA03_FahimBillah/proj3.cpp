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


using namespace std;

/*
Creates a single random integer between the boundaries set
*/
int randomNumberGenerator()
{
    //creates a random number
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    // generates random number
    default_random_engine dre(seed);
    mt19937 mt(seed);

    //create boundaries
    uniform_int_distribution<int> dist(0, 1000000);

// return a random number
return dist(mt);
}

/*
Creates a file to be filled with the randomized numbers that will be randomized
*/
void createFile(int numValues)
{
    int counter;
    ofstream fout;

    fout.clear();
    fout.open("randomizedValues.txt");

    cout << "Generating " << numValues << " random numbers" << endl << endl;

    //creating n values specified by the project
    for(counter = 0; counter < numValues; counter++)
    {
      fout << randomNumberGenerator() << endl;
    }
    fout.close();
}

/*
Loads the file with ints randomly created
*/
void loadFile(vector<int>& vec, int numValues)
{
    int index, number;
    ifstream fin;

    fin.clear();
    fin.open("randomizedValues.txt");

    // fill the file with rng
    for(index = 0; index < numValues; index++)
    {
      fin >> number;
      vec[index] = number;
    }
    fin.close();
}

/*
First sorting algorithm:Bubble Sort
*/
void bubbleSort(vector<int>& data, unsigned long int& comparisons, unsigned long int& swaps)
{
    bool sorted = false;
    unsigned int count, index;

    for(count = 1; (count < data.size()) && sorted == false; count++)
    {
      sorted = true;

      for(index = 0; index < data.size() - count; index++)
      {
        comparisons++;
        if(data[index] > data[index + 1])
        {
          swaps++;
          swap(data[index], data[index + 1] );
          sorted = false;
      }
    }
  }
}

/*
Partition is used to split the data set in half then would act as a helper function
for quick sort
*/
int partition(vector<int>& data, int first, int last, unsigned long int& comparisons, unsigned long int& swaps)
{
      int x = data[first];
      int y = first;
      int z;

      for(z = first + 1; z < last; z++)
      {
          comparisons++;
          if(data[z] <= x)
          {
              y++;
              swaps++;
  			   swap(data[y], data[z]);
          }
      }
      swaps++;
      swap(data[y], data[first]);

return y;
}

/*
Second sorting algorithm:Quick SORTED
*/
void quickSort(vector<int>& data, int first, int last, unsigned long int& comparisons, unsigned long int& swaps)
{
    int middle;

    comparisons++;
    if( first < last )
    {
        middle = partition(data, first, last, comparisons, swaps);
        quickSort(data, first, middle, comparisons, swaps);
        quickSort(data, middle + 1, last, comparisons, swaps);
    }
}

/*
Run is going to execute the sorting algorithms and record the time each algorithm
needs to sort through the datasets
*/
double run(string sort, vector<int>& data, int numValues, unsigned long int& comparisons, unsigned long int& swaps)
{
    clock_t t1, t2, t3;

    //clear and resize vectors as a safety check
    data.clear();
    data.resize(numValues);

    loadFile(data, numValues);

    comparisons = 0, swaps = 0;

    // check which sort should be run based on the argument that was passed in
    if(sort == "Bubble Sort")
    {
      t1 = clock(); //start clock
      bubbleSort(data, comparisons, swaps);
      t2 = clock(); //end clock

      // subtract difference between two clocks to find duration of the sort
      t3 = t2 - t1;
    }

    else if( sort == "Quick Sort" )
    {
       // begin clock
       t1 = clock();
       // run sort
       quickSort(data, 0, data.size(), comparisons, swaps );
       // end clock
       t2 = clock();

       // subtract difference between two clocks to find duration of the sort
       t3 = t2 - t1;
    }
return (double)t3;
}


int main()
{
    int numValues;
    unsigned long int comparisons = 0, swaps = 0;
    vector<int> bubbleSortSet, quickSortSet;
    double averageTime = 0;
    int numRuns = 10;
    clock_t t1, t2, t3;

    // run loop 3 times, once for 1 000, twice for 10 000, thrice for 100 000
    for( int i = 1, count = 0; count < 3; i *= 10, count++ )
    {
      // set numValues in the beginning of every loop
      numValues = i * 1000;

      // generate a file with the previously specified number of values
      createFile( numValues );

      if( numValues == 100000 )
      {
        // set the number of runs equal to 2 so I don't have to wait forever
        numRuns = 2;
      }
      //bubbleSort
      cout << "Running bubble sort " << numRuns << " times with " << numValues << " values" << endl;

      for( int i = 0; i < numRuns; i++ )
      {
        // run specified sort n times
        averageTime += run( "Bubble Sort", bubbleSortSet, numValues, comparisons, swaps );
      }

      cout << "Average sorting time of " << numRuns << " runs for bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for bubble sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for bubble sort: " << swaps / numRuns << endl << endl;

      //quickSort
      // reset 0
      averageTime = 0, comparisons = 0, swaps = 0;


      numRuns = 10;
      if( numValues == 100000 )
      {
        // set the number of runs equal to 2 so I don't have to wait forever
        numRuns = 2;
      }

      cout << endl << "Running quick sort " << numRuns << " times with " << numValues << " values" << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         averageTime += run("Quick Sort", quickSortSet, numValues, comparisons, swaps);
      }

      cout << "Average sorting time of " << numRuns << " runs for quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for quick sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for quick sort: " << swaps / numRuns << endl << endl;
    }

    //After sorting
    cout << endl << endl << "After data has been sorted" << endl << endl;
    run("Bubble Sort", bubbleSortSet, 10000, comparisons, swaps);

    averageTime = 0, comparisons = 0, swaps = 0;
    numRuns = 10;
    t1 = clock();
    bubbleSort(bubbleSortSet, comparisons, swaps);
    t2 = clock();
    t3 = t2 - t1;

    cout << "After bubble sort has sorted 10,000 values" << endl;
    cout << "Average sorting time of " << numRuns << " runs for bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
    cout << "Average number of comparisons of " << numRuns << " runs for bubble sort: " << comparisons / numRuns << endl;
    cout << "Average number of swaps of " << numRuns << " runs for bubble sort: " << swaps / numRuns << endl << endl;


    run("Quick Sort", quickSortSet, 10000, comparisons, swaps);

    averageTime = 0, comparisons = 0, swaps = 0;
    numRuns = 10;
    t1 = clock();
    quickSort(quickSortSet, 0, quickSortSet.size(), comparisons, swaps );
    t2 = clock();
    t3 = t2 - t1;

    cout << "After quick sort has sorted 10,000 values" << endl;
    cout << "Average sorting time of " << numRuns << " runs for quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
    cout << "Average number of comparisons of " << numRuns << " runs for quick sort: " << comparisons / numRuns << endl;
    cout << "Average number of swaps of " << numRuns << " runs for quick sort: " << swaps / numRuns << endl << endl;


    return EXIT_SUCCESS;
}
