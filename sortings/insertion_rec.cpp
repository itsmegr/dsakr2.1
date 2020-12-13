#include <bits/stdc++.h>
#include <string>
using namespace std;

int stopPointIndex(int *A, int stopPoint,int sortMe)
{
    if(stopPoint<0)
    {
        return stopPoint;
    }
    else
    {
        if(sortMe<A[stopPoint])
        {
              return stopPointIndex(A, stopPoint-1, sortMe);
        }
        else
        {
            return stopPoint;
        }
        
    }
}

void movingElement(int *A, int startPoint, int endPoint)
{
    if(startPoint<=endPoint)
    {

    }
    else
    {
        A[startPoint] = A[startPoint-1];
        movingElement(A, startPoint-1, endPoint);
    }
    
}

void insertionSort(int *A, int n, int sortMeIndex)
{
    int stopPoint,sortMe;
    if(sortMeIndex==n)
    {
        sortMe = A[sortMeIndex];
        stopPoint = stopPointIndex(A, sortMeIndex-1, A[sortMeIndex]);
        movingElement(A, sortMeIndex, stopPoint+1);
        A[stopPoint+1] = sortMe;

    }
    else
    {
        sortMe = A[sortMeIndex];
        stopPoint = stopPointIndex(A, sortMeIndex-1, A[sortMeIndex]);
        movingElement(A, sortMeIndex, stopPoint+1);
        A[stopPoint+1] = sortMe;
        insertionSort(A, n, sortMeIndex+1);


    }
    

}

int main()
{
    int size;
    cin>>size;
    int A[size],n=size-1,sortMeindex=1;
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    insertionSort(A, n,sortMeindex);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }

}