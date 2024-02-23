#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

class FLProgAbstractMenuItem
{
public:
    void setName(String name) { _name = name; };
    String name() { return _name; };
    virtual void setValueString(String value) = 0;
    virtual void setConvertString(String value, uint8_t index = 0) = 0;
    virtual String valueString() = 0;

protected:
    String _name;
};

class FLProgGroupMenuItem : public FLProgAbstractMenuItem
{
public:
    FLProgGroupMenuItem(uint16_t itemsCounts);
    void setItem(uint16_t index, FLProgAbstractMenuItem *item);
    virtual void setValueString(String value) { _valueString = value; };
    virtual String valueString() { return _valueString; };
    virtual void setConvertString(String value, uint8_t index = 0);

protected:
    FLProgAbstractMenuItem **_items = 0;
    uint16_t _itemsCounts = 0;
    String _valueString;
};

class FLProgBasicMenuItem : public FLProgAbstractMenuItem
{
public:
    virtual void setValueString(String value) { (void)value; };
    void initItem(uint8_t aditionalsStringsCount);

protected:
    String *_additionalsStrings = 0;
    uint8_t _additionalsStringsCount = 0;
};
class FLProgEEPROMMenuItem : public FLProgBasicMenuItem
{
public:
protected:
};

class FLProgBooleanMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgBooleanMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };
    virtual String valueString() { return ""; };
    virtual void setConvertString(String value, uint8_t index = 0);

protected:
    String _textForTrue;
    String _textForFalse;
};

class FLProgByteMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgByteMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};

class FLProgIntegerMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgIntegerMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};

class FLProgLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgLongMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};

class FLProgUnsignedLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgUnsignedLongMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};

class FLProgFloatMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgFloatMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};

class FLProgCharMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgCharMenuItem(uint8_t aditionalsStringsCount) { initItem(aditionalsStringsCount); };

protected:
};
