#include "flprogGroupMenuItem.h"

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
  FLProgAbstractMenuItem *temp_item;
  if (current == 0)
  {
    return 0;
  }
  for (int16_t i = 0; i < _itemsCounts; i++)
  {
    temp_item = _items[i];
    if (temp_item == current)
    {
      return this;
    }
    if (temp_item->isGroup())
    {
      temp = temp_item->getCurrentMenuItemParent(current);
      if (temp != 0)
      {
        return temp;
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
