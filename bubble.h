#ifndef BUBBLE_H
#define BUBBLE_H
#include "mainwindow.h"

class Bubble
{
public:
    Bubble();
    void Sort(Pagella a[], int , int );
    void bySelection(Pagella a[], int);
    void findLowestAndExch(int left, int right, Pagella arr[]);
    void arraySwap(Pagella arr[], int, int);    
};

#endif // BUBBLE_H
