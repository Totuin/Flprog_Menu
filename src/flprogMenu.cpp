#include "flprogMenu.h"

FLProgMenu::FLProgMenu(int16_t itemsCounts)
{
    _items = new FLProgAbstractMenuItem *[itemsCounts];
    _itemsCounts = itemsCounts;
}

void FLProgMenu::setItem(int16_t index, FLProgAbstractMenuItem *item)
{
    if (index >= _itemsCounts)
    {
        return;
    }
    _items[index] = item;
}

FLProgAbstractMenuItem *FLProgMenu::getCurrentMenuIntem()
{
    if (_currentMenuItem != 0)
    {
        return _currentMenuItem;
    }

    if (_itemsCounts == 0)
    {
        return 0;
    }
    return _items[0];
}

FLProgAbstractMenuItem *FLProgMenu::getCurrentMenuItemParent()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
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
                return 0;
            }
        }
    }
    return 0;
}

void FLProgMenu::menuItemUp()
{
    if (_itemsCounts <= 0)
    {
        return;
    }
    FLProgAbstractMenuItem *parent = getCurrentMenuItemParent();
    if (parent != 0)
    {
        _currentMenuItem = parent->menuItemUp(getCurrentMenuIntem(), _isRingControl);
        return;
    }
    _currentMenuItem = previous();
}
void FLProgMenu::menuItemDown()
{
    if (_itemsCounts == 0)
    {
        return;
    }
    FLProgAbstractMenuItem *parent = getCurrentMenuItemParent();
    if (parent != 0)
    {
        _currentMenuItem = parent->menuItemDown(getCurrentMenuIntem(), _isRingControl);
        return;
    }
    _currentMenuItem = next();
}

int16_t FLProgMenu::indexForCurrentItem()
{
    if (_itemsCounts == 0)
    {
        return -1;
    }
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    for (int16_t i = 0; i < _itemsCounts; i++)
    {
        if (current == _items[i])
        {
            return i;
        }
    }
    return -1;
}

FLProgAbstractMenuItem *FLProgMenu::next()
{
    int16_t index = indexForCurrentItem();
    if (index < 0)
    {
        return getCurrentMenuIntem();
    }
    if (index == (_itemsCounts - 1))
    {
        if (_isRingControl)
        {
            return _items[0];
        }
        else
        {
            return getCurrentMenuIntem();
        }
    }
    return _items[index + 1];
}
FLProgAbstractMenuItem *FLProgMenu::previous()
{
    int16_t index = indexForCurrentItem();
    if (index < 0)
    {
        return getCurrentMenuIntem();
    }
    if (index == 0)
    {
        if (_isRingControl)
        {
            return _items[(_itemsCounts - 1)];
        }
        else
        {
            return getCurrentMenuIntem();
        }
    }
    return _items[index - 1];
}

void FLProgMenu::menuValueUp()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }

    current->valueUp();
}

void FLProgMenu::menuValueDown()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->valueDown();
}

void FLProgMenu::setValue(bool value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(uint8_t value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(int16_t value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(int32_t value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(uint32_t value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(float value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(char value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

void FLProgMenu::setValue(String value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    current->setValue(value);
}

String FLProgMenu::nameString()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return "";
    }
    return current->name();
}
String FLProgMenu::valueString()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return "";
    }
    return current->valueString();
}
String FLProgMenu::aditionalString(uint8_t index)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return "";
    }
    return current->aditionalString(index);
}

void FLProgMenu::reset()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    _currentMenuItem = _items[0];
}

void FLProgMenu::pressSymbolButton(char value)
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    String temp = current->valueString();
    if (value == '-')
    {
        if (temp.length() == 0)
        {
            return;
        }
        if (temp[0] == '-')
        {
            current->setValue(temp.substring(1));
            return;
        }
        current->setValue((String('-') + temp));
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
        current->setValue(temp);
        return;
    }
    temp.concat(value);
    current->setValue(temp);
}

void FLProgMenu::menuGroupEnter()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (!(current->isGroup()))
    {
        return;
    }
    current = current->firstItem();
    if (current == 0)
    {
        return;
    }
    _currentMenuItem = current;
}
void FLProgMenu::menuGroupExit()
{

    if (_itemsCounts <= 0)
    {
        return;
    }
    FLProgAbstractMenuItem *parent = getCurrentMenuItemParent();
    if (parent == 0)
    {
        return;
    }
    _currentMenuItem = parent;
}

void FLProgMenu::pressBacspaceButton()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    if (current->isGroup())
    {
        return;
    }
    String temp = current->valueString();

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
        temp = temp.substring(0, (temp.length() - 2));
    }
    current->setValue(temp);
}