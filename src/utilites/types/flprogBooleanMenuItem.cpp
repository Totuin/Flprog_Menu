#include "flprogBooleanMenuItem.h"

void FLProgBooleanMenuItem::setValue(String value)
{
    setBooleanValue(flprog::stringToBool(value));
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
    setBooleanValue(!_value);
}
void FLProgBooleanMenuItem::valueDown()
{
    setBooleanValue(!_value);
}

void FLProgBooleanMenuItem::pressSymbolButton(char value)
{
    if (value == '0')
    {
        setBooleanValue(false);
        return;
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        setBooleanValue(true);
        return;
    }
}
