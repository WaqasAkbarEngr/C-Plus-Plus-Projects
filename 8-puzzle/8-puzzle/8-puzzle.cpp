#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77

#include<iostream>
#include<conio.h>

using namespace std;

void main()
{
start:

	int b[1000][3][3];
	int c[3][3];
	int a[][3]={{11,12,13},{21,22,23},{31,32,33}};
	int chk=0; char y_n; int turn=0;
	int row=0; int column=0;
	int empty=0;int complete=1;int KeyStroke;
	int b1=0; int b2=0; int b3=0; int b4=0; int b5=0; int b6=0; int b7=0; int b8=0;
	int f[1000]; int g=-1; int h=0; int num=0; int back; int next; int num2=-1;
	
	for (int i=0; i<3; i++)
	{
		system("cls");
		for (int j=0; j<3; j++)
		{
			system("cls");

value_entry:
puzzle:
			cout<<"\n\n\n\t\t";
			cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			for (int k=0; k<3; k++)
			{
			cout<<"\t\t";
			cout<<"|\t\t|\t\t|\t\t|\n";
			cout<<"\t\t";
			cout<<"|\t"<<a[k][0]<<"\t|\t"<<a[k][1]<<"\t|\t"<<a[k][2]<<"\t|\n";
			cout<<"\t\t";
			cout<<"|\t\t|\t\t|\t\t|\n";
			cout<<"\t\t";
			cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			}

			if (complete>9)
			{
				goto next;
			}
			
			cout<<"Enter the entry "<<i+1<<j+1<<" = \n";
			cin>>chk;

			if (chk==0)
			{
				row=i;
				column=j;
			}

			for(int x=0; x<3; x++)
			{
				for(int y=0; y<3; y++)
				{
				if (a[x][y]==chk)
				{
					system("cls");
					cout<<"\n\t!!! Number already exists,\n\tEnter again\n";
					goto value_entry;
				}
				else if (chk>=9)
				{
					system("cls");
					cout<<"\n\t!!! Invalid Number,\t(Value must be 0-8),\n\n\tPlease Enter Correct Number\n";
					goto value_entry;
				}
				}
			}
			a[i][j]=chk;
			complete++;
		}
	}

after_ini:
		system("cls");

		goto puzzle;

next:

		if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
		{
			goto finish;
		}

		cout<<"\n\tUse arrow keys to move empty block or press 1 to solve automatically\n";
		
		KeyStroke =	getch();
		if (KeyStroke == 224)
		{
			KeyStroke = getch();
			switch (KeyStroke)
			{
			case UP_ARROW:
				if (row<2)
				{
				empty=a[row][column];
				a[row][column]=a[row+1][column];
				a[row+1][column]=empty;
				row=row+1;
				turn++;
				}
				else
					goto after_ini;
				break;
			case DOWN_ARROW:
				if (row>0)
				{
				empty=a[row][column];
				a[row][column]=a[row-1][column];
				a[row-1][column]=empty;
				row=row-1;
				turn++;
				}
				else
					goto after_ini;
				break;
			case RIGHT_ARROW:
				if (column>0)
				{
				empty=a[row][column];
				a[row][column]=a[row][column-1];
				a[row][column-1]=empty;
				column=column-1;
				turn++;
				}
				else
					goto after_ini;
				break;
			case LEFT_ARROW:
				if (column<2)
				{
				empty=a[row][column];
				a[row][column]=a[row][column+1];
				a[row][column+1]=empty;
				column=column+1;
				turn++;
				}
				else
					goto after_ini;
				break;
			default:
				cout << "Some other key." << endl;
			}
		}
		else if (KeyStroke==49)
		{
			goto solution_using_Astar;
		}

		goto after_ini;

solution_using_Astar:
g++;

num2++;
//step1:
		if (row==2)
		{
		}
		else
		{
				empty=a[row][column];
				a[row][column]=a[row+1][column];
				a[row+1][column]=empty;
				row=row+1;

				if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
		{
			goto finish;
		}

				for (int a1=0; a1<3; a1++)
				{
					for (int b1=0; b1<3; b1++)
					{
						c[a1][b1]=a[a1][b1];
					}
				}

				empty=a[row][column];
				a[row][column]=a[row-1][column];
				a[row-1][column]=empty;
				row=row-1;

				if (num>0)
				{
				for (int x1=0; x1<(num+1); x1++)
				{
					for (int y1=0; y1<3; y1++)
					{
						for (int z1=0; z1<3; z1++)
						{
							if (b[x1][y1][z1]==c[y1][z1])
							{	
							}
							else 
							{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=1;
								goto calculate_f;
							}
						}
					}
				}
				}
				if (num==0)
				{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=1;
								goto calculate_f;
				}
		}
end1:

//step2:
		if (row==0)
		{
		}
		else
		{
				empty=a[row][column];
				a[row][column]=a[row-1][column];
				a[row-1][column]=empty;
				row=row-1;

				if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
		{
			goto finish;
		}

				for (int a1=0; a1<3; a1++)
				{
					for (int b1=0; b1<3; b1++)
					{
						c[a1][b1]=a[a1][b1];
					}
				}

				empty=a[row][column];
				a[row][column]=a[row+1][column];
				a[row+1][column]=empty;
				row=row+1;

				if (num>0)
				{
				for (int x1=0; x1<(num+1); x1++)
				{
					for (int y1=0; y1<3; y1++)
					{
						for (int z1=0; z1<3; z1++)
						{
							if (b[x1][y1][z1]==c[y1][z1])
							{
								empty=a[row][column];
								a[row][column]=a[row-1][column];
								a[row-1][column]=empty;
								row=row+1;	
							}
							else 
							{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=2;
								goto calculate_f;
							}
						}
					}
				}
				}
				else if (num==0)
				{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=2;
								goto calculate_f;
				}
		}
end2:

//step3:
		if (column==2)
		{
		}
		else
		{
				empty=a[row][column];
				a[row][column]=a[row][column+1];
				a[row][column+1]=empty;
				column=column+1;

				if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
		{
			goto finish;
		}

				for (int a1=0; a1<3; a1++)
				{
					for (int b1=0; b1<3; b1++)
					{
						c[a1][b1]=a[a1][b1];
					}
				}

				empty=a[row][column];
				a[row][column]=a[row][column-1];
				a[row][column-1]=empty;
				column=column-1;

				if (num>0)
				{
				for (int x1=0; x1<(num+1); x1++)
				{
					for (int y1=0; y1<3; y1++)
					{
						for (int z1=0; z1<3; z1++)
						{
							if (b[x1][y1][z1]==c[y1][z1])
							{
								empty=a[row][column];
								a[row][column]=a[row-1][column];
								a[row-1][column]=empty;
								column=column-1;	
							}
							else 
							{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=3;
								goto calculate_f;
							}
						}
					}
				}
				}
				else if (num==0)
				{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=3;
								goto calculate_f;
				}
		}
end3:

//step4:
		if (column==0)
		{
		}
		else
		{
				empty=a[row][column];
				a[row][column]=a[row][column-1];
				a[row][column-1]=empty;
				column=column-1;

				if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
		{
			goto finish;
		}

				for (int a1=0; a1<3; a1++)
				{
					for (int b1=0; b1<3; b1++)
					{
						c[a1][b1]=a[a1][b1];
					}
				}

				empty=a[row][column];
				a[row][column]=a[row][column+1];
				a[row][column+1]=empty;
				column=column+1;

				if (num>0)
				{
				for (int x1=0; x1<(num+1); x1++)
				{
					for (int y1=0; y1<3; y1++)
					{
						for (int z1=0; z1<3; z1++)
						{
							if (b[x1][y1][z1]==c[y1][z1])
							{
								empty=a[row][column];
								a[row][column]=a[row-1][column];
								a[row-1][column]=empty;
								column=column+1;	
							}
							else 
							{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=4;
								goto calculate_f;
							}
						}
					}
				}
				}
				if (num==0)
				{
								for(int c1=0; c1<3; c1++)
								{
									for(int d1=0; d1<3; d1++)
									{
										b[num][c1][d1]=c[c1][d1];
									}
								}
								back=4;
								goto calculate_f;
				}
		}
end4:

if(num>0)
{
		for (int x=0; x<num; x++)
		{
			for (int y=num; y>-1; y--)
			{
				if (x==y)
				{
				}
				else
				{
				if (f[x]<=f[y])
				{
					next=x;
					for (int g1=0; g1<3; g1++)
					{
						for (int h1=0; h1<3; h1++)
						{
							a[g1][h1]=b[next][g1][h1];
						}
					}
				}
				}
			}
		}

		goto solution_using_Astar;
}
calculate_f:

		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				switch(a[i][j])
				{
				case 1:

					if (i==0 && j==0)
					{
						b1=0;
					}
					else if ( (i==0 && j==1) || (i==1 && j==0) )
					{
						b1=1;
					}
					else if ( (i==0 && j==2) || (i==1 && j==1) || (i==2 && j==0) )
					{
						b1=2;
					}
					else if ( (i==2 && j==1) || (i==1 && j==2) )
					{
						b1=3;
					}
					else if ( (i==2 && j==2) )
					{
						b1=4;
					}
					break;

				case 2:

					if ( i==0 && j==1 )
					{
						b2=0;
					}
					else if ( (i==0 && j==0) || (i==1 && j==1) || (i==0 && j==2) )
					{
						b2=1;
					}
					else if ( (i==1 && j==0) || (i==2 && j==1) || (i==1 && j==2) )
					{
						b2=2;
					}
					else if ( (i==2 && j==0) || (i==2 && j==2) )
					{
						b2=3;
					}
					break;

				case 3:

					if (i==0 && j==2)
					{
						b3=0;
					}
					else if ( (i==0 && j==1) || (i==1 && j==2) )
					{
						b3=1;
					}
					else if ( (i==0 && j==0) || (i==1 && j==1) || (i==2 && j==2) )
					{
						b3=2;
					}
					else if ( (i==2 && j==1) || (i==1 && j==0) )
					{
						b3=3;
					}
					else if ( (i==2 && j==0) )
					{
						b3=4;
					}
					break;

				case 4:

					if ( i==1 && j==0 )
					{
						b4=0;
					}
					else if ( (i==0 && j==0) || (i==1 && j==1) || (i==2 && j==0) )
					{
						b4=1;
					}
					else if ( (i==0 && j==1) || (i==2 && j==1) || (i==1 && j==2) )
					{
						b4=2;
					}
					else if ( (i==0 && j==2) || (i==2 && j==2) )
					{
						b4=3;
					}
					break;

				case 5:

					if ( i==1 && j==1 )
					{
						b5=0;
					}
					else if ( (i==0 && j==1) || (i==1 && j==0) || (i==1 && j==2) || (i==2 && j==1) )
					{
						b5=1;
					}
					else if ( (i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2) )
					{
						b5=2;
					}
					break;

				case 6:

					if ( i==1 && j==2 )
					{
						b6=0;
					}
					else if ( (i==0 && j==2) || (i==1 && j==1) || (i==2 && j==2) )
					{
						b6=1;
					}
					else if ( (i==1 && j==0) || (i==2 && j==1) || (i==0 && j==1) )
					{
						b6=2;
					}
					else if ( (i==2 && j==0) || (i==0 && j==0) )
					{
						b6=3;
					}
					break;

				case 7:

					if (i==2 && j==0)
					{
						b7=0;
					}
					else if ( (i==1 && j==0) || (i==2 && j==1) )
					{
						b7=1;
					}
					else if ( (i==0 && j==0) || (i==1 && j==1) || (i==2 && j==2) )
					{
						b7=2;
					}
					else if ( (i==0 && j==1) || (i==1 && j==2) )
					{
						b7=3;
					}
					else if ( (i==0 && j==2) )
					{
						b7=4;
					}
					break;

				case 8:

					if ( i==2 && j==1 )
					{
						b8=0;
					}
					else if ( (i==2 && j==0) || (i==1 && j==1) || (i==2 && j==2) )
					{
						b8=1;
					}
					else if ( (i==1 && j==0) || (i==0 && j==1) || (i==1 && j==2) )
					{
						b8=2;
					}
					else if ( (i==0 && j==0) || (i==0 && j==2) )
					{
						b8=3;
					}
					break;

				}
			}
		}

		h=b1+b2+b3+b4+b5+b6+b7+b8;
		f[num]=g+h;
		num++;

		if (back==1)
		{
			goto end1;
		}
		if (back==2)
		{
			goto end2;
		}
		if (back==3)
		{
			goto end3;
		}
		if (back==4)
		{
			goto end4;
		}


finish:
		system("cls");
			cout<<"\n\n\n\t\t";
			cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			for (int k=0; k<3; k++)
			{
			cout<<"\t\t";
			cout<<"|\t\t|\t\t|\t\t|\n";
			cout<<"\t\t";
			cout<<"|\t"<<a[k][0]<<"\t|\t"<<a[k][1]<<"\t|\t"<<a[k][2]<<"\t|\n";
			cout<<"\t\t";
			cout<<"|\t\t|\t\t|\t\t|\n";
			cout<<"\t\t";
			cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			}
		cout<<"\t\t*****************************************\n";
		cout<<"\t\t*\t\t\t\t        *\n";
		cout<<"\t\t*      Congratulation You Have Won      *\n";
		cout<<"\t\t*\t\t\t \t        *\n";
		cout<<"\t\t*  You Have Completed It In "<<turn<<" turns     *\n";
		cout<<"\t\t*\t\t\t \t        *\n";
		cout<<"\t\t*****************************************\n";
		cout<<"\n\t\t    Do You Want To Play Again? (Y/N)";
		cin>>y_n;
		if(y_n=='y')
		{
			goto start;
		}
		else
			goto exit;

exit:
	exit(1);
}