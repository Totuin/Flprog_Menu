#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgLongMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual String valueString();
    virtual void setValue(String value);

    virtual int32_t longValue() { return _value; };

    virtual void setLongValue(int32_t value);
    virtual void setLongMaxValue(int32_t value);
    virtual void setLongMinValue(int32_t value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();

    virtual bool isLong() { return true; };

protected:
    int32_t _value = 0;
    int32_t _maxValue;
    int32_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};