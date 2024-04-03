//InsertSort
#include <stdio.h>

void insertSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

//MergeSort
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
    int i = begin, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }
    for (i = 0; i < k; i++) {
        a[begin + i] = temp[i];
    }
}

void MergeSort(int* a, int begin, int end, int* temp) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}


//QuickSort(递归版）
int Partition(int* a, int begin, int end) {
    int pivot = a[end];
    int i = (begin - 1);
    for (int j = begin; j <= end - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    return (i + 1);
}

void QuickSort_Recursion(int* a, int begin, int end) {
    if (begin < end) {
        int pi = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, pi - 1);
        QuickSort_Recursion(a, pi + 1, end);
    }
}


//CountSort
void CountSort(int* a, int size, int max) {
    int output[size];
    int count[max + 1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < size; i++) {
        a[i] = output[i];
    }
}

//RadixCountSor
void RadixCountSort(int* a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountSort(a, size, max);
    }
}

//测试程序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE1 10000
#define ARRAY_SIZE2 50000
#define ARRAY_SIZE3 200000

// 插入排序函数
void insertSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// 归并排序辅助函数
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
    int i = begin, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }
    for (i = 0; i < k; i++) {
        a[begin + i] = temp[i];
    }
}

// 归并排序函数
void MergeSort(int* a, int begin, int end, int* temp) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}

// 快速排序辅助函数
int Partition(int* a, int begin, int end) {
    int pivot = a[end];
    int i = (begin - 1);
    for (int j = begin; j <= end - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;
    return (i + 1);
}

// 快速排序函数（递归版）
void QuickSort_Recursion(int* a, int begin, int end) {
    if (begin < end) {
        int pi = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, pi - 1);
        QuickSort_Recursion(a, pi + 1, end);
    }
}

// 计数排序函数
void CountSort(int* a, int size, int max) {
    int output[size];
    int count[max + 1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < size; i++) {
        a[i] = output[i];
    }
}

// 基数计数排序函数
void RadixCountSort(int* a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountSort(a, size, max);
    }
}



int main() {
    int array1[ARRAY_SIZE1], array2[ARRAY_SIZE2], array3[ARRAY_SIZE3];
    int temp1[ARRAY_SIZE1], temp2[ARRAY_SIZE2], temp3[ARRAY_SIZE3];

    // 初始化随机数发生器
    srand(time(NULL));

    // 填充数组
    for (int i = 0; i < ARRAY_SIZE1; i++) {
        array1[i] = rand() % ARRAY_SIZE1;
    }
    for (int i = 0; i < ARRAY_SIZE2; i++) {
        array2[i] = rand() % ARRAY_SIZE2;
    }
    for (int i = 0; i < ARRAY_SIZE3; i++) {
        array3[i] = rand() % ARRAY_SIZE3;
    }

    // 测试插入排序
    {
        int* arrays[] = { array1, array2, array3 };
        int sizes[] = { ARRAY_SIZE1, ARRAY_SIZE2, ARRAY_SIZE3 };
        for (int i = 0; i < 3; i++) {
            int* arr = arrays[i];
            int size = sizes[i];

            clock_t start_time = clock();
            insertSort(arr, size);
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("InsertSort for size %d took %f seconds\n", size, time_spent);
        }
    }

    // 测试归并排序
    {
        int* arrays[] = { array1, array2, array3 };
        int sizes[] = { ARRAY_SIZE1, ARRAY_SIZE2, ARRAY_SIZE3 };
        for (int i = 0; i < 3; i++) {
            int* arr = arrays[i];
            int size = sizes[i];

            clock_t start_time = clock();
            MergeSort(arr, 0, size - 1, (i == 0) ? temp1 : (i == 1) ? temp2 : temp3);
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("MergeSort for size %d took %f seconds\n", size, time_spent);
        }
    }

    // 测试快速排序
    {
        int* arrays[] = { array1, array2, array3 };
        int sizes[] = { ARRAY_SIZE1, ARRAY_SIZE2, ARRAY_SIZE3 };
        for (int i = 0; i < 3; i++) {
            int* arr = arrays[i];
            int size = sizes[i];

            clock_t start_time = clock();
            QuickSort_Recursion(arr, 0, size - 1);
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("QuickSort for size %d took %f seconds\n", size, time_spent);
        }
    }

    // 测试计数排序
    {
        int max = ARRAY_SIZE3; // 假设最大值为数组大小
        int* arrays[] = { array1, array2, array3 };
        int sizes[] = { ARRAY_SIZE1, ARRAY_SIZE2, ARRAY_SIZE3 };
        for (int i = 0; i < 3; i++) {
            int* arr = arrays[i];
            int size = sizes[i];

            clock_t start_time = clock();
            CountSort(arr, size, max);
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("CountSort for size %d took %f seconds\n", size, time_spent);
        }
    }

    // 测试基数计数排序
    {
        double totalTime = 0.0;
        for (int i = 0; i < NUM_SORTS; i++) {
            // 填充小数组
            for (int j = 0; j < SMALL_ARRAY_SIZE; j++) {
                smallArray[j] = rand() % SMALL_ARRAY_SIZE;
            }
            // 记录开始时间
            clock_t start_time = clock();
            // 执行排序
            RadixCountSort(smallArray, SMALL_ARRAY_SIZE);
            // 记录结束时间
            clock_t end_time = clock();
            // 累加时间
            totalTime += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        }
        printf("RadixCountSort for %d sorts of size %d took %f seconds\n", NUM_SORTS, SMALL_ARRAY_SIZE, totalTime);
    }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "test_data.txt"

    // 函数声明
    void generateTestData(const char* fileName, int size);
    void sortTestData(const char* fileName);

    // 生成测试数据并保存到文件
    void generateTestData(const char* fileName, int size) {
        FILE* file = fopen(fileName, "w");
        if (file == NULL) {
            printf("无法打开文件 %s\n", fileName);
            return;
        }

        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d ", rand() % size);
        }

        fclose(file);
        printf("测试数据已生成并保存到文件 %s\n", fileName);
    }

    // 从文件读取数据并进行排序
    void sortTestData(const char* fileName) {
        int size = 10000; // 假设文件中的数据量为10000
        int array[size];
        int tempArray[size];

        FILE* file = fopen(fileName, "r");
        if (file == NULL) {
            printf("无法打开文件 %s\n", fileName);
            return;
        }

        int i = 0;
        while (fscanf(file, "%d", &array[i]) == 1) {
            i++;
        }
        fclose(file);

        // 使用排序函数对数据进行排序
        // 使用归并排序
        MergeSort(array, 0, i - 1, tempArray);

        // 打印排序后的数据（可选）
        for (int j = 0; j < i; j++) {
            printf("%d ", array[j]);
        }
        printf("\n数据已从文件 %s 读取并排序\n", fileName);
    }

    int main() {
        // 生成测试数据
        generateTestData(FILE_NAME, 10000);

        // 读取测试数据进行排序
        sortTestData(FILE_NAME);

        return 0;
    }

    //生成测试数据的函数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100 // 假设每个数组的大小为100
#define NUM_ARRAYS 10 // 假设要生成的数组数量为10

// 生成测试数据并保存到文件
    void generateTestData(const char* fileName) {
        FILE* file = fopen(fileName, "w");
        if (file == NULL) {
            printf("无法打开文件 %s\n", fileName);
            return;
        }

        srand(time(NULL)); // 初始化随机数发生器
        for (int i = 0; i < NUM_ARRAYS; i++) {
            int* array = malloc(ARRAY_SIZE * sizeof(int));
            for (int j = 0; j < ARRAY_SIZE; j++) {
                array[j] = rand(); // 生成随机数
            }
            fprintf(file, "%s", array); // 将数组写入文件，每个数组之间用逗号分隔
            free(array); // 释放数组内存
        }

        fclose(file);
        printf("测试数据已生成并保存到文件 %s\n", fileName);
    }


    //读取并排列数据的函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 从文件读取数据并进行排序
    void sortTestData(const char* fileName) {
        FILE* file = fopen(fileName, "r");
        if (file == NULL) {
            printf("无法打开文件 %s\n", fileName);
            return;
        }

        int* array = malloc(ARRAY_SIZE * sizeof(int));
        int size = 0;
        while (fscanf(file, "%d", &array[size]) == 1) {
            size++;
        }
        fclose(file);

        // 使用排序函数对数据进行排序
        // 例如，使用快速排序
        QuickSort_Recursion(array, 0, size - 1);

        // 打印排序后的数据（可选）
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n数据已从文件 %s 读取并排序\n", fileName);

        free(array); // 释放数组内存
    }


    //快排的非递归版本

#include <stdio.h>
#include <stdlib.h>

// 快速排序非递归版本
    void QuickSort(int* a, int low, int high) {
        int i, j;
        int temp[high - low + 1];

        // 归并排序的合并部分
        void Merge(int low, int high, int* temp) {
            int mid = (low + high) / 2;
            int left_end = mid, right_end = high;
            int k = low;

            while (low <= left_end && right_end >= mid + 1) {
                if (a[low] <= a[right_end]) {
                    temp[k++] = a[low++];
                }
                else {
                    temp[k++] = a[right_end--];
                }
            }

            while (low <= left_end) {
                temp[k++] = a[low++];
            }

            while (right_end >= mid + 1) {
                temp[k++] = a[right_end--];
            }

            for (i = 0; i <= high - low; i++) {
                a[low + i] = temp[i];
            }
        }

        // 快速排序的划分部分
        void Partition(int* a, int low, int high) {
            int pivot = a[high];
            int i = low - 1;
            for (int j = low; j <= high - 1; j++) {
                if (a[j] < pivot) {
                    i++;
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            temp = a[i + 1];
            a[i + 1] = a[high];
            a[high] = temp;
        }

        // 快速排序的合并部分
        void MergeSort(int* a, int low, int high) {
            if (low < high) {
                int mid = (low + high) / 2;
                MergeSort(a, low, mid);
                MergeSort(a, mid + 1, high);
                Merge(low, high, temp);
            }
        }

        // 快速排序的非递归部分
        int stack[high - low + 1];
        int top = -1;
        stack[++top] = low;
        stack[++top] = high;

        while (top >= 0) {
            high = stack[top--];
            low = stack[top--];
            MergeSort(a, low, high);
        }
    }

    int main() {
        // 测试快速排序非递归版本
        int array[] = { 10, 7, 8, 9, 1, 5 };
        int n = sizeof(array) / sizeof(array[0]);
        QuickSort(array, 0, n - 1);

        printf("Sorted array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        return 0;
    }
