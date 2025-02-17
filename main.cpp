#include "Application.hpp"
#include "GapBuffer.hpp"
int main(int argc, char* argv[]) {
    Application app;
    app.run();

/*
    GapBuffer buffer;
    buffer.insertChar('h');
    buffer.insertChar('e');
    buffer.insertChar('l');
    buffer.insertChar('l');
    buffer.insertChar('o');
    buffer.insertChar(' ');
    buffer.insertChar('W');
    buffer.insertChar('o');
    buffer.insertChar('r');
    buffer.insertChar('l');
    buffer.insertChar('d');
    buffer.printBuffer();
    buffer.moveCursorLeft();
    buffer.moveCursorLeft();
    buffer.moveCursorLeft();
    buffer.moveCursorLeft();
    buffer.moveCursorLeft();
    buffer.insertChar('X');
    buffer.printBuffer();
    buffer.moveCursorRight();

    buffer.printBuffer();
    buffer.deleteChar();
    buffer.printBuffer(); */
    return 0;
}
