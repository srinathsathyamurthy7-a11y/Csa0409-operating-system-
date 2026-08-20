
#include <stdio.h>

int main() {
	int n, index, i, block;

	printf("Enter number of blocks: ");
	scanf("%d", &n);

	printf("Enter index block: ");
	scanf("%d", &index);

	printf("Enter block numbers:\n");
	for(i = 0; i < n; i++) {
		scanf("%d", &block);
		printf("Index[%d] -> Block %d\n", i, block);
	}

	return 0;
}
