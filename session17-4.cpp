#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
void inArray(int **arr, int *size) {
    printf("\nNhap so phan tu: ");
    scanf("%d", size);
    *arr = (int *)malloc((*size) * sizeof(int));
    if (*arr == NULL) {
        printf("\nLoi cap phat bo nho!\n");
        exit(1);
    }
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
void printEvenNumbers(int *arr, int size) {
    printf("\nCac so chan trong mang: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void printPrimeNumbers(int *arr, int size) {
    printf("\nCac so nguyen to trong mang: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void reverseArray(int *arr, int size) {
    printf("\nMang sau khi dao nguoc: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void searchElement(int *arr, int size) {
    int element;
    printf("\nNhap phan tu can tim: ");
    scanf("%d", &element);
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("\nPhan tu %d duoc tim thay tai vi tri %d\n", element, i + 1);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("\nPhan tu %d khong ton tai trong mang\n", element);
    }
}
int main() {
    int *arr = NULL;
    int size = 0;
    int pos;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &pos);
        switch (pos) {
            case 1:{
                inArray(&arr, &size);
                break;
            }
            case 2:{
                if (arr != NULL) {
                    printEvenNumbers(arr, size);
                } else {
                    printf("\nChua nhap mang!\n");
                }
                break;
            }
            case 3:{
                if (arr != NULL) {
                    printPrimeNumbers(arr, size);
                } else {
                    printf("\nChua nhap mang!\n");
                }
                break;
            }
            case 4:{
                if (arr != NULL) {
                    reverseArray(arr, size);
                } else {
                    printf("\nChua nhap mang!\n");
                }
                break;
            }
            case 5:{
                if (arr != NULL) {
                    int sortChoice;
                    printf("\n1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("\nLua chon cua ban: ");
                    scanf("%d", &sortChoice);
                    if (sortChoice == 1) {
                        sortArray(arr, size, true);
                    } else if (sortChoice == 2) {
                        sortArray(arr, size, false);
                    } else {
                        printf("\nLua chon khong hop le!\n");
                    }
                } else {
                    printf("\nChua nhap mang!\n");
                }
                break;
            }
            case 6:{
                if (arr != NULL) {
                    searchElement(arr, size);
                } else {
                    printf("\nChua nhap mang!\n");
                }
                break;
            }
            case 7:{
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
    		}
		}
    } while (pos != 7);
    if (arr != NULL) {
        free(arr);
    }
    return 0;
}
