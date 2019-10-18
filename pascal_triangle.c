#include <stdio.h>
#include <stdlib.h>
void print_pascal(int size){

	puts("1");
	if(size == 1){
		return;
	}
	puts("1\t1");
	if(size == 2){
		return;
	}

	int* odd = malloc(sizeof(int) * size);
	int* even = malloc(sizeof(int) * (size));

	even[0] = 1;
	even[1] = 1;

	for(int i = 3; i < size; i++){
			
		odd[0] = 1;
		odd[i - 1] = 1;
			
		printf("%d\t", odd[0]);

		for(int j = 0; j < (i - 2); j++){

			odd[j + 1] = even[j] + even[j + 1];
			printf("%d\t", odd[j + 1]);
		}
		printf("%d\t\n", odd[i - 1]);

		i += 1;

		even[0] = 1;
		even[i - 1] = 1;
			
		printf("%d\t", even[0]);
			
		for(int j = 0; j < (i - 2); j++){
			even[j + 1] = odd[j] + odd[j + 1];
			printf("%d\t", even[j + 1]);
		}
		printf("%d\t\n", even[i - 1]);

	}
	if((size > 2) && (size % 2 == 1)){
		printf("1\t");
		for(int i = 0; i < (size - 2); i++)
			printf("%d\t", (even[i] + even[i + 1]));
		printf("1\n");
	}	

	free(odd);
	free(even);
}

int main(void){

	int size = 0;
	//main loop
	while(1){
		puts("How many lines would you like in your pascal triangle?");
		puts("Enter 0 to quit");

		//input start
		while((scanf("%d", &size) != 1) || (size < 0)){
			while(getchar() != '\n')
				; //gets rid of(flushes) the input that scanf denied
			puts("Enter a positive number please...");
		}
		while(getchar() != '\n')
				; //if scanf reads an integer successfully,
				  //gets rid of the rest of the input such as
				  //characters or newline or decimal part of a
				  //float if the user enters on purpose or accidentally

		//output start
		puts("");
		if(size == 0)
			break;

		print_pascal(size);
		puts("");
	}
	return 0;
}
