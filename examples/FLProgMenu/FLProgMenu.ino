#include "flprogMenu.h"

FLProgBooleanMenuItem item1(0);
FLProgGroupMenuItem group1(2);
FLProgMenu menu(2);

void setup()
{
    item1.setConvertString("False", 0);
    item1.setConvertString("True", 1);
    group1.setItem(0, &item1);
    menu.setItem(0, &group1);
}

void loop()
{
}