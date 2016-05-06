#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define len(x) ((int)log10(x)+1)

struct node{
	int freq;
	char symbol;
	struct node *right, *left;
};


typedef struct node Node;


int frequencies[27] = {70, 20, 24, 64, 110, 21, 30, 74, 98, 97, 45, 10, 32, 12, 70, 20, 2, 54, 40, 76, 28, 90, 42, 1, 20, 1, 107 };

int smaller(Node *a[], int diff){
	int small;
	int i = 0;

	while (a[i]->freq == -1){
		i++;
	}
	small = i;
	if (i == diff){
		i++;
		while (a[i]->freq == -1){
			i++;
		}
		small = i;
	}

	for (i = 0; i < 27; i++){
		if (a[i]->freq == -1)
			continue;
		if (i == diff)
			continue;
		if ((a[i]->freq) < (a[small]->freq))
			small = i;
	}

	return small;
}

void HuffmanTree(Node **tree){
	Node *temp;
	Node *a[27];
	int i, subtrees = 27;
	int small1, small2;

	for (i = 0; i < 27; i++){
		a[i] = malloc(sizeof(Node));
		a[i]->freq = frequencies[i];
		a[i]->symbol = i;
		a[i]->left = NULL;
		a[i]->right = NULL;
	}

	while (subtrees>1){
		small1 = smaller(a, -1);
		small2 = smaller(a, small1);
		temp = a[small1];
		a[small1] = malloc(sizeof(Node));
		a[small1]->freq = temp->freq + a[small2]->freq;
		a[small1]->symbol = 127;
		a[small1]->left = a[small2];
		a[small1]->right = temp;
		a[small2]->freq = -1;
		subtrees--;
	}

	*tree = a[small1];

	return;
}

void table(int code_table[], Node *tree, int code){
	if (tree->symbol < 27){
		code_table[(int)tree->symbol] = code;
	}
	else{
		table(code_table, tree->left, code * 10 + 1);
		table(code_table, tree->right, code * 10 + 2);
	}

	return;
}

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

	fprintf(stderr, "original bits = %d\n", original * 8);
	fprintf(stderr, "Compressed bits = %d\n", compress);
	
	return;
}

int main(){
	Node *tree;
	int code_table[27];
	int compress;
	char filename[20];
	FILE *input, *output;

	HuffmanTree(&tree);
	table(code_table, tree, 0);

	printf("\nPlease enter file name:\n");
	scanf("%s", filename);

	input = fopen(filename, "r");
	output = fopen("output.txt", "w");

	compress(input, output, code_table);

	return 0;
}
