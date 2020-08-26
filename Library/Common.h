#include<iostream>
#include<Windows.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


using namespace std;
class Common
{
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void txtColor(int);
};