/* Include files */

#include "blascompat32.h"
#include "xplane_interface2_sfun.h"
#include "c1_xplane_interface2.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "xplane_interface2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[8] = { "dataref", "value_bytes", "len",
  "dataref_bytes", "nargin", "nargout", "value", "send_msg" };

/* Function Declarations */
static void initialize_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance);
static void initialize_params_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance);
static void enable_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance);
static void disable_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance);
static void set_sim_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance);
static void sf_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance);
static void initSimStructsc1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_send_msg, const char_T *c1_identifier,
  uint8_T c1_y[509]);
static void c1_b_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[509]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[40]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_value_bytes, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void init_dsm_address_info(SFc1_xplane_interface2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_xplane_interface2 = 0U;
}

static void initialize_params_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance)
{
}

static void enable_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  uint8_T c1_u[509];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T (*c1_send_msg)[509];
  c1_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 509; c1_i0++) {
    c1_u[c1_i0] = (*c1_send_msg)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 2, 1, 509),
                FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_xplane_interface2;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  uint8_T c1_uv0[509];
  int32_T c1_i1;
  uint8_T (*c1_send_msg)[509];
  c1_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "send_msg", c1_uv0);
  for (c1_i1 = 0; c1_i1 < 509; c1_i1++) {
    (*c1_send_msg)[c1_i1] = c1_uv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_xplane_interface2 = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_xplane_interface2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_xplane_interface2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
}

static void sf_c1_xplane_interface2(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_value;
  uint32_T c1_debug_family_var_map[8];
  char_T c1_dataref[40];
  uint8_T c1_value_bytes;
  real_T c1_len;
  uint8_T c1_dataref_bytes[40];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  uint8_T c1_send_msg[509];
  int32_T c1_i3;
  static char_T c1_cv0[40] = { 's', 'i', 'm', '/', 'o', 'p', 'e', 'r', 'a', 't',
    'i', 'o', 'n', '/', 'o', 'v', 'e', 'r', 'r', 'i', 'd', 'e', '/', 'o', 'v',
    'e', 'r', 'r', 'i', 'd', 'e', '_', 'j', 'o', 'y', 's', 't', 'i', 'c', 'k' };

  int32_T c1_i4;
  int32_T c1_i5;
  static uint8_T c1_uv1[4] = { 68U, 82U, 69U, 70U };

  uint8_T c1_x;
  int32_T c1_i6;
  static uint8_T c1_uv2[40] = { 115U, 105U, 109U, 47U, 111U, 112U, 101U, 114U,
    97U, 116U, 105U, 111U, 110U, 47U, 111U, 118U, 101U, 114U, 114U, 105U, 100U,
    101U, 47U, 111U, 118U, 101U, 114U, 114U, 105U, 100U, 101U, 95U, 106U, 111U,
    121U, 115U, 116U, 105U, 99U, 107U };

  int32_T c1_j;
  real_T c1_b_j;
  int32_T c1_i7;
  uint8_T *c1_b_value;
  uint8_T (*c1_b_send_msg)[509];
  c1_b_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_value = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_value, 0U);
  for (c1_i2 = 0; c1_i2 < 509; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_send_msg)[c1_i2], 1U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_value;
  c1_value = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c1_dataref, 0U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_value_bytes, 1U,
    c1_b_sf_marshallOut, c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_len, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_dataref_bytes, 3U,
    c1_d_sf_marshallOut, c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 5U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_value, 6U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_send_msg, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i3 = 0; c1_i3 < 40; c1_i3++) {
    c1_dataref[c1_i3] = c1_cv0[c1_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i4 = 0; c1_i4 < 509; c1_i4++) {
    c1_send_msg[c1_i4] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_send_msg[c1_i5] = c1_uv1[c1_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_send_msg[4] = 0U;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_x = c1_value;
  memcpy(&c1_value_bytes, &c1_x, 1U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_send_msg[8] = c1_value_bytes;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_len = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  for (c1_i6 = 0; c1_i6 < 40; c1_i6++) {
    c1_dataref_bytes[c1_i6] = c1_uv2[c1_i6];
  }

  c1_j = 0;
  while (c1_j < 40) {
    c1_b_j = 1.0 + (real_T)c1_j;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
    c1_send_msg[_SFD_EML_ARRAY_BOUNDS_CHECK("send_msg", (int32_T)
      _SFD_INTEGER_CHECK("len", c1_len), 1, 509, 1, 0) - 1] =
      c1_dataref_bytes[_SFD_EML_ARRAY_BOUNDS_CHECK("dataref_bytes", (int32_T)
      _SFD_INTEGER_CHECK("j", c1_b_j), 1, 40, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_len++;
    c1_j++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -17);
  sf_debug_symbol_scope_pop();
  for (c1_i7 = 0; c1_i7 < 509; c1_i7++) {
    (*c1_b_send_msg)[c1_i7] = c1_send_msg[c1_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_xplane_interface2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_xplane_interface2
  (SFc1_xplane_interface2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i8;
  uint8_T c1_b_inData[509];
  int32_T c1_i9;
  uint8_T c1_u[509];
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i8 = 0; c1_i8 < 509; c1_i8++) {
    c1_b_inData[c1_i8] = (*(uint8_T (*)[509])c1_inData)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 509; c1_i9++) {
    c1_u[c1_i9] = c1_b_inData[c1_i9];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 2, 1, 509), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_send_msg, const char_T *c1_identifier,
  uint8_T c1_y[509])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_send_msg), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_send_msg);
}

static void c1_b_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[509])
{
  uint8_T c1_uv3[509];
  int32_T c1_i10;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv3, 1, 3, 0U, 1, 0U, 2, 1,
                509);
  for (c1_i10 = 0; c1_i10 < 509; c1_i10++) {
    c1_y[c1_i10] = c1_uv3[c1_i10];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_send_msg;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y[509];
  int32_T c1_i11;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_send_msg = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_send_msg), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_send_msg);
  for (c1_i11 = 0; c1_i11 < 509; c1_i11++) {
    (*(uint8_T (*)[509])c1_outData)[c1_i11] = c1_y[c1_i11];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i12;
  uint8_T c1_b_inData[40];
  int32_T c1_i13;
  uint8_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i12 = 0; c1_i12 < 40; c1_i12++) {
    c1_b_inData[c1_i12] = (*(uint8_T (*)[40])c1_inData)[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 40; c1_i13++) {
    c1_u[c1_i13] = c1_b_inData[c1_i13];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 2, 1, 40), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[40])
{
  uint8_T c1_uv4[40];
  int32_T c1_i14;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 3, 0U, 1, 0U, 2, 1, 40);
  for (c1_i14 = 0; c1_i14 < 40; c1_i14++) {
    c1_y[c1_i14] = c1_uv4[c1_i14];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dataref_bytes;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y[40];
  int32_T c1_i15;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_dataref_bytes = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dataref_bytes), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_dataref_bytes);
  for (c1_i15 = 0; c1_i15 < 40; c1_i15++) {
    (*(uint8_T (*)[40])c1_outData)[c1_i15] = c1_y[c1_i15];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_value_bytes, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_value_bytes),
    &c1_thisId);
  sf_mex_destroy(&c1_value_bytes);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_value_bytes;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_value_bytes = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_value_bytes),
    &c1_thisId);
  sf_mex_destroy(&c1_value_bytes);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i16;
  char_T c1_b_inData[40];
  int32_T c1_i17;
  char_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i16 = 0; c1_i16 < 40; c1_i16++) {
    c1_b_inData[c1_i16] = (*(char_T (*)[40])c1_inData)[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 40; c1_i17++) {
    c1_u[c1_i17] = c1_b_inData[c1_i17];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 40), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_xplane_interface2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[10];
  c1_ResolvedFunctionInfo (*c1_b_info)[10];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i18;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[10])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "typecast";
  (*c1_b_info)[0].dominantType = "uint8";
  (*c1_b_info)[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c1_b_info)[0].fileTimeLo = 1307651236U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c1_b_info)[1].name = "eml_int_nbits";
  (*c1_b_info)[1].dominantType = "char";
  (*c1_b_info)[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  (*c1_b_info)[1].fileTimeLo = 1286818780U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c1_b_info)[2].name = "eml_index_rdivide";
  (*c1_b_info)[2].dominantType = "uint8";
  (*c1_b_info)[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c1_b_info)[2].fileTimeLo = 1286818780U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c1_b_info)[3].name = "eml_index_class";
  (*c1_b_info)[3].dominantType = "";
  (*c1_b_info)[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[3].fileTimeLo = 1286818778U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c1_b_info)[4].name = "eml_index_times";
  (*c1_b_info)[4].dominantType = "int32";
  (*c1_b_info)[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c1_b_info)[4].fileTimeLo = 1286818780U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c1_b_info)[5].name = "eml_index_class";
  (*c1_b_info)[5].dominantType = "";
  (*c1_b_info)[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[5].fileTimeLo = 1286818778U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c1_b_info)[6].name = "eml_index_rdivide";
  (*c1_b_info)[6].dominantType = "int32";
  (*c1_b_info)[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c1_b_info)[6].fileTimeLo = 1286818780U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c1_b_info)[7].name = "eml_index_class";
  (*c1_b_info)[7].dominantType = "";
  (*c1_b_info)[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[7].fileTimeLo = 1286818778U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c1_b_info)[8].name = "eml_unsigned_class";
  (*c1_b_info)[8].dominantType = "char";
  (*c1_b_info)[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  (*c1_b_info)[8].fileTimeLo = 1286818800U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  (*c1_b_info)[9].context = "";
  (*c1_b_info)[9].name = "length";
  (*c1_b_info)[9].dominantType = "char";
  (*c1_b_info)[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/length.m";
  (*c1_b_info)[9].fileTimeLo = 1303146206U;
  (*c1_b_info)[9].fileTimeHi = 0U;
  (*c1_b_info)[9].mFileTimeLo = 0U;
  (*c1_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c1_i18 = 0; c1_i18 < 10; c1_i18++) {
    c1_r0 = &c1_info[c1_i18];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i18);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i18);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn(SFc1_xplane_interface2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i19;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i19, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i19;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void init_dsm_address_info(SFc1_xplane_interface2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_xplane_interface2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(400831133U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2553266488U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3134792965U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(236532312U);
}

mxArray *sf_c1_xplane_interface2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1Cmcrz5Oj0KMvWS45ZftIC");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

static const mxArray *sf_get_sim_state_info_c1_xplane_interface2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"send_msg\",},{M[8],M[0],T\"is_active_c1_xplane_interface2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_xplane_interface2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_xplane_interface2InstanceStruct *chartInstance;
    chartInstance = (SFc1_xplane_interface2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_xplane_interface2MachineNumber_,
           1,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,372);
        _SFD_CV_INIT_EML_FOR(0,1,0,289,313,367);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 509;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          uint8_T *c1_value;
          uint8_T (*c1_send_msg)[509];
          c1_send_msg = (uint8_T (*)[509])ssGetOutputPortSignal(chartInstance->S,
            1);
          c1_value = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_value);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_send_msg);
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
  return "5g9EcUT96AhEPMWbZOBDqB";
}

static void sf_opaque_initialize_c1_xplane_interface2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
  initialize_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_xplane_interface2(void *chartInstanceVar)
{
  enable_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_xplane_interface2(void *chartInstanceVar)
{
  disable_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_xplane_interface2(void *chartInstanceVar)
{
  sf_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_xplane_interface2(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_xplane_interface2
    ((SFc1_xplane_interface2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_xplane_interface2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_xplane_interface2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_xplane_interface2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_xplane_interface2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_xplane_interface2(S);
}

static void sf_opaque_set_sim_state_c1_xplane_interface2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_xplane_interface2(S, st);
}

static void sf_opaque_terminate_c1_xplane_interface2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_xplane_interface2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_xplane_interface2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_xplane_interface2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_xplane_interface2((SFc1_xplane_interface2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_xplane_interface2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_xplane_interface2_optimization_info();
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
  ssSetChecksum0(S,(50932239U));
  ssSetChecksum1(S,(1455931722U));
  ssSetChecksum2(S,(2265247182U));
  ssSetChecksum3(S,(2378613970U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_xplane_interface2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_xplane_interface2(SimStruct *S)
{
  SFc1_xplane_interface2InstanceStruct *chartInstance;
  chartInstance = (SFc1_xplane_interface2InstanceStruct *)malloc(sizeof
    (SFc1_xplane_interface2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_xplane_interface2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_xplane_interface2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_xplane_interface2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_xplane_interface2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_xplane_interface2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_xplane_interface2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_xplane_interface2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_xplane_interface2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_xplane_interface2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_xplane_interface2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_xplane_interface2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_xplane_interface2;
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

void c1_xplane_interface2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_xplane_interface2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_xplane_interface2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_xplane_interface2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_xplane_interface2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
