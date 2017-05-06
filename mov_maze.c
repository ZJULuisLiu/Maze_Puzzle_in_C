/*This is a programme designed for*/
/* traversing the fixed maze*/
#include <stdio.h>
#define MAXLINE 1000
int count=0;
static int coor_data[MAXLINE][2];//used to store the coordinates of the path
int maze[10][10]={{0,0,0,0,0,0,0,0,0,0},
                  {0,1,1,0,1,1,1,0,1,0},
				  {0,1,1,0,1,1,1,0,1,0},
				  {0,1,1,1,1,0,0,1,1,0},
				  {0,1,0,0,0,1,1,1,1,0},
				  {0,1,1,1,0,1,1,1,1,0},
				  {0,1,0,1,1,1,0,1,1,0},
				  {0,1,0,0,0,1,0,0,1,0},
				  {0,0,1,1,1,1,1,1,1,0},
				  {0,0,0,0,0,0,0,0,0,0}};  //set the maze
int mov_maze (int row, int col); // use this function to traverse the maze
void coordinates(); //show the coordinates of the sucuessful path on the screen  
void print(); // show the already-traversed maze on the screen
int main (void)
{
	if (!mov_maze(1,1))
	  printf ("Damn!No available path TAT.\n");
	else {
		printf("Path below:\n");
		print();
		printf("Coordinates of the movement:\n");
		coordinates();
	}
	
	return 0;
}

int mov_maze (int row, int col)
{
	int res=0;
	if (maze[row][col]==1){
	maze[row][col]=3; // set 3 for the sign of the already-tried but failed path
	if (row==8&&col==8) res=1;// exit of the function
	else 
	{
		res=mov_maze (row+1,col);
		if (!res) res=mov_maze (row-1,col);
		if (!res) res=mov_maze (row,col+1);
		if (!res) res=mov_maze (row,col-1);
	}// try 4 directions
    }
	if (res==1){
		maze[row][col]=7;
		coor_data[count][0]=row;
		coor_data[count][1]=col;
		count++;
	}// use 7 to show the right path out of maze and record the coordinates into the array
	return res;
}

void print ()
{
	int i,j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			printf ("%d",maze[i][j]);
		}
		printf ("\n");
	}
}
void coordinates()
{
	int i;
	for (i=count-1;i>=0;i--){
		if (i!=0){
			printf ("(%d,%d)->",coor_data[i][0],coor_data[i][1]);
		}
		else printf ("(%d,%d)",coor_data[i][0],coor_data[i][1]);
	}
}                 
