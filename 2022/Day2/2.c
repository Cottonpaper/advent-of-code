#include <stdio.h>
#include <stdlib.h>

int totalPoints(char o, char u) {
	// A - Rock, B - Paper, C - Scissors
	// X - Rock, Y - Paper, Z - Scissors

	int oI = o - 'A';		// store shapes as ints starting @ 0
	int uI = u - 'X';

	int pointTable[3][3] = {	//	[your move] * [opponent]
		{1+3, 1+0, 1+6},	    //	shape points + outcome points
		{2+6, 2+3, 2+0},
		{3+0, 3+6, 3+3}
	};

	//printf("%d\t%d\t=\t%d\n", uI, oI, pointTable[uI][oI]);
	return pointTable[uI][oI];
}

int cnvrtShape(char o, char u) {

	int oI = o - 'A';
	int uI = u - 'X';

	char shapeTable[3][3] = {
		{'Z', 'X', 'Y'},
		{'X', 'Y', 'Z'},
		{'Y', 'Z', 'X'}
	};

	return shapeTable[oI][uI];
}

int main() {
	FILE *input;
	input = fopen("input.txt", "r");

	char buffer[5];
	char o[2500], u[2500];	// store both players moves' in separate arrays
	int i = 0;				// 2 moves per line * 2500 lines
	int sum = 0;

	while(fgets(buffer,5,input) != NULL) {
		o[i] = buffer[0];
		u[i] = buffer[2];
		i++;
	}
	for(int j = 0; j < 2500; j++) {
		u[j] = cnvrtShape(o[j], u[j]);
		sum += totalPoints(o[j], u[j]);
	}

	printf("Total Sum: %d\n", sum);

	return 0;
}
