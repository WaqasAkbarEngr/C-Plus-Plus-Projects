#include<iostream>
#include<cstdlib>

using namespace std;

char field[10] = { '0','1','2','3','4','5','6','7','8','9' };
bool gameover = false;
bool winner = false;
int input;
int turn_count = 0;

void display()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\t" << field[(3*i + 1)] << "\t|\t" << field[(3 * i + 2)] << "\t|\t" << field[(3 * i + 3)] <<"\t"<< endl;
		if (i < 2)
		{
			cout << "________________|_______________|_________________\n";
		}
	}
}

void check_win()
{
	for (int i = 0; i < 3; i++)
	{
		if (((field[((3 * 1) + (i - 2))] == field[((3 * 2) + (i - 2))]) &&
			(field[((3 * 2) + (i - 2))] == field[((3 * 3) + (i - 2))])) ||
			((field[3*i+1]==field[3*i+2])&&(field[3*i+2]==field[3*i+3])))
		{
			winner = true;
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		if (field[1 + (2 * i)] == field[5] && field[5] == field[5+(4-2*i)])
		{
			winner = true;
		}
	}
}
char toss()
{
	int coin = rand() % 2 + 1;
	if (coin == 1)
	{
		return '1';
	}
	if (coin == 2)
	{
		return '2';
	}
}

char change_turn()
{
	if (field[0] == '1')
	{
		return '2';
	}
	if (field[0] == '2')
	{
		return '1';
	}
}

void main()
{
		field[0] = toss();

		while (!gameover)
		{
			system("cls");
			display();

			if (winner)
			{
				cout << "Player " << field[0] << " has won the game!!!!!\n";
				gameover = true;
				break;
			}

			if ((winner==false) && (turn_count == 9))
			{
				cout << "Game is Draw!!!!!\n";
				gameover = true;
				break;
			}

			cout << "Its Player " << field[0] << " turn\n";
			cout << "Choose number to place your mark: ";
			cin >> input;
			turn_count++;
			
			if (field[0] == '1')
			{
				field[input] = 'O';
			}
			
			if (field[0] == '2')
			{
				field[input] = 'X';
			}
			
			check_win();
			field[0] = change_turn();
		}

	system("pause");
}