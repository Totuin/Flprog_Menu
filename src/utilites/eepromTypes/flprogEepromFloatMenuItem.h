#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogFloatMenuItem.h"

class FLProgEepromFloatMenuItem : public FLProgFloatMenuItem
{
public:
    FLProgEepromFloatMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setFloatValue(float value);
    void initValue();

    virtual void setFloatMinValue(float value);

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};
