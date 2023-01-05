#include<iostream>
using namespace std;

class algo
{

public:	
	void insertionSort(int arr[], int n)
	{
	    int i, key, j;
	    for (i = 1; i < n; i++)
	    {
	        key = arr[i];
	        j = i - 1;
	 
	        while (j >= 0 && arr[j] > key)
	        {
	            arr[j + 1] = arr[j];
	            j = j - 1;
	        }
	        arr[j + 1] = key;
	    }
	}
	 
	void printArrayI(int arr[], int n)
	{
	    int i;
	    for (i = 0; i < n; i++)
	        cout << arr[i] << " ";
	    cout << endl ;
	}
	
	
	
	void merge(int array[], int const left, int const mid,
			int const right)
	{
		int const subArrayOne = mid - left + 1;
		int const subArrayTwo = right - mid;
	
		int *leftArray = new int[subArrayOne],
			*rightArray = new int[subArrayTwo];
	
		for (int i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];
		for (int j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];
	
		int indexOfSubArrayOne
			= 0, 
			indexOfSubArrayTwo
			= 0; 
		int indexOfMergedArray
			= left; 
		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				array[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				array[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}
		
		while (indexOfSubArrayOne < subArrayOne) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}
		
		while (indexOfSubArrayTwo < subArrayTwo) {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}
	
	void mergeSort(int array[], int const begin, int const end)
	{
		if (begin >= end)
			return;
	
		int mid = begin + (end - begin) / 2;
		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}
	
	void printArrayM(int A[], int size)
	{
		for (int i = 0; i < size; i++)
			cout << A[i] << " ";
	}
	

	int partition(int arr[], int start, int end)
	{
	
		int pivot = arr[start];
	
		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] <= pivot)
				count++;
		}
	
		int pivotIndex = start + count;
		swap(arr[pivotIndex], arr[start]);
	
		int i = start, j = end;
	
		while (i < pivotIndex && j > pivotIndex) {
	
			while (arr[i] <= pivot) {
				i++;
			}
	
			while (arr[j] > pivot) {
				j--;
			}
	
			if (i < pivotIndex && j > pivotIndex) {
				swap(arr[i++], arr[j--]);
			}
		}
	
		return pivotIndex;
	}
	
	void quickSort(int arr[], int start, int end)
	{
	
		if (start >= end)
			return;
	
		int p = partition(arr, start, end);
	
		quickSort(arr, start, p - 1);
	
		quickSort(arr, p + 1, end);
	}
	void printArrayQ(int arr[], int n)
	{
	    int i;
	    for (i = 0; i < n; i++)
	        cout << arr[i] << " ";
	    cout << endl ;
	}
	
	

	void swapp(int *xp, int *yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	
	void selectionSort(int arr[], int n)
	{
		int i, j, min_idx;
	
		for (i = 0; i < n-1; i++)
		{
		
			min_idx = i;
			for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
	
			if(min_idx!=i)
				swapp(&arr[min_idx], &arr[i]);
		}
	}
	
	void printArrayS(int arr[], int size)
	{
		int i;
		for (i=0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	
	
	
	void heapify(int arr[], int n, int i)
	{
	    int largest = i; 
	    int l = 2 * i + 1; 
	    int r = 2 * i + 2; 
	 
	    if (l < n && arr[l] > arr[largest])
	        largest = l;
	 
	    if (r < n && arr[r] > arr[largest])
	        largest = r;
	 
	    if (largest != i) {
	        swap(arr[i], arr[largest]);
	 
	
	        heapify(arr, n, largest);
	    }
	}
	 
	
	void heapSort(int arr[], int n)
	{
	
	    for (int i = n / 2 - 1; i >= 0; i--)
	        heapify(arr, n, i);
	 
	    for (int i = n - 1; i >= 0; i--) {
	        swap(arr[0], arr[i]);
	 
	        heapify(arr, i, 0);
	    }
	}
	 
	
	void printArrayH(int arr[], int n)
	{
	    for (int i = 0; i < n; ++i)
	        cout << arr[i] << " ";
	    cout << "\n";
	}
	
	void bubbleSort(int arr[], int n)
	{
	    int i, j;
	    for (i = 0; i < n - 1; i++)
	 
	        for (j = 0; j < n - i - 1; j++)
	            if (arr[j] > arr[j + 1])
	                swap(arr[j], arr[j + 1]);
	}
	 
	void printArrayB(int arr[], int size)
	{
	    int i;
	    for (i = 0; i < size; i++)
	        cout << arr[i] << " ";
	    cout << endl;
	}

	
};


int main()
{
	algo A;
	int arr[] = {12 , 45 , 25 , 2 , 6 , 17 , 9 , 8 , 99 , 101 , 167};
	int N = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"Karim Abdulnabi __ Computer Science__ 10089"<<endl<<endl;
	
	cout<<"insertion sort"<<endl;
	A.insertionSort(arr , N );
	A.printArrayI(arr , N);
	cout<<endl;
	
	cout<<"merge sort"<<endl;
	A.mergeSort(arr , 0 , N-1);
	A.printArrayM(arr , N);
	cout<<endl<<endl;
	
	cout<<"quick sort"<<endl;
	A.quickSort(arr , 0 , N-1);
	A.printArrayQ(arr , N);
	cout<<endl;
	
	cout<<"selction sort"<<endl;
	A.selectionSort(arr ,N );
	A.printArrayS(arr , N);
	cout<<endl;
	
	cout<<"heap sort"<<endl;
	A.heapSort(arr , N);
	A.printArrayH(arr , N);
	cout<<endl;
	
	cout<<"bubble sort"<<endl;
	A.bubbleSort(arr , N);
	A.printArrayB(arr , N);
	cout<<endl;
	
	


	return 0 ;
}