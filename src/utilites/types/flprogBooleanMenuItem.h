#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgBooleanMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgBooleanMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual String valueString();
    virtual void setValue(String value);

    virtual bool booleanValue() { return _value; };
    virtual bool isBoolean() { return true; };

    virtual void valueUp();
    virtual void valueDown();
    virtual void setBooleanValue(bool value) { _value = value; };
    virtual void pressSymbolButton(char value);

    void textForTrue(String value) { _textForTrue = value; };
    void textForFalse(String value) { _textForFalse = value; };

protected:
    bool _value = false;
    String _textForTrue = "true";
    String _textForFalse = "false";
};