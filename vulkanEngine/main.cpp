#include <iostream>
#include "application.h"

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}