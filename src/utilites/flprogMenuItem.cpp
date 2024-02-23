#include "flprogMenuItem.h"

FLProgGroupMenuItem::FLProgGroupMenuItem(uint16_t itemsCounts)
{
    _items = new FLProgAbstractMenuItem *[itemsCounts];
    _itemsCounts = itemsCounts;
}

void FLProgGroupMenuItem::setItem(uint16_t index, FLProgAbstractMenuItem *item)
{
    if (index >= _itemsCounts)
    {
        return;
    }
    _items[index] = item;
}

void FLProgGroupMenuItem::setConvertString(String value, uint8_t index)
{
    (void)value;
    (void)index;
}

void FLProgBasicMenuItem::initItem(uint8_t aditionalsStringsCount)
{
    _additionalsStringsCount = aditionalsStringsCount;
    if (_additionalsStringsCount > 0)
    {
        _additionalsStrings = new String[aditionalsStringsCount];
    }
}

void FLProgBooleanMenuItem::setConvertString(String value, uint8_t index)
{
    if (index == 0)
    {
        _textForFalse = value;
    }
    if (index == 1)
    {
        _textForTrue = value;
    }
}