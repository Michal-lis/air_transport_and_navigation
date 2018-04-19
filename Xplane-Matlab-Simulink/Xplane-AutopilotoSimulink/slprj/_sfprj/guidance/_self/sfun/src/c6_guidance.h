#ifndef __c6_guidance_h__
#define __c6_guidance_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c6_ResolvedFunctionInfo;

typedef struct {
  real_T c6_ALT_CONTROL;
  real_T c6_VPATH_CONTROL;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c6_doneDoubleBufferReInit;
  boolean_T c6_isStable;
  uint8_T c6_is_active_c6_guidance;
  ChartInfoStruct chartInfo;
} SFc6_guidanceInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_guidance_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_guidance_get_check_sum(mxArray *plhs[]);
extern void c6_guidance_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
