#include "flprogEepromLongMenuItem.h"

FLProgEepromLongMenuItem::FLProgEepromLongMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromLongMenuItem::saveBuffer()
{
    _chip->saveLong(_addres, _value);
}