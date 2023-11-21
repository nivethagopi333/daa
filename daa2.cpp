#include <stdio.h>

int binarySearchUnsorted(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return the index
        }

        // If the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        }
        // If the right half is sorted
        else {
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array of the specified size
    int arr[size];

    // Get array elements from the user
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;

    // Get the target element from the user
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform binary search for unsorted array and print the result
    int result = binarySearchUnsorted(arr, size, target);

    if (result != -1) {
        printf("Found in the position %d\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}

