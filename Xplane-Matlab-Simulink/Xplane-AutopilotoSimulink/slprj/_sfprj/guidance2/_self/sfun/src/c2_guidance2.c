/* Include files */

#include "blascompat32.h"
#include "guidance2_sfun.h"
#include "c2_guidance2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "guidance2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_b_ROLL_CONTROL              (0.0)
#define c2_b_HEADING_CONTROL           (1.0)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[7] = { "ROLL_CONTROL",
  "HEADING_CONTROL", "nargin", "nargout", "heading_error", "control_mode_in",
  "control_mode" };

/* Function Declarations */
static void initialize_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance);
static void initialize_params_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance);
static void enable_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance);
static void disable_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance);
static void sf_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance);
static void initSimStructsc2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_control_mode, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_guidance2, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_guidance2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_guidance2 = 0U;
}

static void initialize_params_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'ROLL_CONTROL' in the parent workspace.\n");
  sf_mex_import_named("ROLL_CONTROL", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_ROLL_CONTROL = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'HEADING_CONTROL' in the parent workspace.\n");
  sf_mex_import_named("HEADING_CONTROL", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_HEADING_CONTROL = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_control_mode;
  c2_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_control_mode;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_guidance2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_control_mode;
  c2_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_control_mode = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "control_mode");
  chartInstance->c2_is_active_c2_guidance2 = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_guidance2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_guidance2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance)
{
}

static void sf_c2_guidance2(SFc2_guidance2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_heading_error;
  real_T c2_control_mode_in;
  uint32_T c2_debug_family_var_map[7];
  real_T c2_c_ROLL_CONTROL;
  real_T c2_c_HEADING_CONTROL;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 1.0;
  real_T c2_control_mode;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T *c2_b_heading_error;
  real_T *c2_b_control_mode;
  real_T *c2_b_control_mode_in;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c2_b_control_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_heading_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_heading_error, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_control_mode, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_control_mode_in, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_ROLL_CONTROL, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_HEADING_CONTROL, 4U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_heading_error;
  c2_b_hoistedGlobal = *c2_b_control_mode_in;
  c2_heading_error = c2_hoistedGlobal;
  c2_control_mode_in = c2_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_c_ROLL_CONTROL, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_c_HEADING_CONTROL, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_heading_error, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_control_mode_in, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_control_mode, 6U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  c2_c_HEADING_CONTROL = c2_b_HEADING_CONTROL;
  c2_c_ROLL_CONTROL = c2_b_ROLL_CONTROL;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  CV_EML_IF(0, 1, 0, FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_control_mode = c2_control_mode_in;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_x = c2_heading_error;
  c2_b_x = c2_x;
  c2_y = muDoubleScalarAbs(c2_b_x);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_y >= 20.0)) {
    if (CV_EML_COND(0, 1, 1, c2_control_mode_in != c2_b_ROLL_CONTROL)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
      c2_control_mode = c2_b_ROLL_CONTROL;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    c2_c_x = c2_heading_error;
    c2_d_x = c2_c_x;
    c2_b_y = muDoubleScalarAbs(c2_d_x);
    guard2 = FALSE;
    if (CV_EML_COND(0, 1, 2, c2_b_y < 2.0)) {
      if (CV_EML_COND(0, 1, 3, c2_control_mode_in == c2_b_ROLL_CONTROL)) {
        CV_EML_MCDC(0, 1, 1, TRUE);
        CV_EML_IF(0, 1, 2, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
        c2_control_mode = c2_b_HEADING_CONTROL;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 2, FALSE);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  *c2_b_control_mode = c2_control_mode;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_guidance2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_guidance2(SFc2_guidance2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_control_mode, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_control_mode),
    &c2_thisId);
  sf_mex_destroy(&c2_control_mode);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_control_mode;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_guidance2InstanceStruct *)chartInstanceVoid;
  c2_control_mode = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_control_mode),
    &c2_thisId);
  sf_mex_destroy(&c2_control_mode);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_guidance2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[2];
  c2_ResolvedFunctionInfo (*c2_b_info)[2];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[2])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "abs";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[0].fileTimeLo = 1286818694U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[1].name = "eml_scalar_abs";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c2_b_info)[1].fileTimeLo = 1286818712U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_guidance2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_guidance2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_guidance2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_guidance2);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_guidance2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_guidance2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_guidance2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1500660429U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(962637708U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2398873762U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1393547878U);
}

mxArray *sf_c2_guidance2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QTyQb4pjTA4z6GBuDwScuE");
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

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_guidance2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"control_mode\",},{M[8],M[0],T\"is_active_c2_guidance2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_guidance2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_guidance2InstanceStruct *chartInstance;
    chartInstance = (SFc2_guidance2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_guidance2MachineNumber_,
          2,
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
          init_script_number_translation(_guidance2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_guidance2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_guidance2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"heading_error");
          _SFD_SET_DATA_PROPS(1,2,0,1,"control_mode");
          _SFD_SET_DATA_PROPS(2,1,1,0,"control_mode_in");
          _SFD_SET_DATA_PROPS(3,10,0,0,"ROLL_CONTROL");
          _SFD_SET_DATA_PROPS(4,10,0,0,"HEADING_CONTROL");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,490);
        _SFD_CV_INIT_EML_IF(0,1,0,137,164,198,242);
        _SFD_CV_INIT_EML_IF(0,1,1,244,308,361,427);
        _SFD_CV_INIT_EML_IF(0,1,2,361,427,-1,427);

        {
          static int condStart[] = { 247, 277 };

          static int condEnd[] = { 271, 308 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,247,308,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 368, 396 };

          static int condEnd[] = { 390, 427 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,368,427,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_heading_error;
          real_T *c2_control_mode;
          real_T *c2_control_mode_in;
          c2_control_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c2_control_mode = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_heading_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_heading_error);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_control_mode);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_control_mode_in);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_ROLL_CONTROL);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c2_HEADING_CONTROL);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_guidance2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "xdFo0XvfZzFGU6gMrhjSP";
}

static void sf_opaque_initialize_c2_guidance2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_guidance2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_guidance2((SFc2_guidance2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_guidance2(void *chartInstanceVar)
{
  enable_c2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_guidance2(void *chartInstanceVar)
{
  disable_c2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_guidance2(void *chartInstanceVar)
{
  sf_c2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_guidance2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_guidance2((SFc2_guidance2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_guidance2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_guidance2(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_guidance2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_guidance2((SFc2_guidance2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_guidance2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_guidance2(S);
}

static void sf_opaque_set_sim_state_c2_guidance2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_guidance2(S, st);
}

static void sf_opaque_terminate_c2_guidance2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_guidance2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_guidance2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_guidance2((SFc2_guidance2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_guidance2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_guidance2((SFc2_guidance2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_guidance2(SimStruct *S)
{
  /* Actual parameters from chart:
     HEADING_CONTROL ROLL_CONTROL
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for HEADING_CONTROL*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for ROLL_CONTROL*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_guidance2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3712881170U));
  ssSetChecksum1(S,(2726642923U));
  ssSetChecksum2(S,(3354416999U));
  ssSetChecksum3(S,(896935637U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_guidance2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_guidance2(SimStruct *S)
{
  SFc2_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_guidance2InstanceStruct *)malloc(sizeof
    (SFc2_guidance2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_guidance2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_guidance2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_guidance2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_guidance2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_guidance2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_guidance2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_guidance2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_guidance2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_guidance2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_guidance2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_guidance2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_guidance2;
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

void c2_guidance2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_guidance2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_guidance2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_guidance2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_guidance2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
