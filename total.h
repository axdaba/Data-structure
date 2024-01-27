#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include<chrono>
#define MAXSIZE 11000

using namespace std;
typedef struct {
    int key;
    
}RedType;
typedef struct {
    RedType* T;
    //RedType T[MAXSIZE + 1];
    int length;
  
    double t1;
    double t2;
    double t3;
    double t4;
    double t5;
}SqList;

typedef struct QNode {
    SqList S;
    struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue; 
void InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, SqList e);
void Dequeue(LinkQueue& Q, SqList& e);
int Partition(SqList& L, int low, int high, int& comparecount, int& movecount);
void Qsort(SqList& L, int low, int high, int& comparecount, int& movecount);
void bubblesort(SqList& L, int& comparecount, int& movecount);
int maxBit(SqList& data, int n, int& comparecount);
void radixsort(SqList& data, int n, int& comparecount, int& movecount);
void Swap(int& t1, int& t2);
void HeapAdjust(SqList& R, int s, int m, int& comparecount, int& movecount);
void HeapSort(SqList& R, int n, int& comparecount, int& movecount);
void BinsertSort(SqList& L, int& compare, int& move);
