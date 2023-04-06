#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
int RandomN(int max, int min) {
	return (rand() % max) + min;
}
char RandomC() {
	char c = 'a' + rand() % 26;
	return c;
}

