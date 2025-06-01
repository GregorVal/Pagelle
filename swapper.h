#ifndef SWAPPER_H
#define SWAPPER_H

//function used to swap variables
template <typename var>
void swap(var *a, var *b)
{
    var temp = *a;
    *a = *b;
    *b = temp;
}

//WORKING STATUS VERIFIED
//function used to swap arrays.
//Becouse the array name point to itself there is no need to use *
//we use polymorfism so that the user does not need to change the function name
template <typename array>
void swap(array arr[], int indexPrev, int indexNext)
{
    array temp = arr[indexPrev];
    arr[indexPrev] = arr[indexNext];
    arr[indexNext] = temp;
}







template <typename array>
void selectionSort(array a[], int slotNumber)
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

/*
 * WORKING STATUS VERIFIED
 * this version is for structure array sort
 * call it like:
 * selectionSort(Pippo, 5, &Pippo[0].structmember);
*/
template <typename array, typename var>
void selectionSort(array a[], int slotNumber, var* ptr)
{
    int arrSize = slotNumber - 1;
    for(int i = 0; i < arrSize; i++)
        findLowestAndExch(i, arrSize, a, ptr);
}

template <typename array>
void findLowestAndExch(int left, int right, array arr[])
{
    //Find what is the array slot with the lowest value and store its index into
    //the variable called Lowest.
    //The loop works by comparing the first with the second slot, then the second with the third and so on.
    //When the loops finds that the actual slot is bigger than its successor, sets the Lowest to be the successor
    //only if the successor is also lower than the actual Lowest slot value.
    int Lowest = left; //set an initial value
    for(int j = left; j < right; j++)
        if(arr[j] > arr[j+1] && arr[j+1] <arr[Lowest])
            Lowest = j + 1;

    //swap the indexes of the array
    swap(arr, Lowest, left);
}

//WORKING STATUS VERIFIED
//this is for the structure sorting
template <typename array, typename var>
void findLowestAndExch(int left, int right, array arr[], var* ptr)
{
    int Lowest = left;

    for(int j = left; j < right; j++)
        if(*(ptr + (sizeof(array) / sizeof(int)) * j) >
            *(ptr + (sizeof(array) / sizeof(int)) * (j+1)) &&
            *(ptr + (sizeof(array) / sizeof(int)) * (j+1)) <
            *(ptr + (sizeof(array) / sizeof(int)) * Lowest))
            Lowest = j + 1;

    swap(arr, Lowest, left);
}

#endif // SWAPPER_H
