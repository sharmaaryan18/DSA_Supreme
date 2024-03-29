#include<iostream>
using namespace std;
 
 int partition(int arr[], int s, int e){ //Step 1: choose pivotElement
    int pivotIndex=s;
    int pivotElement=arr[s];

    //Step 2:Find the right position for pivot element and swap
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }
    //while exiting the loop we have the right position of pivot 
    int rightIndex= s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;

    //Step 3: put  smaller elements in left and greater elements in right

    int i=s;
    int j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        //2 cases
        //A-you found the element s to swap 
        //B- no need to swap
        if(i< pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    } 
    return pivotIndex;
 }
void quickSort(int arr[], int s, int e){
    //base case
    if(s>=e)
    return;
   //partition logic
  int p = partition(arr,s,e); 

  //recursive calls
  //pivot element -> left 
  quickSort(arr,s,p-1);

  //pivot element -> right
  quickSort(arr,p+1,e);

}

int main(){
    int arr[]={8,1,3,5,5,5,5,1,1,4,4,4,20,50,30};
    int n=15;

    int s=0;
    int e=n-1;

    quickSort(arr,s,e);

    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}   