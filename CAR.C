/*
	      Name:Nihil shee
	      Doc:6/7/26
	      Obj:Car building
	      Email:nikhilshee22@gmail.com
*/
#include<stdio.h>
#include<conio.h>
void main(){
     clrscr();
     sound(500);
     delay(200);
     nosound();
     gotoxy(40,10);
     textcolor(YELLOW);
     cprintf("--------------------");
     gotoxy(40,11);
     cprintf("||");
     gotoxy(40,12);
     cprintf("||");
     gotoxy(40,13);
     cprintf("---------------------");
     gotoxy(59,11);
     cprintf("||");
     gotoxy(59,12);
     cprintf("||");
     gotoxy(61,11);
     cprintf("--------");
     gotoxy(61,13);
     cprintf("--------");
     gotoxy(68,11);
     cprintf("|");
     gotoxy(68,12);
     cprintf("|");
     gotoxy(68,13);
     cprintf("|");
      gotoxy(69,11);
     cprintf("*");
      gotoxy(69,13);
     cprintf("*");

     gotoxy(42,14);
     textcolor(DARKGRAY);
     cprintf("00     00       00      00");

     getch();
}