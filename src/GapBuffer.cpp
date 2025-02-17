#include "GapBuffer.hpp"
#include <iostream>

using namespace std;
void GapBuffer::insertChar(char c)
{
    m_buffer[cursor] = c;
    cursor++;
    gapStart++;
    characterCount++;
}
void GapBuffer::deleteChar() {

    if (cursor==0) {
        return;
    }

    m_buffer[cursor--]=0;
    gapStart--;
    characterCount--;
}
void GapBuffer::moveCursorLeft() {
    //prevent going to negative index
    if (cursor==0) {
        return;
    }

    cursor--;
    gapStart--;
    m_buffer[gapEnd] = m_buffer[cursor];
    gapEnd--;
}
void GapBuffer::moveCursorRight() {

    if (characterCount ==cursor){ return; }

    gapEnd++;
    m_buffer[cursor] = m_buffer[gapEnd];
    cursor++;
    gapStart++;
}
void GapBuffer::printBuffer() const {

    for (int i=0;i<m_buffer.size();i++) {
        if (i==cursor) {
            std::cout<<"|";
        }
        else if (i>=gapStart && i<=gapEnd) {
            std::cout<<"_";
        }
        else {
            std::cout<<m_buffer[i];
        }
    }
    std::cout<<std::endl;
    for (int i=0; i < gapStart  -1 ; i++) {
        std::cout<<m_buffer[i];
    }
    for (int i=gapEnd+1; i < m_buffer.size(); i++) {
        std::cout<<m_buffer[i];
    }
    std::cout<<std::endl;
}
const std::string& GapBuffer::getText()const {
    std::string output = "";
    for (int i=0; i < gapStart  -1 ; i++) {
       output+= m_buffer[i];
    }
    for (int i=gapEnd+1; i < m_buffer.size(); i++) {
        output+=  m_buffer[i];
    }

    return output;
}
int GapBuffer::getCursorPos()const {
    return cursor;
}
