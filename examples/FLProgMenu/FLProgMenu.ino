#include "flprogMenu.h"

FLProgBooleanMenuItem boolItem("Bool");
FLProgByteMenuItem byteItem("Byte");
FLProgIntegerMenuItem integerItem("Integer");
FLProgLongMenuItem longItem("Long");
FLProgUnsignedLongMenuItem unsignedLongItem("UnsignedLong");
FLProgFloatMenuItem floatItem("Float");
FLProgCharMenuItem charItem("Char");

FLProgGroupMenuItem group1("Group", 6);
FLProgMenu menu(2);

void setup()
{
    boolItem.setConvertString("False", 0);
    boolItem.setConvertString("True", 1);
    byteItem.setConvertString(FLPROG_MENU_DEC_CONVERT_TYPE);
    integerItem.setConvertString(FLPROG_MENU_HEX_CONVERT_TYPE);
    longItem.setConvertString(FLPROG_MENU_BIN_CONVERT_TYPE);
    floatItem.setConvertString("2");
    charItem.setConvertString(FLPROG_MENU_SYMBOL_CONVERT_TYPE);

    menu.setItem(0, &group1);
    menu.setItem(1, &boolItem);

    group1.setItem(0, &byteItem);
    group1.setItem(1, &integerItem);
    group1.setItem(2, &longItem);
    group1.setItem(3, &unsignedLongItem);
    group1.setItem(4, &floatItem);
    group1.setItem(5, &charItem);
}

void loop()
{
}