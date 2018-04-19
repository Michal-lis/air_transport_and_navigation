#ifndef __c3_guidance2_h__
#define __c3_guidance2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_sqlDPqpC0uriFz1tcs1upYG
#define struct_sqlDPqpC0uriFz1tcs1upYG

typedef struct sqlDPqpC0uriFz1tcs1upYG
{
  char_T name;
  real_T _long;
  real_T lat;
  real_T alt;
  real_T airspeed;
  real_T fase;
} c3_sqlDPqpC0uriFz1tcs1upYG;

#else

typedef struct sqlDPqpC0uriFz1tcs1upYG c3_sqlDPqpC0uriFz1tcs1upYG;

#endif

typedef struct {
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_guidance2;
  c3_sqlDPqpC0uriFz1tcs1upYG c3_wp[6];
  real_T c3_HOLD_ALT;
  real_T c3_HOLD_SPEED;
  real_T c3_alt_value;
  real_T c3_speed_value;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc3_guidance2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_guidance2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_guidance2_get_check_sum(mxArray *plhs[]);
extern void c3_guidance2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
