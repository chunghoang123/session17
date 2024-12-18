#include<stdio.h>
#include<stdlib.h>
void inArray(int **arr,int *size){
	printf("nhap kich co cua mang: \n");
	scanf("%d",size);
	*arr=(int *)malloc((*size)* sizeof(int));
	if(*arr== NULL){
		printf("loi\n");
		exit(1);
	}
	printf("nhap gia tri vao mang: \n");
	for(int i=0;i<*size;i++){
		printf("arr[%d]",i+1);
		scanf("%d",&(*arr)[i]);
	}
}
void displayArray(int *arr,int size){
	printf("cac gia tri trong mang\n");
	for(int i=0;i<size;i++){
		printf("%d",*(arr+i));
	}
	printf("\n");
}
int arrayLength(int *arr,int size){
	return size;
}
int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}
int max(int *arr,int size){
	int max = *arr;
	for(int i=0;i<size;i++){
		if(*(arr+i)>max){
			max=*(arr+i);
		}
	}
	return max;
}
int main(){
	int *arr=NULL;
	int size=0;
	int pos;
	do{
	printf("\nMENU\n");
	printf("1. Nhap vao so phan tu va tung phan tu\n");
	printf("2. Hien thi cac phan tu trong mang\n");
	printf("3. Tinh do dai mang\n");
	printf("4. Tinh tong cac phan tu trong mang\n");
	printf("5. Hien thi phan tu lon nhat\n");
	printf("6. Thoat\n");
	printf("\nLua chon cua ban: ");
	scanf("%d", &pos);
		switch(pos){
			case 1:{
				inArray(&arr,&size);
				break;
			}
			case 2:{
				if(arr==NULL){
					printf("chu co mang\n");
				}else{
					displayArray(arr,size);
				}
				break;
			}
			case 3:{
				if(arr==NULL){
					printf("chu co mang\n");
				}else{
					printf("do dai mang: %d\n",arrayLength(arr,size));
				}
				break;
			}
			case 4:{
				if(arr==NULL){
					printf("chu co mang\n");
				}else{
					printf("tong cac phan tu trong mang: %d\n",sumArray(arr,size));
				}
				break;	
			}
			case 5:{
				if(arr==NULL){
					printf("chu co mang\n");
				}else{
					printf("phan tu lon nhat trong mang: %d\n",max(arr,size));
				}
				break;
			}
			case 6:{
				printf("thao chuong trinh");
				break;
			default:
				printf("lua chon ko hop le");		
				break;
			}
		}
	}while(pos!=6);
		if(arr!=NULL){
			free(arr);
		}
		return 0;
	
}













