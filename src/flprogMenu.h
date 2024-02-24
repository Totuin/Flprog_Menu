#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "utilites/flprogMenuItem.h"

class FLProgMenu
{
public:
    FLProgMenu(int16_t itemsCounts);

    void setItem(int16_t index, FLProgAbstractMenuItem *item);
    void isRingControl(bool value) { _isRingControl = value; };

    void menuItemUp();
    void menuItemDown();

    void menuValueUp();
    void menuValueDown();

    void menuGroupEnter();
    void menuGroupExit();

    void pressSymbolButton(char value);
    void pressBacspaceButton();

    void reset();

    void setValue(bool value);
    void setValue(uint8_t value);
    void setValue(int16_t value);
    void setValue(int32_t value);
    void setValue(uint32_t value);
    void setValue(float value);
    void setValue(char value);
    void setValue(String value);

    FLProgAbstractMenuItem *getCurrentMenuIntem();

    String nameString();
    String valueString();
    String aditionalString(uint8_t index);

protected:
    FLProgAbstractMenuItem *getCurrentMenuItemParent();
    FLProgAbstractMenuItem *next();
    FLProgAbstractMenuItem *previous();
    int16_t indexForCurrentItem();

    int16_t _itemsCounts = 0;
    FLProgAbstractMenuItem **_items = 0;
    FLProgAbstractMenuItem *_currentMenuItem = 0;
    bool _isRingControl = false;
};
