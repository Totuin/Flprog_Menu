#include "flprogBasicMenuItem.h"

void FLProgBasicMenuItem::privatePressSymbolButton(char value)
{
    String temp = valueString();
    if (value == '-')
    {
        if (temp.length() == 0)
        {
            return;
        }
        if (temp.charAt(0) == '-')
        {
            setValue(temp.substring(1));
            return;
        }
        setValue((String('-') + temp));
        return;
    }
    if ((value == '.') || (value == ','))
    {
        if (temp.length() == 0)
        {
            return;
        }
        if (temp.indexOf('.') > -1)
        {
            return;
        }
        temp.concat('.');
        setValue(temp);
        return;
    }
    temp.concat(value);
    setValue(temp);
}

void FLProgBasicMenuItem::privatePressBacspaceButton()
{
    String temp = valueString();
    if (temp.length() == 0)
    {
        return;
    }
    if (temp.length() == 1)
    {
        temp = "";
    }
    else
    {
        temp = temp.substring(0, (temp.length() - 1));
    }
    setValue(temp);
}
