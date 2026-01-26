#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractMenuItem.h"


class FLProgGroupMenuItem : public FLProgAbstractMenuItem
{
public:
    FLProgGroupMenuItem(String name, int16_t itemsCounts, uint8_t aditionalsStringsCount = 0);
    void setItem(int16_t index, FLProgAbstractMenuItem *item);
    virtual void setValueString(String value) { _valueString = value; };
    virtual String valueString() { return _valueString; };

    virtual bool isGroup() { return true; };

    virtual FLProgAbstractMenuItem *getCurrentMenuItemParent(FLProgAbstractMenuItem *current);

    virtual FLProgAbstractMenuItem *menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *firstItem();

protected:
    FLProgAbstractMenuItem *previous(FLProgAbstractMenuItem *current, bool _isRingControl);
    FLProgAbstractMenuItem *next(FLProgAbstractMenuItem *current, bool _isRingControl);
    int16_t indexForCurrentItem(FLProgAbstractMenuItem *current);
    FLProgAbstractMenuItem **_items = 0;
    int16_t _itemsCounts = 0;
    String _valueString;
};
