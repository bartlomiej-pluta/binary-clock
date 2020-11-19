#ifndef __NIGHTM_H__
#define __NIGHTM_H__

#include "config.h"
#include "time.h"

void nightm_config(struct NIGHTM_CFG* cfg);
void nightm_handle(struct TIME_HMS* curr_time);

#endif