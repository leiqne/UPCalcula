#pragma once
#ifndef HELPERS_H
#define HELPERS_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <thread>

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

std::string join(std::vector<std::string> vec, std::string separator) {
	return std::accumulate(vec.begin(), vec.end(), std::string(),
		[&](const std::string& a, const std::string& b) -> std::string {
			return a.empty() ? b : a + separator + b;
		}
	);
}

std::string Run(std::vector<std::string> args_) {
    std::string cmd = join(args_, " ");
    std::string output;

    auto run_subprocess = [cmd, &output]() {
        char buffer[256];
        std::stringstream ss;

        FILE* pipe = _popen(cmd.c_str(), "r");
        if (!pipe) {
            std::cerr << "Error al lanzar el subproceso" << std::endl;
            return "Error";
        }

        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            ss << buffer;
        }

        output = ss.str();
        _pclose(pipe);
    };

    std::thread t(run_subprocess);
    t.detach();

    return output;
}


#endif