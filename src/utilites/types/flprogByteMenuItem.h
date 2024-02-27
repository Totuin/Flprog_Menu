#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgByteMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgByteMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual String valueString();
    virtual void setValue(String value);

    virtual uint8_t byteValue() { return _value; };
    virtual void setByteValue(uint8_t value);

    virtual void setByteMaxValue(uint8_t value);
    virtual void setByteMinValue(uint8_t value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();

    virtual bool isByte() { return true; };

protected:
    uint8_t _value = 0;
    uint8_t _maxValue;
    uint8_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};
