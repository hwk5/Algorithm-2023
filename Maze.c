#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 현재 위치를 나타내는 구조체
	int x;
	int y;
} Current;
typedef struct { // 스택 구조체 선언
	Current data[100];
	int top;
} Stack;
char maze[10][10] = { // 미로 생성(1 은 벽, 0은 길, S는 출발점, F는 도착점)
{'1','1','1','1','1','1','1','1','1'},
{'1','0','0','1','0','1','1','1','1'},
{'1','0','0','0','0','0','0','1','0'},
{'1','0','1','1','0','1','0','0','0'},
{'1','0','1','1','S','1','1','1','0'},
{'1','0','1','1','0','0','0','0','0'},
{'1','0','0','1','0','1','0','0','1'},
{'1','0','0','0','0','1','0','0','1'},
{'1','1','1','1','F','1','1','1','1'},
};
void push(Stack* s, Current data) { // 스택 push 함수
	if (s->top == 99) { // 스택이 꽉 차있는 상황
		printf("스택 오버플로우\n"); // 스택 오버플로우 출력
		return;
	}
	else { // 스택이 꽉 차있지 않은 상황
		s->top++; // top에 1을 더하고
		s->data[s->top].x = data.x; // Current 구조체의 x값에 스택의 data 배
		//열의 '스택의 top'번째에 있는 값의 x값을 저장
			s->data[s->top].y = data.y; // Current 구조체의 y값에 스택의 data 배
		//열의 '스택의 top'번째에 있는 값의 y값을 저장
	}
}
Current pop(Stack* s) { // 스택 pop 함수
	if (s->top == -1) { // 스택이 비어있는 상황
		printf("스택 언더플로우\n"); // 스택 언더플로우 출력
		return;
	}
	return s->data[(s->top)--]; // 스택 내의 Current 구조체의 data 배열의 '스택의
	//top'번째에 있는 값을 반환 후, 1 감소
}
void Find(Stack* s, int x, int y) { // 미로의 길을 찾는 함수
	if (x < 0 || y < 0 || x > 10 || y > 10) { // x, y 값이 미로의 크기를 벗어난 값일때의 예외 처리
			return;
	}
	if (maze[x][y] != '#' && maze[x][y] != '1') { // 미로의 벽이거나 방문하지 않은곳일 때 
			Current temp; // x, y값을 저장할 Current 구조체의 temp 변수 선언
		temp.x = x; // temp의 x값에 x값 저장
		temp.y = y; // temp의 y값에 y값 저장
		push(s, temp); // 해당 x, y값을 스택에 push
	}
}
int main(void) {
	Stack s; // 스택 구조체 선언
	Current c; // Current 구조체 선언
	int i, j, x, y; // 사용할 변수 선언
	s.top = -1; // 스택의 top을 -1로 초기화
	for (i = 0; i < 10; i++) { // 시작점 탐색
		for (j = 0; j < 10; j++) {
			if (maze[i][j] == 'S') {
				c.x = i;
				c.y = j;
			}
		}
	}
	printf("이동 경로\n");
	printf("시작 지점 (%d, %d) -> ", c.x, c.y); // 시작 지점의 좌표 출력
	while (maze[c.x][c.y] != 'F') { // 도착점에 도달할 때까지 반복
		x = c.x; // x값에 Current 구조체의 x값 저장
		y = c.y; // y값에 Current 구조체의 y값 저장
		maze[x][y] = '1'; // 방문한 곳 표시
		Find(&s, x + 1, y); // 이동 가능한 곳 탐색: 오른쪽
		Find(&s, x - 1, y); // 이동 가능한 곳 탐색: 왼쪽
		Find(&s, x, y + 1); // 이동 가능한 곳 탐색: 위
		Find(&s, x, y - 1); // 이동 가능한 곳 탐색: 아래
		if (s.top == -1) { // 이동 가능한 곳이 없을 때
			printf("이동경로 탐색 실패.\n");
			return 0;
		}
		else { // 이동 가능할 곳이 있을 때
			c = pop(&s); // 스택에서 pop해서 Current 구조체에 저장
			printf("(%d, %d) -> ", c.x, c.y); // 좌표 출력
		}
	}
	printf("미로 탈출\n");
	return 0;
}
