#include <iostream>
using namespace std; 

void selection_sort(int a[], int n){

    for(int i = 0; i < n - 1; i++){
        int min_ind = i; 
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_ind]){
                min_ind = j;
            }
        }
        int temp = a[i]; 
        a[i] = a[min_ind]; 
        a[min_ind] = temp; 
    }
}

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i]; 
        int j = i - 1; 

        while(j >= 0 && a[j] > key){
            a[j+1] = a[j]; 
            j--; 
        }
        a[j+1] = key;
    }   
}

int main(){

    int a[5] = {7, 12, 9, 11, 3};
    selection_sort(a, 5); 
    for(int i = 0; i < 5; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl; 

    int b[5] = {7, 12, 9, 11, 3};
    insertion_sort(b,5); 
    for(int i = 0; i < 5; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl; 

    return 0;
}