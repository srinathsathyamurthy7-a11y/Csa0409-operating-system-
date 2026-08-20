#include <stdio.h>

int main() {
	int n, start, i;

	printf("Enter number of blocks: ");
	scanf("%d", &n);

	printf("Enter starting block: ");
	scanf("%d", &start);

	printf("Allocated blocks: ");
	for (i = 0; i < n; i++) {
		printf("%d ", start + i);
	}

	return 0;
}
