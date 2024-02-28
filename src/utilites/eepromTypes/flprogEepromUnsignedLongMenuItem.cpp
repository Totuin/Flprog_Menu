#include "flprogEepromUnsignedLongMenuItem.h"

FLProgEepromUnsignedLongMenuItem::FLProgEepromUnsignedLongMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromUnsignedLongMenuItem::saveBuffer()
{
    _chip->saveUnsignedLong(_addres, _value);
}