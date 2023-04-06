#include "MyForm.h"
using namespace UPCalcula;
int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::Run(gcnew UPCalcula::MyForm);
}


