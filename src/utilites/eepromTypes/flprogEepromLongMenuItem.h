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

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};
