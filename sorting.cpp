
#include <iostream>
#include <climits>
using namespace std;
void bubble(int arr[],int n){
    for(int i =0;i<n-1;i++){
        bool flag = true;
        for(int j =0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag  = false;
            }
        }
        if(flag == true){
            break;
        }
    }
}
void selection(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int min = INT_MAX;
        int mindex = 0;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                mindex = j;
            }
        }
        swap(arr[i],arr[mindex]);
    }
}
void insert(int arr[],int n){
    for(int i =0;i<n;i++){
        int j = i;
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
void merge(int arr[],int l,int mid,int r){
     int len1 = mid-l+1;
      int len2 = r-mid;
      int arr1[len1],arr2[len2];
      for(int i=0;i<len1;i++){
          arr1[i] = arr[l+i];
      }
      for(int j=0;j<len2;j++){
          arr2[j] = arr[mid+j+1];
      }
      int i=0,j=0,k =l;
      while(i<len1 && j<len2){
          if(arr1[i]<arr2[j]){
              arr[k++] = arr1[i++];
          }else{
              arr[k++] = arr2[j++];
          }

      }
      while(i<len1){
          arr[k++] = arr1[i++];
      }
      while(j<len2){
          arr[k++] = arr2[j++];
      }
}

void mergesort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);



    selection(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    bubble(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    insert(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
