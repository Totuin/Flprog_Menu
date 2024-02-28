#include "flprogEepromBooleanMenuItem.h"

FLProgEepromBooleanMenuItem::FLProgEepromBooleanMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, uint8_t bit, bool isBuffered, uint8_t aditionalsStringsCount)
{
    _chip = chip;
    _addres = addres;
    _bit = bit;
    _isBuffered = isBuffered;
    initItem(name, aditionalsStringsCount);
}

void FLProgEepromBooleanMenuItem::saveBuffer()
{
    _chip->saveBoolean(_addres, _bit, _value);
}

void FLProgEepromBooleanMenuItem::setBooleanValue(bool value)
{
    FLProgBooleanMenuItem::setBooleanValue(value);
    if (_isBuffered)
    {
        return;
    }
    saveBuffer();
}

void FLProgEepromBooleanMenuItem::initValue()
{
    _value = _chip->readBoolean(_addres, _bit);
}