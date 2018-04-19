/* Include files */

#include "blascompat32.h"
#include "guidance_sfun.h"
#include "c6_guidance.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "guidance_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_b_VPATH_CONTROL             (0.0)
#define c6_b_ALT_CONTROL               (1.0)

/* Variable Declarations */

/* Variable Definitions */
static const char *c6_debug_family_names[7] = { "VPATH_CONTROL", "ALT_CONTROL",
  "nargin", "nargout", "altitude_error", "control_mode_in", "control_mode" };

/* Function Declarations */
static void initialize_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance);
static void initialize_params_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance);
static void enable_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance);
static void disable_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance);
static void set_sim_state_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance);
static void sf_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c6_guidance
  (SFc6_guidanceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[15]);
static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u);
static real_T c6_emlrt_marshallIn(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_control_mode, const char_T *c6_name);
static uint8_T c6_b_emlrt_marshallIn(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_guidance, const char_T *c6_name);
static void init_dsm_address_info(SFc6_guidanceInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_guidance = 0U;
}

static void initialize_params_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance)
{
  real_T c6_d0;
  real_T c6_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'VPATH_CONTROL' in the parent workspace.\n");
  sf_mex_import("VPATH_CONTROL", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                &c6_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_VPATH_CONTROL = c6_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'ALT_CONTROL' in the parent workspace.\n");
  sf_mex_import("ALT_CONTROL", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                &c6_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_ALT_CONTROL = c6_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_guidance(SFc6_guidanceInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T *c6_control_mode;
  c6_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  c6_hoistedGlobal = *c6_control_mode;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_is_active_c6_guidance;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_control_mode;
  c6_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_control_mode = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "control_mode");
  chartInstance->c6_is_active_c6_guidance = c6_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "is_active_c6_guidance");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_guidance(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance)
{
}

static void sf_c6_guidance(SFc6_guidanceInstanceStruct *chartInstance)
{
  int32_T c6_previousEvent;
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_altitude_error;
  real_T c6_control_mode_in;
  uint32_T c6_debug_family_var_map[7];
  real_T c6_c_VPATH_CONTROL = c6_b_VPATH_CONTROL;
  real_T c6_c_ALT_CONTROL = c6_b_ALT_CONTROL;
  real_T c6_nargin = 4.0;
  real_T c6_nargout = 1.0;
  real_T c6_control_mode;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_y;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_y;
  real_T *c6_b_altitude_error;
  real_T *c6_b_control_mode;
  real_T *c6_b_control_mode_in;
  c6_b_control_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_altitude_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3);
  _SFD_DATA_RANGE_CHECK(*c6_b_altitude_error, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_b_control_mode, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_control_mode_in, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_VPATH_CONTROL, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_ALT_CONTROL, 4U);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3);
  c6_hoistedGlobal = *c6_b_altitude_error;
  c6_b_hoistedGlobal = *c6_b_control_mode_in;
  c6_altitude_error = c6_hoistedGlobal;
  c6_control_mode_in = c6_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_c_VPATH_CONTROL, c6_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c6_c_ALT_CONTROL, c6_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c6_nargin, c6_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c6_nargout, c6_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c6_altitude_error, c6_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c6_control_mode_in, c6_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c6_control_mode, c6_sf_marshall, 6U);
  CV_EML_FCN(0, 0);

  /*  Fija el tipo de control lateral */
  _SFD_EML_CALL(0, 5);
  CV_EML_IF(0, 0, FALSE);
  _SFD_EML_CALL(0, 8);
  c6_control_mode = c6_control_mode_in;
  _SFD_EML_CALL(0, 11);
  c6_x = c6_altitude_error;
  c6_b_x = c6_x;
  c6_y = muDoubleScalarAbs(c6_b_x);
  if (CV_EML_IF(0, 1, c6_y >= 15.0)) {
    _SFD_EML_CALL(0, 12);
    c6_control_mode = c6_b_VPATH_CONTROL;

    /*  control del vpath */
  } else {
    _SFD_EML_CALL(0, 13);
    c6_c_x = c6_altitude_error;
    c6_d_x = c6_c_x;
    c6_b_y = muDoubleScalarAbs(c6_d_x);
    if (CV_EML_IF(0, 2, c6_b_y < 5.0)) {
      _SFD_EML_CALL(0, 14);
      c6_control_mode = c6_b_ALT_CONTROL;

      /*  control de altitud */
    }
  }

  _SFD_EML_CALL(0, -14);
  sf_debug_symbol_scope_pop();
  *c6_b_control_mode = c6_control_mode;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_guidanceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c6_guidance
  (SFc6_guidanceInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc6_guidanceInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray *sf_c6_guidance_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[15];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i0;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c6_i0 = 0; c6_i0 < 15; c6_i0 = c6_i0 + 1) {
    c6_r0 = &c6_info[c6_i0];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i0);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[15])
{
  c6_info[0].context = "";
  c6_info[0].name = "isempty";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[B]isempty";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "abs";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[1].fileLength = 566U;
  c6_info[1].fileTime1 = 1221267132U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[2].name = "nargin";
  c6_info[2].dominantType = "";
  c6_info[2].resolved = "[B]nargin";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[3].name = "gt";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[B]gt";
  c6_info[3].fileLength = 0U;
  c6_info[3].fileTime1 = 0U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[4].name = "isa";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]isa";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[5].name = "ischar";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[B]ischar";
  c6_info[5].fileLength = 0U;
  c6_info[5].fileTime1 = 0U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[6].name = "islogical";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[B]islogical";
  c6_info[6].fileLength = 0U;
  c6_info[6].fileTime1 = 0U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[7].name = "size";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]size";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[8].name = "class";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved = "[B]class";
  c6_info[8].fileLength = 0U;
  c6_info[8].fileTime1 = 0U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[9].name = "zeros";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[B]zeros";
  c6_info[9].fileLength = 0U;
  c6_info[9].fileTime1 = 0U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[10].name = "eml_scalar_abs";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[10].fileLength = 461U;
  c6_info[10].fileTime1 = 1203447960U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[11].name = "isinteger";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[B]isinteger";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[12].name = "isreal";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved = "[B]isreal";
  c6_info[12].fileLength = 0U;
  c6_info[12].fileTime1 = 0U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context = "";
  c6_info[13].name = "ge";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved = "[B]ge";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context = "";
  c6_info[14].name = "lt";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[B]lt";
  c6_info[14].fileLength = 0U;
  c6_info[14].fileTime1 = 0U;
  c6_info[14].fileTime2 = 0U;
}

static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  boolean_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc6_guidanceInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((boolean_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static real_T c6_emlrt_marshallIn(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_control_mode, const char_T *c6_name)
{
  real_T c6_y;
  real_T c6_d2;
  sf_mex_import(c6_name, sf_mex_dup(c6_control_mode), &c6_d2, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d2;
  sf_mex_destroy(&c6_control_mode);
  return c6_y;
}

static uint8_T c6_b_emlrt_marshallIn(SFc6_guidanceInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_guidance, const
  char_T *c6_name)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_name, sf_mex_dup(c6_b_is_active_c6_guidance), &c6_u0, 1, 3,
                0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_b_is_active_c6_guidance);
  return c6_y;
}

static void init_dsm_address_info(SFc6_guidanceInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_guidance_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(517555918U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1362591140U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(615857500U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2146510604U);
}

mxArray *sf_c6_guidance_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3226745616U);
    pr[1] = (double)(339125951U);
    pr[2] = (double)(3980296005U);
    pr[3] = (double)(4088270319U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c6_guidance(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"control_mode\",},{M[8],M[0],T\"is_active_c6_guidance\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_guidance_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_guidanceInstanceStruct *chartInstance;
    chartInstance = (SFc6_guidanceInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_guidanceMachineNumber_,
          6,
          1,
          1,
          5,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_guidanceMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_guidanceMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_guidanceMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"altitude_error");
          _SFD_SET_DATA_PROPS(1,2,0,1,"control_mode");
          _SFD_SET_DATA_PROPS(2,1,1,0,"control_mode_in");
          _SFD_SET_DATA_PROPS(3,10,0,0,"VPATH_CONTROL");
          _SFD_SET_DATA_PROPS(4,10,0,0,"ALT_CONTROL");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,412);
        _SFD_CV_INIT_EML_IF(0,0,130,157,192,236);
        _SFD_CV_INIT_EML_IF(0,1,238,268,323,355);
        _SFD_CV_INIT_EML_IF(0,2,323,355,-1,355);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshall);

        {
          real_T *c6_altitude_error;
          real_T *c6_control_mode;
          real_T *c6_control_mode_in;
          c6_control_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c6_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_altitude_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_altitude_error);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_control_mode);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_control_mode_in);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c6_VPATH_CONTROL);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c6_ALT_CONTROL);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_guidanceMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_guidance(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_guidanceInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
  initialize_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_guidance(void *chartInstanceVar)
{
  enable_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_guidance(void *chartInstanceVar)
{
  disable_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_guidance(void *chartInstanceVar)
{
  sf_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c6_guidance(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_guidance((SFc6_guidanceInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c6_guidance();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c6_guidance(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_guidance();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_guidance((SFc6_guidanceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c6_guidance(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_guidance(S);
}

static void sf_opaque_set_sim_state_c6_guidance(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_guidance(S, st);
}

static void sf_opaque_terminate_c6_guidance(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_guidanceInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_guidance((SFc6_guidanceInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c6_guidance((SFc6_guidanceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_guidance(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_guidance((SFc6_guidanceInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_guidance(SimStruct *S)
{
  /* Actual parameters from chart:
     ALT_CONTROL VPATH_CONTROL
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for ALT_CONTROL*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for VPATH_CONTROL*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"guidance","guidance",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"guidance","guidance",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"guidance","guidance",6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"guidance","guidance",6,2);
      sf_mark_chart_reusable_outputs(S,"guidance","guidance",6,1);
    }

    sf_set_rtw_dwork_info(S,"guidance","guidance",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3528377019U));
  ssSetChecksum1(S,(1577940015U));
  ssSetChecksum2(S,(1183033027U));
  ssSetChecksum3(S,(3763784571U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_guidance(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "guidance", "guidance",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_guidance(SimStruct *S)
{
  SFc6_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc6_guidanceInstanceStruct *)malloc(sizeof
    (SFc6_guidanceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_guidanceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_guidance;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_guidance;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_guidance;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_guidance;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_guidance;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_guidance;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_guidance;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_guidance;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_guidance;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_guidance;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_guidance;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c6_guidance_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_guidance(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_guidance(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_guidance(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_guidance_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
