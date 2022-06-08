#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void shell_sort(int arr[], int n);
void merge_sort(int arr[], int n);
void quick_sort(int arr[], int n);
void heap_sort(int arr[], int n);

int main(void) {
	int arr[] = { 5, 2, 0, 1, 3, 4, 9, 8, 7, 6 };

	// bubble_sort(arr, N);
	// selection_sort(arr, N);
	// insertion_sort(arr, N);
	// shell_sort(arr, N);
	// merge_sort(arr, N);
	// quick_sort(arr, N);
	heap_sort(arr, N);

	return 0;
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/***********************************************************/
/*                       冒泡排序                           */
/***********************************************************/
void bubble_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) { // i 表示第几次排序
		// 冒泡
		bool isSorted = true;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) { // Caution: >= 不稳定
				swap(arr, j, j + 1);
				isSorted = false;
			}
		}
		if (isSorted) break;
		// 打印数组
		print_arr(arr, n);
	}
}

/***********************************************************/
/*                       选择排序                           */
/***********************************************************/
void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr, i, minIndex);
		print_arr(arr, n);
	}
}

/***********************************************************/
/*                       插入排序                           */
/***********************************************************/
void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) { // i 表示无序区的第一个元素
		int value = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		}
		// j < 0 || arr[j] <= value
		arr[j + 1] = value;
		print_arr(arr, n);
	}
}

/***********************************************************/
/*                       希尔排序                           */
/***********************************************************/
void shell_sort(int arr[], int n) {
	int gap = n / 2;
	while (gap != 0) {
		// 组间进行简单的插入排序
		for (int i = gap; i < n; i++) {
			// 要插入的值
			int value = arr[i];

			int j = i - gap;
			while (j >= 0 && arr[j] > value) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = value;
		}
		print_arr(arr, n);
		gap = gap / 2; // 缩小增量
	}
}

/***********************************************************/
/*                       归并排序                           */
/***********************************************************/
void merge(int arr[], int left, int mid, int right) {
	int* tmp = malloc((right - left + 1) * sizeof(int));
	if (tmp == NULL) {
		printf("Error: malloc failed in merge.\n");
		exit(1);
	}
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {  // Caution: 不能写成 < ,否则就不稳定
			tmp[k++] = arr[i++];
		}
		else {
			tmp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		tmp[k++] = arr[i++];
	}

	while (j <= right) {
		tmp[k++] = arr[j++];
	}

	// 复制数据
	for (k = 0; k < right - left + 1; k++) {
		arr[left + k] = tmp[k];
	}
	free(tmp);
}

void merge_sort1(int arr[], int left, int right) {
	// 边界条件
	if (left >= right) return;
	int mid = left + (right - left >> 1);
	merge_sort1(arr, left, mid);
	merge_sort1(arr, mid + 1, right);
	// 合并两个有序数组
	merge(arr, left, mid, right);

	print_arr(arr, N);
}

void merge_sort(int arr[], int n) {
	merge_sort1(arr, 0, n - 1);
}


/***********************************************************/
/*                       快速排序                           */
/***********************************************************/

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j && arr[j] >= pivot) {
			j--;
		}
		// i == j || arr[j] < pivot
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot) {
			i++;
		}
		// i == j || arr[i] > pivot
		arr[j] = arr[i];
	}
	// i == j
	arr[i] = pivot;

	print_arr(arr, N);
	return i;
}

void quick_sort1(int arr[], int left, int right) {
	// 边界条件
	if (left >= right) return;
	int idx = partition(arr, left, right);
	quick_sort1(arr, left, idx - 1);
	quick_sort1(arr, idx + 1, right);
}

void quick_sort(int arr[], int n) {
	quick_sort1(arr, 0, n - 1);
}

/***********************************************************/
/*                       快速排序                           */
/***********************************************************/
void heapify(int arr[], int idx, int length) {
	while (idx < length) {
		int leftChild = 2 * idx + 1;
		int rightChild = 2 * idx + 2;
		int maxIdx = idx;
		if (leftChild < length && arr[leftChild] > arr[maxIdx]) {
			maxIdx = leftChild;
		}
		if (rightChild < length && arr[rightChild] > arr[maxIdx]) {
			maxIdx = rightChild;
		}
		if (maxIdx == idx) break;
		swap(arr, idx, maxIdx);
		idx = maxIdx;
	}
}

void build_heap(int arr[], int n) {
	// 找到第一个非叶子结点：2 * i + 1 <= n - 1  -->  i <= (n - 2) / 2
	for (int i = (n - 2) / 2; i >= 0; i--) {
		heapify(arr, i, n);
	}
}

void heap_sort(int arr[], int n) {
	// 构建大顶堆
	build_heap(arr, n);
	print_arr(arr, n);
	// 无序区的长度
	int length = n;
	while (length > 1) {
		// 交换堆顶元素和无序区的最后一个元素
		swap(arr, 0, length - 1);
		length--;

		print_arr(arr, n);
		// 重新调整成大顶堆
		heapify(arr, 0, length);
	}
}