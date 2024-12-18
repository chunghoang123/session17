#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void inString(char **str) {
    char buffer[1000];
    printf("\nNhap chuoi: ");
    getchar(); // Clear buffer
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("\nLoi\n");
        exit(1);
    }
    strcpy(*str, buffer);
}
void printReverseString(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi!\n");
    } else {
        printf("\nChuoi dao nguoc la: ");
        for (int i = strlen(str) - 1; i >= 0; i--) {
            putchar(str[i]);
        }
        printf("\n");
    }
}
int countWords(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi!\n");
        return 0;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}
void compareStrings(char *str1, char *str2) {
    if (str1 == NULL || str2 == NULL) {
        printf("\nChua nhap du chuoi!\n");
        return;
    }
    if (strlen(str1) > strlen(str2)) {
        printf("\nChuoi moi ngan hon chuoi ban dau.\n");
    } else if (strlen(str1) < strlen(str2)) {
        printf("\nChuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("\nHai chuoi co do dai bang nhau.\n");
    }
}
void toUpperCase(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi!\n");
        return;
    }
    for (char *p = str; *p != '\0'; p++) {
        *p = toupper(*p);
    }
    printf("\nChuoi sau khi chuyen sang chu in hoa: %s\n", str);
}
void appendString(char **str1, char *str2) {
    if (*str1 == NULL || str2 == NULL) {
        printf("\nChua nhap du chuoi!\n");
        return;
    }
    *str1 = (char *)realloc(*str1, (strlen(*str1) + strlen(str2) + 1) * sizeof(char));
    if (*str1 == NULL) {
        printf("\nLoi cap phat bo nho!\n");
        exit(1);
    }
    strcat(*str1, str2);
    printf("\nChuoi sau khi noi: %s\n", *str1);
}
int main() {
    char *str = NULL;
    char buffer[1000];
    int pos;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &pos);

        switch (pos) {
            case 1:{
                inString(&str);
                break;
            }
            case 2:{
                printReverseString(str);
                break;
			}
            case 3:{
                char *tempStr = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(tempStr, str);
                printf("\nSo luong tu trong chuoi: %d\n", countWords(tempStr));
                free(tempStr);
                break;
            }
            case 4:{
                printf("\nNhap chuoi khac: ");
                getchar(); // Clear buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 
                compareStrings(str, buffer);
                break;
            }
            case 5:{
                toUpperCase(str);
                break;
            }
            case 6:{
                printf("\nNhap chuoi khac de noi vao chuoi ban dau: ");
                getchar(); // Clear buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 
                appendString(&str, buffer);
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
    if (str != NULL) {
        free(str);
    }
    return 0;
}

