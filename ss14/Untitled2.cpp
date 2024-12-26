#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return binarySearchRecursive(arr, mid + 1, right, x);
        return binarySearchRecursive(arr, left, mid - 1, x);
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    if (result != -1)
        printf("Phan tu %d duoc tim thay tai vi tri %d (khong de quy)\n", x, result);
    else
        printf("Phan tu %d khong ton tai trong mang (khong de quy)\n", x);

    result = binarySearchRecursive(arr, 0, n - 1, x);
    if (result != -1)
        printf("Phan tu %d duoc tim thay tai vi tri %d (de quy)\n", x, result);
    else
        printf("Phan tu %d khong ton tai trong mang (de quy)\n", x);

    return 0;
}

