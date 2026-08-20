#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, head, i, total = 0;

	printf("Enter number of requests: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter requests:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter initial head position: ");
	scanf("%d", &head);

	printf("Order: %d ", head);

	for (i = 0; i < n; i++) {
		total += abs(head - a[i]);
		head = a[i];
		printf("-> %d ", head);
	}

	printf("\nTotal head movement = %d\n", total);

	return 0;
}
