#ifndef __NIGHTM_H__
#define __NIGHTM_H__

#include "config.h"
#include "rtc.h"

void nightm_config(struct NIGHTM_CFG* cfg);
void nightm_handle(struct RTC_DATA* rtc);

#endif