#include "flprogByteMenuItem.h"

void FLProgByteMenuItem::setValue(String value)
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
    if (temp > 255)
    {
        return;
    }
    setByteValue((uint8_t)temp);
}

String FLProgByteMenuItem::valueString()
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

void FLProgByteMenuItem::setByteMaxValue(uint8_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgByteMenuItem::setByteMinValue(uint8_t value)
{
    _minValue = value;
    setByteValue(value);
    _hasMin = true;
}

void FLProgByteMenuItem::setByteValue(uint8_t value)
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

void FLProgByteMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value > (_maxValue - step()))
        {
            return;
        }
    }
    if (_value > (255 - step()))
    {
        return;
    }
    setByteValue(_value + step());
}
void FLProgByteMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + step()))
        {
            return;
        }
    }
    if (_value < (step()))
    {
        return;
    }
    setByteValue(_value - step());
}

void FLProgByteMenuItem::pressSymbolButton(char value)
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

void FLProgByteMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}

void FLProgByteMenuItem::pressClearButton()
{
    if (_hasMin)
    {
        setByteValue(_minValue);
        return;
    }
    setByteValue(0);
}
