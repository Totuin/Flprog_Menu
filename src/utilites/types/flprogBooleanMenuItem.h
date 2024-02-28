#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgBooleanMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgBooleanMenuItem(){};
    FLProgBooleanMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual String valueString();
    virtual void setValue(String value);

    virtual bool booleanValue() { return _value; };
    virtual void setBooleanValue(bool value) { _value = value; };

    void textForTrue(String value) { _textForTrue = value; };
    void textForFalse(String value) { _textForFalse = value; };

    virtual void valueUp();
    virtual void valueDown();

    virtual void pressSymbolButton(char value);
    virtual void pressClearButton() { _value = false; };

    virtual bool isBoolean() { return true; };

protected:
    bool _value = false;
    String _textForTrue = "true";
    String _textForFalse = "false";
};