#include "flprogBooleanMenuItem.h"

void FLProgBooleanMenuItem::setValue(String value)
{
    _value = flprog::stringToBool(value);
}

String FLProgBooleanMenuItem::valueString()
{
    if (_value)
    {
        return _textForTrue;
    }
    return _textForFalse;
}

void FLProgBooleanMenuItem::valueUp()
{
    _value = !_value;
}
void FLProgBooleanMenuItem::valueDown()
{
    _value = !_value;
}

void FLProgBooleanMenuItem::pressSymbolButton(char value)
{
    if (value == '0')
    {
        _value = false;
        return;
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        _value = true;
        return;
    }
}
