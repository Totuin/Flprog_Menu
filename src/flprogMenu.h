#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "utilites/controllers/flprogSingleImpulseValueController.h"
#include "utilites/controllers/flprogAccelerationValueController.h"
#include "utilites/controllers/flprogDoubleAccelerationValueController.h"
#include "utilites/basic/flprogGroupMenuItem.h"
#include "utilites/types/flprogBooleanMenuItem.h"
#include "utilites/types/flprogByteMenuItem.h"
#include "utilites/types/flprogIntegerMenuItem.h"
#include "utilites/types/flprogLongMenuItem.h"
#include "utilites/types/flprogUnsignedLongMenuItem.h"
#include "utilites/types/flprogFloatMenuItem.h"
#include "utilites/types/flprogCharMenuItem.h"

class FLProgMenu
{
public:
    FLProgMenu(String name, int16_t itemsCounts, uint8_t valueControllerType = FLPROG_MENU_NO_VALUE_CONTROLLER);

    void setItem(int16_t index, FLProgAbstractMenuItem *item);
    void isRingControl(bool value) { _isRingControl = value; };
    void setAccelerationTime(uint32_t time);
    void setAccelerationPeriog(uint32_t time);
    void setDoubleAccelerationTime(uint32_t time);
    void setDoubleAccelerationPeriog(uint32_t time);

    void menuItemUp();
    void menuItemDown();

    void menuValueUp();
    void menuValueDown();

    void menuGroupEnter();
    void menuGroupExit();

    void valueUpButtonStatus(bool status);
    void valueDownButtonStatus(bool status);

    void pressSymbolButton(char value);
    void pressBacspaceButton();
    void pressClearButton();

    void reset();
    void resetController();
    void setValue(String value);

    bool currentMenuIsGroup();
    bool isActiveMainMenu();
    String nameParentMenu();

    FLProgAbstractMenuItem *getCurrentMenuIntem();

    String nameString();
    String valueString();
    String aditionalString(uint8_t index);
    void setCurrentItem(FLProgAbstractMenuItem *item);

protected:
    FLProgAbstractMenuItem *getCurrentMenuItemParent();
    FLProgAbstractMenuItem *next();
    FLProgAbstractMenuItem *previous();
    int16_t indexForCurrentItem();

    int16_t _itemsCounts = 0;
    FLProgAbstractMenuItem **_items = 0;
    FLProgAbstractMenuItem *_currentMenuItem = 0;
    bool _isRingControl = false;

    FLProgAbstractValueController *_valueController = 0;
    String _name = "";
};
