#include "flprogMenu.h"

FLProgMenu::FLProgMenu(String name, int16_t itemsCounts, uint8_t valueControllerType)
{
    _items = new FLProgAbstractMenuItem *[itemsCounts];
    _itemsCounts = itemsCounts;
    _name = name;
    if (valueControllerType == FLPROG_MENU_SINGLE_IMPULSE_VALUE_CONTROLLER)
    {
        _valueController = new FLProgSingleImpulseValueController;
    }
    if (valueControllerType == FLPROG_MENU_ACCELERATION_VALUE_CONTROLLER)
    {
        _valueController = new FLProgAccelerationValueController;
    }

    if (valueControllerType == FLPROG_MENU_DOUBLE_ACCELERATION_VALUE_CONTROLLER)
    {
        _valueController = new FLProgDoubleAccelerationValueController;
    }
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
    if (_currentMenuItem != 0)
    {
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
        resetController();
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
    if (_currentMenuItem != 0)
    {
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
        resetController();
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

void FLProgMenu::resetController()
{
    if (_valueController == 0)
    {
        return;
    }
    _valueController->reset();
}

void FLProgMenu::reset()
{
    resetController();
    if (_itemsCounts <= 0)
    {
        return;
    }
    if (_currentMenuItem != 0)
    {
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
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
    current->pressSymbolButton(value);
}

void FLProgMenu::menuGroupEnter()
{

    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    resetController();
    _currentMenuItem->resetInput();
    _currentMenuItem->saveBuffer();
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
    if (_currentMenuItem != 0)
    {
        resetController();
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
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
    current->pressBacspaceButton();
}

void FLProgMenu::pressClearButton()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return;
    }
    current->pressClearButton();
}

bool FLProgMenu::currentMenuIsGroup()
{
    FLProgAbstractMenuItem *current = getCurrentMenuIntem();
    if (current == 0)
    {
        return false;
    }
    return current->isGroup();
}

bool FLProgMenu::isActiveMainMenu()
{
    if (_itemsCounts <= 0)
    {
        return false;
    }
    FLProgAbstractMenuItem *parent = getCurrentMenuItemParent();
    if (parent == 0)
    {
        return true;
    }
    return false;
}

String FLProgMenu::nameParentMenu()
{
    if (_itemsCounts <= 0)
    {
        return "";
    }
    FLProgAbstractMenuItem *parent = getCurrentMenuItemParent();
    if (parent == 0)
    {
        return _name;
    }
    return parent->name();
}

void FLProgMenu::setCurrentItem(FLProgAbstractMenuItem *item)
{
    resetController();
    if (_currentMenuItem != 0)
    {
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
    }
    _currentMenuItem = item;
}

void FLProgMenu::valueUpButtonStatus(bool status)
{
    if (_valueController == 0)
    {
        return;
    }
    if (_valueController->valueUpButtonStatus(status))
    {
        menuValueUp();
    }
}
void FLProgMenu::valueDownButtonStatus(bool status)
{
    if (_valueController == 0)
    {
        return;
    }
    if (_valueController->valueDownButtonStatus(status))
    {
        menuValueDown();
    }
}

void FLProgMenu::setAccelerationTime(uint32_t time)
{
    if (_valueController == 0)
    {
        return;
    }
    _valueController->setAccelerationTime(time);
}

void FLProgMenu::setAccelerationPeriog(uint32_t time)
{
    if (_valueController == 0)
    {
        return;
    }
    _valueController->setAccelerationPeriog(time);
}

void FLProgMenu::setDoubleAccelerationTime(uint32_t time)
{
    if (_valueController == 0)
    {
        return;
    }
    _valueController->setDoubleAccelerationTime(time);
}

void FLProgMenu::setDoubleAccelerationPeriog(uint32_t time)
{
    if (_valueController == 0)
    {
        return;
    }
    _valueController->setDoubleAccelerationPeriog(time);
}

void FLProgMenu::saveBuffer()
{
    if (_currentMenuItem != 0)
    {
        _currentMenuItem->resetInput();
        _currentMenuItem->saveBuffer();
    }
}