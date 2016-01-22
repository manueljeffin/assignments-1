/*
*
* Slide To Win
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

int solved (int m,int n,char matrix[m][n]){
	int i,j,flag=1,k=49,flagprev=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			flagprev=flag;
			if(matrix[i][j] != k){
				flag=0;
			}
			k++;
		}
	}
	return flagprev;
}

void printmat(int m,int n,char matrix[m][n]){
	int i,j;
	printf("\n");
	for(int i=0;i<m;i++){
		printf("|");
		for(int j=0;j<n;j++){
			printf(" %c |",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//simple solution
	char matrix[3][3] = {{'1','2',' '},{'4','5','3'},{'7','8','6'}};
	// the values of row and col indicate the position of ' ' character
	int row=0,col=2;
	
	//solution with more steps
	//char matrix[3][3] = {{'4','2','5'},{'1','7','6'},{'3','8',' '}};
	//int row=2,col=2;

	int i,j,rowprev=0,colprev=0;
	char move,temp;

	int flag = 0;
	flag = solved(3,3,matrix);
	
	while (flag == 0){
		system("clear");
		printmat(3,3,matrix);
		printf("\nPress U for Up, D for Down, L for Left, R for Right, Q for Quit\n");
		printf("\nEnter a move: ");
		scanf("%c", &move);
		move = toupper(move);

		rowprev=row;
		colprev=col;
		if (move == 'Q'){
			break;
		}
		switch(move){
			case 'U':
				row = row - 1;
				col = col;
				break;
			case 'D':
				row = row + 1;
				col = col;
				break;
			case 'L':
				row = row;
				col = col - 1;
			break;
			case 'R':
				row = row;
				col = col + 1;
				break;
			default:
				break;
		}
		if(row<=2 && row>=0 && col >=0 && col<= 2){
			temp = matrix[row][col];
			matrix[row][col]=matrix[rowprev][colprev];
			matrix[rowprev][colprev]=temp;
		}else{
			printf("invalid move\n");
			row=rowprev;
			col=colprev;
		}
		flag = solved(3,3,matrix);
	}

	
	if(flag == 1){
		system("clear");
		printmat(3,3,matrix);
		printf("\n");
		printf("Solved:):)\n");
	}else{
		system("clear");
		printmat(3,3,matrix);
		printf("\n");
		printf("Unsolved:(:(\n");

	}
	return 0;
}