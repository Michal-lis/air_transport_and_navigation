/* Include files */

#include "blascompat32.h"
#include "xplane_interface2_sfun.h"
#include "c4_xplane_interface2.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "xplane_interface2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[8] = { "dataref", "value_bytes", "len",
  "dataref_bytes", "value", "nargin", "nargout", "send_msg" };

/* Function Declarations */
static void initialize_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance);
static void initialize_params_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance);
static void enable_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance);
static void disable_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance);
static void set_sim_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance);
static void sf_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance);
static void initSimStructsc4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_send_msg, const char_T *c4_identifier,
  uint8_T c4_y[509]);
static void c4_b_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[509]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real32_T c4_d_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[29]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[4]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[13]);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_h_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_xplane_interface2, const
  char_T *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_xplane_interface2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_xplane_interface2 = 0U;
}

static void initialize_params_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance)
{
}

static void enable_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  uint8_T c4_u[509];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T (*c4_send_msg)[509];
  c4_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 509; c4_i0++) {
    c4_u[c4_i0] = (*c4_send_msg)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 509),
                FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_xplane_interface2;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  uint8_T c4_uv0[509];
  int32_T c4_i1;
  uint8_T (*c4_send_msg)[509];
  c4_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "send_msg", c4_uv0);
  for (c4_i1 = 0; c4_i1 < 509; c4_i1++) {
    (*c4_send_msg)[c4_i1] = c4_uv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_xplane_interface2 = c4_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_xplane_interface2");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_xplane_interface2(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
}

static void sf_c4_xplane_interface2(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  real_T c4_hoistedGlobal;
  real_T c4_value;
  uint32_T c4_debug_family_var_map[8];
  char_T c4_dataref[29];
  uint8_T c4_value_bytes[4];
  real_T c4_len;
  uint8_T c4_dataref_bytes[29];
  real32_T c4_b_value;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  uint8_T c4_send_msg[509];
  int32_T c4_i3;
  static char_T c4_cv0[29] = { 's', 'i', 'm', '/', 'j', 'o', 'y', 's', 't', 'i',
    'c', 'k', '/', 'y', 'o', 'k', 'e', '_', 'p', 'i', 't', 'c', 'h', '_', 'r',
    'a', 't', 'i', 'o' };

  int32_T c4_i4;
  int32_T c4_i5;
  static uint8_T c4_uv1[4] = { 68U, 82U, 69U, 70U };

  real32_T c4_x;
  int32_T c4_j;
  real_T c4_b_j;
  int32_T c4_i6;
  static uint8_T c4_uv2[29] = { 115U, 105U, 109U, 47U, 106U, 111U, 121U, 115U,
    116U, 105U, 99U, 107U, 47U, 121U, 111U, 107U, 101U, 95U, 112U, 105U, 116U,
    99U, 104U, 95U, 114U, 97U, 116U, 105U, 111U };

  int32_T c4_c_j;
  int32_T c4_i7;
  real_T *c4_c_value;
  uint8_T (*c4_b_send_msg)[509];
  c4_b_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_c_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_c_value, 0U);
  for (c4_i2 = 0; c4_i2 < 509; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c4_b_send_msg)[c4_i2], 1U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_c_value;
  c4_value = c4_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c4_dataref, 0U, c4_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_value_bytes, 1U,
    c4_e_sf_marshallOut, c4_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_len, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_dataref_bytes, 3U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_value, MAX_uint32_T,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_value, 4U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_send_msg, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i3 = 0; c4_i3 < 29; c4_i3++) {
    c4_dataref[c4_i3] = c4_cv0[c4_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i4 = 0; c4_i4 < 509; c4_i4++) {
    c4_send_msg[c4_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  for (c4_i5 = 0; c4_i5 < 4; c4_i5++) {
    c4_send_msg[c4_i5] = c4_uv1[c4_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_send_msg[4] = 0U;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_b_value = (real32_T)c4_value;
  sf_debug_symbol_switch(4U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_x = c4_b_value;
  memcpy(&c4_value_bytes[0], &c4_x, 4U);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_len = 6.0;
  c4_j = 0;
  while (c4_j < 4) {
    c4_b_j = 1.0 + (real_T)c4_j;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
    c4_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c4_len), 1, 509, 1, 0) - 1] =
      c4_value_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("value_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c4_b_j), 1, 4, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
    c4_len++;
    c4_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  for (c4_i6 = 0; c4_i6 < 29; c4_i6++) {
    c4_dataref_bytes[c4_i6] = c4_uv2[c4_i6];
  }

  c4_c_j = 0;
  while (c4_c_j < 29) {
    c4_b_j = 1.0 + (real_T)c4_c_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
    c4_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c4_len), 1, 509, 1, 0) - 1] =
      c4_dataref_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("dataref_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c4_b_j), 1, 29, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
    c4_len++;
    c4_c_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  for (c4_i7 = 0; c4_i7 < 509; c4_i7++) {
    (*c4_b_send_msg)[c4_i7] = c4_send_msg[c4_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_xplane_interface2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_xplane_interface2
  (SFc4_xplane_interface2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i8;
  uint8_T c4_b_inData[509];
  int32_T c4_i9;
  uint8_T c4_u[509];
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i8 = 0; c4_i8 < 509; c4_i8++) {
    c4_b_inData[c4_i8] = (*(uint8_T (*)[509])c4_inData)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 509; c4_i9++) {
    c4_u[c4_i9] = c4_b_inData[c4_i9];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 509), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_send_msg, const char_T *c4_identifier,
  uint8_T c4_y[509])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_send_msg), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_send_msg);
}

static void c4_b_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[509])
{
  uint8_T c4_uv3[509];
  int32_T c4_i10;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv3, 1, 3, 0U, 1, 0U, 2, 1,
                509);
  for (c4_i10 = 0; c4_i10 < 509; c4_i10++) {
    c4_y[c4_i10] = c4_uv3[c4_i10];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_send_msg;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y[509];
  int32_T c4_i11;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_send_msg = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_send_msg), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_send_msg);
  for (c4_i11 = 0; c4_i11 < 509; c4_i11++) {
    (*(uint8_T (*)[509])c4_outData)[c4_i11] = c4_y[c4_i11];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real32_T c4_d_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_y;
  real32_T c4_f0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f0, 1, 1, 0U, 0, 0U, 0);
  c4_y = c4_f0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_value;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_value = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_value), &c4_thisId);
  sf_mex_destroy(&c4_value);
  *(real32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  uint8_T c4_b_inData[29];
  int32_T c4_i13;
  uint8_T c4_u[29];
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i12 = 0; c4_i12 < 29; c4_i12++) {
    c4_b_inData[c4_i12] = (*(uint8_T (*)[29])c4_inData)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 29; c4_i13++) {
    c4_u[c4_i13] = c4_b_inData[c4_i13];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 29), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[29])
{
  uint8_T c4_uv4[29];
  int32_T c4_i14;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 3, 0U, 1, 0U, 2, 1, 29);
  for (c4_i14 = 0; c4_i14 < 29; c4_i14++) {
    c4_y[c4_i14] = c4_uv4[c4_i14];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_dataref_bytes;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y[29];
  int32_T c4_i15;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_dataref_bytes = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dataref_bytes), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_dataref_bytes);
  for (c4_i15 = 0; c4_i15 < 29; c4_i15++) {
    (*(uint8_T (*)[29])c4_outData)[c4_i15] = c4_y[c4_i15];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i16;
  uint8_T c4_b_inData[4];
  int32_T c4_i17;
  uint8_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i16 = 0; c4_i16 < 4; c4_i16++) {
    c4_b_inData[c4_i16] = (*(uint8_T (*)[4])c4_inData)[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
    c4_u[c4_i17] = c4_b_inData[c4_i17];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[4])
{
  uint8_T c4_uv5[4];
  int32_T c4_i18;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv5, 1, 3, 0U, 1, 0U, 2, 1, 4);
  for (c4_i18 = 0; c4_i18 < 4; c4_i18++) {
    c4_y[c4_i18] = c4_uv5[c4_i18];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_value_bytes;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y[4];
  int32_T c4_i19;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_value_bytes = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_value_bytes), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_value_bytes);
  for (c4_i19 = 0; c4_i19 < 4; c4_i19++) {
    (*(uint8_T (*)[4])c4_outData)[c4_i19] = c4_y[c4_i19];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i20;
  char_T c4_b_inData[29];
  int32_T c4_i21;
  char_T c4_u[29];
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i20 = 0; c4_i20 < 29; c4_i20++) {
    c4_b_inData[c4_i20] = (*(char_T (*)[29])c4_inData)[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 29; c4_i21++) {
    c4_u[c4_i21] = c4_b_inData[c4_i21];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 29), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_xplane_interface2_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[13];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i22;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c4_i22 = 0; c4_i22 < 13; c4_i22++) {
    c4_r0 = &c4_info[c4_i22];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i22);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i22);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[13])
{
  c4_info[0].context = "";
  c4_info[0].name = "typecast";
  c4_info[0].dominantType = "single";
  c4_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c4_info[0].fileTimeLo = 1307651236U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 0U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c4_info[1].name = "eml_float_nbits";
  c4_info[1].dominantType = "char";
  c4_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c4_info[1].fileTimeLo = 1307651242U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c4_info[2].name = "eml_float_model";
  c4_info[2].dominantType = "char";
  c4_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c4_info[2].fileTimeLo = 1307651242U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c4_info[3].name = "eml_index_rdivide";
  c4_info[3].dominantType = "int32";
  c4_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c4_info[3].fileTimeLo = 1286818780U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c4_info[4].name = "eml_index_class";
  c4_info[4].dominantType = "";
  c4_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[4].fileTimeLo = 1286818778U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c4_info[5].name = "eml_int_nbits";
  c4_info[5].dominantType = "char";
  c4_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c4_info[5].fileTimeLo = 1286818780U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c4_info[6].name = "eml_index_rdivide";
  c4_info[6].dominantType = "uint8";
  c4_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c4_info[6].fileTimeLo = 1286818780U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c4_info[7].name = "eml_index_times";
  c4_info[7].dominantType = "int32";
  c4_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c4_info[7].fileTimeLo = 1286818780U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c4_info[8].name = "eml_index_class";
  c4_info[8].dominantType = "";
  c4_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[8].fileTimeLo = 1286818778U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c4_info[9].name = "eml_index_rdivide";
  c4_info[9].dominantType = "int32";
  c4_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c4_info[9].fileTimeLo = 1286818780U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c4_info[10].name = "eml_index_class";
  c4_info[10].dominantType = "";
  c4_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[10].fileTimeLo = 1286818778U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c4_info[11].name = "eml_unsigned_class";
  c4_info[11].dominantType = "char";
  c4_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c4_info[11].fileTimeLo = 1286818800U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context = "";
  c4_info[12].name = "length";
  c4_info[12].dominantType = "char";
  c4_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/length.m";
  c4_info[12].fileTimeLo = 1303146206U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i23;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i23, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i23;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_xplane_interface2, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_xplane_interface2), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_xplane_interface2);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_xplane_interface2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_xplane_interface2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3292265511U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3943971388U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2473449797U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1132919053U);
}

mxArray *sf_c4_xplane_interface2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y1JOoYAhxKpuHImjc3NIqH");
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

static const mxArray *sf_get_sim_state_info_c4_xplane_interface2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"send_msg\",},{M[8],M[0],T\"is_active_c4_xplane_interface2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_xplane_interface2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_xplane_interface2InstanceStruct *chartInstance;
    chartInstance = (SFc4_xplane_interface2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_xplane_interface2MachineNumber_,
           4,
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
          init_script_number_translation(_xplane_interface2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_xplane_interface2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_xplane_interface2MachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,419);
        _SFD_CV_INIT_EML_FOR(0,1,0,243,253,305);
        _SFD_CV_INIT_EML_FOR(0,1,1,336,360,414);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 509;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T *c4_value;
          uint8_T (*c4_send_msg)[509];
          c4_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S,
            1);
          c4_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_value);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_send_msg);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_xplane_interface2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "I3O0H6MBmdFICYeFLsjsAC";
}

static void sf_opaque_initialize_c4_xplane_interface2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
  initialize_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_xplane_interface2(void *chartInstanceVar)
{
  enable_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_xplane_interface2(void *chartInstanceVar)
{
  disable_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_xplane_interface2(void *chartInstanceVar)
{
  sf_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_xplane_interface2(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_xplane_interface2
    ((SFc4_xplane_interface2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_xplane_interface2();/* state var info */
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

extern void sf_internal_set_sim_state_c4_xplane_interface2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_xplane_interface2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_xplane_interface2(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_xplane_interface2(S);
}

static void sf_opaque_set_sim_state_c4_xplane_interface2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_xplane_interface2(S, st);
}

static void sf_opaque_terminate_c4_xplane_interface2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_xplane_interface2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_xplane_interface2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_xplane_interface2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_xplane_interface2((SFc4_xplane_interface2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_xplane_interface2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_xplane_interface2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1056389495U));
  ssSetChecksum1(S,(38930454U));
  ssSetChecksum2(S,(3107663532U));
  ssSetChecksum3(S,(2770574119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_xplane_interface2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_xplane_interface2(SimStruct *S)
{
  SFc4_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc4_xplane_interface2InstanceStruct *)malloc(sizeof
    (SFc4_xplane_interface2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_xplane_interface2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_xplane_interface2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_xplane_interface2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_xplane_interface2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_xplane_interface2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_xplane_interface2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_xplane_interface2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_xplane_interface2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_xplane_interface2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_xplane_interface2;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_xplane_interface2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_xplane_interface2;
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

void c4_xplane_interface2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_xplane_interface2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_xplane_interface2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_xplane_interface2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_xplane_interface2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
