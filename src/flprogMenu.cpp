#include "flprogMenu.h"

FLProgMenu::FLProgMenu(uint16_t itemsCounts)
{
    _items = new FLProgAbstractMenuItem *[itemsCounts];
    _itemsCounts = itemsCounts;
}

void FLProgMenu::setItem(uint16_t index, FLProgAbstractMenuItem *item)
{
    if (index >= _itemsCounts)
    {
        return;
    }
    _items[index] = item;
}