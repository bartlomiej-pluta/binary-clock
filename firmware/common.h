#ifndef __COMMON_H__
#define __COMMON_H__

#define __PROJ_NAME__ "Binary Clock"
#define __PROJ_AUTHOR__ "Bartlomiej Pluta"
#define __PROJ_DATE__ "2020"
#define __PROJ_REV__ "rev:1.0"

#define R_PORT(P) __R_PORT(P)
#define R_DDR(P) __R_DDR(P)
#define R_PIN(P) __R_PIN(P)

#define __R_PORT(P) (PORT ## P)
#define __R_DDR(P) (DDR ## P)
#define __R_PIN(P) (PIN ## P)

#endif