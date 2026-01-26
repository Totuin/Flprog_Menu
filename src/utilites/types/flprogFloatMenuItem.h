#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgFloatMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgFloatMenuItem(){};
    FLProgFloatMenuItem(String name, uint8_t aditionalsStringsCount = 0);

    virtual double floatValue() { return _value; };

    virtual String valueString();
    virtual void setValue(String value);

    virtual void setFloatValue(double value);
    virtual void setFloatMaxValue(double value);
    virtual void setFloatMinValue(double value);

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();
    virtual void pressClearButton();

    virtual bool isFloat() { return true; };
    virtual void resetInput();

protected:
    String removeLastZeroSymbol(String value);
    double _value = 0;
    double _maxValue;
    double _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
    uint8_t _zerroCount = 0;
    bool _isNeedDot = false;
};
