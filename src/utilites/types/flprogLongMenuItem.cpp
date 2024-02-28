#include "flprogLongMenuItem.h"

void FLProgLongMenuItem::setValue(String value)
{
    value.toUpperCase();
    uint32_t temp;
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        temp = flprog::hexStringToLong(value);
    }
    else
    {
        if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
        {
            temp = flprog::binStringToLong(value);
        }
        else
        {
            temp = value.toInt();
        }
    }
    setLongValue(temp);
}

String FLProgLongMenuItem::valueString()
{
    int32_t tempValue = abs(_value);
    String temp;

    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        temp = String(tempValue, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        temp = String(tempValue, BIN);
    }
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        temp = String(tempValue, HEX);
    }
    if (_value < 0)
    {
        temp = "-" + temp;
    }
    temp.toUpperCase();
    return temp;
}

void FLProgLongMenuItem::setLongValue(int32_t value)
{
    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }
    _value = value;
}

void FLProgLongMenuItem::setLongMaxValue(int32_t value)
{
    _maxValue = value;
    _hasMax = true;
}

void FLProgLongMenuItem::setLongMinValue(int32_t value)
{
    _minValue = value;
    if (!(_minValue < 0))
    {
        setLongValue(_minValue);
    }
    _hasMin = true;
}

void FLProgLongMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value > (_maxValue - step()))
            return;
    }
    if (_value > (2147483647 - step()))
    {
        return;
    }
    setLongValue(_value + step());
}

void FLProgLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + step()))
        {
            return;
        }
    }
    if (_value < (-2147483647 + step()))
    {
        return;
    }
    setLongValue(_value - step());
}

void FLProgLongMenuItem::pressSymbolButton(char value)
{
    if (value == '-')
    {
        privatePressSymbolButton(value);
        return;
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if ((value == '0') || (value == '1'))
        {
            privatePressSymbolButton(value);
        }
        return;
    }
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        privatePressSymbolButton(value);
    }
}

void FLProgLongMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}

void FLProgLongMenuItem::pressClearButton()
{
    if (_hasMin)
    {
        if (!(_minValue < 0))
        {
            setLongValue(_minValue);
            return;
        }
    }
    setLongValue(0);
}