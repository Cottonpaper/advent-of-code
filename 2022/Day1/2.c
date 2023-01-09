#include <stdio.h>
#include <stdlib.h>

/*
Problem: Return the total calories carried by the three elves
carrying the most calories
*/

int sort(int arr[], int n) {
	int i, j;

	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]) {
				
				int temp = arr[j];	// swap i/j
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int sum3 = (arr[n - 1] + arr[n - 2] + arr[n - 3]);

	return sum3;
}

int main() {
	FILE *input;
	input = fopen("input.txt", "r");

	char buffer[32];
	int e[256];
	int sum = 0, i = 0;

	while(fgets(buffer,32,input) != NULL) {
		if(buffer[0] == '\n') {
			e[i] = sum;
			sum = 0;
			i++;
		}
		sum += atoi(buffer);
	}
	int eLen = sizeof(e) / sizeof(e[0]);
	int sum3 = sort(e, eLen);

	//for(int o = 0; o < eLen; o++) printf("%d\n", e[o]);

	printf("Sum of top three elves: %d\n", sum3);
	return 0;
}