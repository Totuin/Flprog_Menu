#include "flprogEepromFloatMenuItem.h"

FLProgEepromFloatMenuItem::FLProgEepromFloatMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromFloatMenuItem::saveBuffer()
{
    _chip->saveFloat(_addres, _value);
}