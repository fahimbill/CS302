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
