#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int freq;
	char symbol;
	struct node *right, *left;
};

typedef struct node Node;

void compress(FILE input, FILE output, int code_table[]){
	char bit, c, x = 0;
	int n, lenght, bitsleft = 8;
	int original = 0, compress = 0;

	while ((c = fgetc(input)) != 10){
		original++;
		if (c == 32){
			lenght = len(code_table[26]);
			n = code_table[26];
		}
		else{
			lenght = len(code_table[c - 97]);
			n = code_table[c - 97];
		}

		while (lenght > 0){
			compress++;
			bit = n % 10 - 1;
			n /= 10;
			x = x | bit;
			bitsleft--;
			lenght--;
			if (bitsleft == 0){
				fputc(x, output);
				x = 0;
				bitsleft = 8;
			}

			x = x << 1;
		}
	}

	if (bitsleft != 8){
		x = x << (bitsleft - 1);
		fputc(x, output);
	}

	fprintf(stderr, "Compress bits = %d\n", original * 8);
	fprintf(stderr, "DeCompressed bits = %d\n", compress);
	
	return;
}

int main(){
	Node *tree;
	int code_table[27];
	int compress;
	char filename[20];
	FILE *input, *output;

	printf("\nPlease enter file name:\n");
	scanf("%s", filename);

	input = fopen(filename, "r");
	output = fopen("output.txt", "w");

	decompress(input, output, code_table);

	return 0;
}