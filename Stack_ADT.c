#pragma warning (disable : 4996)
#include <stdio.h>
#define SIZE 50 // 스택의 사이즈를 매크로 함수로 지정
#define TRUE 1 // 참인 경우를 1이라는 매크로 함수로 지정
#define FALSE 0 // 거짓인 경우를 0이라는 매크로 함수로 지정
typedef char data; // 스택에 들어갈 자료형을 character형으로 지정

typedef struct arr_stack { //배열로 만든 스택을 구조체로 선언 
	data arr[SIZE];// 스택 내부에 데이터를 넣을 배열 선언. 배열 크기는 50이다.
	int top; // 배열의 top 인덱스를 정수형으로 선언.
}arr_stack;

typedef arr_stack Stack; // 스택의 이름을 typedef를 통해 변환

void Initialize(Stack *pstack) { // 스택 초기설정 함수
	pstack->top = -1; // top에 -1을 대입함으로써 스택을 초기화한다.
}

int isEmpty(Stack* pstack) { // 추가 1, 스택이 비었는지 확인하기 위한 isEmpty 함수
	if (pstack->top == -1) // top 인덱스가 -1이면 실행. 즉, 초기화되고 아무것도 안들어온 빈 상태면 실행.
		return TRUE; // 1을 반환한다.
	else // 스택에 데이터가 들어있을 경우
		return FALSE; // 0을 반환한다.
}

void isFull(Stack* pstack) { // 스택이 가득 차있는지 체크하는 isFull 함수 선언
	if (pstack->top == SIZE-1) // 스택의 top index 번호가 스택의 최대 사이즈와 같은지 체크
		printf("TRUE\n"); // 같으면 가득 찼다는 의미의 TRUE 출력
	else 
		printf("FALSE\n"); // 다르면 가득 차지 않았다는 의미의 FALSE 출력
}

void push(Stack* pstack, data data) { // push 함수
	pstack->top += 1; // top 인덱스를 1증가 시킨다.
	pstack->arr[pstack->top] = data; //스택의 다음 칸에 data를 대입한다.
}

void pop(Stack* pstack) { // pop 함수
	int E_result = isEmpty(pstack);
	if (E_result == TRUE) { // isEmpty에서 1이 반환되었을 때. 즉 스택이 비어있을 때 실행
		printf("Error!\n"); // error 메시지 출력
	}
	else{
		printf("Return : %c\n", pstack->arr[pstack->top]);
		pstack->top -= 1; // 스택의 top 인덱스를 1 감소시키면서 데이터를 삭제한다
	}
}

data peek(Stack* pstack) { // peek 함수
	int E_result = isEmpty(pstack);
	if (E_result == TRUE) { //isEmpty에서 1이 반환되었을 때. 즉 스택이 비어있을 때 실행
		printf("Error!\n");// error 메시지 출력
	}
	else return pstack->arr[pstack->top]; // 배열로 구성된 스택의 top 인덱스에 있는 데이터를 반환한다.
}

int traverse_rear(Stack* pstack, int pos) { // 스택의 상단 요소로 pos 변수를 옮김
	pos = pstack->top+1; // 포지션 변수를 탑인덱스 번호로 갱신
	return pos; // 갱신된 포지션 변수 반환
}

int element_count(Stack* pstack) { // 스택에 들어있는 요소의 개수를 세는 element_count 함수 선언
	int s_cnt= pstack->top + 1; // 스택의 요소를 체크하는 s_cnt 변수 선언 및 top 인덱스 숫자+1만큼 대입. 
	return s_cnt; // 스택에 들어있는 요소의 개수와 같은 s_cnt 변수 반환
}

void top(Stack* pstack) { // 스택의 top 인덱스 번호와 데이터를 뽑아내기 위한 top 함수 선언
	printf("현재 스택의 top 인덱스 번호( %d, %c )\n", pstack->top, pstack->arr[pstack->top]);
	//현재 스택의 top 인덱스 번호와 그 데이터를 출력. 스택 순서는 0번부터 시작한다.
}

void replace(Stack* pstack, char data) { // top 인덱스에 들어있는 요소를 교체하기 위한 replace 함수 선언
	pop(pstack); // 스택 최상단에 있는 요소를 빼낸다.
	push(pstack, data); // 스택 최상단에 새로운 요소를 push 한다.
}

int search(Stack* pstack, data data) { // 원하는 요소가 있는지 체크하기 위한 search 함수 선언. isMember와 연동된다.
	int i; // for문을 위한 int i 선언
	for (i = pstack->top; i >= 0; i--) //i를 top 인덱스부터 스택의 최하단까지 감소시키며 검색
		if (pstack->arr[i] == data) return i; //arr[i]에 찾는 데이터 요소가 있는지 체크하고, 있다면 그 배열 번호를 반환
	return -1; // 찾지 못했다면 -1을 반환한다.
}

int isMember(Stack* pstack, data data) { // 찾는 요소가 스택에 있는지 판단하기 위한 isMember 함수 선언.
	int s = search(pstack, data); // 서치의 결과를 int s에 저장한다.
	if (s == -1) return FALSE; // 만약 찾지 못했다면, 찾는 요소가 없다는 의미로 FASE를 반환한다.
	else if (s >= 0) return TRUE; // search에 성공했다면, 0이상의 리턴값이 생기므로 TRUE를 반환한다.
}

void median(Stack* pstack) { // 추가 2, 스택의 가운데 요소를 찾기 위한 median 함수 선언
	char med; // 스택의 가운데 요소를 저장한 med 문자형 변수 선언
	if (!(pstack->top % 2)) { // 현재 스택에 담긴 요소 개수가 홀수라면 실행
		med = pstack->arr[pstack->top / 2]; // med 변수에 스택의 가운데 요소를 대입
		printf("현재 스택의 가운데 요소는: %c\n", med); // 현재 스택의 가운데 요소 출력
	}
	else { // 현재 스택에 담긴 요소 개수가 짝수라면 실행
		med = pstack->arr[(pstack->top + 1) / 2]; // med 변수에 스택의 가운데 요소를 대입
		printf("현재 스택의 가운데 요소는: %c\n", med); // 현재 스택의 가운데 요소 출력
	}
}

void print(Stack* pstack, int pos) { // print 함수
	int i;
	int E_result = isEmpty(pstack);
	if (E_result == 1) { //isEmpty에서 1이 반환되었을 때. 즉 스택이 비어있을 때 실행
		printf(" ");// error 메시지 출력
	}
	else {
		for (i = 0; i < (pstack->top) + 1; i++) { //i=0부터 top인덱스의 번호까지 증가
			if (i == pos - 1) printf(" (%c) ", pstack->arr[i]); //arr[i]의 데이터값을 출력함
			else printf(" %c ", pstack->arr[i]);
		}
	}
}

void help() { // 추가 3, 사용자가 명령어를 확인하기 위한 help 함수 선언
	printf("Stack_ADT program\n");
	printf("==========H E L P==========\n");
	printf("PUSH\t\t: +(data)\n");
	printf("POP\t\t: -\n");
	printf("TRAVERSE_FRONT\t: <\n");
	printf("TRAVERSE_REAR\t: >\n");
	printf("REPLACE \t: =(data)\n");
	printf("IS FULL \t: F\n");
	printf("TOP \t\t: T\n");
	printf("IS_MEMBER \t: ?\n");
	printf("ELEMENT COUNT \t: #\n");
	printf("PEEK \t\t: P\n");
	printf("CLEAR \t\t: C\n");
	printf("PRINT \t\t: L\n");
	printf("Find Center \t: M\n");
	printf("HELP \t\t: H\n");
	printf("QUIT \t\t: Q\n");
}

int main()
{
	Stack stack; // 스택 선언
	Initialize(&stack); // 스택 초기화
	char input[30] = { 0, }; // 초기 명령어를 받을 input 변수 선언
	char command[30] = { 0, }; //input에서 공백을 지우고 기호와 요소만 남길 command 변수 선언
	int i; // for문에 활용될 i 선언
	int pos = 0; // 스택 내에서 현재 포지션을 나타내기 위한 pos 변수 선언
	char pk; // peek 함수에 사용될 pk 문자형 변수 선언
	int cnt; // element_count 함수에 사용될 cnt 변수 선언
	char r_str[SIZE];

	printf("Stack_ADT program\n");
	printf("==========H E L P==========\n");
	printf("PUSH\t\t: +(data)\n");
	printf("POP\t\t: -\n");
	printf("TRAVERSE_FRONT\t: <\n");
	printf("TRAVERSE_REAR\t: >\n");
	printf("REPLACE \t: =(data)\n");
	printf("IS FULL \t: F\n");
	printf("TOP \t\t: T\n");
	printf("IS_MEMBER \t: ?\n");
	printf("ELEMENT COUNT \t: #\n");
	printf("PEEK \t\t: P\n");
	printf("CLEAR \t\t: C\n");
	printf("PRINT \t\t: L\n");
	printf("Find Center \t: M\n");
	printf("HELP \t\t: H\n");
	printf("QUIT \t\t: Q\n");

	while (1) {
		printf("[원하는 명령을 입력하세요] >> "); // 명령어 입력받음
		scanf("%[^\n]", input); // 공백을 포함하여 input에 명령어를 저장
		getchar(); // 입력 버퍼를 지워줌

		int j = 0; // 정수형 변수 j 선언
		for (i = 0; i < strlen(input); i++) { // input 길이만큼 for문 반복
			if (input[i] != ' ') { // input의 요소가 공백이 아닐 때 실행
				command[j] = input[i]; //command 변수의 0번부터 기호와 문자를 채워넣는다.
				j++;
			}
		}

		for (i = 0; i < strlen(command); i += 2) { //기호와 문자만 남은 command 명령어에서, 기호만 읽어내기 위해 2칸씩 띄운다.
			//ex) command[] = '+a+b+c' 라면 0번 인덱스의 +, 2번 인덱스의 +, 3번 인덱스의 +를 인식한다. 
			if (command[i] == '+') { //기호가 +일 때 실행
				push(&stack, command[i + 1]); // push 함수 실행
				pos++; // pos 변수 1 증가
			}

			else if (command[i] == '-') { //기호가 -일 때 실행
				int e_result = isEmpty(&stack); // 스택이 비어있는지 먼저 체크한다.
				pop(&stack); // pop 함수 실행
				pos--; // pos 변수 1 감소
				if (e_result == TRUE) pos++; // 만약 스택이 비어있던 상태라면, pos 변수를 다시 복구해준다.

				if (command[i + 1] == '-') { // -가 연속으로 등장할 때를 위한 if문 command가 --일 때 실행된다.
					do {
						pop(&stack); // pop 함수 실행
						pos--; // pos 변수 1 감소
						if (e_result == TRUE) pos++; // 만약 스택이 비어있던 상태라면, pos 변수를 다시 복구해준다.
					} while (command[i + 1] != '-'); // command를 계속 검사했을 때, ---...인 부분이 끝날 때 까지 실행한다.
				}
			}

			else if ((command[i] >= 48 && command[i] <= 57) && command[i + 1] == '-') { // 5-, 4-등 숫자와 -가 결합했을 때 실행
				int loop = command[i] - '0'; // -를 몇번 실행할지 int형 loop 변수에 저장
				for (i = 0; i < loop; i++) { // -를 반복하고자 하는 횟수만큼 for문 실행
					pop(&stack); // pop 함수 실행
					pos--; // pos 변수 1 감소
				}
			}

			else if (command[i] == '<')	pos = 1; // pos 변수를 1로 돌린다.


			else if (command[i] == '>') pos = traverse_rear(&stack, pos); // pos 변수를 맨 끝으로 보낸다

			else if (command[i] == 'C' || command[i] == 'c') Initialize(&stack); // 스택을 비우고 싶다면, Initialize 함수를 통해 재초기화 한다.
			//사용자가 대문자를 입력하던 소문자를 입력하던 상관 없게 조건문을 짰다.

			else if (command[i] == 'E' || command[i] == 'e') { // 추가1, 스택이 비어있는지 체크하는 isEmpty 함수 선언
				int e_result = isEmpty(&stack);// e_result라는 변수에 isEmpty 함수의 반환값 저장
				if (e_result == TRUE) printf("현재 스택은 비어있습니다.\n");
				else printf("현재 스택에는 요소가 들어있는 상태입니다.\n");
			}

			else if (command[i] == 'F' || command[i] == 'f') isFull(&stack); // 스택이 가득 차있는지 체크할 isFull 함수 실행

			else if (command[i] == 'H' || command[i] == 'h') help(); // 추가 3, 명령어를 확인하기 위한 help 함수 실행

			else if (command[i] == 'L' || command[i] == 'l') break; // 스택을 프린트하길 원한다면, 반복문을 벗어나 프린트 단계로 넘어가게 한다.

			else if (command[i] == 'M' || command[i] == 'm') median(&stack); // 추가 2, median 함수 실행

			else if (command[i] == 'P' || command[i] == 'p') { // peek 함수 실행
				pk = peek(&stack); // pk 문자형 변수에 peek 함수의 반환값을 저장
				printf("--------------------\n");
				printf("현재 스택의 top index data: %c", pk); // 현재 스택의 top 인덱스 문자를 출력
				printf("\n--------------------\n");
			}

			else if (command[i] == 'Q' || command[i] == 'q') { // 추가 3, 프로그램 종료를 위한 함수 실행
				printf("프로그램을 종료합니다. BYE BYE!");
				return 0; // 프로그램 종료
			}

			else if (command[i] == 'T' || command[i] == 't') top(&stack); // top 함수 실행

			else if (command[i] == '#') {
				cnt = element_count(&stack); // 정수형 cnt 변수에 element_count 함수의 결과값 반환
				printf("현재 스택에 들어있는 요소의 개수는: %d\n", cnt); // 현재 스택에 들어있는 요소의 개수 출력

			}

			else if (command[i] == '=') replace(&stack, command[i + 1]); // replace 함수 실행

			else if (command[i] == '?') {
				int result = isMember(&stack, command[i + 1]); // 정수형 result 변수에 isMember 함수의 결과값 저장
				if (result == TRUE) printf("TRUE\n"); // result가 TRUE라면, TRUE라고 출력
				else printf("FALSE\n"); // result가 FALSE라면, FALSE라고 출력
			}
		}
		//출력 단계
		printf("====================\n"); // 출력 양식
		print(&stack, pos); // print 함수에 스택의 정보와 pos 변수 전달
		printf("\n====================\n"); // 출력 양식
		for (i = 0; i < strlen(command); i++) { // command를 초기화하기 위한 for문
			command[i] = ' '; // command를 다시 비워주고 반복문의 처음으로 돌아감.
		}
	}
}

