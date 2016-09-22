#include <stdio.h>
float v[6] = {0.0, 4.0, 4.5, 5.0, 2.0, 1.5};

int main(){
	int id, q;

	scanf("%d %d", &id, &q);

	printf("Total: R$ %.2f\n", v[id]*q);
	return 0;
}
