#include "iostream"

void sort(int a[],int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] < a[j]){
				int temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
		}
	}
}

int binary_Search(int arr[],int left, int right,int data = 31){

	if (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] == data) return mid;
		else if (arr[mid] < data) binary_Search(arr, mid + 1, right,data);
		else binary_Search(arr, left, mid,data);	
	}
	else return -1;
}

int interpolation_Search(int arr[],int length,int data = 31) {
	int lo = 0;
	int hi = length - 1;
	int mid = -1;
	int comparisons = 1;
	int index = -1;

	while (lo <= hi) {
		printf("\nSo sanh lan thu %d  \n", comparisons);
		printf("lo : %d, list[%d] = %d\n", lo, lo, arr[lo]);
		printf("hi : %d, list[%d] = %d\n", hi, hi, arr[hi]);

		comparisons++;

		// phan tu chot (probe) tai vi tri trung vi
		mid = lo + (((hi - lo) / (arr[hi] - arr[lo])) * (data - arr[lo]));
		printf("Vi tri trung vi = %d\n", mid);

		// tim thay du lieu
		if (arr[mid] == data) {
			index = mid;
			break;
		}
		else {
			if (arr[mid] < data) {
				// neu du lieu co gia tri lon hon, tim du lieu trong phan lon hon 
				lo = mid + 1;
			}
			else {
				// neu du lieu co gia tri nho hon, tim du lieu trong phan nho hon 
				hi = mid - 1;
			}
		}
	}

	printf("\nTong so phep so sanh da thuc hien: %d", --comparisons);
	return index;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1,
		n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1],
		*R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete L, R;
}
void mergeSort(int arr[], int l,int r){
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int Tower(int n, char a, char b, char c){
	if (n == 1){
		std::cout << "\t" << a << "-------" << c << std::endl;
		return 1;
	}	
	return Tower(n - 1, a, c, b) + Tower(1, a, b, c) + Tower(n - 1, b, a, c);	
}

void output(int a[],int n){
	for (int i = 0; i < n; i++) std::cout << a[i] << " - > ";
	std::cout << std::endl;
}
//void main()
//{
//	int a[] = {10,14,19,26,27,31,33,35,42,44};
//	int n = 10;
//
//	//sort(a,n);
//
//	//mergeSort(a, 0, n - 1);
//	//output(a, n);
//
//	//char a = 'A',
//	//	b = 'B',
//	//	c = 'C';
//
//	//std::cout << Tower(5, a, b, c) << " <= KQ"<<std::endl;
//
//	//std::cout << "\nTim thay vi tri: " << interpolation_Search(a,n);
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		std::cout << "\nGia tri " << a[i] << " dc tim thay o vi tri trog mang a[]: " << binary_Search(a, 0, n - 1,a[i]);
//	}
//
//	system("pause");
//
//}