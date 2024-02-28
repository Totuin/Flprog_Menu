#include "flprogEepromCharMenuItem.h"

FLProgEepromCharMenuItem::FLProgEepromCharMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromCharMenuItem::saveBuffer()
{
    _chip->saveByte(_addres, ((uint8_t)_value));
}