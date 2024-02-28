#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogUnsignedLongMenuItem.h"

class FLProgEepromUnsignedLongMenuItem : public FLProgUnsignedLongMenuItem
{
public:
    FLProgEepromUnsignedLongMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setUnsignedLongValue(uint32_t value);
    void initValue();

    virtual void setUnsignedLongMinValue(uint32_t value);

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};
