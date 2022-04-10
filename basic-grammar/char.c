#include <stdio.h>

int main() {
 int a;
 char c;
 scanf("%d",&a);
 printf("%d",a);
 int temp;
 while((temp=getchar()) != EOF && temp != '\n') {}
 scanf("%c",&c);
 printf("%c\n",c);

 return 0;
}
