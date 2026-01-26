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

void FLProgEepromLongMenuItem::setLongValue(int32_t value)
{
    FLProgLongMenuItem::setLongValue(value);
    if (_isBuffered)
    {
        return;
    }
    saveBuffer();
}

void FLProgEepromLongMenuItem::initValue()
{
    _value = _chip->readLong(_addres);
}

void FLProgEepromLongMenuItem::setLongMinValue(int32_t value)
{
    _minValue = value;
    _hasMin = true;
}
