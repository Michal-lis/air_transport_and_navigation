/* Include files */

#include "blascompat32.h"
#include "guidance2_sfun.h"
#include "c3_guidance2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "guidance2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_b_HOLD_ALT                  (0.0)
#define c3_b_HOLD_SPEED                (0.0)
#define c3_b_alt_value                 (2000.0)
#define c3_b_speed_value               (115.0)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[12] = { "wp", "HOLD_ALT", "HOLD_SPEED",
  "alt_value", "speed_value", "nargin", "nargout", "WP", "lat", "lon", "alt",
  "airspeed" };

/* Function Declarations */
static void initialize_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance);
static void initialize_params_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance);
static void enable_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance);
static void disable_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance);
static void set_sim_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance);
static void sf_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance);
static void initSimStructsc3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_airspeed, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_d_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_sqlDPqpC0uriFz1tcs1upYG c3_y[6]);
static char_T c3_e_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_guidance2, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_guidance2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_guidance2 = 0U;
}

static void initialize_params_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_m0 = NULL;
  int32_T c3_i0;
  c3_sqlDPqpC0uriFz1tcs1upYG c3_rv0[6];
  c3_sqlDPqpC0uriFz1tcs1upYG *c3_r0;
  const mxArray *c3_mxField;
  int32_T c3_i1;
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  sf_set_error_prefix_string(
    "Error evaluating data 'wp' in the parent workspace.\n");
  c3_m0 = sf_mex_get_sfun_param(chartInstance->S, 4, 1);
  c3_i0 = 0;
  while (c3_i0 < 6) {
    c3_r0 = &c3_rv0[_SFD_EML_ARRAY_BOUNDS_CHECK(0, c3_i0, 0, 5, 1, 0)];
    c3_mxField = sf_mex_getfield(c3_m0, "name", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->name, 1, 10, 0U, 0,
                        0U, 0);
    c3_mxField = sf_mex_getfield(c3_m0, "long", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->_long, 1, 0, 0U, 0,
                        0U, 0);
    c3_mxField = sf_mex_getfield(c3_m0, "lat", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->lat, 1, 0, 0U, 0,
                        0U, 0);
    c3_mxField = sf_mex_getfield(c3_m0, "alt", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->alt, 1, 0, 0U, 0,
                        0U, 0);
    c3_mxField = sf_mex_getfield(c3_m0, "airspeed", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->airspeed, 1, 0, 0U,
                        0, 0U, 0);
    c3_mxField = sf_mex_getfield(c3_m0, "fase", "wp", c3_i0);
    sf_mex_import_named("wp", sf_mex_dup(c3_mxField), &c3_r0->fase, 1, 0, 0U, 0,
                        0U, 0);
    c3_i0++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  sf_mex_destroy(&c3_m0);
  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    chartInstance->c3_wp[c3_i1] = c3_rv0[c3_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'HOLD_ALT' in the parent workspace.\n");
  sf_mex_import_named("HOLD_ALT", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_HOLD_ALT = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'HOLD_SPEED' in the parent workspace.\n");
  sf_mex_import_named("HOLD_SPEED", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_HOLD_SPEED = c3_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'alt_value' in the parent workspace.\n");
  sf_mex_import_named("alt_value", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_alt_value = c3_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'speed_value' in the parent workspace.\n");
  sf_mex_import_named("speed_value", sf_mex_get_sfun_param(chartInstance->S, 3,
    0), &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_speed_value = c3_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T *c3_airspeed;
  real_T *c3_alt;
  real_T *c3_lat;
  real_T *c3_lon;
  c3_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(5), FALSE);
  c3_hoistedGlobal = *c3_airspeed;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_alt;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_lat;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_lon;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_guidance2;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_airspeed;
  real_T *c3_alt;
  real_T *c3_lat;
  real_T *c3_lon;
  c3_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_airspeed = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "airspeed");
  *c3_alt = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "alt");
  *c3_lat = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "lat");
  *c3_lon = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "lon");
  chartInstance->c3_is_active_c3_guidance2 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "is_active_c3_guidance2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_guidance2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance)
{
}

static void sf_c3_guidance2(SFc3_guidance2InstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_WP;
  uint32_T c3_debug_family_var_map[12];
  c3_sqlDPqpC0uriFz1tcs1upYG c3_c_wp[6];
  real_T c3_c_HOLD_ALT;
  real_T c3_c_HOLD_SPEED;
  real_T c3_c_alt_value;
  real_T c3_c_speed_value;
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 4.0;
  real_T c3_lat;
  real_T c3_lon;
  real_T c3_alt;
  real_T c3_airspeed;
  int32_T c3_i2;
  static c3_sqlDPqpC0uriFz1tcs1upYG c3_d_wp[6] = { { '1', -0.34334796409554608,
      39.47617517913698, 2000.0, 110.0, 2.0 }, { '2', -0.393371992798961,
      39.494413146937212, 2200.0, 110.0, 2.0 }, { '3', -0.42478649955483339,
      39.466976171815951, 1900.0, 90.0, 2.0 }, { '4', -0.37657991233231991,
      39.473712789675552, 1900.0, 90.0, 2.0 }, { '5', -0.32554603334915672,
      39.438308180873968, 2300.0, 110.0, 2.0 }, { '5', -0.38398949867421872,
      39.464623283982249, 2300.0, 110.0, 2.0 } };

  static c3_sqlDPqpC0uriFz1tcs1upYG c3_rv1[6] = { { '1', -0.34334796409554608,
      39.47617517913698, 2000.0, 110.0, 2.0 }, { '2', -0.393371992798961,
      39.494413146937212, 2200.0, 110.0, 2.0 }, { '3', -0.42478649955483339,
      39.466976171815951, 1900.0, 90.0, 2.0 }, { '4', -0.37657991233231991,
      39.473712789675552, 1900.0, 90.0, 2.0 }, { '5', -0.32554603334915672,
      39.438308180873968, 2300.0, 110.0, 2.0 }, { '5', -0.38398949867421872,
      39.464623283982249, 2300.0, 110.0, 2.0 } };

  real_T *c3_b_lat;
  real_T *c3_b_WP;
  real_T *c3_b_lon;
  real_T *c3_b_alt;
  real_T *c3_b_airspeed;
  c3_b_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_b_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_lat, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_WP, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_lon, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_alt, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_airspeed, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_HOLD_ALT, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_HOLD_SPEED, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_alt_value, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_speed_value, 9U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_WP;
  c3_WP = c3_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c3_c_wp, 0U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_c_HOLD_ALT, 1U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_c_HOLD_SPEED, 2U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_c_alt_value, 3U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c_speed_value, 4U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_WP, 7U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_lat, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_lon, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_alt, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_airspeed, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_c_speed_value = c3_b_speed_value;
  c3_c_alt_value = c3_b_alt_value;
  c3_c_HOLD_SPEED = c3_b_HOLD_SPEED;
  c3_c_HOLD_ALT = c3_b_HOLD_ALT;
  for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
    c3_c_wp[c3_i2] = c3_d_wp[c3_i2];
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_lat = c3_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)_SFD_INTEGER_CHECK(
    "WP", c3_WP), 1, 6, 1, 0) - 1].lat;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_lon = c3_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)_SFD_INTEGER_CHECK(
    "WP", c3_WP), 1, 6, 1, 0) - 1]._long;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  CV_EML_IF(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_alt = c3_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)_SFD_INTEGER_CHECK(
    "WP", c3_WP), 1, 6, 1, 0) - 1].alt;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  CV_EML_IF(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_airspeed = c3_rv1[_SFD_EML_ARRAY_BOUNDS_CHECK("wp", (int32_T)
    _SFD_INTEGER_CHECK("WP", c3_WP), 1, 6, 1, 0) - 1].airspeed;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  *c3_b_lat = c3_lat;
  *c3_b_lon = c3_lon;
  *c3_b_alt = c3_alt;
  *c3_b_airspeed = c3_airspeed;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_guidance2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_guidance2(SFc3_guidance2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_airspeed, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_airspeed),
    &c3_thisId);
  sf_mex_destroy(&c3_airspeed);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d4;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d4, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d4;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_airspeed;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_airspeed = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_airspeed),
    &c3_thisId);
  sf_mex_destroy(&c3_airspeed);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i3;
  c3_sqlDPqpC0uriFz1tcs1upYG c3_b_inData[6];
  int32_T c3_i4;
  c3_sqlDPqpC0uriFz1tcs1upYG c3_u[6];
  const mxArray *c3_y = NULL;
  int32_T c3_i5;
  int32_T c3_iv0[2];
  int32_T c3_i6;
  c3_sqlDPqpC0uriFz1tcs1upYG *c3_r1;
  char_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
    c3_b_inData[c3_i3] = (*(c3_sqlDPqpC0uriFz1tcs1upYG (*)[6])c3_inData)[c3_i3];
  }

  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_u[c3_i4] = c3_b_inData[c3_i4];
  }

  c3_y = NULL;
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_iv0[c3_i5] = 1 + 5 * c3_i5;
  }

  sf_mex_assign(&c3_y, sf_mex_createstructarray("structure", 2, c3_iv0), FALSE);
  for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
    c3_r1 = &c3_u[c3_i6];
    c3_b_u = c3_r1->name;
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_b_y, "name", "name", c3_i6);
    c3_c_u = c3_r1->_long;
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_c_y, "long", "long", c3_i6);
    c3_d_u = c3_r1->lat;
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_d_y, "lat", "lat", c3_i6);
    c3_e_u = c3_r1->alt;
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_e_y, "alt", "alt", c3_i6);
    c3_f_u = c3_r1->airspeed;
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_f_y, "airspeed", "airspeed", c3_i6);
    c3_g_u = c3_r1->fase;
    c3_g_y = NULL;
    sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_addfield(c3_y, c3_g_y, "fase", "fase", c3_i6);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_guidance2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i7;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i7, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i7;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_d_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_sqlDPqpC0uriFz1tcs1upYG c3_y[6])
{
  int32_T c3_i8;
  uint32_T c3_uv0[2];
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[6] = { "name", "long", "lat", "alt",
    "airspeed", "fase" };

  c3_sqlDPqpC0uriFz1tcs1upYG (*c3_r2)[6];
  int32_T c3_i9;
  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_uv0[c3_i8] = 1U + 5U * (uint32_T)c3_i8;
  }

  c3_thisId.fParent = c3_parentId;
  sf_mex_check_struct(c3_parentId, c3_u, 6, c3_fieldNames, 2U, c3_uv0);
  c3_r2 = (c3_sqlDPqpC0uriFz1tcs1upYG (*)[6])c3_y;
  for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
    c3_thisId.fIdentifier = "name";
    (*c3_r2)[c3_i9].name = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "name", "name", c3_i9)), &c3_thisId);
    c3_thisId.fIdentifier = "long";
    (*c3_r2)[c3_i9]._long = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "long", "long", c3_i9)), &c3_thisId);
    c3_thisId.fIdentifier = "lat";
    (*c3_r2)[c3_i9].lat = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "lat", "lat", c3_i9)), &c3_thisId);
    c3_thisId.fIdentifier = "alt";
    (*c3_r2)[c3_i9].alt = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "alt", "alt", c3_i9)), &c3_thisId);
    c3_thisId.fIdentifier = "airspeed";
    (*c3_r2)[c3_i9].airspeed = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "airspeed", "airspeed", c3_i9)), &c3_thisId);
    c3_thisId.fIdentifier = "fase";
    (*c3_r2)[c3_i9].fase = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_u, "fase", "fase", c3_i9)), &c3_thisId);
  }

  sf_mex_destroy(&c3_u);
}

static char_T c3_e_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  char_T c3_y;
  char_T c3_c0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_c0, 1, 10, 0U, 0, 0U, 0);
  c3_y = c3_c0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_c_wp;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_sqlDPqpC0uriFz1tcs1upYG c3_y[6];
  int32_T c3_i10;
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)chartInstanceVoid;
  c3_c_wp = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_wp), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_c_wp);
  for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
    (*(c3_sqlDPqpC0uriFz1tcs1upYG (*)[6])c3_outData)[c3_i10] = c3_y[c3_i10];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_guidance2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_guidance2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_guidance2);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_guidance2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_guidance2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_guidance2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(558469274U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1985378662U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3851687279U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1385195140U);
}

mxArray *sf_c3_guidance2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NmKo2y6BwNOBhCUp8aIyiG");
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_guidance2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[10],T\"airspeed\",},{M[1],M[8],T\"alt\",},{M[1],M[5],T\"lat\",},{M[1],M[7],T\"lon\",},{M[8],M[0],T\"is_active_c3_guidance2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_guidance2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_guidance2InstanceStruct *chartInstance;
    chartInstance = (SFc3_guidance2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_guidance2MachineNumber_,
          3,
          1,
          1,
          10,
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
          _SFD_SET_DATA_PROPS(0,10,0,0,"wp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"lat");
          _SFD_SET_DATA_PROPS(2,1,1,0,"WP");
          _SFD_SET_DATA_PROPS(3,2,0,1,"lon");
          _SFD_SET_DATA_PROPS(4,2,0,1,"alt");
          _SFD_SET_DATA_PROPS(5,2,0,1,"airspeed");
          _SFD_SET_DATA_PROPS(6,10,0,0,"HOLD_ALT");
          _SFD_SET_DATA_PROPS(7,10,0,0,"HOLD_SPEED");
          _SFD_SET_DATA_PROPS(8,10,0,0,"alt_value");
          _SFD_SET_DATA_PROPS(9,10,0,0,"speed_value");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,292);
        _SFD_CV_INIT_EML_IF(0,1,0,144,155,177,207);
        _SFD_CV_INIT_EML_IF(0,1,1,209,222,251,291);
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
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_lat;
          real_T *c3_WP;
          real_T *c3_lon;
          real_T *c3_alt;
          real_T *c3_airspeed;
          c3_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_WP = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_wp);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_lat);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_WP);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_lon);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_alt);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_airspeed);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c3_HOLD_ALT);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_HOLD_SPEED);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_alt_value);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_speed_value);
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
  return "ycunCLcoccMM0RqfKaInCD";
}

static void sf_opaque_initialize_c3_guidance2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_guidance2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_guidance2((SFc3_guidance2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_guidance2(void *chartInstanceVar)
{
  enable_c3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_guidance2(void *chartInstanceVar)
{
  disable_c3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_guidance2(void *chartInstanceVar)
{
  sf_c3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_guidance2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_guidance2((SFc3_guidance2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_guidance2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_guidance2(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_guidance2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_guidance2((SFc3_guidance2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_guidance2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_guidance2(S);
}

static void sf_opaque_set_sim_state_c3_guidance2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_guidance2(S, st);
}

static void sf_opaque_terminate_c3_guidance2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_guidance2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_guidance2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_guidance2((SFc3_guidance2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_guidance2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_guidance2((SFc3_guidance2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_guidance2(SimStruct *S)
{
  /* Actual parameters from chart:
     HOLD_ALT HOLD_SPEED alt_value speed_value wp
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for HOLD_ALT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for HOLD_SPEED*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for alt_value*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for speed_value*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_guidance2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2455337403U));
  ssSetChecksum1(S,(730976860U));
  ssSetChecksum2(S,(836083596U));
  ssSetChecksum3(S,(3003163871U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_guidance2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_guidance2(SimStruct *S)
{
  SFc3_guidance2InstanceStruct *chartInstance;
  chartInstance = (SFc3_guidance2InstanceStruct *)malloc(sizeof
    (SFc3_guidance2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_guidance2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_guidance2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_guidance2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_guidance2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_guidance2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_guidance2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_guidance2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_guidance2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_guidance2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_guidance2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_guidance2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_guidance2;
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

void c3_guidance2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_guidance2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_guidance2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_guidance2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_guidance2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
