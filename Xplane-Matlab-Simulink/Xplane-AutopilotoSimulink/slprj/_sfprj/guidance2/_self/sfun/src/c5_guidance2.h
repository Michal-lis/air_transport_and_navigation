#ifndef __c5_guidance2_h__
#define __c5_guidance2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_guidance2;
  real_T c5_HOLD_HEADING;
  real_T c5_heading_value;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc5_guidance2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_guidance2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_guidance2_get_check_sum(mxArray *plhs[]);
extern void c5_guidance2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
