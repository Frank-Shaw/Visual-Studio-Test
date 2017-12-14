#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void progress(char* str, int start, int total)
{
	int bar_len = 50;
	double percentage = start * 100.0 / total;
	if (start == 0)
		printf("%s\n", str);

	char buf[120];
	memset(buf, 0x00, sizeof(buf));

	int i; 
	for (i = 0; i <= percentage / (100 / bar_len); i++){
		buf[i] = '=';
		buf[i + 1] = '>';
	}
	printf("\rprocess:[%-52s]%.2f%%", buf, percentage);
	
	if (percentage == 100)
		printf("\n");
}
int main()
{
	for (int i = 0; i < 102; i++){
		progress("rotate", i, 101);
		Sleep(50);
	}
	system("pause\n");
		
}
