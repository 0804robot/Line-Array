#ifndef LINE_ARRAY_H
#define LINE_ARRAY_H

#include <Arduino.h>

class LineArray
{
private:
    int sen_1;
    int sen_2;
    int sen_3;
    int sen_4;
    int sen_5;

public:
    LineArray(int s_1, int s_2, int s_3, int s_4, int s_5);
    void init();
    int readValue();
};

#endif