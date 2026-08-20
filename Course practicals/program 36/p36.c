#include <stdio.h>

int main(void) {
	int n, i;
	int block[20];

	printf("Enter number of blocks: ");
	scanf("%d", &n);

	printf("Enter block numbers:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &block[i]);

	printf("First block: %d\n", block[0]);
	printf("Last block: %d\n", block[n - 1]);

	printf("Linked blocks:\n");
	for (i = 0; i < n - 1; i++)
		printf("%d -> %d\n", block[i], block[i + 1]);

	printf("%d -> NULL\n", block[n - 1]);

	return 0;
}
