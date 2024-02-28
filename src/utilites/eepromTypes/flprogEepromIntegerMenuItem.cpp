#include "flprogEepromIntegerMenuItem.h"

FLProgEepromIntegerMenuItem::FLProgEepromIntegerMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromIntegerMenuItem::saveBuffer()
{
    _chip->saveInteger(_addres, _value);
}