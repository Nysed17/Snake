#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x = 10, y = 10;
int taby = 20, tabx = 30;
int i, j, gameover = 0;
int score = 0;
int ya = 6;
int xa = 4;

void clr(){
	system("clear");
}

void gotoxy(int x, int y){
	printf("%c[%d;%df", 0x1B, x, y);
}

void random_apl(){	
	printf("\x1b[31m\u2600");
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
				printf("\x1b[32m#");
			}
			else printf(" ");
		}
		printf("\n");
	}
	if (y > 29){
		gameover = 1;
	}
	if (y < 3){
		gameover = 1;
	}
	if (x > 19){
		gameover = 1;
	}
	if (x < 3){
		gameover = 1;
	}
	gotoxy(x,y);
	printf("\x1b[33mO");

		if (xa == x && ya == y){
			++score;
			xa = rand()%19+1;
			ya = rand()%29+1;
			if (xa < 2){
				xa++;
			}
			if (ya < 2){
				ya++;
			}
			gotoxy(xa,ya);
			random_apl();
		} else {
			gotoxy(xa,ya);
			random_apl();
		}

		gotoxy(10,40);
		printf("Score: %d", score);
		input();
}

int main(){
	
	while(!gameover){
				tabella();
	}

	return 0;
}
