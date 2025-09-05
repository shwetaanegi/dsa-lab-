#include <stdio.h>

#define CAPACITY 100

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid -1;
    }
    return -1;
}

int insertAtPosition(int arr[], int size, int element, int position, int capacity) {
    if(size >= capacity) {
        printf("Array is full, cannot insert\n");
        return size;
    }
    if(position < 0 || position > size) {
        printf("Invalid position\n");
        return size;
    }

    for(int i = size; i > position; i--) {
        arr[i] = arr[i-1];
    }

    arr[position] = element;
    return size + 1;
}

int deleteElement(int arr[], int size, int element) {
    int pos = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            pos = i;
            break;
        }
    }
    if(pos == -1) {
        printf("Element not found, cannot delete\n");
        return size;
    }
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    return size - 1;
}

void printArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int size) {
    // Simple bubble sort to prepare for binary search
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[CAPACITY];
    int size = 0;
    int choice, val, pos, result;

    printf("Enter the number of elements (max %d): ", CAPACITY);
    scanf("%d", &size);
    if(size < 0 || size > CAPACITY) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

   while(1) {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Linear Search\n");
    printf("4. Binary Search\n");
    printf("5. Print Array\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter position to insert (0 to %d): ", size);
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            size = insertAtPosition(arr, size, val, pos, CAPACITY);
            printf("After insertion: ");
            printArray(arr, size);
            break;

        case 2:
            if(size == 0) {
                printf("Array is empty, nothing to delete.\n");
                break;
            }
            printf("Enter element to delete: ");
            scanf("%d", &val);
            size = deleteElement(arr, size, val);
            printf("After deletion: ");
            printArray(arr, size);
            break;
            case 3:
                if(size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter value to search (Linear Search): ");
                scanf("%d", &val);
                result = linearSearch(arr, size, val);
                if(result == -1)
                    printf("Element %d not found.\n", val);
                else
                    printf("Element %d found at position %d.\n", val, result);
                break;

            case 4:
                if(size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                sortArray(arr, size); // binary search requires sorted array
                printf("Enter value to search (Binary Search): ");
                scanf("%d", &val);
                result = binarySearch(arr, size, val);
                if(result == -1)
                    printf("Element %d not found.\n", val);
                else
                    printf("Element %d found at position %d.\n", val, result);
                break;

            case 5:
                printArray(arr, size);
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
