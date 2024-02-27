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
        if (_value > _maxValue)
        {
            return;
        }
    }
    _value = _value + _step;
}

void FLProgFloatMenuItem::valueDown()
{
    if (_hasMin)
    {
        if (_value < _minValue)
        {
            return;
        }
    }

    _value = _value - _step;
}