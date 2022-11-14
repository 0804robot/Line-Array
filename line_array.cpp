#include <line_array.h>

//constructor
LineArray::LineArray(int s_1, int s_2, int s_3, int s_4, int s_5)
{
    sen_1 = s_1;
    sen_2 = s_2;
    sen_3 = s_3;
    sen_4 = s_4;
    sen_5 = s_5;
    previous_position = 0;
    checkpoint_count = 0;
    lost_line_count = 0;
}
//initialization fumction
void LineArray::init()
{
    pinMode(sen_1, INPUT);
    pinMode(sen_2, INPUT);
    pinMode(sen_3, INPUT);
    pinMode(sen_4, INPUT);
    pinMode(sen_5, INPUT);
}
// read value function
int LineArray::readValue()
{
    int linePosition[5];
    linePosition[0] = 1 - digitalRead(sen_1);            //read infrared reflectance sensors
    linePosition[1] = 1 - digitalRead(sen_2);
    linePosition[2] = 1 - digitalRead(sen_3);
    linePosition[3] = 1 - digitalRead(sen_4);
    linePosition[4] = 1 - digitalRead(sen_5);
    
    this->CheckForCheckpoints(linePosition);
    int pos = linePosition[0] * 4 + linePosition[1] * 3 + linePosition[2]  * 2 + linePosition[3] * 1 + linePosition[4] * 0;
    if (linePosition[0] == 0 && linePosition[1] == 0 && linePosition[2] ==  0 && linePosition[3] == 0 && linePosition[4] == 0){
        lost_line_count++;
        return previous_position;
    }else if (linePosition[0] == 1 && linePosition[1] == 1 && linePosition[2] ==  1 && linePosition[3] == 1 && linePosition[4] == 1){
        return 10;
    }
    pos = 2 - (pos /(linePosition[0] + linePosition[1] + linePosition[2] + linePosition[3] + linePosition[4]));
    previous_position = pos;
    return pos;
}

void LineArray::CheckForCheckpoints(int linePos[5]){
    int points_count = 0;
    for (int i = 0; i < 5; i++){
        if (linePos[i] == 1) {
            points_count++;
        }
    }
    if (points_count >= 3) {
        this->checkpoint_count++;
    }
}