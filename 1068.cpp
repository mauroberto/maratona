#include<stdio.h>
#include<stack>
using namespace std;

int main(){
  char e[1010];

  while(scanf("%s", e) != EOF){
    stack<char> s;
    int i ;
    for(i = 0; e[i] != '\0'; i++){
      if(e[i] == '('){
        s.push('(');
      }else if(e[i] == ')'){
        //printf("%c\n", e[i]);
        if(!s.empty() && s.top() == '('){
          s.pop();
        }else{
          printf("incorrect\n");
          break;
        }
      }
    }
    //printf("%s\n", e);
    if(s.empty() && e[i] == '\0'){
      printf("correct\n");
    }else if(!s.empty()){
      printf("incorrect\n");
    }

    //printf("\n");
  }

  return 0;
}
