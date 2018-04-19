#ifndef __c2_udpReceive_example_h__
#define __c2_udpReceive_example_h__

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

typedef struct {
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_udpReceive_example;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c2_airspeed_ant;
  boolean_T c2_airspeed_ant_not_empty;
  real_T c2_pitch_rate_ant;
  boolean_T c2_pitch_rate_ant_not_empty;
  real_T c2_roll_rate_ant;
  boolean_T c2_roll_rate_ant_not_empty;
  real_T c2_yaw_rate_ant;
  boolean_T c2_yaw_rate_ant_not_empty;
  real_T c2_pitch_ant;
  boolean_T c2_pitch_ant_not_empty;
  real_T c2_roll_ant;
  boolean_T c2_roll_ant_not_empty;
  real_T c2_heading_ant;
  boolean_T c2_heading_ant_not_empty;
  real_T c2_alpha_ant;
  boolean_T c2_alpha_ant_not_empty;
  real_T c2_beta_ant;
  boolean_T c2_beta_ant_not_empty;
  real_T c2_vpath_ant;
  boolean_T c2_vpath_ant_not_empty;
  real_T c2_lat_ant;
  boolean_T c2_lat_ant_not_empty;
  real_T c2_lon_ant;
  boolean_T c2_lon_ant_not_empty;
  real_T c2_alt_ant;
  boolean_T c2_alt_ant_not_empty;
} SFc2_udpReceive_exampleInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_udpReceive_example_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_udpReceive_example_get_check_sum(mxArray *plhs[]);
extern void c2_udpReceive_example_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
