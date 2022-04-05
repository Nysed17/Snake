#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x = 10, y = 10;
int taby = 20, tabx = 30;
int i, j, gameover = 0;

void clr(){
	system("clear");
}

void gotoxy(int x, int y){
	printf("%c[%d;%df", 0x1B, x, y);
}

void input(){
	
	switch(getchar()){
		case 'w':
			x--;
			break;	
		case 's':
			x++;
			break;
		case 'a':
			y--;
			break;
		case 'd':
			y++;
			break;
	}
}

void tabella(){
	
	system("stty -echo");
  system("stty -icanon");

	clr();	

	for ( i = 0 ; i < taby ; i++ ){
		for ( j = 0 ; j < tabx ; j++ ){
			if ( i == 0 || i == taby - 1 || j == 0 || j == tabx - 1 ){
				printf("#");
			}
			else printf(" ");
		}
		printf("\n");
	}

	  gotoxy(x,y);
		printf("O");

}

int main(){

	while(!gameover){
		tabella();
		input();
	}

	return 0;
}
