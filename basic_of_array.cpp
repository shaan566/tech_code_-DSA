#include <bits/stdc++.h>
using namespace std;
int greater_number_arr(int arr[],int n){
  int max=INT_MIN;
  for(int i=0;i<n;i++){
    if(arr[i]>max){
      max= arr[i];
    }
  }
  return max;
}
int smaller_number_arr(int arr[],int n){
  int min=INT_MAX;
  for(int i =0;i<n;i++){
    if( arr[i] < min){
      min = arr[i];
      
    }
  }
  return min;
}
int remove_Duplicates(int arr[],int n ) {
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;

}
void reverse_arr(int arr[],int i , int j){
   while(i<j){
       swap(arr[i],arr[j]);
       i++;j--;
   }
}
void rotate_arr(int arr[], int k,int n) {
     k = k % n;
    reverse_arr(arr,0,n-k-1);
    reverse_arr(arr,n-k,n-1);
    reverse_arr(arr,0,n-1);

}
int missing_Number(int arr[],int n) {
    int ans =0;
    for(int i =1;i<=n;i++){
        ans = ans ^ i;
    }
    for(int i =0;i<n;i++){
        ans= ans^arr[i];
    }
    return ans;
}
int single_Number(int  arr[],int n) {
    int num =0;
    for(int i=0;i<n;i++){
        num = num ^ arr[i];
    }
    return num;
}
void move_Zeroes_to_end(int arr[],int n) {
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
               i++;
        }
    }
    for(int k=i;k<n;k++){
        arr[k] = 0;
    }
}


