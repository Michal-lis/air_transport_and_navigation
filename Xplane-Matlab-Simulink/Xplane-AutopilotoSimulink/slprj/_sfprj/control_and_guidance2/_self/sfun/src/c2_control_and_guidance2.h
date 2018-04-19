#ifndef __c2_control_and_guidance2_h__
#define __c2_control_and_guidance2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c2_ResolvedFunctionInfo;

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
} c2_sqlDPqpC0uriFz1tcs1upYG;

#else

typedef struct sqlDPqpC0uriFz1tcs1upYG c2_sqlDPqpC0uriFz1tcs1upYG;

#endif

typedef struct {
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_control_and_guidance2;
  c2_sqlDPqpC0uriFz1tcs1upYG c2_wp[6];
  real_T c2_NUM_WP;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  const mxArray *c2_h;
  boolean_T c2_h_not_empty;
  real_T c2_N;
  boolean_T c2_N_not_empty;
} SFc2_control_and_guidance2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_control_and_guidance2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_control_and_guidance2_get_check_sum(mxArray *plhs[]);
extern void c2_control_and_guidance2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
