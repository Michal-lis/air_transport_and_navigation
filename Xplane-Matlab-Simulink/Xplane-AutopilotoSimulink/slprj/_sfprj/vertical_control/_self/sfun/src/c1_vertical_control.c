/* Include files */

#include "blascompat32.h"
#include "vertical_control_sfun.h"
#include "c1_vertical_control.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "vertical_control_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_b_elevators_min             (0.49000000000000005)
#define c1_b_elevators_max             (0.42000000000000004)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[6] = { "elevators_min",
  "elevators_max", "nargin", "nargout", "elevators", "elevators_ratio" };

/* Function Declarations */
static void initialize_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance);
static void initialize_params_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance);
static void enable_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance);
static void disable_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance);
static void set_sim_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance);
static void sf_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance);
static void initSimStructsc1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_elevators_ratio, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_eml_scalar_eg(SFc1_vertical_controlInstanceStruct *chartInstance);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_vertical_control, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_vertical_controlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_vertical_control = 0U;
}

static void initialize_params_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'elevators_min' in the parent workspace.\n");
  sf_mex_import_named("elevators_min", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_elevators_min = c1_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'elevators_max' in the parent workspace.\n");
  sf_mex_import_named("elevators_max", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_elevators_max = c1_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_elevators_ratio;
  c1_elevators_ratio = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  c1_hoistedGlobal = *c1_elevators_ratio;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_vertical_control;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_elevators_ratio;
  c1_elevators_ratio = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_elevators_ratio = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "elevators_ratio");
  chartInstance->c1_is_active_c1_vertical_control = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_vertical_control");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_vertical_control(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
}

static void sf_c1_vertical_control(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_elevators;
  uint32_T c1_debug_family_var_map[6];
  real_T c1_c_elevators_min;
  real_T c1_c_elevators_max;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_elevators_ratio;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_varargin_1;
  real_T c1_varargin_2;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_xk;
  real_T c1_e_x;
  real_T c1_b_A;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_b_y;
  real_T c1_b_varargin_1;
  real_T c1_b_varargin_2;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_b_xk;
  real_T c1_j_x;
  real_T *c1_b_elevators;
  real_T *c1_b_elevators_ratio;
  c1_b_elevators_ratio = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_elevators = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_elevators_min, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_elevators_max, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_elevators, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_elevators_ratio, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_elevators;
  c1_elevators = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_c_elevators_min, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_c_elevators_max, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_elevators, 4U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_elevators_ratio, 5U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  c1_c_elevators_max = c1_b_elevators_max;
  c1_c_elevators_min = c1_b_elevators_min;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, c1_elevators < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    c1_A = -c1_elevators;
    c1_x = c1_A;
    c1_b_x = c1_x;
    c1_y = c1_b_x / c1_b_elevators_min;
    c1_varargin_1 = c1_y;
    c1_varargin_2 = c1_varargin_1;
    c1_c_x = c1_varargin_2;
    c1_d_x = c1_c_x;
    c1_eml_scalar_eg(chartInstance);
    c1_xk = c1_d_x;
    c1_e_x = c1_xk;
    c1_eml_scalar_eg(chartInstance);
    c1_elevators_ratio = muDoubleScalarMin(c1_e_x, 1.0);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_b_A = -c1_elevators;
    c1_f_x = c1_b_A;
    c1_g_x = c1_f_x;
    c1_b_y = c1_g_x / c1_b_elevators_max;
    c1_b_varargin_1 = c1_b_y;
    c1_b_varargin_2 = c1_b_varargin_1;
    c1_h_x = c1_b_varargin_2;
    c1_i_x = c1_h_x;
    c1_eml_scalar_eg(chartInstance);
    c1_b_xk = c1_i_x;
    c1_j_x = c1_b_xk;
    c1_eml_scalar_eg(chartInstance);
    c1_elevators_ratio = muDoubleScalarMax(c1_j_x, -1.0);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c1_b_elevators_ratio = c1_elevators_ratio;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_vertical_controlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_vertical_control
  (SFc1_vertical_controlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_vertical_controlInstanceStruct *chartInstance;
  chartInstance = (SFc1_vertical_controlInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_elevators_ratio, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_elevators_ratio),
    &c1_thisId);
  sf_mex_destroy(&c1_elevators_ratio);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_elevators_ratio;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_vertical_controlInstanceStruct *chartInstance;
  chartInstance = (SFc1_vertical_controlInstanceStruct *)chartInstanceVoid;
  c1_elevators_ratio = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_elevators_ratio),
    &c1_thisId);
  sf_mex_destroy(&c1_elevators_ratio);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_vertical_control_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[11];
  c1_ResolvedFunctionInfo (*c1_b_info)[11];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[11])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mrdivide";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[0].fileTimeLo = 1325124138U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 1319729966U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].name = "rdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[1].fileTimeLo = 1286818844U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].name = "eml_div";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[2].fileTimeLo = 1313347810U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "min";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datafun/min.m";
  (*c1_b_info)[3].fileTimeLo = 1311255318U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datafun/min.m";
  (*c1_b_info)[4].name = "eml_min_or_max";
  (*c1_b_info)[4].dominantType = "char";
  (*c1_b_info)[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c1_b_info)[4].fileTimeLo = 1303146212U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c1_b_info)[5].name = "eml_scalar_eg";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[5].fileTimeLo = 1286818796U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c1_b_info)[6].name = "eml_scalexp_alloc";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c1_b_info)[6].fileTimeLo = 1286818796U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c1_b_info)[7].name = "eml_index_class";
  (*c1_b_info)[7].dominantType = "";
  (*c1_b_info)[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[7].fileTimeLo = 1286818778U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  (*c1_b_info)[8].name = "eml_scalar_eg";
  (*c1_b_info)[8].dominantType = "double";
  (*c1_b_info)[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[8].fileTimeLo = 1286818796U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  (*c1_b_info)[9].context = "";
  (*c1_b_info)[9].name = "max";
  (*c1_b_info)[9].dominantType = "double";
  (*c1_b_info)[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datafun/max.m";
  (*c1_b_info)[9].fileTimeLo = 1311255316U;
  (*c1_b_info)[9].fileTimeHi = 0U;
  (*c1_b_info)[9].mFileTimeLo = 0U;
  (*c1_b_info)[9].mFileTimeHi = 0U;
  (*c1_b_info)[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datafun/max.m";
  (*c1_b_info)[10].name = "eml_min_or_max";
  (*c1_b_info)[10].dominantType = "char";
  (*c1_b_info)[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c1_b_info)[10].fileTimeLo = 1303146212U;
  (*c1_b_info)[10].fileTimeHi = 0U;
  (*c1_b_info)[10].mFileTimeLo = 0U;
  (*c1_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c1_i0 = 0; c1_i0 < 11; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_eml_scalar_eg(SFc1_vertical_controlInstanceStruct *chartInstance)
{
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_vertical_controlInstanceStruct *chartInstance;
  chartInstance = (SFc1_vertical_controlInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_vertical_controlInstanceStruct *chartInstance;
  chartInstance = (SFc1_vertical_controlInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_vertical_control, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_vertical_control), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_vertical_control);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_vertical_controlInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_vertical_controlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_vertical_control_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3649085004U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2572304970U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3313467527U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1926585459U);
}

mxArray *sf_c1_vertical_control_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("o2SVhCaXOFeZ0G7rocu34E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c1_vertical_control(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"elevators_ratio\",},{M[8],M[0],T\"is_active_c1_vertical_control\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_vertical_control_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_vertical_controlInstanceStruct *chartInstance;
    chartInstance = (SFc1_vertical_controlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_vertical_controlMachineNumber_,
           1,
           1,
           1,
           4,
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
          init_script_number_translation(_vertical_controlMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_vertical_controlMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_vertical_controlMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"elevators_min");
          _SFD_SET_DATA_PROPS(1,10,0,0,"elevators_max");
          _SFD_SET_DATA_PROPS(2,1,1,0,"elevators");
          _SFD_SET_DATA_PROPS(3,2,0,1,"elevators_ratio");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,303);
        _SFD_CV_INIT_EML_IF(0,1,0,164,180,238,303);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_elevators;
          real_T *c1_elevators_ratio;
          c1_elevators_ratio = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c1_elevators = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c1_elevators_min);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c1_elevators_max);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_elevators);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_elevators_ratio);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_vertical_controlMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "TjolgcP3K5qORNHTKbv9qH";
}

static void sf_opaque_initialize_c1_vertical_control(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar);
  initialize_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_vertical_control(void *chartInstanceVar)
{
  enable_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_vertical_control(void *chartInstanceVar)
{
  disable_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_vertical_control(void *chartInstanceVar)
{
  sf_c1_vertical_control((SFc1_vertical_controlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_vertical_control(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_vertical_control
    ((SFc1_vertical_controlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_vertical_control();/* state var info */
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

extern void sf_internal_set_sim_state_c1_vertical_control(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_vertical_control();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_vertical_control(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_vertical_control(S);
}

static void sf_opaque_set_sim_state_c1_vertical_control(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_vertical_control(S, st);
}

static void sf_opaque_terminate_c1_vertical_control(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_vertical_controlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_vertical_control_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_vertical_control((SFc1_vertical_controlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_vertical_control(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_vertical_control((SFc1_vertical_controlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_vertical_control(SimStruct *S)
{
  /* Actual parameters from chart:
     elevators_max elevators_min
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for elevators_max*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for elevators_min*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_vertical_control_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1218139005U));
  ssSetChecksum1(S,(382566136U));
  ssSetChecksum2(S,(140422684U));
  ssSetChecksum3(S,(4032480157U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_vertical_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_vertical_control(SimStruct *S)
{
  SFc1_vertical_controlInstanceStruct *chartInstance;
  chartInstance = (SFc1_vertical_controlInstanceStruct *)malloc(sizeof
    (SFc1_vertical_controlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_vertical_controlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_vertical_control;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_vertical_control;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_vertical_control;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_vertical_control;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_vertical_control;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_vertical_control;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_vertical_control;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_vertical_control;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_vertical_control;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_vertical_control;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_vertical_control;
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

void c1_vertical_control_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_vertical_control(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_vertical_control(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_vertical_control(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_vertical_control_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
