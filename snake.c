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

void random_apl(int xa, int ya){
		int ap = 149;
		printf("\x1b[31m%c", ap);
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

void tabella(int xa, int ya){
	
	system("stty -echo");
  system("stty -icanon");

	clr();	

	for ( i = 0 ; i < taby ; i++ ){
		for ( j = 0 ; j < tabx ; j++ ){
			if ( i == 0 || i == taby - 1 || j == 0 || j == tabx - 1 ){
				printf("\x1b[32m#");
			}
			else printf(" ");
		}
		printf("\n");
	}
	if (y > 29){
		y--;
	}
	if (y < 2){
		y++;
	}
	if (x > 19){
		x--;
	}
	if (x < 2){
		x++;
	}
	gotoxy(xa,ya);
	random_apl(xa,ya);
	gotoxy(x,y);
	printf("\x1b[33mO");
}

int main(){
	
	while(!gameover){
		int ya = rand()%29+1;
		int xa = rand()%19+1;
		tabella(xa,ya);
		input();
	}

	return 0;
}
