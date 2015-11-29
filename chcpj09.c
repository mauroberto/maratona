#include <stdio.h>
int n, m;
int ganha[1000010];

int main(){
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        if (ganha[i] == 0) {
            for (int j = 1; j <= m && i+j <= n; j++) {
                ganha[i+j]++;
            }
        }
    }

    if(ganha[n]) printf("Paula\n");
    else printf("Carlos\n");
    return 0;
}
