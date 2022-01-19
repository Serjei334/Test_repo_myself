#include<iostream> 
#include<random>
#include<chrono>
#include<stdlib.h>

using namespace std;


int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

void ClearConsole() {
	system("cls");
}

enum TCell : char {
	CROSS = 'X',
	ZERO = 'O',
	EMPTY = '_'
};

enum TProgress {
	In_progress,
	Player_won,
	AI_Won,
	Draw,
	NotStarted
};

struct TCoord {
	size_t y;
	size_t x;
};

struct TGame {
	TCell** ppField{ nullptr };
	const size_t size{ 3 };
	TCell human{EMPTY};
	TCell ai{EMPTY};
	size_t turn{ 0 };
	TProgress progress{ In_progress };
};

void GameInit(TGame& g) {
	g.ppField = new TCell * [g.size];
	for (size_t i = 0; i < g.size; i++) {
		g.ppField[i] = new TCell[g.size];
	}

	for (size_t y = 0; y < g.size; y++) {
		for (size_t x = 0; x < g.size; x++) {
			g.ppField[y][x] = EMPTY;	
		}
	}

	if (getRandomNum(0, 100) > 50) {
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else {
		g.ai = CROSS;
		g.human = ZERO;
		g.turn = 1;
	}

}

void GameDeinit(TGame& g) {

	for (size_t i = 0; i < g.size; i++) {
		delete [] g.ppField[i];
	}
	delete[] g.ppField;
	g.ppField = nullptr;
}

void PrintGame(const TGame& g) {
	cout << "    1   2   3\n   ___________\n";//разметка столбцов
	for (size_t y = 0; y < g.size; y++) {
		cout << y +1 <<  " | "; //разметка строк
		for (size_t x = 0; x < g.size; x++) {
			cout << g.ppField[y][x] << " | ";
		}
		cout << endl;
	}
	cout << "\n Human:\t" << g.human << "\n AI\t" << g.ai << "\n";
}

TProgress GetWon(const TGame& g)
{
	for (size_t y = 0; y < g.size; y++) {
		if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
		{
			if (g.ppField[y][0] == g.human) {
				cout << "\n\t\tPLAYER WON";
				return Player_won;
			}
			if (g.ppField[y][0] == g.ai) {
				cout << "\n\t\tAI WON";
				return AI_Won;
			}
		}
	}
	for (size_t x =0; x < g.size; x++) {
		if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
		{
			if (g.ppField[0][x] == g.human) {
				return Player_won;
			}
			if (g.ppField[0][x] == g.ai) {
				return AI_Won;
			}
		}
	}


	if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[0][2]) {
		if (g.ppField[1][1] == g.human) {
			return Player_won;
		}
		if (g.ppField[1][1] == g.ai) {
			return AI_Won;
		}
	}

	if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2]) {
		if (g.ppField[1][1] == g.human) {
			return Player_won;
		}
		if (g.ppField[1][1] == g.ai) {
			return AI_Won;
		}
	}

	bool Draw1 = true;
	for (size_t y = 0; y < g.size; y++) {
		for (size_t x = 0; x < g.size; x++) {
			if (g.ppField[y][x] == EMPTY) {
				Draw1 = false;
				break;
			}
		}
		if (!Draw1) {
			break;
		}
	}
	if (Draw1)
	{ 
		cout << "Draw\n";
		return Draw;
	}

	return In_progress;
}

TCoord getHumanCoord(const TGame& g) {
	TCoord c;
	do {
		cout << "\nEnter x: ";
		cin >> c.x;
		cout << "\nEnter y: ";
		cin >> c.y;
		c.x--;
		c.y--;
	} while (c.x > 2 || c.y > 2 || g.ppField[c.y][c.x] != EMPTY);
	return c;
}

TCoord getAICoord(TGame& g)
{
	//============================================
	
	if (g.ppField[1][1] == EMPTY)
	{
		return { 1,1 };
	}
	
	TCoord buff[4];
	size_t num{ 0 };
	if (g.ppField[0][0] == EMPTY) {
		buff[num] = { 0,0 };
		num++;
	}
	if (g.ppField[2][0] == EMPTY) {
		buff[num] = { 2,0 };
		num++;
	}
	if (g.ppField[0][2] == EMPTY) {
		buff[num] = { 0,2 };
		num++;
	}
	if (g.ppField[2][2] == EMPTY) {
		buff[num] = { 2,2 };
		num++;
	}

	if (num > 0)
	{
		const size_t index = rand() % num;
		return buff[index];
	}

	num = 0;
	if (g.ppField[0][1] == EMPTY) {
		buff[num] = { 0,1 };
		num++;
	}
	if (g.ppField[1][0] == EMPTY) {
		buff[num] = { 1,0 };
		num++;
	}
	if (g.ppField[2][1] == EMPTY) {
		buff[num] = { 2,1 };
		num++;
	}
	if (g.ppField[1][2] == EMPTY) {
		buff[num] = { 1,2 };
		num++;
	}
	if (num > 0)
	{
		const size_t index = rand() % num;
		return buff[index];
	}
	//====================================================


}




int main()
{
	TGame g;
	GameInit(g);
	ClearConsole();
	PrintGame(g);

	do {
		if (g.turn % 2 == 0)
		{
			TCoord c = getHumanCoord(g);
			g.ppField[c.y][c.x] = g.human;
		}
		else
		{
			TCoord c = getAICoord(g);
			g.ppField[c.y][c.x] = g.ai;
		}
		ClearConsole();
		PrintGame(g);
		g.turn++;
		g.progress = GetWon(g);

	} while (g.progress == In_progress);

	

	GameDeinit(g);

	return 0;
}


