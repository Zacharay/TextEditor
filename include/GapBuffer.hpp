#pragma once
#include <iostream>
#include <vector>
class GapBuffer{
public:
        size_t initial_size = 128;
        unsigned int characterCount = 0;
        GapBuffer()
            :m_buffer(initial_size,'\0'),gapStart(1),gapEnd(initial_size-1),cursor(0){};

        void insertChar(char c);
        void deleteChar();
        void moveCursorRight();
        void moveCursorLeft();
        void printBuffer()const;
        const std::string& getText()const;
        int getCursorPos()const;
private:
        int cursor;
        int gapStart;
        int gapEnd;
        std::vector<char>m_buffer;
};