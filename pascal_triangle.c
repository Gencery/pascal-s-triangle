#include <stdio.h>
#include <stdlib.h>
void print_pascal(int size){

	int* odd = NULL;
	int* even = NULL;

	if(size == 1){
		puts("1");
	}
	else if(size == 2){
		puts("1\n1\t1");
	}
	else{

		odd = malloc(sizeof(int))
			;
		even = malloc(sizeof(int) * 2))
			;

		*odd = 1;
		*even = 1;
		*(even + 1) = 1;


		printf("%d\n", *odd);
		printf("%d\t%d\n", *even, *(even + 1));

		for(int i = 3; i < size; i++){
			
			odd = realloc(odd, sizeof(int) * i)

			*odd = 1;
			*(odd + i - 1) = 1;
			
			printf("%d\t", *(odd));

			for(int j = 0; j < (i - 2); j++){

				*(odd + j + 1) = *(even + j) + *(even + j + 1);
				printf("%d\t", *(odd + j + 1));
			}
			printf("%d\t\n", *(odd + i - 1));

			i += 1;

			even = realloc(even, sizeof(int) * i)
				;
			
			*even = 1;
			*(even + i - 1) = 1;
			
			printf("%d\t", *(even));
			
			for(int j = 0; j < (i - 2); j++){
				*(even + j + 1) = *(odd + j) + *(odd + j + 1);
				printf("%d\t", *(even + j + 1));
			}
			printf("%d\t\n", *(even + i - 1));
		}			
	}
	if((size > 2) && (size % 2 == 1)){
		printf("1\t");
		for(int i = 0; i < (size - 2); i++)
			printf("%d\t", (*(even + i) + *(even + i + 1)));
		printf("1\n");
	}	

	free(odd);
	free(even);
}

int main(void){

	double dsize = 0;
	int size = 0;
	//main loop
	while(1){
		puts("How many lines would you like in your pascal triangle?");
		puts("Enter 0 to quit");
	
		//input start
		while((scanf("%lf", &dsize) != 1) || (dsize < 0)){
			while(getchar() != '\n')
				;
			puts("Enter a positive number please...");
		}
		getchar();
		//input end

		//output start
		puts("");
		size = (int)dsize;
		if(size == 0)
			break;

		print_pascal(size);
		puts("");
		//output end
	}
	return 0;
}
