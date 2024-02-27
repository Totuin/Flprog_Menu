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

    virtual void setFloatValue(float value) ;
    virtual void setFloatMaxValue(float value);
    virtual void setFloatMinValue(float value);

    virtual void valueUp();
    virtual void valueDown();

    virtual bool isFloat() { return true; };

protected:
    float _value = 0;
    float _maxValue;
    float _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};
