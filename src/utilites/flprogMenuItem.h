#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_MENU_DEC_CONVERT_TYPE "D"
#define FLPROG_MENU_HEX_CONVERT_TYPE "H"
#define FLPROG_MENU_BIN_CONVERT_TYPE "B"
#define FLPROG_MENU_SYMBOL_CONVERT_TYPE "B"

class FLProgAbstractMenuItem
{
public:
    void setName(String name) { _name = name; };
    String name() { return _name; };

    virtual void setValueString(String value) { (void)value; };
    virtual void setConvertString(String value, uint8_t index = 0) = 0;

    virtual String valueString() { return ""; };
    void setAditionalString(String value, uint8_t index);
    String aditionalString(uint8_t index);
    virtual String convertString() { return FLPROG_MENU_DEC_CONVERT_TYPE; };

    virtual bool booleanValue() { return false; };
    virtual uint8_t byteleanValue() { return 0; };
    virtual int16_t integerValue() { return 0; };
    virtual int32_t longValue() { return 0; };
    virtual uint32_t unsignedLongValue() { return 0; };
    virtual float floatValue() { return 0; };
    virtual char charValue() { return (char)0; };

    void setValue(String value);

    virtual void setBooleanValue(bool value) { (void)value; };
    virtual void setByteValue(uint8_t value) { (void)value; };
    virtual void setIntegerValue(int16_t value) { (void)value; };
    virtual void setLongValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongValue(uint32_t value) { (void)value; };
    virtual void setFloatValue(float value) { (void)value; };
    virtual void setCharValue(char value) { (void)value; };

    virtual void setByteMaxValue(uint8_t value) { (void)value; };
    virtual void setIntegeMaxValue(int16_t value) { (void)value; };
    virtual void setLongMaxValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongMaxValue(uint32_t value) { (void)value; };
    virtual void setFloatMaxValue(float value) { (void)value; };

    virtual void setByteMinValue(uint8_t value) { (void)value; };
    virtual void setIntegeMinValue(int16_t value) { (void)value; };
    virtual void setLongMinValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongMinValue(uint32_t value) { (void)value; };
    virtual void setFloatMinValue(float value) { (void)value; };

    virtual void setStep(float value) { (void)value; };

    virtual bool isBoolean() { return false; };
    virtual bool isByte() { return false; };
    virtual bool isInteger() { return false; };
    virtual bool isLong() { return false; };
    virtual bool isUnsignedLong() { return false; };
    virtual bool isFloat() { return false; };
    virtual bool isChar() { return false; };
    virtual bool isGroup() { return false; };

    virtual void valueUp(){};
    virtual void valueDown(){};
    virtual void pressSymbolButton(char value) { (void)value; };
    virtual void pressBacspaceButton(){};

    virtual FLProgAbstractMenuItem *getCurrentMenuItemParent(FLProgAbstractMenuItem *current);
    virtual FLProgAbstractMenuItem *menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *firstItem() { return 0; };

protected:
    void initItem(String name, uint8_t aditionalsStringsCount);
    String _name;
    uint8_t _additionalsStringsCount = 0;
    String *_additionalsStrings = 0;
};

class FLProgGroupMenuItem : public FLProgAbstractMenuItem
{
public:
    FLProgGroupMenuItem(String name, int16_t itemsCounts, uint8_t aditionalsStringsCount = 0);
    void setItem(int16_t index, FLProgAbstractMenuItem *item);
    virtual void setValueString(String value) { _valueString = value; };
    virtual String valueString() { return _valueString; };
    virtual void setConvertString(String value, uint8_t index = 0);

    virtual bool isGroup() { return true; };

    virtual FLProgAbstractMenuItem *getCurrentMenuItemParent(FLProgAbstractMenuItem *current);

    virtual FLProgAbstractMenuItem *menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl);
    virtual FLProgAbstractMenuItem *firstItem();

protected:
    FLProgAbstractMenuItem *previous(FLProgAbstractMenuItem *current, bool _isRingControl);
    FLProgAbstractMenuItem *next(FLProgAbstractMenuItem *current, bool _isRingControl);
    int16_t indexForCurrentItem(FLProgAbstractMenuItem *current);
    FLProgAbstractMenuItem **_items = 0;
    int16_t _itemsCounts = 0;
    String _valueString;
};

class FLProgBasicMenuItem : public FLProgAbstractMenuItem
{
public:
    virtual void setValueString(String value) { (void)value; };
    virtual void setConvertString(String value, uint8_t index = 0);
    virtual void setStep(float value) { _step = value; };

    virtual String valueString();
    virtual String convertString() { return _convertText; };

protected:
    void privatePressSymbolButton(char value);
    void privatePressBacspaceButton();
    float _step = 1;
    String _convertText = FLPROG_MENU_DEC_CONVERT_TYPE;
};

class FLProgBooleanMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgBooleanMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };

    virtual String valueString();

    virtual void setConvertString(String value, uint8_t index = 0);

    virtual bool booleanValue() { return _value; };

    virtual bool isBoolean() { return true; };

    virtual void valueUp();
    virtual void valueDown();
    virtual void setBooleanValue(bool value) { _value = value; };
    virtual void pressSymbolButton(char value);

protected:
    String _textForFalse;
    bool _value = false;
};

class FLProgByteMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgByteMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };
    virtual uint8_t byteleanValue() { return _value; };

    virtual bool isByte() { return true; };

    virtual void valueUp();
    virtual void valueDown();
    virtual void setByteValue(uint8_t value) { _value = value; };
    virtual void setByteMaxValue(uint8_t value);
    virtual void setByteMinValue(uint8_t value);

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();

protected:
    uint8_t _value = 0;
    uint8_t _maxValue;
    uint8_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};

class FLProgIntegerMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgIntegerMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };
    virtual int16_t integerValue() { return _value; };

    virtual bool isInteger() { return true; };

    virtual void valueUp();
    virtual void valueDown();

    virtual void setIntegerValue(int16_t value) { _value = value; };
    virtual void setIntegeMaxValue(int16_t value);
    virtual void setIntegeMinValue(int16_t value);

    virtual void pressSymbolButton(char value);
    virtual void pressBacspaceButton();

protected:
    int16_t _value = 0;
    int16_t _maxValue;
    int16_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};

class FLProgLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgLongMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };
    virtual int32_t longValue() { return _value; };

    virtual bool isLong() { return true; };

    virtual void valueUp();
    virtual void valueDown();

    virtual void setLongValue(int32_t value) { _value = value; };
    virtual void setLongMaxValue(int32_t value);
    virtual void setLongMinValue(int32_t value);

protected:
    int32_t _value = 0;
    int32_t _maxValue;
    int32_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};

class FLProgUnsignedLongMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgUnsignedLongMenuItem(String name, uint8_t aditionalsStringsCount = 0) { initItem(name, aditionalsStringsCount); };
    virtual uint32_t unsignedLongValue() { return _value; };

    virtual bool isUnsignedLong() { return true; };

    virtual void valueUp();
    virtual void valueDown();

    virtual void setUnsignedLongValue(uint32_t value) { _value = value; };
    virtual void setUnsignedLongMaxValue(uint32_t value);
    virtual void setUnsignedLongMinValue(uint32_t value);

protected:
    uint32_t _value = 0;
    uint32_t _maxValue;
    uint32_t _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};

class FLProgFloatMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgFloatMenuItem(String name, uint8_t aditionalsStringsCount = 0);

    virtual float floatValue() { return _value; };

    virtual bool isFloat() { return true; };

    virtual String valueString();

    virtual void valueUp();
    virtual void valueDown();

    virtual void setFloatValue(float value) { _value = value; };
    virtual void setFloatMaxValue(float value);
    virtual void setFloatMinValue(float value);

protected:
    float _value = 0;
    float _maxValue;
    float _minValue;
    bool _hasMax = false;
    bool _hasMin = false;
};

class FLProgCharMenuItem : public FLProgBasicMenuItem
{
public:
    FLProgCharMenuItem(String name, uint8_t aditionalsStringsCount = 0);

    virtual char charValue() { return _value; };

    virtual String valueString();

    virtual bool isChar() { return true; };

    virtual void valueUp();
    virtual void valueDown();

protected:
    virtual void setCharValue(char value) { _value = value; };
    char _value = 0;
};
