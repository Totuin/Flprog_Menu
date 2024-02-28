#include "flprogCharMenuItem.h"

FLProgCharMenuItem::FLProgCharMenuItem(String name, uint8_t aditionalsStringsCount)
{
    initItem(name, aditionalsStringsCount);
    _convertType = FLPROG_MENU_SYMBOL_CONVERT_TYPE;
}

void FLProgCharMenuItem::setValue(String value)
{
    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
    {
        setCharValue(flprog::stringToChar(value));
        return;
    }
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
    setCharValue((char)((uint8_t)temp));
}

String FLProgCharMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
    {
        return String(_value);
    }
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String((uint8_t)_value, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String((uint8_t)_value, BIN);
    }
    String temp = String((uint8_t)_value, HEX);
    temp.toUpperCase();
    return temp;
}

void FLProgCharMenuItem::valueUp()
{
    if (((uint8_t)_value) > (255 - step()))
    {
        return;
    }
    setCharValue((char)(((uint8_t)_value) + step()));
}

void FLProgCharMenuItem::valueDown()
{
    if (((uint8_t)_value) < step())
    {
        return;
    }
    setCharValue((char)(((uint8_t)_value) - step()));
}

void FLProgCharMenuItem::pressSymbolButton(char value)
{
    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
    {
        setCharValue(value);
        return;
    }
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

void FLProgCharMenuItem::pressBacspaceButton()
{
    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
    {
        return;
    }
    privatePressBacspaceButton();
}