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

    /*  #define FLPROG_MENU_DEC_CONVERT_TYPE "D"
    #define FLPROG_MENU_BIN_CONVERT_TYPE "B"
    #define FLPROG_MENU_SYMBOL_CONVERT_TYPE "B"
    */

    int32_t temp;
    if (convertString() == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        tempflprog::hexStringToLong(value);
    }
    else
    {
        temp = value.toInt();
    }
    if (isByte())
    {
        if ((temp >= 0) && (temp < 256))
        {
            setByteValue(temp);
        }
        return;
    }
    if (isInteger())
    {
        setIntegerValue(value.toInt());
        return;
    }
    if (isLong())
    {
        setLongValue(value.toInt());
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(value.toInt());
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

void FLProgBasicMenuItem::privatePressSymbolButton(char value)
{
    String temp = valueString();
    if (value == '-')
    {
        if (temp.length() == 0)
        {
            return;
        }
        if (temp[0] == '-')
        {
            setValue(temp.substring(1));
            return;
        }
        setValue((String('-') + temp));
        return;
    }
    if ((value == '.') || (value == ','))
    {
        if (temp.length() == 0)
        {
            return;
        }
        if (temp.indexOf('.') > -1)
        {
            return;
        }
        temp.concat('.');
        setValue(temp);
        return;
    }
    temp.concat(value);
    setValue(temp);
}

void FLProgBasicMenuItem::privatePressBacspaceButton()
{
    String temp = valueString();
    if (temp.length() == 0)
    {
        return;
    }
    if (temp.length() == 1)
    {
        temp = "";
    }
    else
    {
        temp = temp.substring(0, (temp.length() - 1));
    }
    setValue(temp);
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

void FLProgBooleanMenuItem::pressSymbolButton(char value)
{
    if (value == '0')
    {
        _value = false;
        return;
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        _value = true;
        return;
    }
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

void FLProgByteMenuItem::pressSymbolButton(char value)
{
    if (flprog::isHexNumberChar(value))
    {
        if (_convertText == FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if (!((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value))))
    {
        return;
    }

    if (_convertText == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if (!((value == '0') || (value == '1')))
        {
            return;
        }
    }
    privatePressSymbolButton(value);
}

void FLProgByteMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
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

void FLProgIntegerMenuItem::pressSymbolButton(char value)
{
    if (value != '-')
    {
        if (flprog::isHexNumberChar(value))
        {
            if (_convertText == FLPROG_MENU_HEX_CONVERT_TYPE)
            {
                return;
            }
        }
        if (!((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value))))
        {
            return;
        }

        if (_convertText == FLPROG_MENU_BIN_CONVERT_TYPE)
        {

            if (!((value == '0') || (value == '1')))
            {
                return;
            }
        }
    }
    privatePressSymbolButton(value);
}
void FLProgIntegerMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
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