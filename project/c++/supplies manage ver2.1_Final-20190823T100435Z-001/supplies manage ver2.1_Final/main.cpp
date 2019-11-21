#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <unistd.h>
#define true 1
#define false 0
#include "menu.h"
#define MAX 200

using namespace std;

int main(){
	
    SetConsoleTitle("supplies manage ver1.0");
	color_set();
   	ShowConsoleCursor(false);
	system("cls");

	ShowConsoleCursor(true);
	gotoxy(45,5);
	cout << " Product of NghiaLe Student of PTIT";
	gotoxy(51,6);
	cout <<"supplies manage ver1.0";
	gotoxy(58,7);
	cout << "WELCOME ...";
	sleep(2);
	bool T;
	do
	{
		T = login();
	
	}
	while (T != true);
    system("cls");
   	ShowConsoleCursor(false);
	   menu();    
    //draw_case5();
    /////////////////////////
    /////////////////////////
	getch();
	return 0;
	}
