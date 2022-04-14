

[TOC]



### 문자

- ##### C언어에서 문자를 처리하는 방법에 대해 학습한다.

- ##### 문자와 버퍼의 관계를 바르게 이해하고 학습한다.





##### 아스키코드

1. C프로그램의 문자는 아스키코드를 따른다.
2. 아스키코드는 0~127중에 1바이트 문자로 구성되며 주요문자를 출력하게 해준다

~~~
0 : 48
A : 65
a : 97
~~~



1. 캐릭터형 자체에 숫자를 넣어서 처리할 수 있다.
2. 문자 입출력에서 형식지정자로 %c를 사용한다.

~~~c
#include <stdio.h>

int main() {
 char a = 65;
 printf("%c\n",a);
}
~~~







#### 문자

1. 문자열을 처리할 때 버퍼의 개념이 많이 사용된다.
2. 버퍼란 임시적으로 특정한 데이터를 저장하기 위한 목적으로 사용된다.
3. c프로그램은 기본적으로 사용자가 의도하지 않아도 자동으로 버퍼를 이용해 입출력을 처리한다.



##### 입력버퍼로 인해 흔히 발생하는 오류

~~~c
#include <stdio.h>

int main() {
 int a;
 char c;
 scanf("%d",&a);
 printf("%d\n",a);
 scanf("%c",&c);
 printf("%c\n",c);

 return 0;
}
~~~

- printf가 a를 출력한 후, 입력버퍼에 있던 개행(\n)을 char c에 입력한다.



##### 남아있는 버퍼를 항상 지울 수 있도록 수정

~~~c
#include <stdio.h>

int main() {
 int a;
 char c;
 scanf("%d",&a);
 printf("%d\n",a);
 int temp;
 // 한 자씩 받아서 파일의 끝이거나 개행문자를 만나면 입력을 멈추므로, 항상 입력버퍼를 비워야한다.
 while((temp=getchar()) != EOF && temp != '\n') {}
 scanf("%c",&c);
 printf("%c\n",c);

 return 0;
}

~~~

- getchars() 는 단 하나의 문자를 입력받는다.





### 문자열

- 전통적인 c언어에서 문자열을 다루는 방법에 대해 학습합니다.
- 다양한 문자열 관련 함수를 익히고 활용합니다.



문자열의개념

- 문자열은 말 그대로 문자들의 배열이다.
- 문자열은 컴퓨터 메모리의 구조상에서 마지막에 널을 포함합니다.

| 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| H    | E    | L    | L    | O    |      | W    | O    | R    | L    | D    | \0   |

- \0 == null (존재하지 않는다.)

- 널은 문자열의 끝을 알리는 목적으로 사용된다.
- printf()를 실행하면, 내부적으로 null을 만날 때까지 출력한다.





문자열과 포인터

- 문자열 형태로 포인터를 사용하면 포인터에 특정한 문자열의 주소를 넣게된다.
- 다음 코드는 "Hello World" 문자열을 읽기전용으로 메모리에 넣은 뒤에 그 위치를 처리한다.
- 이러한 문자열을 '문자열리터럴'이라고 한다. 이는 컴파일러가 알아서 메모리주소를 결정한다.

~~~c
#include <stdio.h>
int main() {
 char *a = "Hello World";
 printf("%s\n",a);
 return 0;
}
~~~



- 포인터로 문자열을 선언 후, 배열처럼 사용 가능하다.

~~~c
#include <stdio.h>
int main() {
 char *a = "Hello World";
 printf("%c\n",a[1]);
 printf("%c\n",a[3]);
 printf("%c\n",a[5]);
 return 0;
}
~~~





문자열입출력함수

- 문자열입출력을 수행한다.
- scan()는 공백을 만날때까지 입력받지만, get()은 공백까지 포함하여 한 줄을 입력받는다.

~~~c
#include <stdio.h>
int main() {
 char a[100];
 gets(a);
 printf("%s\n",a);
 return 0;
}
~~~



- get()은 버퍼의 크기를 벗어나버려도 입력을 받는다.
- c11표준부터는 버퍼의 크기를 지키는 gets_s()가 추가되었다.

~~~c
#include <stdio.h>
int main() {
 char a[100];
 gets_s(a,sizeof(a));
 printf("%s\n",a);
 return 0;
}
~~~





문자열 처리를 위한 다양한 함수

- c언어의 문자열처리와 관련해서는 기본적인 문자열 함수를 알아야 한다.
- <string.h> 에 포함되어있다.

| 함수명   | 설명                                                         |
| -------- | ------------------------------------------------------------ |
| strlen() | 문자열의 길이를 반환한다.                                    |
| strcmp() | 문자열1이문자열2보다 사전적으로 앞에있으면 -1, 뒤에있으면 1 반환 |
| strcpy() | 문자열을 복사한다.                                           |
| strcat() | 문자열 1에 문자열 2를 더한다.                                |
| strata() | 문자열1에 문자열2가 어떻게 포함되어있는 지 를 반환한다.      |



~~~c
#include <stdio.h>
int main() {
 char a[20] = "seongtaek kim";
 printf("문자열길이 : %d\n",strlen(a));
 return 0;
}
~~~



~~~c
#include <stdio.h>
int main() {
 char a[20] = "seongtaek kim";
 char b[20] = "staek";
 printf("문자열비교 : %d\n",strcmp(a,b));
 return 0;
}
~~~



- c언어에서는 기본적으로 a=b와 같은 방식으로는 문자열을 복사할 수 없다.

~~~c
#include <stdio.h>
int main() {
 char a[20] = "seongtaek kim";
 char b[20] = "staek";
 strcpy(a,b);
 printf("복사된문자열 : %s\n",a);
 return 0;
}
~~~

- b 문자열을 a에 복사하는 것임.





~~~c
#include <stdio.h>
int main() {
 char a[20] = "seongtaek kim";
 char b[20] = "staek";
 strcat(a,b);
 printf("합쳐진문자열 : %s\n",a);
 return 0;
}
~~~

- a+b 형태로 문자열이 출력됨.



- 긴 문자열에서 짧은 문자열을 찾아 그 위치를 반환한다.
- 짧은 문자열을 찾은 주소 값 자체를 반환하므로 단순히 출력하면, 찾은 이후 모든 문자열이 반환된다.

~~~c
#include <stdio.h>
int main() {
 char a[20] = "seongtaek kim";
 char b[20] = "seongtaek";
 printf("문자열 : %s\n", strstr(a,b));
 return 0;
}
~~~

- seongtaek 이 출력된다.







### 포인터배열

- 배열은 포인터와 동일한 방식으로 동작한다.
- 배열의 이름은 배열의 원소의 첫 번째 주소가 된다.
- 차이점은, 포인터는 변수이고 배열의이름은 상수이다.



##### 배열의 이름이 변수인지 상수인지는 다음 소스로 확인.

~~~c
#include <stdio.h>
int main(void) {
 int a=10;
  int b[10];
  b = &a;
 return 0;
}
~~~

- 문법에러 발생



##### 포인터는 배열처럼 사용할 수 있다.

~~~c
#include <stdio.h>
int main(void) {
 int a[5] = {1,2,3,4,5};
 int *b= a;
 printf("%d\n",b[2]);
 return 0;
}
~~~



##### 배열의 이름은 배열의 첫 번째 원소의 주소이다.

~~~c
#include <stdio.h>
int main(void) {
 int a[5] = {1,2,3,4,5};
 int *b= &a[0];
 printf("%d\n",b[2]);
 return 0;
}
~~~



##### 포인터는 연산을 통해 자료형 크기만큼 이동한다.

~~~c
#include <stdio.h>
int main(void) {
 int a[5] = {1,2,3,4,5};
 int i;
 for(i=0 ; i<5 ; i++) {
  printf("%d ", a+i);
 }
 return 0;
}
~~~

- 정수형 포인터는 4byte씩 이동함.



크기가 10인 double형 배열을 선언했을 때 배열의 시작주소가 xfkrh gksek.

이 때 배열의 마지막 원소의 주소는 ?

~~~c
#include <stdio.h>
int main(void) {
 double b[10];
 printf("%d %d\n",b,b+9);
 return 0;
}
~~~

- x + 9*8 이다.



##### 배열을 포인터처럼 사용해서 각 원소에 접근할 수 있다.

~~~c
#include <stdio.h>
int main(void) {
 int a[5] = {1,2,3,4,5};
 int i;
 for(i=0; i<5 ; i++) {
  printf("%d ",*(a+i));
 }
 return 0;
}
~~~

- a+1 은 a 보다 자료형의 byte 만큼 크다.



~~~c
#include <stdio.h>
int main(void) {
 int a[5] = {1,2,3,4,5};
 int *p= a;
 printf("%d\n", *(p++));
 printf("%d\n", *(++p));
 printf("%d\n", *(p+2));
 return 0;
}
~~~



##### 2차원 배열을 포인터로 처리

~~~c
#include <stdio.h>
int main(void) {
 int a[2][5] = {{1,2,3,4,5},{,6,7,8,9,10}};
 int (*p)[5] = a[1];
 int i;
 for(i=0; i<5; i++) {
  printf("%d",p[0][i]);
 }
 return 0;
}
~~~

- 2번째 행 시작 주소를 포인터에 할당한 후 연속으로 출력







### 동적메모리 할당

- 일반적으로 c언어에서 배열의 경우 사전에 적절한 크기만큼 할당해 주어야 한다.
- 우리가 원하는 만큼만 메모리를 할당해서 사용하고자 한다면 동적메모리 할당을 사용한다.
- 동적이라는 말은 프로그램실행도중 이라는 의미이다.





##### 동적메모리 할당함수

- c언어에선느 malloc() 함수를 이용해 원하는 만큼 메모리 공간을 확보할 수 있다.
- malloc()은 메모리할당에 성공하면 주소를 반환하고, 그렇지 않으면 NULL을 반환한다.
- <stdlib.h> 에 정의되어 있다.





~~~c
#include <stdio.h>
#include <stdlib.h>
int main() {
 int *a = malloc(sizeof(int));
 printf("%d\n",a);
 a = malloc(sizeof(int));
 printf("%d\n",a);
 return 0;
}
~~~

- 동적메모리할당을 수행할 때마다 할당되는 표인터의 주소는 변칙적이다.

- 동적으로 할당된 변수는 힙영역에 저장된다.





- 전동적인 c언어에서는 스택에 선언된 변수는 따로 메모리해제를 안해도 된다.
- 반면, 동적으로 할당된 변수는 반드시 free()로 해제해야 한다.
- 메모리 누수 방지는 코어개발자의 핵심역량이다.





~~~c
#include <stdio.h>
#include <stdlib.h>
int main() {
 int *a = malloc(sizeof(int));
 printf("%d\n",a);
 free(a);
 a = malloc(sizeof(int));
 printf("%d\n",a);
 return 0;
}
~~~

- 할당한 메모리를 해제한 후 다시 할당하면, 같은 메모리주소를 할당받을 확률이 높다.







- 일괄적인 범위의 메모리를 모두 특정한 값으로 설정하기 위해 memset()을 사용한다.
- memset(포인터, 값, 크기);
- 한 바이트 씩 값을 저장하므로 문자열 배열의 처리방식과 흡사하다.
- <string.h>에 정의되어 있다.





##### Memset() 예제 

~~~c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 char *a malloc(100);
 memset(a,'A',100);
 for(int i=0; i<100 ; i++) {
  printf("%c ",a[i]);
 }
 return 0;
}
~~~

- 기존에는 단순히 반복문을 이용해 원소를 처리했으나 memset()은 일반적으로 더 빠르게 동작한다.





##### 2차원포인터 동적할당 예제

~~~c
#include <stdio.h>
#include <stdlib.h>
int main() {
 int** p = (int**)malloc(sizeof(int*)*3);
 for(int i=0 ; i<3; i++) {
   *(p+1) = (int*)malloc(sizeof(int)*3);
 }
 for(int i=0 ; i<3 ; i++) {
   for(int j=0 ; j<3 ; j++) {
     *(*(p+i)+j) = i*3+j;
   } 
 }
  
 for(int i=0 ; i<3 ; i++) {
   for(int j=0 ; j<3 ; j++) {
     printf("%d ",*(*(p+i)+j));
   } 
   printf("\n");
 }
 return 0;

~~~













### 함수포인터

- c언어에서는 함수의 이름을 이용해 특정한 함수를 호출한다.
- 함수 이름은 메모리 주소를 반환한다.



~~~c
#include <stdio.h>
void function() {
 printf("it's my function");
}
int main() {
 printf("%d\n"m function);
 return 0;
}
~~~

함수포인터는 특정한 함수의 반환자료형을 지정하는 방식으로 선언할 수 있다.

함수포인터를 이용하면 형태가 같은 서로 다른기능의 함수를 선택적으로 사용할 수 있다.

반환자료형(*이름)(매개변수) = 함수명;





##### 매개변수 및 반환자료형이 없는 함수포인터

~~~c
#include <stdio.h>

void myFunction() {
 printf("it is my function");
}
void yourFunction() {
	printf("it is your function");
}
int main() {
 void(*fp)() = myFunction;
 fp();
 fp = yourFunction;
 fp();
 return 0;
}
~~~





##### 매개변수 및 반화자료형이 있는 함수포인터

~~~c
#include <stdio.h>
int add(int a, int b) {
 return a+b;
}
int sub(int a, int b) {
 return a-b;
}
int main() {
 int(*fp)(int, int) = add;
 printf("%d\n",fp(10,3));
 fp = sub;
 printf("%d\n",fp(10,3));
 return 0;
}

~~~



##### 함수포인터를 반환하여 사용하기

~~~c
#include <stdio.h>
int add(int a, int b) {
 return a+b;
}
int(*process(char* a))(int, int) {
 printf("%s\n",a);
 return add;
}
int main() {
 printf("%d\n",process("10과20을 더하겠습니다.")(10,20));
 return 0;
}
~~~



#### 정리

##### c언어 프로그램의 모든 함수는 내부적으로 포인터 형태로 관리할 수 있다.

##### 함수포인터는 자주 사용되지 않지만 알고있으면 컴퓨터의 구조를 이해하는데 도움을 준다.

































































































































































































