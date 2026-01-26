#include "flprogAbstractMenuItem.h"

void FLProgAbstractMenuItem::initItem(String name, uint8_t aditionalsStringsCount)
{
    _name = name;
    _additionalsStringsCount = aditionalsStringsCount;
    if (_additionalsStringsCount > 0)
    {
        _additionalsStrings = new String[aditionalsStringsCount];
    }
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::getCurrentMenuItemParent(FLProgAbstractMenuItem *current)
{
    (void)current;
    return 0;
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl)
{
    (void)isRingControl;
    return current;
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl)
{
    (void)isRingControl;
    return current;
}

String FLProgAbstractMenuItem::aditionalString(uint8_t index)
{
    if (_additionalsStringsCount == 0)
    {
        return "";
    }
    if (index >= _additionalsStringsCount)
    {
        return "";
    }
    return _additionalsStrings[index];
}

void FLProgAbstractMenuItem::setAditionalString(String value, uint8_t index)
{

    if (_additionalsStringsCount == 0)
    {
        return;
    }
    if (index >= _additionalsStringsCount)
    {
        return;
    }
    _additionalsStrings[index] = value;
}

