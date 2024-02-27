#include "flprogUnsignedLongMenuItem.h"

void FLProgUnsignedLongMenuItem::setValue(String value)
{
    value.toUpperCase();
    uint32_t temp;
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {

        temp = flprog::hexStringToUnsignedLong(value);
    }
    else
    {
        if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
        {

            temp = flprog::binStringToUnsignedLong(value);
        }
        else
        {
            temp = value.toInt();
        }
    }
    setUnsignedLongValue(temp);
}

void FLProgUnsignedLongMenuItem::setUnsignedLongValue(uint32_t value)
{
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }
    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    _value = value;
}

void FLProgUnsignedLongMenuItem::pressSymbolButton(char value)
{
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if (!((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value))))
    {
        return;
    }

    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if (!((value == '0') || (value == '1')))
        {
            return;
        }
    }
    privatePressSymbolButton(value);
}

void FLProgUnsignedLongMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}

String FLProgUnsignedLongMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String(_value, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String(_value, BIN);
    }
    String temp = String(_value, HEX);
    temp.toUpperCase();
    return temp;
}

void FLProgUnsignedLongMenuItem::setUnsignedLongMaxValue(uint32_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgUnsignedLongMenuItem::setUnsignedLongMinValue(uint32_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgUnsignedLongMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value > (_maxValue - ((uint32_t)_step)))
        {
            return;
        }
    }
    if (_value > (4294967295 - ((uint32_t)_step)))
    {
        return;
    }
    _value = _value + ((uint32_t)_step);
}

void FLProgUnsignedLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + ((uint32_t)_step)))
        {
            return;
        }
    }
    if (_value == 0)
    {
        return;
    }
    _value = _value - ((uint32_t)_step);
}