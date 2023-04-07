#pragma once
#ifndef HELPERS_H
#define HELPERS_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

std::string vectorToCString(std::vector<std::string> vec) {
	std::string res = "(";
	for (auto element : vec) {
		for (auto c = element.begin(); c != element.end(); ++c) {
			res.push_back(*c);
			res.push_back(',');
		}
	}
	res.pop_back();
	res.push_back(')');
	return res;
}

int RandomN(int max, int min) {
	return (rand() % max) + min;
}
char RandomC() {
	char c = 'a' + rand() % 26;
	return c;
}

#endif