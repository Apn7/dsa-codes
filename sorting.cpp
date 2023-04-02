#include<bits/stdc++.h>
using namespace std;

void swp(int *a, int *b){
    if (a != b) {
        *a ^= *b ^= *a ^= *b;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1])swp(&arr[j],&arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i,j, mind;
    for (int i=0;i<n-1;i++){
        mind = i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[mind]){
                mind = j;
            }
        }
        if (mind!=i) swp(&arr[i],&arr[mind]);
    }
}

void merg(int ara[],int l, int mid, int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int lara[n1],rara[n2];
    for (int i=0;i<n1;i++)lara[i]=ara[l+i];
    for (int i=0;i<n2;i++)rara[i]=ara[mid+1+i];
    int in1=0,in2=0,in=l;
    while (in1<n1 && in2<n2){
        if (lara[in1]<rara[in2]){
            ara[in]=lara[in1];
            in1++;
        }
        else{
           ara[in]=rara[in2];
           in2++;
        }
        in++;
    }
    while (in1 < n1){
        ara[in] = lara[in1];
        in++;
        in1++;
    }
    while (in2 < n2){
        ara[in] = rara[in2];
        in++;
        in2++;
    }
}

void mergeSort(int ara[],int l, int r)
{
    int mid = (l+r)/2;
    if (l>=r) return;
    mergeSort(ara,l,mid);
    mergeSort(ara,mid+1,r);
    merg(ara,l,mid,r);
}

void insertSort(int ara[],int n)
{
    for (int i=1;i<n;i++){
        int key=ara[i];
        int j = i-1;
        while (j>=0 && ara[j]>key){
            swp(&ara[j+1],&ara[j]);
            j--;
        }
    }
}

void min_maxSort(int ara[],int n)
{
    for(int l=0,r=n-1;l<r;l++,r--){
        int mini=l,maxi=r;
        int minv=ara[l];
        int maxv=ara[r];
        for (int i=l;i<=r;i++){
            if (ara[i]>maxv){
                maxv = ara[i];
                maxi = i;
            }
            if (ara[i]<minv){
                minv = ara[i];
                mini = i;
            }
        }
        if (ara[l]!=minv)swp(&ara[l],&ara[mini]);
        if (ara[r]!=maxv)swp(&ara[r],&ara[maxi]);
    }
}

int part(int ara[], int l, int h){
    int pivot = ara[h];
    int i=l;
    for (int j=l;j<h;j++){
        if (ara[j]<pivot){
            swp(&ara[i],&ara[j]);
            i++;
        }
    }
    swp(&ara[i],&ara[h]);
    return i;
}

void quicksort(int ara[], int l, int h){
    if (l >= h) {
        return;
    }
    int p = part(ara, l, h);
    quicksort(ara, l, p - 1);
    quicksort(ara, p + 1, h);
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    selectionSort(a,n);
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}
