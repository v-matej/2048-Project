#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75	
#define KEY_ESC 27

using namespace std;

int get_score();

int board[4][4];
int max_s = get_score();

void start()
{
	cout << "\t\tWelcome to the:" << endl;                                   
	cout << " ___ ___ ___ ___    _____ _____ _____ _____ "<<endl;
	cout << "|_  |   | | | . |  |   __|  _  |     |   __|"<<endl;
	cout << "|  _| | |_  | . |  |  |  |     | | | |   __|"<<endl;
	cout << "|___|___| |_|___|  |_____|__|__|_|_|_|_____|" << endl << endl;
	cout << "To play use the arrow keys, and for exiting use Esc." << endl;
	cout << "Press Enter to start." << endl;
	char ch;
	ch=_getch();
}

void gameover()
{
	cout << " _____ _____ _____ _____    _____ _____ _____ _____" << endl;
	cout << "|   __|  _  |     |   __|  |     |  |  |   __| __  |" << endl;
	cout << "|  |  |     | | | |   __|  |  |  |  |  |   __|    -|" << endl;
	cout << "|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|" << endl;                                           
}

void init_board()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}
}

bool game_ended() 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			if (board[i][j] == 0) 
			{
				return false;
			}
		}
	}


	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (i > 0 && board[i][j] == board[i - 1][j]) 
			{
				return false;
			}
			if (i < 4 - 1 && board[i][j] == board[i + 1][j])
			{
				return false;
			}
			if (j > 0 && board[i][j] == board[i][j - 1]) 
			{
				return false;
			}
			if (j < 4 - 1 && board[i][j] == board[i][j + 1]) 
			{
				return false;
			}
		}
	}

	return true;
}

int score()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum += board[i][j];
		}
	}
	return sum;
}

void print_board()
{
	system("CLS");
	cout << "MAX SCORE: " << max_s << endl;
	cout << "SCORE: " << score() << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "| "<<setw(4);
			if (board[i][j] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << board[i][j];
			}
		}
		cout << "|" << endl;
	}
}

void addRandom()
{
	int rand_i = rand() % 4;
	int rand_j = rand() % 4;
	while (board[rand_i][rand_j] != 0)
	{
		rand_i = rand() % 4;
		rand_j = rand() % 4;
	}
	board[rand_i][rand_j] = 2;
}

void moveLeft() {
	bool moved = false;
	for (int i = 0; i < 4; i++) {
		int current_col = 0;
		int next_col = current_col + 1;
		while (next_col < 4) {
			while (next_col < 4 && board[i][next_col] == 0) {
				next_col++;
			}
			if (next_col >= 4) {
				break;
			}
			if (board[i][current_col] == 0) {
				board[i][current_col] = board[i][next_col];
				board[i][next_col] = 0;
				moved = true;
			}
			else if (board[i][current_col] == board[i][next_col]) {
				board[i][current_col] *= 2;
				board[i][next_col] = 0;
				current_col++;
				next_col++;
				moved = true;
			}
			else {
				current_col++;
				if (current_col == next_col) {
					next_col++;
				}
			}
		}
	}
	if (moved)
	{
		addRandom();
	}
}

void moveRight() {
	bool moved = false;
	for (int i = 0; i < 4; i++) {
		int current_col = 4 - 1;
		int next_col = current_col - 1;
		while (next_col >= 0) {
			while (next_col >= 0 && board[i][next_col] == 0) {
				next_col--;
			}
			if (next_col < 0) {
				break;
			}
			if (board[i][current_col] == 0) {
				board[i][current_col] = board[i][next_col];
				board[i][next_col] = 0;
				moved = true;
			}
			else if (board[i][current_col] == board[i][next_col]) {
				board[i][current_col] *= 2;
				board[i][next_col] = 0;
				current_col--;
				next_col--;
				moved = true;
			}
			else {
				current_col--;
				if (current_col == next_col) {
					next_col--;
				}
			}
		}
	}
	if (moved)
	{
		addRandom();
	}
}

void moveUp() {
	bool moved = false;
	for (int j = 0; j < 4; j++) {
		int current_row = 0;
		int next_row = current_row + 1;
		while (next_row < 4) {
			while (next_row < 4 && board[next_row][j] == 0) {
				next_row++;
			}
			if (next_row >= 4) {
				break;
			}
			if (board[current_row][j] == 0) {
				board[current_row][j] = board[next_row][j];
				board[next_row][j] = 0;
				moved = true;
			}
			else if (board[current_row][j] == board[next_row][j]) {
				board[current_row][j] *= 2;
				board[next_row][j] = 0;
				current_row++;
				next_row++;
				moved = true;
			}
			else {
				current_row++;
				if (current_row == next_row) {
					next_row++;
				}
			}
		}
	}
	if (moved)
	{
		addRandom();
	}
}

void moveDown() {
	bool moved = false;
	for (int j = 0; j < 4; j++) {
		int current_row = 4 - 1;
		int next_row = current_row - 1;
		while (next_row >= 0) {
			while (next_row >= 0 && board[next_row][j] == 0) {
				next_row--;
			}
			if (next_row < 0) {
				break;
			}
			if (board[current_row][j] == 0) {
				board[current_row][j] = board[next_row][j];
				board[next_row][j] = 0;
				moved = true;
			}
			else if (board[current_row][j] == board[next_row][j]) {
				board[current_row][j] *= 2;
				board[next_row][j] = 0;
				current_row--;
				next_row--;
				moved = true;
			}
			else {
				current_row--;
				if (current_row == next_row) {
					next_row--;
				}
			}
		}
	}
	if (moved)
	{
		addRandom();
	}
}

void save_score()
{
	ofstream fout;
	fout.open("max_score.txt");
	fout << score()<<"\n";
	fout.close();
}

int get_score()
{
	int max;
	ifstream fin;
	fin.open("max_score.txt");
	fin >> max;
	fin.close();
	return max;
}

int main()
{
	bool ENDGAME = false;
	bool STOP = false;
	char move;
	srand(time(0));
	start();
	init_board();
	addRandom();
	addRandom();
	print_board();
	while (!ENDGAME&&!STOP)
	{
		switch (move= _getch())
		{
		case KEY_UP:
			moveUp();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_RIGHT:
			moveLeft();
			break;
		case KEY_LEFT:
			moveRight();
			break;
		case KEY_ESC:
			STOP = true;
			break;
		default:
			cout << "Unesen krivi znak." << endl;
			break;
		}
		print_board();
		ENDGAME = game_ended();
	}
	gameover();
	if(score()>max_s)
		save_score();
}
