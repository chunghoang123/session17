#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void inString(char **str) {
    char buffer[1000];
    printf("\nNhap chuoi: ");
    getchar();
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
void printString(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi!\n");
    } else {
        printf("\nChuoi la: %s\n", str);
    }
}
void countCharacters(char *str, int *letters, int *digits, int *specials) {
    *letters = *digits = *specials = 0;
    if (str == NULL) {
        printf("\nChua nhap chuoi!\n");
        return;
    }
    for (char *p = str; *p != '\0'; p++) {
        if (isalpha(*p)) {
            (*letters)++;
        } else if (isdigit(*p)) {
            (*digits)++;
        } else if (!isspace(*p)) {
            (*specials)++;
        }
    }
}
int main() {
    char *str = NULL;
    int pos;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &pos);
        switch (pos) {
            case 1:{
                inString(&str);
                break;
            }
            case 2:{
                printString(str);
                break;
            }
            case 3:{
                int letters, digits, specials;
                countCharacters(str, &letters, &digits, &specials);
                printf("\nSo luong chu cai: %d\n", letters);
                break;
            }
            case 4:{
                int letters, digits, specials;
                countCharacters(str, &letters, &digits, &specials);
                printf("\nSo luong chu so: %d\n", digits);
                break;
            }
            case 5:{
                int letters, digits, specials;
                countCharacters(str, &letters, &digits, &specials);
                printf("\nSo luong ky tu dac biet: %d\n", specials);
                break;
            }
            case 6:{
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");	
			}
		}
    } while (pos != 6);
    if (str != NULL) {
        free(str);
    }
    return 0;
}

