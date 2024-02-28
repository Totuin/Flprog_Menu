#include "flprogEepromByteMenuItem.h"

FLProgEepromByteMenuItem::FLProgEepromByteMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromByteMenuItem::saveBuffer()
{
    _chip->saveByte(_addres, _value);
}