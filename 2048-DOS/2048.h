int findzeros(int table[4][4])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == 0)
				sum++;
		}
	}
	return sum;
}

int game_over(int table[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j - 1] == table[i][j] || table[j - 1][i] == table[j][i])
				return 0;
		}
	}
	return 1;
}

int new_two(int table[4][4])
{
	int zeros_sum = findzeros(table);
	int order_num = rand() % zeros_sum + 1;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == 0)
				sum++;
			if (sum == order_num)
			{
				table[i][j] = 2;
				if (zeros_sum == 1 && game_over(table))
					return 0;
				return 1;
			}
		}
	}
	return 1;
}

int show_result(int table[4][4], int score)
{
	int sum = 0;
	system("cls");
	cout << "2048" << endl;
	cout << "Score:" << score << endl;
	cout << "\xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xbf\n";
	for (int i = 0; i < 4; i++)
	{
		cout << char(179);
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << table[i][j];
			cout << char(179);
		}
		cout << endl;
		if (i < 3)
			cout << "\xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xb4\n";
		else
			cout << "\xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xd9\n";
	}
	return sum;
}

int deal_arr(int table[4][4],char arrow)
{
	return 0;
}