#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 미로 보드의 크기
#define BOARD_SIZE 10

// 이동 방향 정의
enum Dir {
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4,
};

// 좌표 구조체
typedef struct {
	int x;
	int y;
} Pos;

// 미로 보드 구조체
typedef struct {
	char tiles[BOARD_SIZE][BOARD_SIZE];
} Board;

// 플레이어 구조체
typedef struct {
	Pos pos;
	int dir;
	Board* board;
} Player;

// 플레이어 초기화 함수
void InitPlayer(Player* player, Board* board) {
	player->pos = board->enterPos;
	player->dir = DIR_UP;
	player->board = board;
}

// 해당 좌표로 이동 가능한지 확인하는 함수
bool CanGo(Board* board, Pos pos) {
	// 미로 보드 범위를 벗어나면 이동 불가
	if (pos.x < 0 || pos.x >= BOARD_SIZE || pos.y < 0 || pos.y >= BOARD_SIZE)
		return false;
	
	// 해당 좌표의 타일이 ' ' (빈 공간)이면 이동 가능
	return (board->tiles[pos.x][pos.y] == ' ');
}

// 플레이어 이동 함수
void MovePlayer(Player* player, Pos pos) {
	player->pos = pos;
}

// 플레이어가 목적지에 도달할 때까지 미로를 탐색하는 함수
void SearchMaze(Player* player) {
	Pos dest = player->board->exitPos;
	Pos front[DIR_COUNT] = {
		{-1, 0},  // UP
		{0, -1},  // LEFT
		{1, 0},   // DOWN
		{0, 1}    // RIGHT
	};

	// 목적지에 도달할 때까지 반복
	while (player->pos.x != dest.x || player->pos.y != dest.y) {
		// 1. 현재 바라보는 방향을 기준으로 오른쪽 방향이 갈 수 있는지 확인
		int newDir = (player->dir - 1 + DIR_COUNT) % DIR_COUNT;
		Pos nextPos = { player->pos.x + front[newDir].x, player->pos.y + front[newDir].y };
		if (CanGo(player->board, nextPos)) {
			// 오른쪽 방향으로 90도 회전
			player->dir = newDir;

			// 앞으로 전진
			MovePlayer(player, nextPos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else {
			nextPos.x = player->pos.x + front[player->dir].x;
			nextPos.y = player->pos.y + front[player->dir].y;
			if (CanGo(player->board, nextPos)) {
				// 앞으로 전진
				MovePlayer(player, nextPos);
			}
			else {
				// 왼쪽 방향으로 90도 회전
				player->dir = (player->dir + 1) % DIR_COUNT;
			}
		}
	}
}

int main() {
	// 미로 보드 초기화 (임의로 작성)
	Board board = {
		{
			{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
			{'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
			{'#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
			{'#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#'},
			{'#', '#', '#', '#', '#', '#', '#', ' ', '#', '#'},
			{'#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#'},
			{'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
			{'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
			{'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
			{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		}
	};

	Player player;
	InitPlayer(&player, &board);
	SearchMaze(&player);

	printf("Player reached the destination!\n");
	printf("Final position: (%d, %d)\n", player.pos.x, player.pos.y);

	return 0;
}
