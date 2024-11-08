#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_MENU_DEC_CONVERT_TYPE 0
#define FLPROG_MENU_HEX_CONVERT_TYPE 1
#define FLPROG_MENU_BIN_CONVERT_TYPE 2
#define FLPROG_MENU_SYMBOL_CONVERT_TYPE 3

class FLProgAbstractMenuItem
{
public:
    void setName(String name) { _name = name; };
    String name() { return _name; };

    virtual void setConverType(uint8_t value) { (void)value; };
    virtual uint8_t convertType() { return FLPROG_MENU_DEC_CONVERT_TYPE; };

    virtual String valueString() { return ""; };
    void setAditionalString(String value, uint8_t index);
    String aditionalString(uint8_t index);

    virtual bool booleanValue() { return false; };
    virtual uint8_t byteValue() { return 0; };
    virtual int16_t integerValue() { return 0; };
    virtual int32_t longValue() { return 0; };
    virtual uint32_t unsignedLongValue() { return 0; };
    virtual double floatValue() { return 0; };
    virtual char charValue() { return (char)0; };

    virtual void setValue(String value) { (void)value; };

    virtual void setBooleanValue(bool value) { (void)value; };
    virtual void setByteValue(uint8_t value) { (void)value; };
    virtual void setIntegerValue(int16_t value) { (void)value; };
    virtual void setLongValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongValue(uint32_t value) { (void)value; };
    virtual void setFloatValue(double value) { (void)value; };
    virtual void setCharValue(char value) { (void)value; };

    virtual void setByteMaxValue(uint8_t value) { (void)value; };
    virtual void setIntegeMaxValue(int16_t value) { (void)value; };
    virtual void setLongMaxValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongMaxValue(uint32_t value) { (void)value; };
    virtual void setFloatMaxValue(double value) { (void)value; };

    virtual void setByteMinValue(uint8_t value) { (void)value; };
    virtual void setIntegeMinValue(int16_t value) { (void)value; };
    virtual void setLongMinValue(int32_t value) { (void)value; };
    virtual void setUnsignedLongMinValue(uint32_t value) { (void)value; };
    virtual void setFloatMinValue(double value) { (void)value; };

    virtual void setStep(double value) { (void)value; };

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
    virtual void resetInput(){};
    virtual void pressClearButton(){};

    virtual void saveBuffer(){};

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
