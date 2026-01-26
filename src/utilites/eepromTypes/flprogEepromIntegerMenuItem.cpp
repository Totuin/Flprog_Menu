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

void FLProgEepromIntegerMenuItem::setIntegerValue(int16_t value)
{
    FLProgIntegerMenuItem::setIntegerValue(value);
    if (_isBuffered)
    {
        return;
    }
    saveBuffer();
}

void FLProgEepromIntegerMenuItem::initValue()
{
    _value = _chip->readInteger(_addres);
}

void FLProgEepromIntegerMenuItem::setIntegeMinValue(int16_t value)
{
    _minValue = value;
    _hasMin = true;
}
