#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "utilites/flprogMenuItem.h"

class FLProgMenu
{
public:
    FLProgMenu(uint16_t itemsCounts);
    void setItem(uint16_t index, FLProgAbstractMenuItem *item);

protected:
    FLProgAbstractMenuItem **_items = 0;
    uint16_t _itemsCounts = 0;
};
