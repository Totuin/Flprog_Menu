#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "../basic/flprogBasicMenuItem.h"

class FLProgCharMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgCharMenuItem(){};
    FLProgCharMenuItem(String name, uint8_t aditionalsStringsCount = 0);

    virtual char charValue() { return _value; };

    virtual void setCharValue(char value) { _value = value; };

    virtual String valueString();
    virtual void setValue(String value);

    virtual void valueUp();
    virtual void valueDown();
    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();
    virtual void pressClearButton() { _value = (char)0; };

    virtual bool isChar() { return true; };

protected:
    uint8_t step() { return (uint8_t)_step; };
    char _value = (char)0;
};
