#include <stdio.h>

void QuickSort(int a[], int left, int right){
  if(left >= right) return;

  int p = a[left];
  int l = left, r = right;
  while(1){
    while(l < right && a[l] < p) l++;
    while(r > left && a[r] > p) r--;
    if(l >= r) break;

    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
  }

  QuickSort(a, left, l-1);
  QuickSort(a, l+1, right);
}

int main(){
  int i, n;
  printf("Enter the no.of elements in the array\n");
  scanf("%d",&n);
  int a[n];

  printf("\n Input the elements of the array\n");
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("Array Input :\n");
  for(i = 0; i < n; i++) printf("%d\n",a[i]);

  // Calling merge sort to sort the array.
  QuickSort(a, 0, n-1);

  //printing all elements in the array once its sorted.
  printf("Array Elements after sorting are:\n");
  for(i = 0;i < n; i++) printf("%d element is:\t%d\n", i+1, a[i]);

  return 0;

}
