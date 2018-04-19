/* Include files */

#include "blascompat32.h"
#include "xplane_interface_sfun.h"
#include "c7_xplane_interface.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "xplane_interface_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[8] = { "dataref", "value_bytes", "len",
  "dataref_bytes", "value", "nargin", "nargout", "send_msg" };

/* Function Declarations */
static void initialize_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);
static void initialize_params_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance);
static void enable_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);
static void disable_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance);
static void set_sim_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance, const mxArray *c7_st);
static void finalize_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);
static void sf_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);
static void initSimStructsc7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_send_msg, const char_T *c7_identifier,
  uint8_T c7_y[509]);
static void c7_b_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[509]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real32_T c7_d_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_e_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[35]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_f_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[4]);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[13]);
static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_g_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_h_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_xplane_interface, const
  char_T *c7_identifier);
static uint8_T c7_i_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_xplane_interfaceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_xplane_interface = 0U;
}

static void initialize_params_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance)
{
}

static void enable_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  uint8_T c7_u[509];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint8_T (*c7_send_msg)[509];
  c7_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 509; c7_i0++) {
    c7_u[c7_i0] = (*c7_send_msg)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 3, 0U, 1U, 0U, 2, 1, 509),
                FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_xplane_interface;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  uint8_T c7_uv0[509];
  int32_T c7_i1;
  uint8_T (*c7_send_msg)[509];
  c7_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
                      "send_msg", c7_uv0);
  for (c7_i1 = 0; c7_i1 < 509; c7_i1++) {
    (*c7_send_msg)[c7_i1] = c7_uv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_xplane_interface = c7_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_xplane_interface");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_xplane_interface(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
}

static void sf_c7_xplane_interface(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
  int32_T c7_i2;
  real_T c7_hoistedGlobal;
  real_T c7_value;
  uint32_T c7_debug_family_var_map[8];
  char_T c7_dataref[35];
  uint8_T c7_value_bytes[4];
  real_T c7_len;
  uint8_T c7_dataref_bytes[35];
  real32_T c7_b_value;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  uint8_T c7_send_msg[509];
  int32_T c7_i3;
  static char_T c7_cv0[35] = { 's', 'i', 'm', '/', 'f', 'l', 'i', 'g', 'h', 't',
    'm', 'o', 'd', 'e', 'l', '/', 'e', 'n', 'g', 'i', 'n', 'e', '/', 'E', 'N',
    'G', 'N', '_', 't', 'h', 'r', 'o', '[', '0', ']' };

  int32_T c7_i4;
  int32_T c7_i5;
  static uint8_T c7_uv1[4] = { 68U, 82U, 69U, 70U };

  real32_T c7_x;
  int32_T c7_j;
  real_T c7_b_j;
  int32_T c7_i6;
  static uint8_T c7_uv2[35] = { 115U, 105U, 109U, 47U, 102U, 108U, 105U, 103U,
    104U, 116U, 109U, 111U, 100U, 101U, 108U, 47U, 101U, 110U, 103U, 105U, 110U,
    101U, 47U, 69U, 78U, 71U, 78U, 95U, 116U, 104U, 114U, 111U, 91U, 48U, 93U };

  int32_T c7_c_j;
  int32_T c7_i7;
  real_T *c7_c_value;
  uint8_T (*c7_b_send_msg)[509];
  c7_b_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_c_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_c_value, 0U);
  for (c7_i2 = 0; c7_i2 < 509; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c7_b_send_msg)[c7_i2], 1U);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_c_value;
  c7_value = c7_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 9U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c7_dataref, 0U, c7_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c7_value_bytes, 1U,
    c7_e_sf_marshallOut, c7_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_len, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c7_dataref_bytes, 3U,
    c7_d_sf_marshallOut, c7_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_b_value, MAX_uint32_T,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 5U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_value, 4U, c7_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c7_send_msg, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  for (c7_i3 = 0; c7_i3 < 35; c7_i3++) {
    c7_dataref[c7_i3] = c7_cv0[c7_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i4 = 0; c7_i4 < 509; c7_i4++) {
    c7_send_msg[c7_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  for (c7_i5 = 0; c7_i5 < 4; c7_i5++) {
    c7_send_msg[c7_i5] = c7_uv1[c7_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_send_msg[4] = 0U;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_b_value = (real32_T)c7_value;
  sf_debug_symbol_switch(4U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_x = c7_b_value;
  memcpy(&c7_value_bytes[0], &c7_x, 4U);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_len = 6.0;
  c7_j = 0;
  while (c7_j < 4) {
    c7_b_j = 1.0 + (real_T)c7_j;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
    c7_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c7_len), 1, 509, 1, 0) - 1] =
      c7_value_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("value_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c7_b_j), 1, 4, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
    c7_len++;
    c7_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
  for (c7_i6 = 0; c7_i6 < 35; c7_i6++) {
    c7_dataref_bytes[c7_i6] = c7_uv2[c7_i6];
  }

  c7_c_j = 0;
  while (c7_c_j < 35) {
    c7_b_j = 1.0 + (real_T)c7_c_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
    c7_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c7_len), 1, 509, 1, 0) - 1] =
      c7_dataref_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("dataref_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c7_b_j), 1, 35, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
    c7_len++;
    c7_c_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  for (c7_i7 = 0; c7_i7 < 509; c7_i7++) {
    (*c7_b_send_msg)[c7_i7] = c7_send_msg[c7_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  sf_debug_check_for_state_inconsistency(_xplane_interfaceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_xplane_interface
  (SFc7_xplane_interfaceInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i8;
  uint8_T c7_b_inData[509];
  int32_T c7_i9;
  uint8_T c7_u[509];
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i8 = 0; c7_i8 < 509; c7_i8++) {
    c7_b_inData[c7_i8] = (*(uint8_T (*)[509])c7_inData)[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 509; c7_i9++) {
    c7_u[c7_i9] = c7_b_inData[c7_i9];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 3, 0U, 1U, 0U, 2, 1, 509), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_send_msg, const char_T *c7_identifier,
  uint8_T c7_y[509])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_send_msg), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_send_msg);
}

static void c7_b_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[509])
{
  uint8_T c7_uv3[509];
  int32_T c7_i10;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_uv3, 1, 3, 0U, 1, 0U, 2, 1,
                509);
  for (c7_i10 = 0; c7_i10 < 509; c7_i10++) {
    c7_y[c7_i10] = c7_uv3[c7_i10];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_send_msg;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y[509];
  int32_T c7_i11;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_send_msg = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_send_msg), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_send_msg);
  for (c7_i11 = 0; c7_i11 < 509; c7_i11++) {
    (*(uint8_T (*)[509])c7_outData)[c7_i11] = c7_y[c7_i11];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real32_T c7_d_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real32_T c7_y;
  real32_T c7_f0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_f0, 1, 1, 0U, 0, 0U, 0);
  c7_y = c7_f0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_value;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real32_T c7_y;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_value = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_value), &c7_thisId);
  sf_mex_destroy(&c7_value);
  *(real32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i12;
  uint8_T c7_b_inData[35];
  int32_T c7_i13;
  uint8_T c7_u[35];
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i12 = 0; c7_i12 < 35; c7_i12++) {
    c7_b_inData[c7_i12] = (*(uint8_T (*)[35])c7_inData)[c7_i12];
  }

  for (c7_i13 = 0; c7_i13 < 35; c7_i13++) {
    c7_u[c7_i13] = c7_b_inData[c7_i13];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 3, 0U, 1U, 0U, 2, 1, 35), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_e_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[35])
{
  uint8_T c7_uv4[35];
  int32_T c7_i14;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_uv4, 1, 3, 0U, 1, 0U, 2, 1, 35);
  for (c7_i14 = 0; c7_i14 < 35; c7_i14++) {
    c7_y[c7_i14] = c7_uv4[c7_i14];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_dataref_bytes;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y[35];
  int32_T c7_i15;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_dataref_bytes = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_dataref_bytes), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_dataref_bytes);
  for (c7_i15 = 0; c7_i15 < 35; c7_i15++) {
    (*(uint8_T (*)[35])c7_outData)[c7_i15] = c7_y[c7_i15];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i16;
  uint8_T c7_b_inData[4];
  int32_T c7_i17;
  uint8_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i16 = 0; c7_i16 < 4; c7_i16++) {
    c7_b_inData[c7_i16] = (*(uint8_T (*)[4])c7_inData)[c7_i16];
  }

  for (c7_i17 = 0; c7_i17 < 4; c7_i17++) {
    c7_u[c7_i17] = c7_b_inData[c7_i17];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 3, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_f_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint8_T c7_y[4])
{
  uint8_T c7_uv5[4];
  int32_T c7_i18;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_uv5, 1, 3, 0U, 1, 0U, 2, 1, 4);
  for (c7_i18 = 0; c7_i18 < 4; c7_i18++) {
    c7_y[c7_i18] = c7_uv5[c7_i18];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_value_bytes;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y[4];
  int32_T c7_i19;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_value_bytes = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_value_bytes), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_value_bytes);
  for (c7_i19 = 0; c7_i19 < 4; c7_i19++) {
    (*(uint8_T (*)[4])c7_outData)[c7_i19] = c7_y[c7_i19];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i20;
  char_T c7_b_inData[35];
  int32_T c7_i21;
  char_T c7_u[35];
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i20 = 0; c7_i20 < 35; c7_i20++) {
    c7_b_inData[c7_i20] = (*(char_T (*)[35])c7_inData)[c7_i20];
  }

  for (c7_i21 = 0; c7_i21 < 35; c7_i21++) {
    c7_u[c7_i21] = c7_b_inData[c7_i21];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 35), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_xplane_interface_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[13];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i22;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c7_i22 = 0; c7_i22 < 13; c7_i22++) {
    c7_r0 = &c7_info[c7_i22];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i22);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i22);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[13])
{
  c7_info[0].context = "";
  c7_info[0].name = "typecast";
  c7_info[0].dominantType = "single";
  c7_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c7_info[0].fileTimeLo = 1307651236U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c7_info[1].name = "eml_float_nbits";
  c7_info[1].dominantType = "char";
  c7_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c7_info[1].fileTimeLo = 1307651242U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c7_info[2].name = "eml_float_model";
  c7_info[2].dominantType = "char";
  c7_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[2].fileTimeLo = 1307651242U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c7_info[3].name = "eml_index_rdivide";
  c7_info[3].dominantType = "int32";
  c7_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c7_info[3].fileTimeLo = 1286818780U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c7_info[4].name = "eml_index_class";
  c7_info[4].dominantType = "";
  c7_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[4].fileTimeLo = 1286818778U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c7_info[5].name = "eml_int_nbits";
  c7_info[5].dominantType = "char";
  c7_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c7_info[5].fileTimeLo = 1286818780U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c7_info[6].name = "eml_index_rdivide";
  c7_info[6].dominantType = "uint8";
  c7_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c7_info[6].fileTimeLo = 1286818780U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c7_info[7].name = "eml_index_times";
  c7_info[7].dominantType = "int32";
  c7_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[7].fileTimeLo = 1286818780U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[8].name = "eml_index_class";
  c7_info[8].dominantType = "";
  c7_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[8].fileTimeLo = 1286818778U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c7_info[9].name = "eml_index_rdivide";
  c7_info[9].dominantType = "int32";
  c7_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c7_info[9].fileTimeLo = 1286818780U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c7_info[10].name = "eml_index_class";
  c7_info[10].dominantType = "";
  c7_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[10].fileTimeLo = 1286818778U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c7_info[11].name = "eml_unsigned_class";
  c7_info[11].dominantType = "char";
  c7_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c7_info[11].fileTimeLo = 1286818800U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context = "";
  c7_info[12].name = "length";
  c7_info[12].dominantType = "char";
  c7_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[12].fileTimeLo = 1303146206U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
}

static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_g_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i23;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i23, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i23;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_xplane_interface, const
  char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_xplane_interface), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_xplane_interface);
  return c7_y;
}

static uint8_T c7_i_emlrt_marshallIn(SFc7_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_xplane_interfaceInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_xplane_interface_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2450417356U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4184852337U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3886798302U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3288737980U);
}

mxArray *sf_c7_xplane_interface_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MyjRSMkTuTZhDKNJxMGdzC");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(509);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

static const mxArray *sf_get_sim_state_info_c7_xplane_interface(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"send_msg\",},{M[8],M[0],T\"is_active_c7_xplane_interface\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_xplane_interface_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_xplane_interfaceInstanceStruct *chartInstance;
    chartInstance = (SFc7_xplane_interfaceInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_xplane_interfaceMachineNumber_,
           7,
           1,
           1,
           2,
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
          init_script_number_translation(_xplane_interfaceMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_xplane_interfaceMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_xplane_interfaceMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"value");
          _SFD_SET_DATA_PROPS(1,2,0,1,"send_msg");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,425);
        _SFD_CV_INIT_EML_FOR(0,1,0,249,259,311);
        _SFD_CV_INIT_EML_FOR(0,1,1,342,366,420);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 509;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          real_T *c7_value;
          uint8_T (*c7_send_msg)[509];
          c7_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S,
            1);
          c7_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_value);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_send_msg);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_xplane_interfaceMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "LBHD6P54cgs5aeT9W3wOn";
}

static void sf_opaque_initialize_c7_xplane_interface(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
  initialize_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_xplane_interface(void *chartInstanceVar)
{
  enable_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_xplane_interface(void *chartInstanceVar)
{
  disable_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_xplane_interface(void *chartInstanceVar)
{
  sf_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_xplane_interface(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_xplane_interface
    ((SFc7_xplane_interfaceInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_xplane_interface();/* state var info */
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

extern void sf_internal_set_sim_state_c7_xplane_interface(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_xplane_interface();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_xplane_interface(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_xplane_interface(S);
}

static void sf_opaque_set_sim_state_c7_xplane_interface(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_xplane_interface(S, st);
}

static void sf_opaque_terminate_c7_xplane_interface(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_xplane_interfaceInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_xplane_interface_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_xplane_interface(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_xplane_interface((SFc7_xplane_interfaceInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_xplane_interface(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_xplane_interface_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(872734494U));
  ssSetChecksum1(S,(3814627492U));
  ssSetChecksum2(S,(888913952U));
  ssSetChecksum3(S,(173433963U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_xplane_interface(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_xplane_interface(SimStruct *S)
{
  SFc7_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc7_xplane_interfaceInstanceStruct *)malloc(sizeof
    (SFc7_xplane_interfaceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_xplane_interfaceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_xplane_interface;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_xplane_interface;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_xplane_interface;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_xplane_interface;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_xplane_interface;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_xplane_interface;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_xplane_interface;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_xplane_interface;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_xplane_interface;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_xplane_interface;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_xplane_interface;
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

void c7_xplane_interface_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_xplane_interface(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_xplane_interface(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_xplane_interface(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_xplane_interface_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
