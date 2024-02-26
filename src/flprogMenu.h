#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "utilites/flprogMenuItem.h"

#define FLPROG_MENU_NO_VALUE_CONTROLLER 0
#define FLPROG_MENU_SINGLE_IMPULSE_VALUE_CONTROLLER 1
#define FLPROG_MENU_ACCELERATION_VALUE_CONTROLLER 2
#define FLPROG_MENU_DOUBLE_ACCELERATION_VALUE_CONTROLLER 3

class FLProgAbstractValueController
{
public:
    virtual bool valueUpButtonStatus(bool status) = 0;
    virtual bool valueDownButtonStatus(bool status) = 0;
    virtual void reset() = 0;

    virtual void setAccelerationTime(uint32_t time) { (void)time; };
    virtual void setAccelerationPeriog(uint32_t time) { (void)time; };
    virtual void setDoubleAccelerationTime(uint32_t time) { (void)time; };
    virtual void setDoubleAccelerationPeriog(uint32_t time) { (void)time; };
};

class FLProgSingleImpulseValueController : public FLProgAbstractValueController
{
public:
    FLProgSingleImpulseValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void reset(){};

protected:
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
};

class FLProgAccelerationValueController : public FLProgAbstractValueController
{
public:
    FLProgAccelerationValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void setAccelerationTime(uint32_t time) { startAccelerationTime = time; };
    virtual void setAccelerationPeriog(uint32_t time) { updatePeriod = time; };
    virtual void reset();

protected:
    bool checkStatus();
    uint32_t startPressTime;
    uint32_t lastEventTime;
    uint32_t startAccelerationTime;
    uint32_t updatePeriod;
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
    bool isCanEvents = false;
};

class FLProgDoubleAccelerationValueController : public FLProgAbstractValueController
{
public:
    FLProgDoubleAccelerationValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void setAccelerationTime(uint32_t time) { startAccelerationTime = time; };
    virtual void setAccelerationPeriog(uint32_t time) { updatePeriod = time; };
    virtual void setDoubleAccelerationTime(uint32_t time) { doubleStartAccelerationTime = time; };
    virtual void setDoubleAccelerationPeriog(uint32_t time) { doubleUpdatePeriod = time; };
    virtual void reset();

protected:
    bool checkStatus();
    uint32_t startPressTime;
    uint32_t lastEventTime;
    uint32_t startAccelerationTime;
    uint32_t doubleStartAccelerationTime;
    uint32_t updatePeriod;
    uint32_t doubleUpdatePeriod;
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
    bool isCanEvents = false;
    bool isCanDoubleEvents = false;
};

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
