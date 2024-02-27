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
    value.toUpperCase();
    uint32_t temp;
    if (convertType() == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        if (isUnsignedLong())
        {
            temp = flprog::hexStringToUnsignedLong(value);
        }
        else
        {
            temp = flprog::hexStringToLong(value);
        }
    }
    else
    {
        if (convertType() == FLPROG_MENU_BIN_CONVERT_TYPE)
        {
            if (isUnsignedLong())
            {
                temp = flprog::binStringToUnsignedLong(value);
            }
            else
            {
                temp = flprog::binStringToLong(value);
            }
        }
        else
        {
            temp = value.toInt();
        }
    }
    if (isByte())
    {
        if (temp < 256)
        {
            setByteValue((uint8_t)temp);
        }
        return;
    }
    if (isInteger())
    {
        if ((((int32_t)temp) < 32768) && (((int32_t)temp) > -32768))
        {
            setIntegerValue((int16_t)temp);
        }
        return;
    }
    if (isLong())
    {
        if ((((int32_t)temp) < 2147483647) && (((int32_t)temp) > -2147483647))
        {
            setLongValue((int32_t)temp);
        }
        return;
    }
    if (isUnsignedLong())
    {
        setUnsignedLongValue(temp);
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

String FLProgBasicMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        if (isUnsignedLong())
        {
            return String(unsignedLongValue(), DEC);
        }
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        if (isUnsignedLong())
        {
            return String(unsignedLongValue(), BIN);
        }
    }
    String temp;
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {

        if (isUnsignedLong())
        {
            temp = String(unsignedLongValue(), HEX);
            temp.toUpperCase();
            return temp;
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
        if (temp.charAt(0) == '-')
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

String FLProgBooleanMenuItem::valueString()
{
    if (_value)
    {
        return _textForTrue;
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

String FLProgByteMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String(_value, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String(_value, BIN);
    }
    String temp = String(_value, HEX);
    temp.toUpperCase();
    return temp;
}

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

void FLProgByteMenuItem::setByteValue(uint8_t value)
{
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }
    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    _value = value;
}

void FLProgByteMenuItem::valueUp()
{
    int16_t temp = _value + ((uint8_t)_step);
    if (_hasMax)
    {
        if (temp > _maxValue)
        {
            return;
        }
    }
    if (temp > 255)
    {
        return;
    }
    _value = (uint8_t)temp;
}
void FLProgByteMenuItem::valueDown()
{
    int16_t temp = _value - ((uint8_t)_step);
    if (_hasMin)
    {
        if (temp < _minValue)
        {
            return;
        }
    }
    if (temp < 0)
    {
        return;
    }
    _value = (uint8_t)temp;
}

void FLProgByteMenuItem::pressSymbolButton(char value)
{
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if (!((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value))))
    {
        return;
    }

    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
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

String FLProgIntegerMenuItem::valueString()
{
    int16_t tempValue = abs(_value);
    String temp;
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        temp = String(tempValue, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        temp = String(tempValue, BIN);
    }
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        temp = String(tempValue, HEX);
    }
    if (_value < 0)
    {
        temp = "-" + temp;
    }
    temp.toUpperCase();
    return temp;
}

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

void FLProgIntegerMenuItem::setIntegerValue(int16_t value)

{
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }

    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    _value = value;
};

void FLProgIntegerMenuItem::valueUp()
{
    int32_t temp = _value + ((int16_t)_step);
    if (_hasMax)
    {
        if (temp > _maxValue)
        {
            return;
        }
    }
    if (temp > 32767)
    {
        return;
    }
    _value = (int16_t)temp;
}

void FLProgIntegerMenuItem::valueDown()
{
    int32_t temp = _value - ((int16_t)_step);
    if (_hasMin)
    {
        if (temp < _minValue)
        {
            return;
        }
    }
    if (temp < -32767)
    {
        return;
    }
    _value = (int16_t)temp;
}

void FLProgIntegerMenuItem::pressSymbolButton(char value)
{
    if (value == '-')
    {
        privatePressSymbolButton(value);
        return;
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if ((value == '0') || (value == '1'))
        {
            privatePressSymbolButton(value);
        }
        return;
    }
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        privatePressSymbolButton(value);
    }
}

void FLProgIntegerMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}
//--------------------------------FLProgLongMenuItem---------------------------

String FLProgLongMenuItem::valueString()
{
    int32_t tempValue = abs(_value);
    String temp;

    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        temp = String(tempValue, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        temp = String(tempValue, BIN);
    }
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        temp = String(tempValue, HEX);
    }
    if (_value < 0)
    {
        temp = "-" + temp;
    }
    temp.toUpperCase();
    return temp;
}

void FLProgLongMenuItem::setLongValue(int32_t value)
{
    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }
    _value = value;
}

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
        if (_value > (_maxValue - ((int32_t)_step)))
            return;
    }
    if (_value > (2147483647 - ((int32_t)_step)))
    {
        return;
    }
    _value = _value + ((int32_t)_step);
}

void FLProgLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + ((int32_t)_step)))
        {
            return;
        }
    }
    if (_value < (-2147483647 + ((int32_t)_step)))
    {
        return;
    }
    _value = _value - ((int32_t)_step);
}

void FLProgLongMenuItem::pressSymbolButton(char value)
{
    if (value == '-')
    {
        privatePressSymbolButton(value);
        return;
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if ((value == '0') || (value == '1'))
        {
            privatePressSymbolButton(value);
        }
        return;
    }
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if ((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value)))
    {
        privatePressSymbolButton(value);
    }
}

void FLProgLongMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}

//--------------------------------FLProgUnsignedLongMenuItem---------------------------
void FLProgUnsignedLongMenuItem::setUnsignedLongValue(uint32_t value)
{
    if (_hasMin)
    {
        if (value < _minValue)
        {
            return;
        }
    }
    if (_hasMax)
    {
        if (value > _maxValue)
        {
            return;
        }
    }
    _value = value;
}

void FLProgUnsignedLongMenuItem::pressSymbolButton(char value)
{
    if (flprog::isHexNumberChar(value))
    {
        if (_convertType != FLPROG_MENU_HEX_CONVERT_TYPE)
        {
            return;
        }
    }
    if (!((flprog::isNumberChar(value)) || (flprog::isHexNumberChar(value))))
    {
        return;
    }

    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {

        if (!((value == '0') || (value == '1')))
        {
            return;
        }
    }
    privatePressSymbolButton(value);
}

void FLProgUnsignedLongMenuItem::pressBacspaceButton()
{
    privatePressBacspaceButton();
}

String FLProgUnsignedLongMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String(_value, DEC);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String(_value, BIN);
    }
    String temp = String(_value, HEX);
    temp.toUpperCase();
    return temp;
}

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
        if (_value > (_maxValue - ((uint32_t)_step)))
        {
            return;
        }
    }
    if (_value > (4294967295 - ((uint32_t)_step)))
    {
        return;
    }
    _value = _value + ((uint32_t)_step);
}

void FLProgUnsignedLongMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + ((uint32_t)_step)))
        {
            return;
        }
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
    _convertType = 2;
}

String FLProgFloatMenuItem::valueString()
{
    return String(_value, _convertType);
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
    _convertType = FLPROG_MENU_SYMBOL_CONVERT_TYPE;
}

String FLProgCharMenuItem::valueString()
{
    if (_convertType == FLPROG_MENU_DEC_CONVERT_TYPE)
    {
        return String((uint8_t)_value, DEC);
    }
    if (_convertType == FLPROG_MENU_HEX_CONVERT_TYPE)
    {
        return String((uint8_t)_value, HEX);
    }
    if (_convertType == FLPROG_MENU_BIN_CONVERT_TYPE)
    {
        return String((uint8_t)_value, BIN);
    }

    if (_convertType == FLPROG_MENU_SYMBOL_CONVERT_TYPE)
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