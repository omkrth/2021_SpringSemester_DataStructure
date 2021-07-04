#pragma warning (disable : 4996)
#include <stdio.h>
#define SIZE 50 // ������ ����� ��ũ�� �Լ��� ����
#define TRUE 1 // ���� ��츦 1�̶�� ��ũ�� �Լ��� ����
#define FALSE 0 // ������ ��츦 0�̶�� ��ũ�� �Լ��� ����
typedef char data; // ���ÿ� �� �ڷ����� character������ ����

typedef struct arr_stack { //�迭�� ���� ������ ����ü�� ���� 
	data arr[SIZE];// ���� ���ο� �����͸� ���� �迭 ����. �迭 ũ��� 50�̴�.
	int top; // �迭�� top �ε����� ���������� ����.
}arr_stack;

typedef arr_stack Stack; // ������ �̸��� typedef�� ���� ��ȯ

void Initialize(Stack *pstack) { // ���� �ʱ⼳�� �Լ�
	pstack->top = -1; // top�� -1�� ���������ν� ������ �ʱ�ȭ�Ѵ�.
}

int isEmpty(Stack* pstack) { // �߰� 1, ������ ������� Ȯ���ϱ� ���� isEmpty �Լ�
	if (pstack->top == -1) // top �ε����� -1�̸� ����. ��, �ʱ�ȭ�ǰ� �ƹ��͵� �ȵ��� �� ���¸� ����.
		return TRUE; // 1�� ��ȯ�Ѵ�.
	else // ���ÿ� �����Ͱ� ������� ���
		return FALSE; // 0�� ��ȯ�Ѵ�.
}

void isFull(Stack* pstack) { // ������ ���� ���ִ��� üũ�ϴ� isFull �Լ� ����
	if (pstack->top == SIZE-1) // ������ top index ��ȣ�� ������ �ִ� ������� ������ üũ
		printf("TRUE\n"); // ������ ���� á�ٴ� �ǹ��� TRUE ���
	else 
		printf("FALSE\n"); // �ٸ��� ���� ���� �ʾҴٴ� �ǹ��� FALSE ���
}

void push(Stack* pstack, data data) { // push �Լ�
	pstack->top += 1; // top �ε����� 1���� ��Ų��.
	pstack->arr[pstack->top] = data; //������ ���� ĭ�� data�� �����Ѵ�.
}

void pop(Stack* pstack) { // pop �Լ�
	int E_result = isEmpty(pstack);
	if (E_result == TRUE) { // isEmpty���� 1�� ��ȯ�Ǿ��� ��. �� ������ ������� �� ����
		printf("Error!\n"); // error �޽��� ���
	}
	else{
		printf("Return : %c\n", pstack->arr[pstack->top]);
		pstack->top -= 1; // ������ top �ε����� 1 ���ҽ�Ű�鼭 �����͸� �����Ѵ�
	}
}

data peek(Stack* pstack) { // peek �Լ�
	int E_result = isEmpty(pstack);
	if (E_result == TRUE) { //isEmpty���� 1�� ��ȯ�Ǿ��� ��. �� ������ ������� �� ����
		printf("Error!\n");// error �޽��� ���
	}
	else return pstack->arr[pstack->top]; // �迭�� ������ ������ top �ε����� �ִ� �����͸� ��ȯ�Ѵ�.
}

int traverse_rear(Stack* pstack, int pos) { // ������ ��� ��ҷ� pos ������ �ű�
	pos = pstack->top+1; // ������ ������ ž�ε��� ��ȣ�� ����
	return pos; // ���ŵ� ������ ���� ��ȯ
}

int element_count(Stack* pstack) { // ���ÿ� ����ִ� ����� ������ ���� element_count �Լ� ����
	int s_cnt= pstack->top + 1; // ������ ��Ҹ� üũ�ϴ� s_cnt ���� ���� �� top �ε��� ����+1��ŭ ����. 
	return s_cnt; // ���ÿ� ����ִ� ����� ������ ���� s_cnt ���� ��ȯ
}

void top(Stack* pstack) { // ������ top �ε��� ��ȣ�� �����͸� �̾Ƴ��� ���� top �Լ� ����
	printf("���� ������ top �ε��� ��ȣ( %d, %c )\n", pstack->top, pstack->arr[pstack->top]);
	//���� ������ top �ε��� ��ȣ�� �� �����͸� ���. ���� ������ 0������ �����Ѵ�.
}

void replace(Stack* pstack, char data) { // top �ε����� ����ִ� ��Ҹ� ��ü�ϱ� ���� replace �Լ� ����
	pop(pstack); // ���� �ֻ�ܿ� �ִ� ��Ҹ� ������.
	push(pstack, data); // ���� �ֻ�ܿ� ���ο� ��Ҹ� push �Ѵ�.
}

int search(Stack* pstack, data data) { // ���ϴ� ��Ұ� �ִ��� üũ�ϱ� ���� search �Լ� ����. isMember�� �����ȴ�.
	int i; // for���� ���� int i ����
	for (i = pstack->top; i >= 0; i--) //i�� top �ε������� ������ ���ϴܱ��� ���ҽ�Ű�� �˻�
		if (pstack->arr[i] == data) return i; //arr[i]�� ã�� ������ ��Ұ� �ִ��� üũ�ϰ�, �ִٸ� �� �迭 ��ȣ�� ��ȯ
	return -1; // ã�� ���ߴٸ� -1�� ��ȯ�Ѵ�.
}

int isMember(Stack* pstack, data data) { // ã�� ��Ұ� ���ÿ� �ִ��� �Ǵ��ϱ� ���� isMember �Լ� ����.
	int s = search(pstack, data); // ��ġ�� ����� int s�� �����Ѵ�.
	if (s == -1) return FALSE; // ���� ã�� ���ߴٸ�, ã�� ��Ұ� ���ٴ� �ǹ̷� FASE�� ��ȯ�Ѵ�.
	else if (s >= 0) return TRUE; // search�� �����ߴٸ�, 0�̻��� ���ϰ��� ����Ƿ� TRUE�� ��ȯ�Ѵ�.
}

void median(Stack* pstack) { // �߰� 2, ������ ��� ��Ҹ� ã�� ���� median �Լ� ����
	char med; // ������ ��� ��Ҹ� ������ med ������ ���� ����
	if (!(pstack->top % 2)) { // ���� ���ÿ� ��� ��� ������ Ȧ����� ����
		med = pstack->arr[pstack->top / 2]; // med ������ ������ ��� ��Ҹ� ����
		printf("���� ������ ��� ��Ҵ�: %c\n", med); // ���� ������ ��� ��� ���
	}
	else { // ���� ���ÿ� ��� ��� ������ ¦����� ����
		med = pstack->arr[(pstack->top + 1) / 2]; // med ������ ������ ��� ��Ҹ� ����
		printf("���� ������ ��� ��Ҵ�: %c\n", med); // ���� ������ ��� ��� ���
	}
}

void print(Stack* pstack, int pos) { // print �Լ�
	int i;
	int E_result = isEmpty(pstack);
	if (E_result == 1) { //isEmpty���� 1�� ��ȯ�Ǿ��� ��. �� ������ ������� �� ����
		printf(" ");// error �޽��� ���
	}
	else {
		for (i = 0; i < (pstack->top) + 1; i++) { //i=0���� top�ε����� ��ȣ���� ����
			if (i == pos - 1) printf(" (%c) ", pstack->arr[i]); //arr[i]�� �����Ͱ��� �����
			else printf(" %c ", pstack->arr[i]);
		}
	}
}

void help() { // �߰� 3, ����ڰ� ��ɾ Ȯ���ϱ� ���� help �Լ� ����
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
	Stack stack; // ���� ����
	Initialize(&stack); // ���� �ʱ�ȭ
	char input[30] = { 0, }; // �ʱ� ��ɾ ���� input ���� ����
	char command[30] = { 0, }; //input���� ������ ����� ��ȣ�� ��Ҹ� ���� command ���� ����
	int i; // for���� Ȱ��� i ����
	int pos = 0; // ���� ������ ���� �������� ��Ÿ���� ���� pos ���� ����
	char pk; // peek �Լ��� ���� pk ������ ���� ����
	int cnt; // element_count �Լ��� ���� cnt ���� ����
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
		printf("[���ϴ� ����� �Է��ϼ���] >> "); // ��ɾ� �Է¹���
		scanf("%[^\n]", input); // ������ �����Ͽ� input�� ��ɾ ����
		getchar(); // �Է� ���۸� ������

		int j = 0; // ������ ���� j ����
		for (i = 0; i < strlen(input); i++) { // input ���̸�ŭ for�� �ݺ�
			if (input[i] != ' ') { // input�� ��Ұ� ������ �ƴ� �� ����
				command[j] = input[i]; //command ������ 0������ ��ȣ�� ���ڸ� ä���ִ´�.
				j++;
			}
		}

		for (i = 0; i < strlen(command); i += 2) { //��ȣ�� ���ڸ� ���� command ��ɾ��, ��ȣ�� �о�� ���� 2ĭ�� ����.
			//ex) command[] = '+a+b+c' ��� 0�� �ε����� +, 2�� �ε����� +, 3�� �ε����� +�� �ν��Ѵ�. 
			if (command[i] == '+') { //��ȣ�� +�� �� ����
				push(&stack, command[i + 1]); // push �Լ� ����
				pos++; // pos ���� 1 ����
			}

			else if (command[i] == '-') { //��ȣ�� -�� �� ����
				int e_result = isEmpty(&stack); // ������ ����ִ��� ���� üũ�Ѵ�.
				pop(&stack); // pop �Լ� ����
				pos--; // pos ���� 1 ����
				if (e_result == TRUE) pos++; // ���� ������ ����ִ� ���¶��, pos ������ �ٽ� �������ش�.

				if (command[i + 1] == '-') { // -�� �������� ������ ���� ���� if�� command�� --�� �� ����ȴ�.
					do {
						pop(&stack); // pop �Լ� ����
						pos--; // pos ���� 1 ����
						if (e_result == TRUE) pos++; // ���� ������ ����ִ� ���¶��, pos ������ �ٽ� �������ش�.
					} while (command[i + 1] != '-'); // command�� ��� �˻����� ��, ---...�� �κ��� ���� �� ���� �����Ѵ�.
				}
			}

			else if ((command[i] >= 48 && command[i] <= 57) && command[i + 1] == '-') { // 5-, 4-�� ���ڿ� -�� �������� �� ����
				int loop = command[i] - '0'; // -�� ��� �������� int�� loop ������ ����
				for (i = 0; i < loop; i++) { // -�� �ݺ��ϰ��� �ϴ� Ƚ����ŭ for�� ����
					pop(&stack); // pop �Լ� ����
					pos--; // pos ���� 1 ����
				}
			}

			else if (command[i] == '<')	pos = 1; // pos ������ 1�� ������.


			else if (command[i] == '>') pos = traverse_rear(&stack, pos); // pos ������ �� ������ ������

			else if (command[i] == 'C' || command[i] == 'c') Initialize(&stack); // ������ ���� �ʹٸ�, Initialize �Լ��� ���� ���ʱ�ȭ �Ѵ�.
			//����ڰ� �빮�ڸ� �Է��ϴ� �ҹ��ڸ� �Է��ϴ� ��� ���� ���ǹ��� ®��.

			else if (command[i] == 'E' || command[i] == 'e') { // �߰�1, ������ ����ִ��� üũ�ϴ� isEmpty �Լ� ����
				int e_result = isEmpty(&stack);// e_result��� ������ isEmpty �Լ��� ��ȯ�� ����
				if (e_result == TRUE) printf("���� ������ ����ֽ��ϴ�.\n");
				else printf("���� ���ÿ��� ��Ұ� ����ִ� �����Դϴ�.\n");
			}

			else if (command[i] == 'F' || command[i] == 'f') isFull(&stack); // ������ ���� ���ִ��� üũ�� isFull �Լ� ����

			else if (command[i] == 'H' || command[i] == 'h') help(); // �߰� 3, ��ɾ Ȯ���ϱ� ���� help �Լ� ����

			else if (command[i] == 'L' || command[i] == 'l') break; // ������ ����Ʈ�ϱ� ���Ѵٸ�, �ݺ����� ��� ����Ʈ �ܰ�� �Ѿ�� �Ѵ�.

			else if (command[i] == 'M' || command[i] == 'm') median(&stack); // �߰� 2, median �Լ� ����

			else if (command[i] == 'P' || command[i] == 'p') { // peek �Լ� ����
				pk = peek(&stack); // pk ������ ������ peek �Լ��� ��ȯ���� ����
				printf("--------------------\n");
				printf("���� ������ top index data: %c", pk); // ���� ������ top �ε��� ���ڸ� ���
				printf("\n--------------------\n");
			}

			else if (command[i] == 'Q' || command[i] == 'q') { // �߰� 3, ���α׷� ���Ḧ ���� �Լ� ����
				printf("���α׷��� �����մϴ�. BYE BYE!");
				return 0; // ���α׷� ����
			}

			else if (command[i] == 'T' || command[i] == 't') top(&stack); // top �Լ� ����

			else if (command[i] == '#') {
				cnt = element_count(&stack); // ������ cnt ������ element_count �Լ��� ����� ��ȯ
				printf("���� ���ÿ� ����ִ� ����� ������: %d\n", cnt); // ���� ���ÿ� ����ִ� ����� ���� ���

			}

			else if (command[i] == '=') replace(&stack, command[i + 1]); // replace �Լ� ����

			else if (command[i] == '?') {
				int result = isMember(&stack, command[i + 1]); // ������ result ������ isMember �Լ��� ����� ����
				if (result == TRUE) printf("TRUE\n"); // result�� TRUE���, TRUE��� ���
				else printf("FALSE\n"); // result�� FALSE���, FALSE��� ���
			}
		}
		//��� �ܰ�
		printf("====================\n"); // ��� ���
		print(&stack, pos); // print �Լ��� ������ ������ pos ���� ����
		printf("\n====================\n"); // ��� ���
		for (i = 0; i < strlen(command); i++) { // command�� �ʱ�ȭ�ϱ� ���� for��
			command[i] = ' '; // command�� �ٽ� ����ְ� �ݺ����� ó������ ���ư�.
		}
	}
}

