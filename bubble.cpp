#include "bubble.h"

Bubble::Bubble()
{

}

//algoritmo migliorato per riordinare le pagelle in base alle medie
void Bubble::Sort(Pagella a[], int left, int right)
{
    int i, j;
    for( i = left; i < right; i++)
        for( j = right; j > i; j--)
            if(a[j - 1].media > a[j].media)
                arraySwap(a, j, j - 1);
}

void Bubble::bySelection(Pagella a[], int slotNumber)
{
    //the slotNumber value is used just to make user friendly the function
    //the arrSize is used becouse an array with 5 slot has indexes going from 0 to 4
    int arrSize = slotNumber - 1;

    //This loop finds the lowest value from the index i and the latest and
    //sets his value as the first one. Every iteration the check is done between the last four,
    //then the last three... etc. indexes.
    for(int i = 0; i < arrSize; i++)
        findLowestAndExch(i, arrSize, a);
}

//this method looks for the lowest number in the provided array section and makes it the first one of it
void Bubble::findLowestAndExch(int left, int right, Pagella arr[])
{
    //Find what is the array slot with the lowest value and store its index into
    //the variable called Lowest.
    //The loop works by comparing the first with the second slot, then the second with the third and so on.
    //When the loops finds that the actual slot is bigger than its successor, sets the Lowest to be the successor
    //only if the successor is also lower than the actual Lowest slot value.
    int Lowest = left; //set an initial value
    for(int j = left; j < right; j++)
        if(arr[j].media > arr[j+1].media && arr[j+1].media <arr[Lowest].media)
            Lowest = j + 1;

    //switch the whole structure data to another index not just a value to another structure
    arraySwap(arr, Lowest, left);
}

//this method swap two arrays
void Bubble::arraySwap(Pagella arr[], int indexPrev, int indexNext)
{
    Pagella temp = arr[indexPrev];
    arr[indexPrev] = arr[indexNext];
    arr[indexNext] = temp;
}
