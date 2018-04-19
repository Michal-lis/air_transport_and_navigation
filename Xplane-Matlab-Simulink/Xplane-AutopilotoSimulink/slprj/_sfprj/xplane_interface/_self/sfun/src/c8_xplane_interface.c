/* Include files */

#include "blascompat32.h"
#include "xplane_interface_sfun.h"
#include "c8_xplane_interface.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "xplane_interface_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[8] = { "dataref", "value_bytes", "len",
  "dataref_bytes", "value", "nargin", "nargout", "send_msg" };

/* Function Declarations */
static void initialize_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);
static void initialize_params_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance);
static void enable_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);
static void disable_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance);
static void set_sim_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance, const mxArray *c8_st);
static void finalize_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);
static void sf_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);
static void initSimStructsc8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_send_msg, const char_T *c8_identifier,
  uint8_T c8_y[509]);
static void c8_b_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[509]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real32_T c8_d_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[33]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_f_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[4]);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[13]);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_g_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_h_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_xplane_interface, const
  char_T *c8_identifier);
static uint8_T c8_i_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_xplane_interfaceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_xplane_interface = 0U;
}

static void initialize_params_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance)
{
}

static void enable_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  uint8_T c8_u[509];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T (*c8_send_msg)[509];
  c8_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
  for (c8_i0 = 0; c8_i0 < 509; c8_i0++) {
    c8_u[c8_i0] = (*c8_send_msg)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 3, 0U, 1U, 0U, 2, 1, 509),
                FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_xplane_interface;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  uint8_T c8_uv0[509];
  int32_T c8_i1;
  uint8_T (*c8_send_msg)[509];
  c8_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "send_msg", c8_uv0);
  for (c8_i1 = 0; c8_i1 < 509; c8_i1++) {
    (*c8_send_msg)[c8_i1] = c8_uv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_xplane_interface = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_xplane_interface");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_xplane_interface(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
}

static void sf_c8_xplane_interface(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
  int32_T c8_i2;
  real_T c8_hoistedGlobal;
  real_T c8_value;
  uint32_T c8_debug_family_var_map[8];
  char_T c8_dataref[33];
  uint8_T c8_value_bytes[4];
  real_T c8_len;
  uint8_T c8_dataref_bytes[33];
  real32_T c8_b_value;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  uint8_T c8_send_msg[509];
  int32_T c8_i3;
  static char_T c8_cv0[33] = { 's', 'i', 'm', '/', 'f', 'l', 'i', 'g', 'h', 't',
    'm', 'o', 'd', 'e', 'l', '/', 'c', 'o', 'n', 't', 'r', 'o', 'l', 's', '/',
    'f', 'l', 'a', 'p', 'r', 'q', 's', 't' };

  int32_T c8_i4;
  int32_T c8_i5;
  static uint8_T c8_uv1[4] = { 68U, 82U, 69U, 70U };

  real32_T c8_x;
  int32_T c8_j;
  real_T c8_b_j;
  int32_T c8_i6;
  static uint8_T c8_uv2[33] = { 115U, 105U, 109U, 47U, 102U, 108U, 105U, 103U,
    104U, 116U, 109U, 111U, 100U, 101U, 108U, 47U, 99U, 111U, 110U, 116U, 114U,
    111U, 108U, 115U, 47U, 102U, 108U, 97U, 112U, 114U, 113U, 115U, 116U };

  int32_T c8_c_j;
  int32_T c8_i7;
  real_T *c8_c_value;
  uint8_T (*c8_b_send_msg)[509];
  c8_b_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_c_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_c_value, 0U);
  for (c8_i2 = 0; c8_i2 < 509; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c8_b_send_msg)[c8_i2], 1U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_c_value;
  c8_value = c8_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 9U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_dataref, 0U, c8_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_value_bytes, 1U,
    c8_e_sf_marshallOut, c8_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_len, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c8_dataref_bytes, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_value, MAX_uint32_T,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_value, 4U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_send_msg, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  for (c8_i3 = 0; c8_i3 < 33; c8_i3++) {
    c8_dataref[c8_i3] = c8_cv0[c8_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i4 = 0; c8_i4 < 509; c8_i4++) {
    c8_send_msg[c8_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 7);
  for (c8_i5 = 0; c8_i5 < 4; c8_i5++) {
    c8_send_msg[c8_i5] = c8_uv1[c8_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_send_msg[4] = 0U;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_b_value = (real32_T)c8_value;
  sf_debug_symbol_switch(4U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  c8_x = c8_b_value;
  memcpy(&c8_value_bytes[0], &c8_x, 4U);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 12);
  c8_len = 6.0;
  c8_j = 0;
  while (c8_j < 4) {
    c8_b_j = 1.0 + (real_T)c8_j;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
    c8_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c8_len), 1, 509, 1, 0) - 1] =
      c8_value_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("value_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c8_b_j), 1, 4, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
    c8_len++;
    c8_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  for (c8_i6 = 0; c8_i6 < 33; c8_i6++) {
    c8_dataref_bytes[c8_i6] = c8_uv2[c8_i6];
  }

  c8_c_j = 0;
  while (c8_c_j < 33) {
    c8_b_j = 1.0 + (real_T)c8_c_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 19);
    c8_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c8_len), 1, 509, 1, 0) - 1] =
      c8_dataref_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("dataref_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c8_b_j), 1, 33, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
    c8_len++;
    c8_c_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  for (c8_i7 = 0; c8_i7 < 509; c8_i7++) {
    (*c8_b_send_msg)[c8_i7] = c8_send_msg[c8_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency(_xplane_interfaceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_xplane_interface
  (SFc8_xplane_interfaceInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i8;
  uint8_T c8_b_inData[509];
  int32_T c8_i9;
  uint8_T c8_u[509];
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i8 = 0; c8_i8 < 509; c8_i8++) {
    c8_b_inData[c8_i8] = (*(uint8_T (*)[509])c8_inData)[c8_i8];
  }

  for (c8_i9 = 0; c8_i9 < 509; c8_i9++) {
    c8_u[c8_i9] = c8_b_inData[c8_i9];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 3, 0U, 1U, 0U, 2, 1, 509), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_send_msg, const char_T *c8_identifier,
  uint8_T c8_y[509])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_send_msg), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_send_msg);
}

static void c8_b_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[509])
{
  uint8_T c8_uv3[509];
  int32_T c8_i10;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_uv3, 1, 3, 0U, 1, 0U, 2, 1,
                509);
  for (c8_i10 = 0; c8_i10 < 509; c8_i10++) {
    c8_y[c8_i10] = c8_uv3[c8_i10];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_send_msg;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y[509];
  int32_T c8_i11;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_send_msg = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_send_msg), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_send_msg);
  for (c8_i11 = 0; c8_i11 < 509; c8_i11++) {
    (*(uint8_T (*)[509])c8_outData)[c8_i11] = c8_y[c8_i11];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real32_T c8_d_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real32_T c8_y;
  real32_T c8_f0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_f0, 1, 1, 0U, 0, 0U, 0);
  c8_y = c8_f0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_value;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real32_T c8_y;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_value = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_value), &c8_thisId);
  sf_mex_destroy(&c8_value);
  *(real32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i12;
  uint8_T c8_b_inData[33];
  int32_T c8_i13;
  uint8_T c8_u[33];
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i12 = 0; c8_i12 < 33; c8_i12++) {
    c8_b_inData[c8_i12] = (*(uint8_T (*)[33])c8_inData)[c8_i12];
  }

  for (c8_i13 = 0; c8_i13 < 33; c8_i13++) {
    c8_u[c8_i13] = c8_b_inData[c8_i13];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 3, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[33])
{
  uint8_T c8_uv4[33];
  int32_T c8_i14;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_uv4, 1, 3, 0U, 1, 0U, 2, 1, 33);
  for (c8_i14 = 0; c8_i14 < 33; c8_i14++) {
    c8_y[c8_i14] = c8_uv4[c8_i14];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_dataref_bytes;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y[33];
  int32_T c8_i15;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_dataref_bytes = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_dataref_bytes), &c8_thisId,
                        c8_y);
  sf_mex_destroy(&c8_dataref_bytes);
  for (c8_i15 = 0; c8_i15 < 33; c8_i15++) {
    (*(uint8_T (*)[33])c8_outData)[c8_i15] = c8_y[c8_i15];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i16;
  uint8_T c8_b_inData[4];
  int32_T c8_i17;
  uint8_T c8_u[4];
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i16 = 0; c8_i16 < 4; c8_i16++) {
    c8_b_inData[c8_i16] = (*(uint8_T (*)[4])c8_inData)[c8_i16];
  }

  for (c8_i17 = 0; c8_i17 < 4; c8_i17++) {
    c8_u[c8_i17] = c8_b_inData[c8_i17];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 3, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_f_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  uint8_T c8_y[4])
{
  uint8_T c8_uv5[4];
  int32_T c8_i18;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_uv5, 1, 3, 0U, 1, 0U, 2, 1, 4);
  for (c8_i18 = 0; c8_i18 < 4; c8_i18++) {
    c8_y[c8_i18] = c8_uv5[c8_i18];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_value_bytes;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y[4];
  int32_T c8_i19;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_value_bytes = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_value_bytes), &c8_thisId,
                        c8_y);
  sf_mex_destroy(&c8_value_bytes);
  for (c8_i19 = 0; c8_i19 < 4; c8_i19++) {
    (*(uint8_T (*)[4])c8_outData)[c8_i19] = c8_y[c8_i19];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i20;
  char_T c8_b_inData[33];
  int32_T c8_i21;
  char_T c8_u[33];
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i20 = 0; c8_i20 < 33; c8_i20++) {
    c8_b_inData[c8_i20] = (*(char_T (*)[33])c8_inData)[c8_i20];
  }

  for (c8_i21 = 0; c8_i21 < 33; c8_i21++) {
    c8_u[c8_i21] = c8_b_inData[c8_i21];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

const mxArray *sf_c8_xplane_interface_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[13];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i22;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c8_i22 = 0; c8_i22 < 13; c8_i22++) {
    c8_r0 = &c8_info[c8_i22];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i22);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i22);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[13])
{
  c8_info[0].context = "";
  c8_info[0].name = "typecast";
  c8_info[0].dominantType = "single";
  c8_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c8_info[0].fileTimeLo = 1307651236U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c8_info[1].name = "eml_float_nbits";
  c8_info[1].dominantType = "char";
  c8_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c8_info[1].fileTimeLo = 1307651242U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c8_info[2].name = "eml_float_model";
  c8_info[2].dominantType = "char";
  c8_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[2].fileTimeLo = 1307651242U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c8_info[3].name = "eml_index_rdivide";
  c8_info[3].dominantType = "int32";
  c8_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c8_info[3].fileTimeLo = 1286818780U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c8_info[4].name = "eml_index_class";
  c8_info[4].dominantType = "";
  c8_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[4].fileTimeLo = 1286818778U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c8_info[5].name = "eml_int_nbits";
  c8_info[5].dominantType = "char";
  c8_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c8_info[5].fileTimeLo = 1286818780U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c8_info[6].name = "eml_index_rdivide";
  c8_info[6].dominantType = "uint8";
  c8_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c8_info[6].fileTimeLo = 1286818780U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c8_info[7].name = "eml_index_times";
  c8_info[7].dominantType = "int32";
  c8_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[7].fileTimeLo = 1286818780U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[8].name = "eml_index_class";
  c8_info[8].dominantType = "";
  c8_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[8].fileTimeLo = 1286818778U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c8_info[9].name = "eml_index_rdivide";
  c8_info[9].dominantType = "int32";
  c8_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c8_info[9].fileTimeLo = 1286818780U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c8_info[10].name = "eml_index_class";
  c8_info[10].dominantType = "";
  c8_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[10].fileTimeLo = 1286818778U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c8_info[11].name = "eml_unsigned_class";
  c8_info[11].dominantType = "char";
  c8_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c8_info[11].fileTimeLo = 1286818800U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context = "";
  c8_info[12].name = "length";
  c8_info[12].dominantType = "char";
  c8_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[12].fileTimeLo = 1303146206U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_g_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i23;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i23, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i23;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_xplane_interface, const
  char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_xplane_interface), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_xplane_interface);
  return c8_y;
}

static uint8_T c8_i_emlrt_marshallIn(SFc8_xplane_interfaceInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_xplane_interfaceInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_xplane_interface_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(715438138U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1973480065U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(589810427U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1803147239U);
}

mxArray *sf_c8_xplane_interface_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("y7PgmeyFQGmuSkcKlynFHC");
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

static const mxArray *sf_get_sim_state_info_c8_xplane_interface(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"send_msg\",},{M[8],M[0],T\"is_active_c8_xplane_interface\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_xplane_interface_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_xplane_interfaceInstanceStruct *chartInstance;
    chartInstance = (SFc8_xplane_interfaceInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_xplane_interfaceMachineNumber_,
           8,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,423);
        _SFD_CV_INIT_EML_FOR(0,1,0,247,257,309);
        _SFD_CV_INIT_EML_FOR(0,1,1,340,364,418);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 509;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          real_T *c8_value;
          uint8_T (*c8_send_msg)[509];
          c8_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S,
            1);
          c8_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_value);
          _SFD_SET_DATA_VALUE_PTR(1U, *c8_send_msg);
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
  return "t9UJGsbJ6pWctgq52ZJ1GD";
}

static void sf_opaque_initialize_c8_xplane_interface(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
  initialize_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_xplane_interface(void *chartInstanceVar)
{
  enable_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_xplane_interface(void *chartInstanceVar)
{
  disable_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_xplane_interface(void *chartInstanceVar)
{
  sf_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_xplane_interface(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_xplane_interface
    ((SFc8_xplane_interfaceInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_xplane_interface();/* state var info */
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

extern void sf_internal_set_sim_state_c8_xplane_interface(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_xplane_interface();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_xplane_interface(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_xplane_interface(S);
}

static void sf_opaque_set_sim_state_c8_xplane_interface(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c8_xplane_interface(S, st);
}

static void sf_opaque_terminate_c8_xplane_interface(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_xplane_interfaceInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_xplane_interface_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_xplane_interface(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_xplane_interface((SFc8_xplane_interfaceInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_xplane_interface(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_xplane_interface_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3730431625U));
  ssSetChecksum1(S,(788666608U));
  ssSetChecksum2(S,(1769889658U));
  ssSetChecksum3(S,(1834719243U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_xplane_interface(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_xplane_interface(SimStruct *S)
{
  SFc8_xplane_interfaceInstanceStruct *chartInstance;
  chartInstance = (SFc8_xplane_interfaceInstanceStruct *)malloc(sizeof
    (SFc8_xplane_interfaceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_xplane_interfaceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_xplane_interface;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_xplane_interface;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_xplane_interface;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_xplane_interface;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_xplane_interface;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_xplane_interface;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_xplane_interface;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_xplane_interface;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_xplane_interface;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_xplane_interface;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_xplane_interface;
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

void c8_xplane_interface_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_xplane_interface(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_xplane_interface(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_xplane_interface(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_xplane_interface_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
