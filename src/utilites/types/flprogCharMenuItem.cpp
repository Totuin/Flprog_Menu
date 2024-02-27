#include "flprogCharMenuItem.h"

FLProgCharMenuItem::FLProgCharMenuItem(String name, uint8_t aditionalsStringsCount)
{
    initItem(name, aditionalsStringsCount);
    _convertType = FLPROG_MENU_SYMBOL_CONVERT_TYPE;
}

void FLProgCharMenuItem::setValue(String value)
{
    setCharValue(flprog::stringToChar(value));
}

String FLProgCharMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String((uint8_t)_value, DEC);
    }
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        return String((uint8_t)_value, HEX);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String((uint8_t)_value, BIN);
    }

    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
    {
        return String(_value);
    }
    return "";
}

void FLProgCharMenuItem::valueUp()
{

    if (((uint8_t)_value) == 255)
    {
        return;
    }
    _value = (char)(((uint8_t)_value) + ((uint8_t)_step));
}

void FLProgCharMenuItem::valueDown()
{

    if (_value == 0)
    {
        return;
    }
    _value = (char)(((uint8_t)_value) - ((uint8_t)_step));
}