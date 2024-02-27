#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgIntegerMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgIntegerMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual int16_t integerValue() { return _value; };

    virtual String valueString();
    virtual void setValue(String value);

    virtual void setIntegerValue(int16_t value);
    virtual void setIntegeMaxValue(int16_t value);
    virtual void setIntegeMinValue(int16_t value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();
    virtual void pressClearButton();

    virtual bool isInteger() { return true; };

protected:
    int16_t _value = 0;
    int16_t _maxValue;
    int16_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};