#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgUnsignedLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgUnsignedLongMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual uint32_t unsignedLongValue() { return _value; };

    virtual String valueString();
    virtual void setValue(String value);

    virtual void setUnsignedLongValue(uint32_t value);
    virtual void setUnsignedLongMaxValue(uint32_t value);
    virtual void setUnsignedLongMinValue(uint32_t value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();

    virtual bool isUnsignedLong() { return true; };

protected:
    uint32_t _value = 0;
    uint32_t _maxValue;
    uint32_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};