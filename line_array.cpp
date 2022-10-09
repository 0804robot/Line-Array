#include <line_array.h>



//constructor
LineArray::LineArray(int s_1, int s_2, int s_3, int s_4, int s_5)
{
    sen_1 = s_1;
    sen_2 = s_2;
    sen_3 = s_3;
    sen_4 = s_4;
    sen_5 = s_5;
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
    return ((DigitalRead(sen_1)*-2)+(DigitalRead(sen_2)*-1)+(DigitalRead(sen_3)*0)+
    (DigitalRead(sen_4)*1)+(DigitalRead(sen_5)*2);
}