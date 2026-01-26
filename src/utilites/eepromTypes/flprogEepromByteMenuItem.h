#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogByteMenuItem.h"

class FLProgEepromByteMenuItem : public FLProgByteMenuItem
{
public:
    FLProgEepromByteMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setByteValue(uint8_t value);
    void initValue();

    virtual void setByteMinValue(uint8_t value);

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};
