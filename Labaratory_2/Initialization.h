#pragma once
#include "OOP_Menu.h"
#include "Laba_2.h"

class Init
{
private:
	Menu lab2;
public:

	Init()
	{
		lab2.AddMenuItem("������ 8, 8 ���i���: ", Zadacha8);
		lab2.AddMenuItem("������ 20, 8 ���i���: ", Zadacha20);
	}
	void Show_Lab()
	{
		lab2.ShowMenu();
	}
};