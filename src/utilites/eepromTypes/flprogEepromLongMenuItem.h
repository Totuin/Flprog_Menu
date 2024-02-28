#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogLongMenuItem.h"

class FLProgEepromLongMenuItem : public FLProgLongMenuItem
{
public:
    FLProgEepromLongMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setLongValue(int32_t value);
    void initValue();

    virtual void setLongMinValue(int32_t value);

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};
