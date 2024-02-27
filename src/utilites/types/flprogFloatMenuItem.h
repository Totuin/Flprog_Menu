#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgFloatMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgFloatMenuItem(String name, uint8_t aditionalsStringsCount = 0);

    virtual float floatValue() { return _value; };

    virtual String valueString();
    virtual void setValue(String value);

    virtual void setFloatValue(float value);
    virtual void setFloatMaxValue(float value);
    virtual void setFloatMinValue(float value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();
    virtual void pressClearButton();

    virtual bool isFloat() { return true; };
    virtual void resetInput();

protected:
    String removeLastZeroSymbol(String value);
    float _value = 0;
    float _maxValue;
    float _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
    uint8_t _zerroCount = 0;
    bool _isNeedDot = false;
};
