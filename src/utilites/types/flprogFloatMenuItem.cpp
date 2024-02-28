#include "flprogFloatMenuItem.h"

FLProgFloatMenuItem::FLProgFloatMenuItem(String name, uint8_t aditionalsStringsCount)
{
    initItem(name, aditionalsStringsCount);
    _convertType = 2;
}

void FLProgFloatMenuItem::setValue(String value)
{
    setFloatValue(value.toFloat());
}

void FLProgFloatMenuItem::setFloatValue(float value)
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

String FLProgFloatMenuItem::valueString()
{
    String temp = String(_value, _convertType);
    uint8_t index = temp.indexOf('.');
    String firstPart = temp.substring(0, index);
    String secondtPart = temp.substring(index + 1);
    String result;
    if ((secondtPart.toInt()) == 0)
    {
        if (!_isNeedDot)
        {
            result = firstPart;
        }
        else
        {
            result = firstPart + '.';
        }
    }
    else
    {
        result = firstPart + '.' + removeLastZeroSymbol(secondtPart);
    }
    for (uint8_t i = 0; i < _zerroCount; i++)
    {
        result = result + '0';
    }
    return result;
}

String FLProgFloatMenuItem::removeLastZeroSymbol(String value)
{
    if (value.length() == 0)
    {
        return value;
    }
    if (value.length() == 1)
    {
        if (value.equals("0"))
        {
            return "";
        }
        else
        {
            return value;
        }
    }
    if (value.charAt(value.length() - 1) == '0')
    {
        return removeLastZeroSymbol(value.substring(0, (value.length() - 1)));
    }
    return value;
}

void FLProgFloatMenuItem::setFloatMaxValue(float value)
{
    _maxValue = value;
    _hasMax = true;
}
void FLProgFloatMenuItem::setFloatMinValue(float value)
{
    _minValue = value;
    if (!(_minValue < 0))
    {
        setFloatValue(_minValue);
        return;
    }
    _hasMin = true;
}

void FLProgFloatMenuItem::valueUp()
{
    _zerroCount = 0;
    if (_hasMax)
    {
        if (_value > (_maxValue - _step))
        {
            return;
        }
    }
    resetInput();
    setFloatValue(_value + _step);
}

void FLProgFloatMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < (_minValue + _step))
        {
            return;
        }
    }
    resetInput();
    setFloatValue(_value - _step);
}

void FLProgFloatMenuItem::pressBacspaceButton()
{
    String temp = valueString();
    if ((temp.charAt(temp.length() - 1)) == '.')
    {
        _isNeedDot = false;
        _zerroCount = 0;
        return;
    }
    if ((temp.charAt(temp.length() - 1)) == '0')
    {
        if (_isNeedDot)
        {
            if (_zerroCount > 0)
            {
                _zerroCount--;
                return;
            }
        }
    }
    privatePressBacspaceButton();
}

void FLProgFloatMenuItem::pressSymbolButton(char value)
{
    if (value == '-')
    {
        privatePressSymbolButton(value);
        return;
    }
    if (value == '.')
    {
        _isNeedDot = true;
        return;
    }
    if (value == ',')
    {
        _isNeedDot = true;
        return;
    }
    if (!(flprog::isNumberChar(value)))
    {
        return;
    }
    if (!_isNeedDot)
    {
        privatePressSymbolButton(value);
        return;
    }
    String temp = valueString();
    uint8_t index = temp.indexOf('.');
    String secondtPart = temp.substring(index + 1);
    if (secondtPart.length() >= _convertType)
    {
        return;
    }
    if (value == '0')
    {
        _zerroCount++;
        return;
    }

    temp.concat(value);
    _zerroCount = 0;
    setValue(temp);
}

void FLProgFloatMenuItem::resetInput()
{
    _zerroCount = 0;
    _isNeedDot = false;
}

void FLProgFloatMenuItem::pressClearButton()
{
    if (_hasMin)
    {
        if (!(_minValue < 0))
        {
            setFloatValue(_minValue);
            return;
        }
    }
    setFloatValue(0);
}