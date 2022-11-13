#ifndef LINE_ARRAY_H
#define LINE_ARRAY_H

#include <Arduino.h>

class LineArray
{
private:
// sensor pins
    int sen_1;
    int sen_2;
    int sen_3;
    int sen_4;
    int sen_5;
    int previous_position;

    void CheckForCheckpoints(int linePos[5]);

public:
// constructor takes pins as arguments
    LineArray(int s_1, int s_2, int s_3, int s_4, int s_5);
    // initialize pins
    void init();
    // read value from the array
    int readValue();

    int checkpoint_count;
};

#endif