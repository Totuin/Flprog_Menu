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

void FLProgEepromUnsignedLongMenuItem::setUnsignedLongValue(uint32_t value)
{
    FLProgUnsignedLongMenuItem::setUnsignedLongValue(value);
    if (_isBuffered)
    {
        return;
    }
    saveBuffer();
}

void FLProgEepromUnsignedLongMenuItem::initValue()
{
    _value = _chip->readUnsignedLong(_addres);
}

void FLProgEepromUnsignedLongMenuItem::setUnsignedLongMinValue(uint32_t value)
{
    _minValue = value;
    _hasMin = true;
}