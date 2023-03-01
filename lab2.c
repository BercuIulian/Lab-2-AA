#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int array[], int length)
{
    srand(time(NULL));

    for (int i=0;i<length;i++)
    {
        int swap_index = rand() % length;
        int temp=array[i];
        array[i]=array[swap_index];
        array[swap_index]=temp;
    }
}

//quick sort

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quicksort(int array[], int length)
{
  srand(time(NULL));
  quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(array, low, high);
    quicksort_recursion(array, low, pivot_index - 1);
    quicksort_recursion(array, pivot_index + 1, high);
  }
}

int partition(int array[], int low, int high)
{
  int pivot_index = low + (rand() % (high - low));
  if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);
  int pivot_value = array[high];
  int i = low;
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);
  return i;
}

//merge sort

void merge_sort(int a[], int length)
{
  merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
  int left_length = m - l + 1;
  int right_length = r - m;
  int temp_left[left_length];
  int temp_right[right_length];
  int i, j, k;
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
}

//heap sort
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//bubble sort
void bubble_sort(int arr[], int length)
{
    int aux,i;
    for (i=1;i<length;i++)
    {
        if (arr[i]<=arr[i-1])
        {
            aux=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=aux;
            i=0;
        }
    }
}

int main()
{
    int a[25],b[50],c[75],d[100];
    int i;
    for (i=0;i<25;i++)
        a[i]=i+1;
    shuffle(a,25);
    /*for (i=0;i<50;i++)
        b[i]=i+1;
    shuffle(b,50);*/
    /*for (i=0;i<75;i++)
        c[i]=i+1;
    shuffle(c,75);*/
    /*for (i=0;i<100;i++)
        d[i]=i+1;
    shuffle(d,100);*/

    //quicksort(d,100);
    //merge_sort(a,25);
    //heapSort(d,sizeof(d) / sizeof(d[0]));
    bubble_sort(a,25);
    return 0;
}
