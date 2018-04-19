#ifndef __c5_guidance_h__
#define __c5_guidance_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  real_T c5_HOLD_HEADING;
  real_T c5_heading_value;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_doneDoubleBufferReInit;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_guidance;
  ChartInfoStruct chartInfo;
} SFc5_guidanceInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_guidance_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_guidance_get_check_sum(mxArray *plhs[]);
extern void c5_guidance_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
