 #include <stdio.h>
#include <stdlib.h>

int main() {
	int n, head, size, i, j, temp, total = 0;

	printf("Enter number of requests: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter requests:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter initial head position: ");
	scanf("%d", &head);

	printf("Enter disk size: ");
	scanf("%d", &size);

	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("Order: %d ", head);

	for(i = 0; i < n; i++) {
		if(a[i] >= head) {
			total += abs(head - a[i]);
			head = a[i];
			printf("-> %d ", head);
		}
	}

	total += abs(head - (size - 1));
	head = size - 1;
	printf("-> %d ", head);

	for(i = n - 1; i >= 0; i--) {
		if(a[i] < head) {
			total += abs(head - a[i]);
			head = a[i];
			printf("-> %d ", head);
		}
	}

	printf("\nTotal head movement = %d", total);

	return 0;
}
