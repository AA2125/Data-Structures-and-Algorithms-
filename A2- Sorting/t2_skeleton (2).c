#include <stdio.h> 
#include "t2.h"
#include<stdbool.h> // wanted to use that for quick sort but nah ill pass


// im just gonna explain my method using pen and paper rather than excessive comments.

int number_comparisons = 0;
int number_swaps = 0;

// i will create a swap function because why not? less work for me
void swap(int arr[], int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}



//useful source 1:https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int arr[], int size) 
{ 
  for(int i = 0; i < size; i++)
  {
    int min_indx = i;
    for(int j = i + 1; j < size; j++)
    {
      number_comparisons++;
      if(arr[min_indx] > arr[j])
      {
        
        min_indx = j; 
        
      }
      
    }
    swap(arr, min_indx , i); // swap occuring (should be 9999 but im getting 10000??)
    number_swaps++;
  }
  
  

} 


// pain just pain

//source used to solve this function: https://www.edureka.co/blog/insertion-sort-in-c/

void insertionSort(int arr[], int size) 
{ 
  int i, temp, j; 
  for (i = 1; i < size; i++) { temp = arr[i]; j = i - 1; while (j >= 0 && arr[j] > temp) 
  {       
    number_swaps++; // swap happens below
    arr[j + 1] = arr[j]; 
    j = j - 1;      

  } 
   arr[j + 1] = temp; 
   number_comparisons++; // tbh just placed it there

   } 

}

// now to the worst one of them all the death itself
//source 1:https://www.geeksforgeeks.org/quick-sort/ 
//source 2:https://www.programiz.com/dsa/quick-sort 
//source 3: https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_program_in_c.htm
// need 2 fuctions a partition and a 2nd quicky sorty(yes i am childish)
// do we though?? yes we do.

void swapy(int* a, int* b) // dumb name but work so does a and b it was in the examples that i fallowed
{
  int t = *a;
  *a = *b;
  *b = t;
}



// we need a fuction to create sub arrays and break it into smaller equal numbers to sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; 
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) 
  {
    number_comparisons++; // increment comarision count 
    if(arr[j] < pivot) 
    {
      i++;
      swapy(&arr[i], &arr[j]);
      number_comparisons++; // Increment comparision count
    }
  }
  swapy(&arr[i + 1], &arr[high]);
  number_swaps++; // Increment swap count
  return (i + 1);
}

//we need a fuction to sort the sub arrays
void QuickSort(int arr[], int low, int high)
{ 
  if (low < high) 
 {
 
 int pi = partition(arr, low, high); 
 QuickSort(arr, low, pi - 1);
 QuickSort(arr, pi + 1, high);
 }
}

// now we call the quicky sorty function to proude a final result
void quickSort(int arr[], int size) 
{ 
  
 QuickSort(arr, 0, size - 1);
}

// task 2 (all good) 3 is meh and 4 can eat a duck
// overall substanderd work but better than assigment 1 screw hash tables 