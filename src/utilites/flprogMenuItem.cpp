#include "flprogMenuItem.h"
void FLProgAbstractMenuItem::initItem(String name, uint8_t aditionalsStringsCount)
{
    _name = name;
    _additionalsStringsCount = aditionalsStringsCount;
    if (_additionalsStringsCount > 0)
    {
        _additionalsStrings = new String[aditionalsStringsCount];
    }
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::getCurrentMenuItemParent(FLProgAbstractMenuItem *current)
{
    (void)current;
    return 0;
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl)
{
    (void)isRingControl;
    return current;
}

FLProgAbstractMenuItem *FLProgAbstractMenuItem::menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl)
{
    (void)isRingControl;
    return current;
}

String FLProgAbstractMenuItem::aditionalString(uint8_t index)
{
    if (_additionalsStringsCount == 0)
    {
        return "";
    }
    if (index >= _additionalsStringsCount)
    {
        return "";
    }
    return _additionalsStrings[index];
}

void FLProgAbstractMenuItem::setAditionalString(String value, uint8_t index)
{

    if (_additionalsStringsCount == 0)
    {
        return;
    }
    if (index >= _additionalsStringsCount)
    {
        return;
    }
    _additionalsStrings[index] = value;
}

void FLProgAbstractMenuItem::setValue(bool value)
{
    if (isBoolean())
    {
        setBooleanValue(value);
        return;
    }
    uint8_t temp;
    if (value)
    {
        temp = 1;
    }
    else
    {
        temp = 0;
    }
    if (isByte())
    {
        setByteValue(temp);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(temp);
        return;
    }
    if (isLong())
    {
        setLongValue(temp);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(temp);
        return;
    }
    if (isFloat())
    {
        setFloatValue(temp);
        return;
    }
    if (isChar())
    {
        setCharValue((char)temp);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(uint8_t value)
{
    if (isBoolean())
    {
        setBooleanValue(value > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value);
        return;
    }
    if (isLong())
    {
        setLongValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatValue(value);
        return;
    }
    if (isChar())
    {
        setCharValue((char)value);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(int16_t value)
{
    if (isBoolean())
    {
        setBooleanValue(value > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value);
        return;
    }
    if (isLong())
    {
        setLongValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatValue(value);
        return;
    }
    if (isChar())
    {
        setCharValue((char)value);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(int32_t value)
{
    if (isBoolean())
    {
        setBooleanValue(value > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value);
        return;
    }
    if (isLong())
    {
        setLongValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatValue(value);
        return;
    }
    if (isChar())
    {
        setCharValue((char)value);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(uint32_t value)
{
    if (isBoolean())
    {
        setBooleanValue(value > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value);
        return;
    }
    if (isLong())
    {
        setLongValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatValue(value);
        return;
    }
    if (isChar())
    {
        setCharValue((char)value);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(float value)
{
    if (isBoolean())
    {
        setBooleanValue(value > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value);
        return;
    }
    if (isLong())
    {
        setLongValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatValue(value);
        return;
    }
    if (isChar())
    {
        setCharValue((char)value);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(char value)
{
    if (isChar())
    {
        setCharValue(value);
        return;
    }
    uint8_t temp = (uint8_t)value;
    if (isBoolean())
    {
        setBooleanValue(temp > 0);
        return;
    }
    if (isByte())
    {
        setByteValue(temp);
        return;
    }
    if (isInteger())
    {
        setIntegerValue(temp);
        return;
    }
    if (isLong())
    {
        setLongValue(temp);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(temp);
        return;
    }
    if (isFloat())
    {
        setFloatValue(temp);
        return;
    }
}

void FLProgAbstractMenuItem::setValue(String value)
{
    if (isBoolean())
    {
        setBooleanValue(flprog::stringToBool(value));
        return;
    }
    if (isFloat())
    {
        setFloatValue(value.toFloat());
        return;
    }
    if (isChar())
    {
        setCharValue(flprog::stringToChar(value));
        return;
    }
    setValue(value.toInt());
}

void FLProgAbstractMenuItem::setMaxValue(uint8_t value)
{

    if (isByte())
    {
        setByteMaxValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMaxValue(value);
        return;
    }
    if (isLong())
    {
        setLongMaxValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMaxValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMaxValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMaxValue(int16_t value)
{

    if (isByte())
    {
        setByteMaxValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMaxValue(value);
        return;
    }
    if (isLong())
    {
        setLongMaxValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMaxValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMaxValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMaxValue(int32_t value)
{

    if (isByte())
    {
        setByteMaxValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMaxValue(value);
        return;
    }
    if (isLong())
    {
        setLongMaxValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMaxValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMaxValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMaxValue(uint32_t value)
{

    if (isByte())
    {
        setByteMaxValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMaxValue(value);
        return;
    }
    if (isLong())
    {
        setLongMaxValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMaxValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMaxValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMaxValue(float value)
{

    if (isByte())
    {
        setByteMaxValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMaxValue(value);
        return;
    }
    if (isLong())
    {
        setLongMaxValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMaxValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMaxValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMinValue(uint8_t value)
{

    if (isByte())
    {
        setByteMinValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMinValue(value);
        return;
    }
    if (isLong())
    {
        setLongMinValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMinValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMinValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMinValue(int16_t value)
{

    if (isByte())
    {
        setByteMinValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMinValue(value);
        return;
    }
    if (isLong())
    {
        setLongMinValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMinValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMinValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMinValue(int32_t value)
{

    if (isByte())
    {
        setByteMinValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMinValue(value);
        return;
    }
    if (isLong())
    {
        setLongMinValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMinValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMinValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMinValue(uint32_t value)
{

    if (isByte())
    {
        setByteMinValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMinValue(value);
        return;
    }
    if (isLong())
    {
        setLongMinValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMinValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMinValue(value);
        return;
    }
}

void FLProgAbstractMenuItem::setMinValue(float value)
{

    if (isByte())
    {
        setByteMinValue(value);
        return;
    }
    if (isInteger())
    {
        setIntegeMinValue(value);
        return;
    }
    if (isLong())
    {
        setLongMinValue(value);
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongMinValue(value);
        return;
    }
    if (isFloat())
    {
        setFloatMinValue(value);
        return;
    }
}

//--------------------------------FLProgGroupMenuItem---------------------------

FLProgGroupMenuItem::FLProgGroupMenuItem(String name, int16_t itemsCounts, uint8_t aditionalsStringsCount)
{
    _items = new FLProgAbstractMenuItem *[itemsCounts];
    _itemsCounts = itemsCounts;
    initItem(name, aditionalsStringsCount);
}

void FLProgGroupMenuItem::setItem(int16_t index, FLProgAbstractMenuItem *item)
{
    if (index >= _itemsCounts)
    {
        return;
    }
    _items[index] = item;
}

void FLProgGroupMenuItem::setConvertString(String value, uint8_t index)
{
    (void)value;
    (void)index;
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::getCurrentMenuItemParent(FLProgAbstractMenuItem *current)
{
    FLProgAbstractMenuItem *temp;
    if (current == 0)
    {
        return 0;
    }
    for (int16_t i = 0; i < _itemsCounts; i++)
    {
        if (_items[i]->isGroup())
        {
            temp = _items[i]->getCurrentMenuItemParent(current);
            if (temp != 0)
            {
                return temp;
            }
        }
        else
        {
            if (_items[i] == current)
            {
                return this;
            }
        }
    }
    return 0;
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::menuItemUp(FLProgAbstractMenuItem *current, bool isRingControl)
{
    if (_itemsCounts == 0)
    {
        return current;
    }
    return previous(current, isRingControl);
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::menuItemDown(FLProgAbstractMenuItem *current, bool isRingControl)
{
    if (_itemsCounts == 0)
    {
        return current;
    }
    return next(current, isRingControl);
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::previous(FLProgAbstractMenuItem *current, bool _isRingControl)
{
    int16_t index = indexForCurrentItem(current);
    if (index < 0)
    {
        return current;
    }
    if (index == 0)
    {
        if (_isRingControl)
        {
            return _items[(_itemsCounts - 1)];
        }
        else
        {
            return current;
        }
    }
    return _items[index - 1];
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::next(FLProgAbstractMenuItem *current, bool _isRingControl)
{
    int16_t index = indexForCurrentItem(current);
    if (index < 0)
    {
        return current;
    }
    if (index == (_itemsCounts - 1))
    {
        if (_isRingControl)
        {
            return _items[0];
        }
        else
        {
            return current;
        }
    }
    return _items[index + 1];
}

int16_t FLProgGroupMenuItem::indexForCurrentItem(FLProgAbstractMenuItem *current)
{
    if (_itemsCounts == 0)
    {
        return -1;
    }
    for (int16_t i = 0; i < _itemsCounts; i++)
    {
        if (current == _items[i])
        {
            return i;
        }
    }
    return -1;
}

FLProgAbstractMenuItem *FLProgGroupMenuItem::firstItem()
{
    if (_itemsCounts == 0)
    {
        return 0;
    }
    return _items[0];
}

//--------------------------------FLProgBasicMenuItem---------------------------

void FLProgBasicMenuItem::setConvertString(String value, uint8_t index)
{
    if (index != 0)
    {
        return;
    }
    _convertText = value;
}

String FLProgBasicMenuItem::valueString()
{
    if (_convertText.equals(FLPROG_MENU_DEC_CONVERT_TYPE))
    {
        if (isByte())
        {
            return String(byteleanValue(), DEC);
        }
        if (isInteger())
        {
            return String(integerValue(), DEC);
        }
        if (isLong())
        {
            return String(longValue(), DEC);
        }
        if (isUnsignedLong())
        {
            return String(unsignedLongValue(), DEC);
        }
    }
    if (_convertText.equals(FLPROG_MENU_HEX_CONVERT_TYPE))
    {
        if (isByte())
        {
            return String(byteleanValue(), HEX);
        }
        if (isInteger())
        {
            return String(integerValue(), HEX);
        }
        if (isLong())
        {
            return String(longValue(), HEX);
        }
        if (isUnsignedLong())
        {
            return String(unsignedLongValue(), HEX);
        }
    }
    if (_convertText.equals(FLPROG_MENU_BIN_CONVERT_TYPE))
    {
        if (isByte())
        {
            return String(byteleanValue(), BIN);
        }
        if (isInteger())
        {
            return String(integerValue(), BIN);
        }
        if (isLong())
        {
            return String(longValue(), BIN);
        }
        if (isUnsignedLong())
        {
            return String(unsignedLongValue(), BIN);
        }
    }
    return "";
}

//--------------------------------FLProgBooleanMenuItem---------------------------

void FLProgBooleanMenuItem::setConvertString(String value, uint8_t index)
{
    if (index == 0)
    {
        _textForFalse = value;
    }
    if (index == 1)
    {
        _convertText = value;
    }
}

String FLProgBooleanMenuItem::valueString()
{
    if (_value)
    {
        return _convertText;
    }
    return _textForFalse;
}

void FLProgBooleanMenuItem::valueUp()
{
    _value = !_value;
}
void FLProgBooleanMenuItem::valueDown()
{
    _value = !_value;
}

//--------------------------------FLProgByteMenuItem---------------------------

void FLProgByteMenuItem::setByteMaxValue(uint8_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgByteMenuItem::setByteMinValue(uint8_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgByteMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value >= _maxValue)
            return;
    }
    if (_value == 255)
    {
        return;
    }
    _value = _value + ((uint8_t)_step);
}
void FLProgByteMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value <= _minValue)
            return;
    }
    if (_value == 0)
    {
        return;
    }
    _value = _value - ((uint8_t)_step);
}

//--------------------------------FLProgIntegerMenuItem---------------------------

void FLProgIntegerMenuItem::setIntegeMaxValue(int16_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgIntegerMenuItem::setIntegeMinValue(int16_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgIntegerMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value >= _maxValue)
            return;
    }
    if (_value == 32767)
    {
        return;
    }
    _value = _value + ((int16_t)_step);
}
void FLProgIntegerMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value <= _minValue)
            return;
    }
    if (_value == -32768)
    {
        return;
    }
    _value = _value - ((int16_t)_step);
}

//--------------------------------FLProgLongMenuItem---------------------------

void FLProgLongMenuItem::setLongMaxValue(int32_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgLongMenuItem::setLongMinValue(int32_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgLongMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value >= _maxValue)
            return;
    }
    if (_value == 2147483647)
    {
        return;
    }
    _value = _value + ((int32_t)_step);
}

void FLProgLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value <= _minValue)
            return;
    }
    if (_value == -2147483648)
    {
        return;
    }
    _value = _value - ((int32_t)_step);
}

//--------------------------------FLProgUnsignedLongMenuItem---------------------------

void FLProgUnsignedLongMenuItem::setUnsignedLongMaxValue(uint32_t value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgUnsignedLongMenuItem::setUnsignedLongMinValue(uint32_t value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgUnsignedLongMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value >= _maxValue)
            return;
    }
    if (_value == 4294967295)
    {
        return;
    }
    _value = _value + ((uint32_t)_step);
}

void FLProgUnsignedLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value <= _minValue)
            return;
    }
    if (_value == 0)
    {
        return;
    }
    _value = _value - ((uint32_t)_step);
}

//--------------------------------FLProgFloatMenuItem---------------------------

FLProgFloatMenuItem::FLProgFloatMenuItem(String name, uint8_t aditionalsStringsCount)
{
    initItem(name, aditionalsStringsCount);
    _convertText = "2";
}

String FLProgFloatMenuItem::valueString()
{
    return String(_value, (_convertText.toInt()));
}

void FLProgFloatMenuItem::setFloatMaxValue(float value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgFloatMenuItem::setFloatMinValue(float value)
{
    _minValue = value;
    _hasMin = true;
}

void FLProgFloatMenuItem::valueUp()
{
    if (_hasMax)
    {
        if (_value >= _maxValue)
            return;
    }
    _value = _value + _step;
}

void FLProgFloatMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value <= _minValue)
            return;
    }

    _value = _value - _step;
}

//--------------------------------FLProgCharMenuItem---------------------------

FLProgCharMenuItem::FLProgCharMenuItem(String name, uint8_t aditionalsStringsCount)
{
    initItem(name, aditionalsStringsCount);
    _convertText = FLPROG_MENU_SYMBOL_CONVERT_TYPE;
}

String FLProgCharMenuItem::valueString()
{
    if (_convertText.equals(FLPROG_MENU_DEC_CONVERT_TYPE))
    {
        return String((uint8_t)_value, DEC);
    }
    if (_convertText.equals(FLPROG_MENU_HEX_CONVERT_TYPE))
    {
        return String((uint8_t)_value, HEX);
    }
    if (_convertText.equals(FLPROG_MENU_BIN_CONVERT_TYPE))
    {
        return String((uint8_t)_value, BIN);
    }

    if (_convertText.equals(FLPROG_MENU_SYMBOL_CONVERT_TYPE))
    {
        return String(_value);
    }
    return "";
}

void FLProgCharMenuItem::valueUp()
{

    if (((uint8_t)_value) == 255)
    {
        return;
    }
    _value = (char)(((uint8_t)_value) + ((uint8_t)_step));
}

void FLProgCharMenuItem::valueDown()
{

    if (_value == 0)
    {
        return;
    }
    _value = (char)(((uint8_t)_value) - ((uint8_t)_step));
}