#include "flprogIntegerMenuItem.h"

void FLProgIntegerMenuItem::setValue(String value)
{
    value.toUpperCase();
    int32_t temp;
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
    if (temp > 32767)
    {
        return;
    }
    if (temp < -32767)
    {
        return;
    }
    setIntegerValue((int16_t)temp);
}

String FLProgIntegerMenuItem::valueString()
{
    int16_t tempValue = abs(_value);
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

void FLProgIntegerMenuItem::setIntegeMaxValue(int16_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgIntegerMenuItem::setIntegeMinValue(int16_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgIntegerMenuItem::setIntegerValue(int16_t value)

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
};

void FLProgIntegerMenuItem::valueUp()
{
    int32_t temp = _value + ((int16_t)_step);
    if (_hasMax)
    {
        if (temp > _maxValue)
        {
            return;
        }
    }
    if (temp > 32767)
    {
        return;
    }
    _value = (int16_t)temp;
}

void FLProgIntegerMenuItem::valueDown()
{
    int32_t temp = _value - ((int16_t)_step);
    if (_hasMin)
    {
        if (temp < _minValue)
        {
            return;
        }
    }
    if (temp < -32767)
    {
        return;
    }
    _value = (int16_t)temp;
}

void FLProgIntegerMenuItem::pressSymbolButton(char value)
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

void FLProgIntegerMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}