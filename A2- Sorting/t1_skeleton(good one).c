#include <stdio.h>
#include <stdlib.h>
#include "t1.h"







//Fills the array with ascending, consecutive numbers, starting from 0.
// source used: https://computer.howstuffworks.com/c10.htm

void fill_ascending(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = i;
        
    } 
    
}

//Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
   for(int i = 0; i < size; i++)
    {
        array[i] = size - i - 1; // turns out i dont need that big ass loop just a small part of it
         // note: i = amout of times the loop has been used
    } 
}

//Fills the array with uniform numbers.
void fill_uniform(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 3; // the output will generate an array of size 10 of 3's

        // NOTE to self: stop being a dumbass and remember a[i] was in your practise codes and is not array[i] you keep making the same mistake everytime 
    }
    
    
}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
// source for lerning random array generation https://www.youtube.com/watch?v=wnjYD_euSJQ
// and also https://www.codespeedy.com/generate-a-random-array-in-c-or-cpp/
// have to use rand() function here.

void fill_with_duplicates(int *array, int size)
{
    // step 1: create a for loop 
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % size - 1; // will generate a random number
        // should act the same as asending function bu random values
    }
    
}

// Notice the pattren? 1 and 3 are the same so can 2 and 5 be similer ? lets find out (kill me plz)

//a useful source that i've found https://stackoverflow.com/questions/60543704/randomly-reorder-elements-in-an-array-without-duplication
//another useful refrence https://stackoverflow.com/questions/31489339/display-duplicates-in-array-in-c
//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.

void fill_without_duplicates(int *array, int size)
{
    fill_ascending(array, size);
    // step 1: create a for loop (all the function share that)
    for(int i = 0; i < size - 1; i++)
    {
        int j = rand() % (size);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp; // a sweet and simple swap process
    }
   
    
}

void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n"); 
}