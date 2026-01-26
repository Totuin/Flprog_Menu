#include "flprogEepromMenu.h"
#include "flprogExternalEEPROM.h"

FLProgExternalEEPROM eeprom(0, 0x50, 30, 3);

FLProgBooleanMenuItem boolItem("Bool");
FLProgEepromBooleanMenuItem eepromBoolItem("Bool-1", &eeprom, 1, 1);

FLProgByteMenuItem byteItem("Byte");
FLProgEepromByteMenuItem eepromByteItem("Byte_1", &eeprom, 2);

FLProgIntegerMenuItem integerItem("Integer");
FLProgLongMenuItem longItem("Long");
FLProgUnsignedLongMenuItem unsignedLongItem("UnsignedLong");
FLProgFloatMenuItem floatItem("Float");
FLProgCharMenuItem charItem("Char");

FLProgGroupMenuItem group1("Group", 2);
FLProgMenu menu("mainMenu", 4);

void setup()
{
    boolItem.textForTrue("False");
    boolItem.textForFalse("True");
    byteItem.setConverType(FLPROG_MENU_DEC_CONVERT_TYPE);
    integerItem.setConverType(FLPROG_MENU_HEX_CONVERT_TYPE);
    longItem.setConverType(FLPROG_MENU_BIN_CONVERT_TYPE);
    floatItem.setConverType(2);
    charItem.setConverType(FLPROG_MENU_SYMBOL_CONVERT_TYPE);

    menu.setItem(0, &group1);
    menu.setItem(1, &boolItem);
    menu.setItem(2, &eepromBoolItem);
    menu.setItem(3, &eepromByteItem);

    group1.setItem(0, &byteItem);
    group1.setItem(1, &integerItem);
    group1.setItem(2, &longItem);
    group1.setItem(3, &unsignedLongItem);
    group1.setItem(4, &floatItem);
    group1.setItem(5, &charItem);

    eeprom.begin();
}

void loop()
{
    eeprom.pool();
}