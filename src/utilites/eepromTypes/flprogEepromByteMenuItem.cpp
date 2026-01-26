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

void FLProgEepromByteMenuItem::setByteValue(uint8_t value)
{
    FLProgByteMenuItem::setByteValue(value);
    if (_isBuffered)
    {
        return;
    }
    saveBuffer();
}

void FLProgEepromByteMenuItem::initValue()
{
    _value = _chip->readByte(_addres);
}

void FLProgEepromByteMenuItem::setByteMinValue(uint8_t value)
{
    _minValue = value;
    _hasMin = true;
}
