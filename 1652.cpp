#include<stdio.h>

char ir[22][22];
char ir2[22][22];

int main(){
  int l, n;

  scanf("%d %d", &l, &n);

  for(int i = 0; i<l; i++){
    scanf("%s", ir[i]);
    scanf("%s", ir2[i]);
  }

  char p[22];

  while(n--){
    scanf("%s", p);
    bool a = false;

    for(int j=0; j<l; j++){
      int i;
      for(i = 0; p[i] != '\0'; i++){
        if(p[i] != ir[j][i]){
          break;
        }
      }

      if(p[i] == '\0'){
        printf("%s\n", ir2[j]);
        a = true;
      }
    }

    if(a){
      continue;
    }
    int i;
    for(i = 0; p[i] != '\0'; i++);
    int l = i;


    if(p[l-1] == 'y' && p[l-2] != 'a' && p[l-2] != 'e' && p[l-2] != 'i' && p[l-2] != 'o' && p[l-2] != 'u'){
      p[l-1] = '\0';
      printf("%sies\n", p);
      a = true;
    }

    if(a){
      continue;
    }

    if(p[l-1] == 'o' || (p[l-1] == 'h' && p[l-2] == 's') || (p[l-1] == 'h' && p[l-2] == 'c') || p[l-1] == 'x' || p[l-1] == 's'){
      printf("%ses\n", p);
      a = true;
    }

    if(a){
      continue;
    }

    printf("%ss\n", p);
  }

  return 0;
}
