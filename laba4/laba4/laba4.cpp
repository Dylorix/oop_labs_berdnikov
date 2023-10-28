#include "keyboard.h"

int main()
{
	laba4::Keyboard keyboard;

	keyboard.addCommand("a", "Pressed A");
	keyboard.addCommand("b", "Pressed B");
	keyboard.addCommand("c", "Pressed C");

	keyboard.workflow("a>b>c");
	keyboard.undo();
	keyboard.copy();
	keyboard.undo();

	return 0;
}