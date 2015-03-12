#include <iostream>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "2048.h"

int table[4][4];

int main()
{
	int score;
	char arrow, ch = 'c';
	SetConsoleOutputCP(437);
	while (ch = 'c')
	{
		score = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				table[i][j] = 0;
			}
		}
		new_two(table);
		new_two(table);
		show_result(table, score);
		while ((ch = getchar()) != 'q')
		{
			if (ch != -32)
				continue;
			arrow = getchar();
			score = score + deal_arr(table, arrow);
		}
	}
}