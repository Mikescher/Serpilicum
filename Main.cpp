#include <iostream>
#include "DBConsole.h"

int main() {
	DBConsole *dbc = new DBConsole();

	dbc->write("Hello Armin", 10, 10);
	dbc->swap();

	for(;;);
}