#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input;
	input = fopen("input.txt", "r");

	int ubCals, elfSum;
	char n[32];

	ubCals = 0, elfSum = 0;

	while(fgets(n,32,input) != NULL) {
		if(n[0] == '\n') {		// if empty line then check sum against ubCals
			if(elfSum > ubCals) {
				ubCals = elfSum;
			}
			elfSum = 0;
		}
		elfSum += atoi(n);
	}

	printf("Highest calorie haul: %d\n", ubCals);
	return 0;
}
