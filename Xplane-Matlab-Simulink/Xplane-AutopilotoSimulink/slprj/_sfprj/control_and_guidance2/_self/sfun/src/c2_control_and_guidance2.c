/* Include files */

#include "blascompat32.h"
#include "control_and_guidance2_sfun.h"
#include "c2_control_and_guidance2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "control_and_guidance2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_b_NUM_WP                    (6.0)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "wp", "NUM_WP", "nargin",
  "nargout", "lat", "lon", "h", "N" };

/* Function Declarations */
static void initialize_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void initialize_params_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void enable_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void disable_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void set_sim_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void sf_c2_control_and_guidance2(SFc2_control_and_guidance2InstanceStruct
  *chartInstance);
static void c2_chartstep_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void initSimStructsc2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_b_N, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[13]);
static void c2_eml_scalar_eg(SFc2_control_and_guidance2InstanceStruct
  *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_e_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sqlDPqpC0uriFz1tcs1upYG c2_y[6]);
static char_T c2_f_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray
   *c2_b_h, const char_T *c2_identifier);
static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2_i_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_control_and_guidance2, const
  char_T *c2_identifier);
static uint8_T c2_j_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_control_and_guidance2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_h = NULL;
  chartInstance->c2_h_not_empty = FALSE;
  chartInstance->c2_N_not_empty = FALSE;
  chartInstance->c2_is_active_c2_control_and_guidance2 = 0U;
}

static void initialize_params_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_sqlDPqpC0uriFz1tcs1upYG c2_rv0[6];
  c2_sqlDPqpC0uriFz1tcs1upYG *c2_r0;
  const mxArray *c2_mxField;
  int32_T c2_i1;
  real_T c2_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'wp' in the parent workspace.\n");
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 1, 1);
  c2_i0 = 0;
  while (c2_i0 < 6) {
    c2_r0 = &c2_rv0[_SFD_EML_ARRAY_BOUNDS_CHECK(0, c2_i0, 0, 5, 1, 0)];
    c2_mxField = sf_mex_getfield(c2_m0, "name", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->name, 1, 10, 0U, 0,
                        0U, 0);
    c2_mxField = sf_mex_getfield(c2_m0, "long", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->_long, 1, 0, 0U, 0,
                        0U, 0);
    c2_mxField = sf_mex_getfield(c2_m0, "lat", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->lat, 1, 0, 0U, 0,
                        0U, 0);
    c2_mxField = sf_mex_getfield(c2_m0, "alt", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->alt, 1, 0, 0U, 0,
                        0U, 0);
    c2_mxField = sf_mex_getfield(c2_m0, "airspeed", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->airspeed, 1, 0, 0U,
                        0, 0U, 0);
    c2_mxField = sf_mex_getfield(c2_m0, "fase", "wp", c2_i0);
    sf_mex_import_named("wp", sf_mex_dup(c2_mxField), &c2_r0->fase, 1, 0, 0U, 0,
                        0U, 0);
    c2_i0++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  sf_mex_destroy(&c2_m0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    chartInstance->c2_wp[c2_i1] = c2_rv0[c2_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'NUM_WP' in the parent workspace.\n");
  sf_mex_import_named("NUM_WP", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_NUM_WP = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  c2_hoistedGlobal = chartInstance->c2_N;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  if (!chartInstance->c2_N_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = sf_mex_dup(chartInstance->c2_h);
  c2_c_y = NULL;
  if (!chartInstance->c2_h_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_duplicatearraysafe(&c2_b_u), FALSE);
  }

  sf_mex_destroy(&c2_b_u);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_control_and_guidance2;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  chartInstance->c2_N = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "N");
  sf_mex_assign(&chartInstance->c2_h, c2_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "h"), TRUE);
  chartInstance->c2_is_active_c2_control_and_guidance2 = c2_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_control_and_guidance2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_control_and_guidance2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_h);
}

static void sf_c2_control_and_guidance2(SFc2_control_and_guidance2InstanceStruct
  *chartInstance)
{
  real_T *c2_lat;
  real_T *c2_lon;
  c2_lon = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_lat = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_NUM_WP, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_lat, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_lon, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_control_and_guidance2(chartInstance);
  sf_debug_check_for_state_inconsistency(_control_and_guidance2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_lat;
  real_T c2_lon;
  uint32_T c2_debug_family_var_map[8];
  c2_sqlDPqpC0uriFz1tcs1upYG c2_c_wp[6];
  real_T c2_c_NUM_WP;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 0.0;
  int32_T c2_i2;
  static c2_sqlDPqpC0uriFz1tcs1upYG c2_d_wp[6] = { { '1', -0.34334796409554608,
      39.47617517913698, 2000.0, 110.0, 2.0 }, { '2', -0.393371992798961,
      39.494413146937212, 2200.0, 110.0, 2.0 }, { '3', -0.42478649955483339,
      39.466976171815951, 1900.0, 90.0, 2.0 }, { '4', -0.37657991233231991,
      39.473712789675552, 1900.0, 90.0, 2.0 }, { '5', -0.32554603334915672,
      39.438308180873968, 2300.0, 110.0, 2.0 }, { '5', -0.38398949867421872,
      39.464623283982249, 2300.0, 110.0, 2.0 } };

  int32_T c2_i3;
  static char_T c2_cv0[3] = { 'a', 'l', 'l' };

  char_T c2_u[3];
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i4;
  static char_T c2_cv1[2] = { 'b', '*' };

  char_T c2_d_u[2];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i5;
  static char_T c2_cv2[2] = { 'o', 'n' };

  char_T c2_e_u[2];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i;
  real_T c2_b_i;
  static c2_sqlDPqpC0uriFz1tcs1upYG c2_rv1[6] = { { '1', -0.34334796409554608,
      39.47617517913698, 2000.0, 110.0, 2.0 }, { '2', -0.393371992798961,
      39.494413146937212, 2200.0, 110.0, 2.0 }, { '3', -0.42478649955483339,
      39.466976171815951, 1900.0, 90.0, 2.0 }, { '4', -0.37657991233231991,
      39.473712789675552, 1900.0, 90.0, 2.0 }, { '5', -0.32554603334915672,
      39.438308180873968, 2300.0, 110.0, 2.0 }, { '5', -0.38398949867421872,
      39.464623283982249, 2300.0, 110.0, 2.0 } };

  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  int32_T c2_i6;
  static char_T c2_cv3[2] = { 'b', 'o' };

  char_T c2_h_u[2];
  const mxArray *c2_h_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_x;
  real_T c2_xk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_r;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i7;
  static char_T c2_cv4[2] = { '.', 'r' };

  char_T c2_k_u[2];
  const mxArray *c2_k_y = NULL;
  real_T *c2_b_lon;
  real_T *c2_b_lat;
  c2_b_lon = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_lat = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_lat;
  c2_b_hoistedGlobal = *c2_b_lon;
  c2_lat = c2_hoistedGlobal;
  c2_lon = c2_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c2_c_wp, 0U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_c_NUM_WP, 1U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_lat, 4U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_lon, 5U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_h, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_N, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  c2_c_NUM_WP = c2_b_NUM_WP;
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    c2_c_wp[c2_i2] = c2_d_wp[c2_i2];
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_h_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
    for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
      c2_u[c2_i3] = c2_cv0[c2_i3];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 3),
                  FALSE);
    sf_mex_call_debug("close", 0U, 1U, 14, c2_y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    sf_mex_assign(&chartInstance->c2_h, sf_mex_call_debug("axes", 1U, 0U), TRUE);
    chartInstance->c2_h_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    c2_b_u = -0.34334796409554608;
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
    c2_c_u = 39.47617517913698;
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
    for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
      c2_d_u[c2_i4] = c2_cv1[c2_i4];
    }

    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    sf_mex_call_debug("plot", 0U, 3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
      c2_e_u[c2_i5] = c2_cv2[c2_i5];
    }

    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    sf_mex_call_debug("hold", 0U, 1U, 14, c2_e_y);
    c2_i = 0;
    while (c2_i < 5) {
      c2_b_i = 2.0 + (real_T)c2_i;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
      c2_f_u = c2_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_b_i), 1, 6, 1, 0) - 1]._long;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_g_u = c2_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_b_i), 1, 6, 1, 0) - 1].lat;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
        c2_h_u[c2_i6] = c2_cv3[c2_i6];
      }

      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_h_u, 10, 0U, 1U, 0U, 2, 1, 2),
                    FALSE);
      sf_mex_call_debug("plot", 0U, 3U, 14, c2_f_y, 14, c2_g_y, 14, c2_h_y);
      c2_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    chartInstance->c2_N = 0.0;
    chartInstance->c2_N_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  chartInstance->c2_N++;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_c_hoistedGlobal = chartInstance->c2_N;
  c2_x = c2_c_hoistedGlobal;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_x;
  c2_b_x = c2_xk;
  c2_c_x = c2_b_x;
  c2_eml_scalar_eg(chartInstance);
  c2_d_x = c2_c_x / 10.0;
  c2_e_x = c2_d_x;
  c2_e_x = muDoubleScalarFloor(c2_e_x);
  c2_r = c2_c_x - c2_e_x * 10.0;
  if (CV_EML_IF(0, 1, 1, c2_r == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    c2_i_u = c2_lon;
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
    c2_j_u = c2_lat;
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
    for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
      c2_k_u[c2_i7] = c2_cv4[c2_i7];
    }

    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_k_u, 10, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
    sf_mex_call_debug("plot", 0U, 4U, 14, sf_mex_dup(chartInstance->c2_h), 14,
                      c2_i_y, 14, c2_j_y, 14, c2_k_y);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -29);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_control_and_guidance2
  (SFc2_control_and_guidance2InstanceStruct *chartInstance)
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
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_N_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_b_N, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_N), &c2_thisId);
  sf_mex_destroy(&c2_b_N);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_N_not_empty = FALSE;
  } else {
    chartInstance->c2_N_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_N;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_b_N = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_N), &c2_thisId);
  sf_mex_destroy(&c2_b_N);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_u;
  const mxArray *c2_y = NULL;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_y = NULL;
  if (!chartInstance->c2_h_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  }

  sf_mex_destroy(&c2_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i8;
  c2_sqlDPqpC0uriFz1tcs1upYG c2_b_inData[6];
  int32_T c2_i9;
  c2_sqlDPqpC0uriFz1tcs1upYG c2_u[6];
  const mxArray *c2_y = NULL;
  int32_T c2_i10;
  int32_T c2_iv0[2];
  int32_T c2_i11;
  c2_sqlDPqpC0uriFz1tcs1upYG *c2_r1;
  char_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
    c2_b_inData[c2_i8] = (*(c2_sqlDPqpC0uriFz1tcs1upYG (*)[6])c2_inData)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 6; c2_i9++) {
    c2_u[c2_i9] = c2_b_inData[c2_i9];
  }

  c2_y = NULL;
  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    c2_iv0[c2_i10] = 1 + 5 * c2_i10;
  }

  sf_mex_assign(&c2_y, sf_mex_createstructarray("structure", 2, c2_iv0), FALSE);
  for (c2_i11 = 0; c2_i11 < 6; c2_i11++) {
    c2_r1 = &c2_u[c2_i11];
    c2_b_u = c2_r1->name;
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_b_y, "name", "name", c2_i11);
    c2_c_u = c2_r1->_long;
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_c_y, "long", "long", c2_i11);
    c2_d_u = c2_r1->lat;
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_d_y, "lat", "lat", c2_i11);
    c2_e_u = c2_r1->alt;
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_e_y, "alt", "alt", c2_i11);
    c2_f_u = c2_r1->airspeed;
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_f_y, "airspeed", "airspeed", c2_i11);
    c2_g_u = c2_r1->fase;
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c2_y, c2_g_y, "fase", "fase", c2_i11);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_control_and_guidance2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[13];
  const mxArray *c2_m1 = NULL;
  int32_T c2_i12;
  c2_ResolvedFunctionInfo *c2_r2;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m1, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c2_i12 = 0; c2_i12 < 13; c2_i12++) {
    c2_r2 = &c2_info[c2_i12];
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r2->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r2->context)), "context", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r2->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r2->name)), "name", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r2->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r2->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", c2_r2->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r2->resolved)), "resolved", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r2->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r2->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r2->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m1, sf_mex_create("nameCaptureInfo", &c2_r2->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i12);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m1, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[13])
{
  c2_info[0].context = "";
  c2_info[0].name = "mod";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[0].fileTimeLo = 1286818744U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[1].name = "eml_scalar_eg";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[1].fileTimeLo = 1286818796U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[2].name = "eml_scalexp_alloc";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[2].fileTimeLo = 1286818796U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[3].name = "eml_scalar_mod";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[3].fileTimeLo = 1307651238U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[4].name = "eml_scalar_eg";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[4].fileTimeLo = 1286818796U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[5].name = "eml_scalar_floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[5].fileTimeLo = 1286818726U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[6].name = "eml_scalar_round";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[6].fileTimeLo = 1307651238U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[7].name = "eml_scalar_abs";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[7].fileTimeLo = 1286818712U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[8].name = "eps";
  c2_info[8].dominantType = "char";
  c2_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[8].fileTimeLo = 1307651240U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[9].name = "eml_is_float_class";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[9].fileTimeLo = 1286818782U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[10].name = "eml_eps";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[10].fileTimeLo = 1307651240U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[11].name = "eml_float_model";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[11].fileTimeLo = 1307651242U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c2_info[12].name = "mtimes";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].fileTimeLo = 1289519692U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_control_and_guidance2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i13, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i13;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_e_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_sqlDPqpC0uriFz1tcs1upYG c2_y[6])
{
  int32_T c2_i14;
  uint32_T c2_uv0[2];
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[6] = { "name", "long", "lat", "alt",
    "airspeed", "fase" };

  c2_sqlDPqpC0uriFz1tcs1upYG (*c2_r3)[6];
  int32_T c2_i15;
  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    c2_uv0[c2_i14] = 1U + 5U * (uint32_T)c2_i14;
  }

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 6, c2_fieldNames, 2U, c2_uv0);
  c2_r3 = (c2_sqlDPqpC0uriFz1tcs1upYG (*)[6])c2_y;
  for (c2_i15 = 0; c2_i15 < 6; c2_i15++) {
    c2_thisId.fIdentifier = "name";
    (*c2_r3)[c2_i15].name = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "name", "name", c2_i15)), &c2_thisId);
    c2_thisId.fIdentifier = "long";
    (*c2_r3)[c2_i15]._long = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "long", "long", c2_i15)), &c2_thisId);
    c2_thisId.fIdentifier = "lat";
    (*c2_r3)[c2_i15].lat = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "lat", "lat", c2_i15)), &c2_thisId);
    c2_thisId.fIdentifier = "alt";
    (*c2_r3)[c2_i15].alt = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "alt", "alt", c2_i15)), &c2_thisId);
    c2_thisId.fIdentifier = "airspeed";
    (*c2_r3)[c2_i15].airspeed = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "airspeed", "airspeed", c2_i15)), &c2_thisId);
    c2_thisId.fIdentifier = "fase";
    (*c2_r3)[c2_i15].fase = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_u, "fase", "fase", c2_i15)), &c2_thisId);
  }

  sf_mex_destroy(&c2_u);
}

static char_T c2_f_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  char_T c2_y;
  char_T c2_c0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_c0, 1, 10, 0U, 0, 0U, 0);
  c2_y = c2_c0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_c_wp;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_sqlDPqpC0uriFz1tcs1upYG c2_y[6];
  int32_T c2_i16;
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)chartInstanceVoid;
  c2_c_wp = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_wp), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_c_wp);
  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    (*(c2_sqlDPqpC0uriFz1tcs1upYG (*)[6])c2_outData)[c2_i16] = c2_y[c2_i16];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray
   *c2_b_h, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_h),
    &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_h);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_control_and_guidance2InstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y;
  c2_y = NULL;
  c2_y = NULL;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_h_not_empty = FALSE;
  } else {
    chartInstance->c2_h_not_empty = TRUE;
    sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_control_and_guidance2, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_control_and_guidance2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_control_and_guidance2);
  return c2_y;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_control_and_guidance2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_control_and_guidance2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_control_and_guidance2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3316460729U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3560172028U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3055461777U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(359739367U);
}

mxArray *sf_c2_control_and_guidance2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("J4kolGZTFkXxG6ii9pY1Y");
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
      pr[1] = (double)(6);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_control_and_guidance2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[4],M[0],T\"N\",S'l','i','p'{{M1x2[163 164],M[0],}}},{M[4],M[0],T\"h\",S'l','i','p'{{M1x2[161 162],M[0],}}},{M[8],M[0],T\"is_active_c2_control_and_guidance2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_control_and_guidance2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_control_and_guidance2InstanceStruct *chartInstance;
    chartInstance = (SFc2_control_and_guidance2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_control_and_guidance2MachineNumber_,
           2,
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
          init_script_number_translation(_control_and_guidance2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_control_and_guidance2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_control_and_guidance2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"wp");
          _SFD_SET_DATA_PROPS(1,10,0,0,"NUM_WP");
          _SFD_SET_DATA_PROPS(2,1,1,0,"lat");
          _SFD_SET_DATA_PROPS(3,1,1,0,"lon");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,444);
        _SFD_CV_INIT_EML_IF(0,1,0,166,179,-1,369);
        _SFD_CV_INIT_EML_IF(0,1,1,394,412,-1,444);
        _SFD_CV_INIT_EML_FOR(0,1,0,282,297,349);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_lat;
          real_T *c2_lon;
          c2_lon = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_lat = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_wp);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c2_NUM_WP);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_lat);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_lon);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_control_and_guidance2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "xqk1oEhKDinHB18MfeSjxE";
}

static void sf_opaque_initialize_c2_control_and_guidance2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_control_and_guidance2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_control_and_guidance2
    ((SFc2_control_and_guidance2InstanceStruct*) chartInstanceVar);
  initialize_c2_control_and_guidance2((SFc2_control_and_guidance2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_control_and_guidance2(void *chartInstanceVar)
{
  enable_c2_control_and_guidance2((SFc2_control_and_guidance2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_control_and_guidance2(void *chartInstanceVar)
{
  disable_c2_control_and_guidance2((SFc2_control_and_guidance2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_control_and_guidance2(void *chartInstanceVar)
{
  sf_c2_control_and_guidance2((SFc2_control_and_guidance2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_control_and_guidance2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_control_and_guidance2
    ((SFc2_control_and_guidance2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_control_and_guidance2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_control_and_guidance2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_control_and_guidance2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_control_and_guidance2
    ((SFc2_control_and_guidance2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_control_and_guidance2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_control_and_guidance2(S);
}

static void sf_opaque_set_sim_state_c2_control_and_guidance2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_control_and_guidance2(S, st);
}

static void sf_opaque_terminate_c2_control_and_guidance2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_control_and_guidance2InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_control_and_guidance2((SFc2_control_and_guidance2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_control_and_guidance2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_control_and_guidance2
    ((SFc2_control_and_guidance2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_control_and_guidance2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_control_and_guidance2
      ((SFc2_control_and_guidance2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_control_and_guidance2(SimStruct *S)
{
  /* Actual parameters from chart:
     NUM_WP wp
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for NUM_WP*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_control_and_guidance2_optimization_info();
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
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1004084819U));
  ssSetChecksum1(S,(4276010637U));
  ssSetChecksum2(S,(512957888U));
  ssSetChecksum3(S,(3876137196U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_control_and_guidance2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_control_and_guidance2(SimStruct *S)
{
  SFc2_control_and_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc2_control_and_guidance2InstanceStruct *)malloc(sizeof
    (SFc2_control_and_guidance2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_control_and_guidance2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_control_and_guidance2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_control_and_guidance2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_control_and_guidance2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_control_and_guidance2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_control_and_guidance2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_control_and_guidance2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_control_and_guidance2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_control_and_guidance2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_control_and_guidance2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_control_and_guidance2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_control_and_guidance2;
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

void c2_control_and_guidance2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_control_and_guidance2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_control_and_guidance2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_control_and_guidance2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_control_and_guidance2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
