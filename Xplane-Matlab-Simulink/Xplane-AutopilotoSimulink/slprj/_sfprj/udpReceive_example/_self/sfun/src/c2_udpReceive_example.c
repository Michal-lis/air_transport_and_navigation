/* Include files */

#include "blascompat32.h"
#include "udpReceive_example_sfun.h"
#include "c2_udpReceive_example.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "udpReceive_example_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[33] = { "index", "data", "n", "nargin",
  "nargout", "recv_data", "numbytes", "airspeed", "pitch_rate", "roll_rate",
  "yaw_rate", "pitch", "roll", "heading", "alpha", "beta", "vpath", "lat", "lon",
  "alt", "airspeed_ant", "pitch_rate_ant", "roll_rate_ant", "yaw_rate_ant",
  "pitch_ant", "roll_ant", "heading_ant", "alpha_ant", "beta_ant", "vpath_ant",
  "lat_ant", "lon_ant", "alt_ant" };

static const char * c2_b_debug_family_names[13] = { "i", "j", "index_bytes",
  "index_aux", "data_bytes", "data_aux", "data", "nargin", "nargout",
  "recv_data", "numbytes", "index", "n" };

/* Function Declarations */
static void initialize_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static void initialize_params_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static void enable_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance);
static void disable_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct *
  chartInstance);
static void c2_update_debugger_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static void set_sim_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance);
static void sf_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static void initSimStructsc2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_alt_ant, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_lon_ant, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_lat_ant, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_vpath_ant, const char_T *c2_identifier);
static real_T c2_h_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_i_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_beta_ant, const char_T *c2_identifier);
static real_T c2_j_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_k_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_alpha_ant, const char_T *c2_identifier);
static real_T c2_l_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_m_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_heading_ant, const char_T *c2_identifier);
static real_T c2_n_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_o_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_roll_ant, const char_T *c2_identifier);
static real_T c2_p_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_q_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_pitch_ant, const char_T *c2_identifier);
static real_T c2_r_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_s_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_yaw_rate_ant, const char_T *c2_identifier);
static real_T c2_t_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_u_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_roll_rate_ant, const char_T *c2_identifier);
static real_T c2_v_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_w_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_pitch_rate_ant, const char_T
  *c2_identifier);
static real_T c2_x_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_y_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_airspeed_ant, const char_T *c2_identifier);
static real_T c2_ab_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_bb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_alt, const char_T *c2_identifier);
static real_T c2_cb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_db_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[200]);
static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_eb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[20]);
static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_fb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_gb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[1085]);
static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_hb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y[200]);
static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real32_T c2_ib_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_jb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[4]);
static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15]);
static void c2_UDPreceiveDATA(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, int8_T c2_recv_data[1085], uint32_T c2_numbytes, uint32_T
  c2_index[20], real_T c2_data[200], real_T *c2_n);
static void c2_eml_int_forloop_overflow_check
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance, uint32_T c2_b);
static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_kb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_lb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_udpReceive_example, const
  char_T *c2_identifier);
static uint8_T c2_mb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_airspeed_ant_not_empty = FALSE;
  chartInstance->c2_pitch_rate_ant_not_empty = FALSE;
  chartInstance->c2_roll_rate_ant_not_empty = FALSE;
  chartInstance->c2_yaw_rate_ant_not_empty = FALSE;
  chartInstance->c2_pitch_ant_not_empty = FALSE;
  chartInstance->c2_roll_ant_not_empty = FALSE;
  chartInstance->c2_heading_ant_not_empty = FALSE;
  chartInstance->c2_alpha_ant_not_empty = FALSE;
  chartInstance->c2_beta_ant_not_empty = FALSE;
  chartInstance->c2_vpath_ant_not_empty = FALSE;
  chartInstance->c2_lat_ant_not_empty = FALSE;
  chartInstance->c2_lon_ant_not_empty = FALSE;
  chartInstance->c2_alt_ant_not_empty = FALSE;
  chartInstance->c2_is_active_c2_udpReceive_example = 0U;
}

static void initialize_params_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
{
}

static void enable_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_k_hoistedGlobal;
  real_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_l_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_m_hoistedGlobal;
  real_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  real_T c2_n_hoistedGlobal;
  real_T c2_n_u;
  const mxArray *c2_o_y = NULL;
  real_T c2_o_hoistedGlobal;
  real_T c2_o_u;
  const mxArray *c2_p_y = NULL;
  real_T c2_p_hoistedGlobal;
  real_T c2_p_u;
  const mxArray *c2_q_y = NULL;
  real_T c2_q_hoistedGlobal;
  real_T c2_q_u;
  const mxArray *c2_r_y = NULL;
  real_T c2_r_hoistedGlobal;
  real_T c2_r_u;
  const mxArray *c2_s_y = NULL;
  real_T c2_s_hoistedGlobal;
  real_T c2_s_u;
  const mxArray *c2_t_y = NULL;
  real_T c2_t_hoistedGlobal;
  real_T c2_t_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_u_hoistedGlobal;
  real_T c2_u_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_v_hoistedGlobal;
  real_T c2_v_u;
  const mxArray *c2_w_y = NULL;
  real_T c2_w_hoistedGlobal;
  real_T c2_w_u;
  const mxArray *c2_x_y = NULL;
  real_T c2_x_hoistedGlobal;
  real_T c2_x_u;
  const mxArray *c2_y_y = NULL;
  real_T c2_y_hoistedGlobal;
  real_T c2_y_u;
  const mxArray *c2_ab_y = NULL;
  real_T c2_ab_hoistedGlobal;
  real_T c2_ab_u;
  const mxArray *c2_bb_y = NULL;
  uint8_T c2_bb_hoistedGlobal;
  uint8_T c2_bb_u;
  const mxArray *c2_cb_y = NULL;
  real_T *c2_airspeed;
  real_T *c2_alpha;
  real_T *c2_alt;
  real_T *c2_beta;
  real_T *c2_heading;
  real_T *c2_lat;
  real_T *c2_lon;
  real_T *c2_pitch;
  real_T *c2_pitch_rate;
  real_T *c2_roll;
  real_T *c2_roll_rate;
  real_T *c2_vpath;
  real_T *c2_yaw_rate;
  c2_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c2_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_vpath = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_yaw_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_roll_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_pitch_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(27), FALSE);
  c2_hoistedGlobal = *c2_airspeed;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_alpha;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_alt;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_beta;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_heading;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_lat;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_lon;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *c2_pitch;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *c2_pitch_rate;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = *c2_roll;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = *c2_roll_rate;
  c2_k_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_l_hoistedGlobal = *c2_vpath;
  c2_l_u = c2_l_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_m_hoistedGlobal = *c2_yaw_rate;
  c2_m_u = c2_m_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_n_hoistedGlobal = chartInstance->c2_airspeed_ant;
  c2_n_u = c2_n_hoistedGlobal;
  c2_o_y = NULL;
  if (!chartInstance->c2_airspeed_ant_not_empty) {
    sf_mex_assign(&c2_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_o_hoistedGlobal = chartInstance->c2_alpha_ant;
  c2_o_u = c2_o_hoistedGlobal;
  c2_p_y = NULL;
  if (!chartInstance->c2_alpha_ant_not_empty) {
    sf_mex_assign(&c2_p_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 14, c2_p_y);
  c2_p_hoistedGlobal = chartInstance->c2_alt_ant;
  c2_p_u = c2_p_hoistedGlobal;
  c2_q_y = NULL;
  if (!chartInstance->c2_alt_ant_not_empty) {
    sf_mex_assign(&c2_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 15, c2_q_y);
  c2_q_hoistedGlobal = chartInstance->c2_beta_ant;
  c2_q_u = c2_q_hoistedGlobal;
  c2_r_y = NULL;
  if (!chartInstance->c2_beta_ant_not_empty) {
    sf_mex_assign(&c2_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 16, c2_r_y);
  c2_r_hoistedGlobal = chartInstance->c2_heading_ant;
  c2_r_u = c2_r_hoistedGlobal;
  c2_s_y = NULL;
  if (!chartInstance->c2_heading_ant_not_empty) {
    sf_mex_assign(&c2_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 17, c2_s_y);
  c2_s_hoistedGlobal = chartInstance->c2_lat_ant;
  c2_s_u = c2_s_hoistedGlobal;
  c2_t_y = NULL;
  if (!chartInstance->c2_lat_ant_not_empty) {
    sf_mex_assign(&c2_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 18, c2_t_y);
  c2_t_hoistedGlobal = chartInstance->c2_lon_ant;
  c2_t_u = c2_t_hoistedGlobal;
  c2_u_y = NULL;
  if (!chartInstance->c2_lon_ant_not_empty) {
    sf_mex_assign(&c2_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 19, c2_u_y);
  c2_u_hoistedGlobal = chartInstance->c2_pitch_ant;
  c2_u_u = c2_u_hoistedGlobal;
  c2_v_y = NULL;
  if (!chartInstance->c2_pitch_ant_not_empty) {
    sf_mex_assign(&c2_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 20, c2_v_y);
  c2_v_hoistedGlobal = chartInstance->c2_pitch_rate_ant;
  c2_v_u = c2_v_hoistedGlobal;
  c2_w_y = NULL;
  if (!chartInstance->c2_pitch_rate_ant_not_empty) {
    sf_mex_assign(&c2_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 21, c2_w_y);
  c2_w_hoistedGlobal = chartInstance->c2_roll_ant;
  c2_w_u = c2_w_hoistedGlobal;
  c2_x_y = NULL;
  if (!chartInstance->c2_roll_ant_not_empty) {
    sf_mex_assign(&c2_x_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 22, c2_x_y);
  c2_x_hoistedGlobal = chartInstance->c2_roll_rate_ant;
  c2_x_u = c2_x_hoistedGlobal;
  c2_y_y = NULL;
  if (!chartInstance->c2_roll_rate_ant_not_empty) {
    sf_mex_assign(&c2_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 23, c2_y_y);
  c2_y_hoistedGlobal = chartInstance->c2_vpath_ant;
  c2_y_u = c2_y_hoistedGlobal;
  c2_ab_y = NULL;
  if (!chartInstance->c2_vpath_ant_not_empty) {
    sf_mex_assign(&c2_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 24, c2_ab_y);
  c2_ab_hoistedGlobal = chartInstance->c2_yaw_rate_ant;
  c2_ab_u = c2_ab_hoistedGlobal;
  c2_bb_y = NULL;
  if (!chartInstance->c2_yaw_rate_ant_not_empty) {
    sf_mex_assign(&c2_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_bb_y, sf_mex_create("y", &c2_ab_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 25, c2_bb_y);
  c2_bb_hoistedGlobal = chartInstance->c2_is_active_c2_udpReceive_example;
  c2_bb_u = c2_bb_hoistedGlobal;
  c2_cb_y = NULL;
  sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_bb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 26, c2_cb_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_airspeed;
  real_T *c2_alpha;
  real_T *c2_alt;
  real_T *c2_beta;
  real_T *c2_heading;
  real_T *c2_lat;
  real_T *c2_lon;
  real_T *c2_pitch;
  real_T *c2_pitch_rate;
  real_T *c2_roll;
  real_T *c2_roll_rate;
  real_T *c2_vpath;
  real_T *c2_yaw_rate;
  c2_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c2_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_vpath = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_yaw_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_roll_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_pitch_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_airspeed = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "airspeed");
  *c2_alpha = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "alpha");
  *c2_alt = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "alt");
  *c2_beta = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "beta");
  *c2_heading = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "heading");
  *c2_lat = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    5)), "lat");
  *c2_lon = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    6)), "lon");
  *c2_pitch = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 7)), "pitch");
  *c2_pitch_rate = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "pitch_rate");
  *c2_roll = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 9)), "roll");
  *c2_roll_rate = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 10)), "roll_rate");
  *c2_vpath = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 11)), "vpath");
  *c2_yaw_rate = c2_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 12)), "yaw_rate");
  chartInstance->c2_airspeed_ant = c2_y_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 13)), "airspeed_ant");
  chartInstance->c2_alpha_ant = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 14)), "alpha_ant");
  chartInstance->c2_alt_ant = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 15)), "alt_ant");
  chartInstance->c2_beta_ant = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 16)), "beta_ant");
  chartInstance->c2_heading_ant = c2_m_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 17)), "heading_ant");
  chartInstance->c2_lat_ant = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 18)), "lat_ant");
  chartInstance->c2_lon_ant = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 19)), "lon_ant");
  chartInstance->c2_pitch_ant = c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 20)), "pitch_ant");
  chartInstance->c2_pitch_rate_ant = c2_w_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 21)), "pitch_rate_ant");
  chartInstance->c2_roll_ant = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 22)), "roll_ant");
  chartInstance->c2_roll_rate_ant = c2_u_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 23)), "roll_rate_ant");
  chartInstance->c2_vpath_ant = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 24)), "vpath_ant");
  chartInstance->c2_yaw_rate_ant = c2_s_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 25)), "yaw_rate_ant");
  chartInstance->c2_is_active_c2_udpReceive_example = c2_lb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 26)),
     "is_active_c2_udpReceive_example");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_udpReceive_example(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance)
{
}

static void sf_c2_udpReceive_example(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  real_T *c2_airspeed;
  uint32_T *c2_numbytes;
  real_T *c2_pitch_rate;
  real_T *c2_roll_rate;
  real_T *c2_yaw_rate;
  real_T *c2_pitch;
  real_T *c2_roll;
  real_T *c2_heading;
  real_T *c2_alpha;
  real_T *c2_beta;
  real_T *c2_vpath;
  real_T *c2_lat;
  real_T *c2_lon;
  real_T *c2_alt;
  int8_T (*c2_recv_data)[1085];
  c2_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c2_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_vpath = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_yaw_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_roll_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_pitch_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_numbytes = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_recv_data = (int8_T (*)[1085])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 1085; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_recv_data)[c2_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_airspeed, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_numbytes, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_pitch_rate, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_roll_rate, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_yaw_rate, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_pitch, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_roll, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_heading, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_alpha, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_beta, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_vpath, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_lat, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_lon, 13U);
  _SFD_DATA_RANGE_CHECK(*c2_alt, 14U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_udpReceive_example(chartInstance);
  sf_debug_check_for_state_inconsistency(_udpReceive_exampleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
{
  uint32_T c2_hoistedGlobal;
  int32_T c2_i1;
  int8_T c2_recv_data[1085];
  uint32_T c2_numbytes;
  uint32_T c2_debug_family_var_map[33];
  uint32_T c2_index[20];
  real_T c2_data[200];
  real_T c2_n;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 13.0;
  real_T c2_airspeed;
  real_T c2_pitch_rate;
  real_T c2_roll_rate;
  real_T c2_yaw_rate;
  real_T c2_pitch;
  real_T c2_roll;
  real_T c2_heading;
  real_T c2_alpha;
  real_T c2_beta;
  real_T c2_vpath;
  real_T c2_lat;
  real_T c2_lon;
  real_T c2_alt;
  int32_T c2_i2;
  int8_T c2_b_recv_data[1085];
  real_T c2_b_n;
  real_T c2_b_data[200];
  uint32_T c2_b_index[20];
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_loop_ub;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_a;
  real_T c2_y;
  real_T c2_b_a;
  real_T c2_b_y;
  real_T c2_c_a;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_f_y;
  real_T c2_g_a;
  real_T c2_g_y;
  real_T c2_h_a;
  real_T c2_h_y;
  real_T c2_i_a;
  real_T c2_i_y;
  real_T c2_j_a;
  real_T c2_j_y;
  real_T c2_k_a;
  real_T c2_k_y;
  real_T c2_l_a;
  real_T c2_l_y;
  real_T c2_m_a;
  real_T c2_m_y;
  uint32_T *c2_b_numbytes;
  real_T *c2_b_airspeed;
  real_T *c2_b_pitch_rate;
  real_T *c2_b_roll_rate;
  real_T *c2_b_yaw_rate;
  real_T *c2_b_pitch;
  real_T *c2_b_roll;
  real_T *c2_b_heading;
  real_T *c2_b_alpha;
  real_T *c2_b_beta;
  real_T *c2_b_vpath;
  real_T *c2_b_lat;
  real_T *c2_b_lon;
  real_T *c2_b_alt;
  int8_T (*c2_c_recv_data)[1085];
  c2_b_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c2_b_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_b_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_b_vpath = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_b_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_b_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_b_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_yaw_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_roll_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_pitch_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_numbytes = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_c_recv_data = (int8_T (*)[1085])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_numbytes;
  for (c2_i1 = 0; c2_i1 < 1085; c2_i1++) {
    c2_recv_data[c2_i1] = (*c2_c_recv_data)[c2_i1];
  }

  c2_numbytes = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 33U, 33U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_index, 0U, c2_r_sf_marshallOut,
    c2_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_data, 1U, c2_q_sf_marshallOut,
    c2_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_n, 2U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_recv_data, 5U, c2_p_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_numbytes, 6U, c2_o_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_airspeed, 7U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pitch_rate, 8U,
    c2_n_sf_marshallOut, c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_roll_rate, 9U,
    c2_n_sf_marshallOut, c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_yaw_rate, 10U,
    c2_n_sf_marshallOut, c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pitch, 11U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_roll, 12U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_heading, 13U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_alpha, 14U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_beta, 15U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_vpath, 16U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_lat, 17U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_lon, 18U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_alt, 19U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_airspeed_ant, 20U,
    c2_m_sf_marshallOut, c2_m_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_pitch_rate_ant,
    21U, c2_l_sf_marshallOut, c2_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_roll_rate_ant, 22U,
    c2_k_sf_marshallOut, c2_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_yaw_rate_ant, 23U,
    c2_j_sf_marshallOut, c2_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_pitch_ant, 24U,
    c2_i_sf_marshallOut, c2_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_roll_ant, 25U,
    c2_h_sf_marshallOut, c2_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_heading_ant, 26U,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_alpha_ant, 27U,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_beta_ant, 28U,
    c2_e_sf_marshallOut, c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_vpath_ant, 29U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_lat_ant, 30U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_lon_ant, 31U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_alt_ant, 32U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_airspeed_ant_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
    chartInstance->c2_airspeed_ant = 0.0;
    chartInstance->c2_airspeed_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
    chartInstance->c2_pitch_rate_ant = 0.0;
    chartInstance->c2_pitch_rate_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
    chartInstance->c2_roll_rate_ant = 0.0;
    chartInstance->c2_roll_rate_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    chartInstance->c2_yaw_rate_ant = 0.0;
    chartInstance->c2_yaw_rate_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    chartInstance->c2_pitch_ant = 0.0;
    chartInstance->c2_pitch_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    chartInstance->c2_roll_ant = 0.0;
    chartInstance->c2_roll_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    chartInstance->c2_heading_ant = 0.0;
    chartInstance->c2_heading_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    chartInstance->c2_alpha_ant = 0.0;
    chartInstance->c2_alpha_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    chartInstance->c2_beta_ant = 0.0;
    chartInstance->c2_beta_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    chartInstance->c2_vpath_ant = 0.0;
    chartInstance->c2_vpath_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    chartInstance->c2_lat_ant = 0.0;
    chartInstance->c2_lat_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    chartInstance->c2_lon_ant = 0.0;
    chartInstance->c2_lon_ant_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    chartInstance->c2_alt_ant = 0.0;
    chartInstance->c2_alt_ant_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_airspeed = chartInstance->c2_airspeed_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_pitch_rate = chartInstance->c2_pitch_rate_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_roll_rate = chartInstance->c2_roll_rate_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_yaw_rate = chartInstance->c2_yaw_rate_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_pitch = chartInstance->c2_pitch_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_roll = chartInstance->c2_roll_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_heading = chartInstance->c2_heading_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_alpha = chartInstance->c2_alpha_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_beta = chartInstance->c2_beta_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_vpath = chartInstance->c2_vpath_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_lat = chartInstance->c2_lat_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_lon = chartInstance->c2_lon_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_alt = chartInstance->c2_alt_ant;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  if (CV_EML_IF(0, 1, 1, (real_T)c2_numbytes > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
    for (c2_i2 = 0; c2_i2 < 1085; c2_i2++) {
      c2_b_recv_data[c2_i2] = c2_recv_data[c2_i2];
    }

    c2_UDPreceiveDATA(chartInstance, c2_b_recv_data, c2_numbytes, c2_b_index,
                      c2_b_data, &c2_b_n);
    for (c2_i3 = 0; c2_i3 < 20; c2_i3++) {
      c2_index[c2_i3] = c2_b_index[c2_i3];
    }

    for (c2_i4 = 0; c2_i4 < 200; c2_i4++) {
      c2_data[c2_i4] = c2_b_data[c2_i4];
    }

    c2_n = c2_b_n;
    c2_i5 = (int32_T)c2_n;
    sf_debug_for_loop_vector_check(1.0, 1.0, c2_n, mxDOUBLE_CLASS, c2_i5);
    c2_loop_ub = c2_i5;
    c2_j = 0;
    while (c2_j <= c2_loop_ub - 1) {
      c2_b_j = 1.0 + (real_T)c2_j;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
      switch (c2_index[_SFD_EML_ARRAY_BOUNDS_CHECK("index", (int32_T)
               _SFD_INTEGER_CHECK("j", c2_b_j), 1, 20, 1, 0) - 1]) {
       case 3U:
        CV_EML_SWITCH(0, 1, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
        c2_a = c2_b_j - 1.0;
        c2_y = c2_a * 8.0;
        c2_airspeed = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+7", c2_y + 7.0), 1, 200, 1, 0) - 1];
        break;

       case 16U:
        CV_EML_SWITCH(0, 1, 0, 2);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
        c2_b_a = c2_b_j - 1.0;
        c2_b_y = c2_b_a * 8.0;
        c2_pitch_rate = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_b_y + 1.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
        c2_c_a = c2_b_j - 1.0;
        c2_c_y = c2_c_a * 8.0;
        c2_roll_rate = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+2", c2_c_y + 2.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
        c2_d_a = c2_b_j - 1.0;
        c2_d_y = c2_d_a * 8.0;
        c2_yaw_rate = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+3", c2_d_y + 3.0), 1, 200, 1, 0) - 1];
        break;

       case 17U:
        CV_EML_SWITCH(0, 1, 0, 3);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
        c2_e_a = c2_b_j - 1.0;
        c2_e_y = c2_e_a * 8.0;
        c2_pitch = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_e_y + 1.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
        c2_f_a = c2_b_j - 1.0;
        c2_f_y = c2_f_a * 8.0;
        c2_roll = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+2", c2_f_y + 2.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
        c2_g_a = c2_b_j - 1.0;
        c2_g_y = c2_g_a * 8.0;
        c2_heading = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+3", c2_g_y + 3.0), 1, 200, 1, 0) - 1];
        break;

       case 18U:
        CV_EML_SWITCH(0, 1, 0, 4);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
        c2_h_a = c2_b_j - 1.0;
        c2_h_y = c2_h_a * 8.0;
        c2_alpha = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_h_y + 1.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
        c2_i_a = c2_b_j - 1.0;
        c2_i_y = c2_i_a * 8.0;
        c2_beta = -c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+2", c2_i_y + 2.0), 1, 200, 1, 0) - 1];
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
        c2_j_a = c2_b_j - 1.0;
        c2_j_y = c2_j_a * 8.0;
        c2_vpath = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+4", c2_j_y + 4.0), 1, 200, 1, 0) - 1];
        break;

       case 22U:
        CV_EML_SWITCH(0, 1, 0, 5);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
        c2_k_a = c2_b_j - 1.0;
        c2_k_y = c2_k_a * 8.0;
        c2_lat = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_k_y + 1.0), 1, 200, 1, 0) - 1];
        break;

       case 23U:
        CV_EML_SWITCH(0, 1, 0, 6);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
        c2_l_a = c2_b_j - 1.0;
        c2_l_y = c2_l_a * 8.0;
        c2_lon = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_l_y + 1.0), 1, 200, 1, 0) - 1];
        break;

       case 24U:
        CV_EML_SWITCH(0, 1, 0, 7);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
        c2_m_a = c2_b_j - 1.0;
        c2_m_y = c2_m_a * 8.0;
        c2_alt = c2_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)
          _SFD_INTEGER_CHECK("(j-1)*8+1", c2_m_y + 1.0), 1, 200, 1, 0) - 1];
        break;

       default:
        CV_EML_SWITCH(0, 1, 0, 0);
        break;
      }

      c2_j++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
    chartInstance->c2_airspeed_ant = c2_airspeed;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
    chartInstance->c2_pitch_rate_ant = c2_pitch_rate;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
    chartInstance->c2_roll_rate_ant = c2_roll_rate;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    chartInstance->c2_yaw_rate_ant = c2_yaw_rate;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
    chartInstance->c2_pitch_ant = c2_pitch;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    chartInstance->c2_roll_ant = c2_roll;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
    chartInstance->c2_heading_ant = c2_heading;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 75);
    chartInstance->c2_alpha_ant = c2_alpha;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 76);
    chartInstance->c2_beta_ant = c2_beta;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
    chartInstance->c2_vpath_ant = c2_vpath;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    chartInstance->c2_lat_ant = c2_lat;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    chartInstance->c2_lon_ant = c2_lon;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
    chartInstance->c2_alt_ant = c2_alt;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -80);
  sf_debug_symbol_scope_pop();
  *c2_b_airspeed = c2_airspeed;
  *c2_b_pitch_rate = c2_pitch_rate;
  *c2_b_roll_rate = c2_roll_rate;
  *c2_b_yaw_rate = c2_yaw_rate;
  *c2_b_pitch = c2_pitch;
  *c2_b_roll = c2_roll;
  *c2_b_heading = c2_heading;
  *c2_b_alpha = c2_alpha;
  *c2_b_beta = c2_beta;
  *c2_b_vpath = c2_vpath;
  *c2_b_lat = c2_lat;
  *c2_b_lon = c2_lon;
  *c2_b_alt = c2_alt;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_udpReceive_example
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance)
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
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_alt_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_alt_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_alt_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_alt_ant);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_alt_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_alt_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_alt_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_alt_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_alt_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_alt_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_lon_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_lon_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lon_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lon_ant);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_lon_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_lon_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_lon_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_lon_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lon_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lon_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_lat_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_lat_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lat_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lat_ant);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_lat_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_lat_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_lat_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_lat_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lat_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lat_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_vpath_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_vpath_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vpath_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vpath_ant);
  return c2_y;
}

static real_T c2_h_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_vpath_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_vpath_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d3;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_vpath_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_vpath_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vpath_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_vpath_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_beta_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_i_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_beta_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_beta_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_beta_ant);
  return c2_y;
}

static real_T c2_j_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_beta_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_beta_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d4;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_beta_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_beta_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_beta_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_beta_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_alpha_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_k_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_alpha_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_alpha_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_alpha_ant);
  return c2_y;
}

static real_T c2_l_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d5;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_alpha_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_alpha_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d5, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d5;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_alpha_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_alpha_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_alpha_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_alpha_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_heading_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_m_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_heading_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_heading_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_heading_ant);
  return c2_y;
}

static real_T c2_n_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d6;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_heading_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_heading_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d6, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d6;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_heading_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_heading_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_heading_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_heading_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_roll_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_o_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_roll_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_roll_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_roll_ant);
  return c2_y;
}

static real_T c2_p_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d7;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_roll_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_roll_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d7, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d7;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_roll_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_roll_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_roll_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_roll_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_pitch_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_q_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_pitch_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pitch_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pitch_ant);
  return c2_y;
}

static real_T c2_r_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d8;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_pitch_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_pitch_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d8, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d8;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_pitch_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_pitch_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pitch_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pitch_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_yaw_rate_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_s_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_yaw_rate_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yaw_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_yaw_rate_ant);
  return c2_y;
}

static real_T c2_t_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d9;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_yaw_rate_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_yaw_rate_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d9, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d9;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_yaw_rate_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_yaw_rate_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yaw_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_yaw_rate_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_roll_rate_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_u_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_roll_rate_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_roll_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_roll_rate_ant);
  return c2_y;
}

static real_T c2_v_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d10;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_roll_rate_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_roll_rate_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d10, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d10;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_roll_rate_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_roll_rate_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_roll_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_roll_rate_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_pitch_rate_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_w_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_pitch_rate_ant, const char_T
  *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pitch_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pitch_rate_ant);
  return c2_y;
}

static real_T c2_x_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d11;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_pitch_rate_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_pitch_rate_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d11, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d11;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_pitch_rate_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_pitch_rate_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pitch_rate_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_pitch_rate_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_airspeed_ant_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_y_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_airspeed_ant, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_airspeed_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_airspeed_ant);
  return c2_y;
}

static real_T c2_ab_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d12;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_airspeed_ant_not_empty = FALSE;
  } else {
    chartInstance->c2_airspeed_ant_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d12, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d12;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_airspeed_ant;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_airspeed_ant = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_airspeed_ant),
    &c2_thisId);
  sf_mex_destroy(&c2_b_airspeed_ant);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_bb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_alt, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_alt), &c2_thisId);
  sf_mex_destroy(&c2_alt);
  return c2_y;
}

static real_T c2_cb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d13, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d13;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_alt;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_alt = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_alt), &c2_thisId);
  sf_mex_destroy(&c2_alt);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i6;
  int8_T c2_b_inData[1085];
  int32_T c2_i7;
  int8_T c2_u[1085];
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i6 = 0; c2_i6 < 1085; c2_i6++) {
    c2_b_inData[c2_i6] = (*(int8_T (*)[1085])c2_inData)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 1085; c2_i7++) {
    c2_u[c2_i7] = c2_b_inData[c2_i7];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 2, 0U, 1U, 0U, 1, 1085), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i8;
  real_T c2_b_inData[200];
  int32_T c2_i9;
  real_T c2_u[200];
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 200; c2_i8++) {
    c2_b_inData[c2_i8] = (*(real_T (*)[200])c2_inData)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 200; c2_i9++) {
    c2_u[c2_i9] = c2_b_inData[c2_i9];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 200), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_db_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[200])
{
  real_T c2_dv0[200];
  int32_T c2_i10;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                200);
  for (c2_i10 = 0; c2_i10 < 200; c2_i10++) {
    c2_y[c2_i10] = c2_dv0[c2_i10];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[200];
  int32_T c2_i11;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_data);
  for (c2_i11 = 0; c2_i11 < 200; c2_i11++) {
    (*(real_T (*)[200])c2_outData)[c2_i11] = c2_y[c2_i11];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i12;
  uint32_T c2_b_inData[20];
  int32_T c2_i13;
  uint32_T c2_u[20];
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i12 = 0; c2_i12 < 20; c2_i12++) {
    c2_b_inData[c2_i12] = (*(uint32_T (*)[20])c2_inData)[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 20; c2_i13++) {
    c2_u[c2_i13] = c2_b_inData[c2_i13];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 7, 0U, 1U, 0U, 2, 1, 20), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_eb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[20])
{
  uint32_T c2_uv0[20];
  int32_T c2_i14;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv0, 1, 7, 0U, 1, 0U, 2, 1, 20);
  for (c2_i14 = 0; c2_i14 < 20; c2_i14++) {
    c2_y[c2_i14] = c2_uv0[c2_i14];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_index;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint32_T c2_y[20];
  int32_T c2_i15;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_index = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_index), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_index);
  for (c2_i15 = 0; c2_i15 < 20; c2_i15++) {
    (*(uint32_T (*)[20])c2_outData)[c2_i15] = c2_y[c2_i15];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_fb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 7, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_numbytes;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint32_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_numbytes = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_numbytes),
    &c2_thisId);
  sf_mex_destroy(&c2_numbytes);
  *(uint32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_gb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[1085])
{
  int8_T c2_iv0[1085];
  int32_T c2_i16;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_iv0, 1, 2, 0U, 1, 0U, 1, 1085);
  for (c2_i16 = 0; c2_i16 < 1085; c2_i16++) {
    c2_y[c2_i16] = c2_iv0[c2_i16];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_recv_data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y[1085];
  int32_T c2_i17;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_recv_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_recv_data), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_recv_data);
  for (c2_i17 = 0; c2_i17 < 1085; c2_i17++) {
    (*(int8_T (*)[1085])c2_outData)[c2_i17] = c2_y[c2_i17];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i18;
  real32_T c2_b_inData[200];
  int32_T c2_i19;
  real32_T c2_u[200];
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i18 = 0; c2_i18 < 200; c2_i18++) {
    c2_b_inData[c2_i18] = (*(real32_T (*)[200])c2_inData)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 200; c2_i19++) {
    c2_u[c2_i19] = c2_b_inData[c2_i19];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 1, 200), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_hb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y[200])
{
  real32_T c2_fv0[200];
  int32_T c2_i20;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_fv0, 1, 1, 0U, 1, 0U, 2, 1,
                200);
  for (c2_i20 = 0; c2_i20 < 200; c2_i20++) {
    c2_y[c2_i20] = c2_fv0[c2_i20];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real32_T c2_y[200];
  int32_T c2_i21;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_data);
  for (c2_i21 = 0; c2_i21 < 200; c2_i21++) {
    (*(real32_T (*)[200])c2_outData)[c2_i21] = c2_y[c2_i21];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real32_T c2_ib_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real32_T c2_y;
  real32_T c2_f0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_f0, 1, 1, 0U, 0, 0U, 0);
  c2_y = c2_f0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_data_aux;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real32_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_data_aux = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data_aux),
    &c2_thisId);
  sf_mex_destroy(&c2_data_aux);
  *(real32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i22;
  int8_T c2_b_inData[4];
  int32_T c2_i23;
  int8_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i22 = 0; c2_i22 < 4; c2_i22++) {
    c2_b_inData[c2_i22] = (*(int8_T (*)[4])c2_inData)[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 4; c2_i23++) {
    c2_u[c2_i23] = c2_b_inData[c2_i23];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 2, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_jb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int8_T c2_y[4])
{
  int8_T c2_iv1[4];
  int32_T c2_i24;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_iv1, 1, 2, 0U, 1, 0U, 1, 4);
  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    c2_y[c2_i24] = c2_iv1[c2_i24];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_data_bytes;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y[4];
  int32_T c2_i25;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_data_bytes = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_data_bytes), &c2_thisId,
    c2_y);
  sf_mex_destroy(&c2_data_bytes);
  for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
    (*(int8_T (*)[4])c2_outData)[c2_i25] = c2_y[c2_i25];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_udpReceive_example_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[15];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i26;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c2_i26 = 0; c2_i26 < 15; c2_i26++) {
    c2_r0 = &c2_info[c2_i26];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i26);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15])
{
  c2_info[0].context = "";
  c2_info[0].name = "eml_int_forloop_overflow_check";
  c2_info[0].dominantType = "";
  c2_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[0].fileTimeLo = 1311255316U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[1].name = "intmax";
  c2_info[1].dominantType = "char";
  c2_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[1].fileTimeLo = 1311255316U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "typecast";
  c2_info[2].dominantType = "int8";
  c2_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c2_info[2].fileTimeLo = 1307651236U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c2_info[3].name = "eml_int_nbits";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c2_info[3].fileTimeLo = 1286818780U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c2_info[4].name = "eml_index_rdivide";
  c2_info[4].dominantType = "uint8";
  c2_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[4].fileTimeLo = 1286818780U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[5].name = "eml_index_class";
  c2_info[5].dominantType = "";
  c2_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[5].fileTimeLo = 1286818778U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c2_info[6].name = "eml_index_times";
  c2_info[6].dominantType = "int32";
  c2_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[6].fileTimeLo = 1286818780U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[7].name = "eml_index_class";
  c2_info[7].dominantType = "";
  c2_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[7].fileTimeLo = 1286818778U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c2_info[8].name = "eml_index_rdivide";
  c2_info[8].dominantType = "int32";
  c2_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[8].fileTimeLo = 1286818780U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c2_info[9].name = "eml_index_class";
  c2_info[9].dominantType = "";
  c2_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[9].fileTimeLo = 1286818778U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m";
  c2_info[10].name = "eml_unsigned_class";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[10].fileTimeLo = 1286818800U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "mtimes";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].fileTimeLo = 1289519692U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c2_info[12].name = "eml_float_nbits";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c2_info[12].fileTimeLo = 1307651242U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_nbits.m";
  c2_info[13].name = "eml_float_model";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[13].fileTimeLo = 1307651242U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  c2_info[14].name = "eml_index_rdivide";
  c2_info[14].dominantType = "int32";
  c2_info[14].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[14].fileTimeLo = 1286818780U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
}

static void c2_UDPreceiveDATA(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, int8_T c2_recv_data[1085], uint32_T c2_numbytes, uint32_T
  c2_index[20], real_T c2_data[200], real_T *c2_n)
{
  uint32_T c2_debug_family_var_map[13];
  real_T c2_i;
  uint32_T c2_j;
  int8_T c2_index_bytes[4];
  uint32_T c2_index_aux;
  int8_T c2_data_bytes[4];
  real32_T c2_data_aux;
  real32_T c2_b_data[200];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 3.0;
  int32_T c2_i27;
  int32_T c2_i28;
  uint32_T c2_loop_ub;
  uint32_T c2_b_j;
  int32_T c2_i29;
  uint64_T c2_u1;
  int32_T c2_i30;
  int8_T c2_x[4];
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b;
  real_T c2_y;
  real_T c2_d14;
  uint32_T c2_u2;
  uint32_T c2_c_j;
  int32_T c2_i31;
  uint64_T c2_u3;
  int32_T c2_i32;
  real_T c2_a;
  real_T c2_b_y;
  int32_T c2_i33;
  sf_debug_symbol_scope_push_eml(0U, 13U, 14U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_i, 0U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_j, 1U, c2_o_sf_marshallOut,
    c2_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_index_bytes, 2U,
    c2_u_sf_marshallOut, c2_u_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_index_aux, 3U,
    c2_o_sf_marshallOut, c2_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_data_bytes, 4U,
    c2_u_sf_marshallOut, c2_u_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_data_aux, 5U, c2_t_sf_marshallOut,
    c2_t_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_b_data, MAX_uint32_T,
    c2_s_sf_marshallOut, c2_s_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 7U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 8U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_recv_data, 9U, c2_p_sf_marshallOut,
    c2_r_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_numbytes, 10U,
    c2_o_sf_marshallOut, c2_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_index, 11U, c2_r_sf_marshallOut,
    c2_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_data, MAX_uint32_T,
    c2_q_sf_marshallOut, c2_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_n, 12U, c2_n_sf_marshallOut,
    c2_n_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
  c2_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
  for (c2_i27 = 0; c2_i27 < 20; c2_i27++) {
    c2_index[c2_i27] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
  for (c2_i28 = 0; c2_i28 < 200; c2_i28++) {
    c2_b_data[c2_i28] = 0.0F;
  }

  sf_debug_symbol_switch(6U, 6U);
  c2_eml_int_forloop_overflow_check(chartInstance, c2_numbytes);
  c2_j = 6U;
  c2_loop_ub = c2_numbytes;
  c2_b_j = 6U;
  while (c2_b_j <= c2_loop_ub) {
    c2_j = c2_b_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
    c2_i++;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
    for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
      c2_u1 = (uint64_T)c2_j + (uint64_T)(uint32_T)c2_i29;
      if (c2_u1 > 4294967295UL) {
        c2_u1 = 4294967295UL;
      }

      c2_index_bytes[c2_i29] = c2_recv_data[(int32_T)(uint32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("recv_data", (int32_T)(uint32_T)
        _SFD_INTEGER_CHECK("j:j+3", (real_T)(uint32_T)c2_u1), 1, 1085, 1, 0) - 1];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
    for (c2_i30 = 0; c2_i30 < 4; c2_i30++) {
      c2_x[c2_i30] = c2_index_bytes[c2_i30];
    }

    memcpy(&c2_index_aux, &c2_x[0], 4U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
    c2_index[_SFD_EML_ARRAY_BOUNDS_CHECK("index", (int32_T)_SFD_INTEGER_CHECK(
      "i", c2_i), 1, 20, 1, 0) - 1] = c2_index_aux;
    c2_k = 0;
    while (c2_k < 8) {
      c2_b_k = 1.0 + (real_T)c2_k;
      CV_EML_FOR(0, 1, 2, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 96);
      c2_b = c2_b_k;
      c2_y = 4.0 * c2_b;
      c2_d14 = muDoubleScalarRound((real_T)c2_j + c2_y);
      if (c2_d14 < 4.294967296E+9) {
        if (c2_d14 >= 0.0) {
          c2_u2 = (uint32_T)c2_d14;
        } else {
          c2_u2 = 0U;
        }
      } else if (c2_d14 >= 4.294967296E+9) {
        c2_u2 = MAX_uint32_T;
      } else {
        c2_u2 = 0U;
      }

      c2_c_j = c2_u2;
      for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
        c2_u3 = (uint64_T)c2_c_j + (uint64_T)(uint32_T)c2_i31;
        if (c2_u3 > 4294967295UL) {
          c2_u3 = 4294967295UL;
        }

        c2_data_bytes[c2_i31] = c2_recv_data[(int32_T)(uint32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("recv_data", (int32_T)(uint32_T)
          _SFD_INTEGER_CHECK("j+4*k:j+4*k+3", (real_T)(uint32_T)c2_u3), 1, 1085,
          1, 0) - 1];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
      for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
        c2_x[c2_i32] = c2_data_bytes[c2_i32];
      }

      memcpy(&c2_data_aux, &c2_x[0], 4U);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
      c2_a = c2_i - 1.0;
      c2_b_y = c2_a * 8.0;
      c2_b_data[_SFD_EML_ARRAY_BOUNDS_CHECK("data", (int32_T)_SFD_INTEGER_CHECK(
        "(i-1)*8+k", c2_b_y + c2_b_k), 1, 200, 1, 0) - 1] = c2_data_aux;
      sf_debug_symbol_switch(6U, 6U);
      c2_k++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 2, 0);
    c2_b_j += 36U;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
  for (c2_i33 = 0; c2_i33 < 200; c2_i33++) {
    c2_data[c2_i33] = c2_b_data[c2_i33];
  }

  sf_debug_symbol_switch(6U, 12U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 102);
  *c2_n = c2_i;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -102);
  sf_debug_symbol_scope_pop();
}

static void c2_eml_int_forloop_overflow_check
  (SFc2_udpReceive_exampleInstanceStruct *chartInstance, uint32_T c2_b)
{
  uint32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i34;
  static char_T c2_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i35;
  static char_T c2_cv1[6] = { 'u', 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[6];
  const mxArray *c2_b_y = NULL;
  c2_b_b = c2_b;
  if (6U > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 4294967259U);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i34 = 0; c2_i34 < 34; c2_i34++) {
      c2_u[c2_i34] = c2_cv0[c2_i34];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i35 = 0; c2_i35 < 6; c2_i35++) {
      c2_b_u[c2_i35] = c2_cv1[c2_i35];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 6),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_kb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i36;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i36, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i36;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_lb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_udpReceive_example, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_mb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_udpReceive_example), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_udpReceive_example);
  return c2_y;
}

static uint8_T c2_mb_emlrt_marshallIn(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u4, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_udpReceive_exampleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_udpReceive_example_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(427489679U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3950057442U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(679910804U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(499916848U);
}

mxArray *sf_c2_udpReceive_example_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("53Iqod9wjMEurE9YZG0AfH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1085);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_udpReceive_example(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"airspeed\",},{M[1],M[13],T\"alpha\",},{M[1],M[18],T\"alt\",},{M[1],M[14],T\"beta\",},{M[1],M[12],T\"heading\",},{M[1],M[16],T\"lat\",},{M[1],M[17],T\"lon\",},{M[1],M[10],T\"pitch\",},{M[1],M[7],T\"pitch_rate\",},{M[1],M[11],T\"roll\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[8],T\"roll_rate\",},{M[1],M[15],T\"vpath\",},{M[1],M[9],T\"yaw_rate\",},{M[4],M[0],T\"airspeed_ant\",S'l','i','p'{{M1x2[184 196],M[0],}}},{M[4],M[0],T\"alpha_ant\",S'l','i','p'{{M1x2[277 286],M[0],}}},{M[4],M[0],T\"alt_ant\",S'l','i','p'{{M1x2[329 336],M[0],}}},{M[4],M[0],T\"beta_ant\",S'l','i','p'{{M1x2[287 295],M[0],}}},{M[4],M[0],T\"heading_ant\",S'l','i','p'{{M1x2[265 276],M[0],}}},{M[4],M[0],T\"lat_ant\",S'l','i','p'{{M1x2[313 320],M[0],}}},{M[4],M[0],T\"lon_ant\",S'l','i','p'{{M1x2[321 328],M[0],}}}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"pitch_ant\",S'l','i','p'{{M1x2[246 255],M[0],}}},{M[4],M[0],T\"pitch_rate_ant\",S'l','i','p'{{M1x2[197 211],M[0],}}},{M[4],M[0],T\"roll_ant\",S'l','i','p'{{M1x2[256 264],M[0],}}},{M[4],M[0],T\"roll_rate_ant\",S'l','i','p'{{M1x2[212 225],M[0],}}},{M[4],M[0],T\"vpath_ant\",S'l','i','p'{{M1x2[296 305],M[0],}}},{M[4],M[0],T\"yaw_rate_ant\",S'l','i','p'{{M1x2[226 238],M[0],}}},{M[8],M[0],T\"is_active_c2_udpReceive_example\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 27, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_udpReceive_example_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_udpReceive_exampleInstanceStruct *chartInstance;
    chartInstance = (SFc2_udpReceive_exampleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_udpReceive_exampleMachineNumber_,
           2,
           1,
           1,
           15,
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
          init_script_number_translation(_udpReceive_exampleMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_udpReceive_exampleMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_udpReceive_exampleMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"recv_data");
          _SFD_SET_DATA_PROPS(1,2,0,1,"airspeed");
          _SFD_SET_DATA_PROPS(2,1,1,0,"numbytes");
          _SFD_SET_DATA_PROPS(3,2,0,1,"pitch_rate");
          _SFD_SET_DATA_PROPS(4,2,0,1,"roll_rate");
          _SFD_SET_DATA_PROPS(5,2,0,1,"yaw_rate");
          _SFD_SET_DATA_PROPS(6,2,0,1,"pitch");
          _SFD_SET_DATA_PROPS(7,2,0,1,"roll");
          _SFD_SET_DATA_PROPS(8,2,0,1,"heading");
          _SFD_SET_DATA_PROPS(9,2,0,1,"alpha");
          _SFD_SET_DATA_PROPS(10,2,0,1,"beta");
          _SFD_SET_DATA_PROPS(11,2,0,1,"vpath");
          _SFD_SET_DATA_PROPS(12,2,0,1,"lat");
          _SFD_SET_DATA_PROPS(13,2,0,1,"lon");
          _SFD_SET_DATA_PROPS(14,2,0,1,"alt");
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
        _SFD_CV_INIT_EML(0,1,2,2,0,1,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1991);
        _SFD_CV_INIT_EML_FCN(0,1,"UDPreceiveDATA",1993,-1,2453);
        _SFD_CV_INIT_EML_IF(0,1,0,338,362,-1,596);
        _SFD_CV_INIT_EML_IF(0,1,1,838,851,-1,1987);
        _SFD_CV_INIT_EML_FOR(0,1,0,945,957,1691);
        _SFD_CV_INIT_EML_FOR(0,1,1,2120,2142,2421);
        _SFD_CV_INIT_EML_FOR(0,1,2,2266,2276,2417);

        {
          static int caseStart[] = { -1, 993, 1056, 1214, 1363, 1507, 1566, 1625
          };

          static int caseExprEnd[] = { 8, 999, 1063, 1221, 1370, 1514, 1573,
            1632 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,965,981,1683,8,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1085;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT8,1,&(dimVector[0]),0,0,0,0.0,1.0,
            0,0,(MexFcnForType)c2_p_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_o_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_n_sf_marshallOut,(MexInFcnForType)c2_n_sf_marshallIn);

        {
          real_T *c2_airspeed;
          uint32_T *c2_numbytes;
          real_T *c2_pitch_rate;
          real_T *c2_roll_rate;
          real_T *c2_yaw_rate;
          real_T *c2_pitch;
          real_T *c2_roll;
          real_T *c2_heading;
          real_T *c2_alpha;
          real_T *c2_beta;
          real_T *c2_vpath;
          real_T *c2_lat;
          real_T *c2_lon;
          real_T *c2_alt;
          int8_T (*c2_recv_data)[1085];
          c2_alt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c2_lon = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c2_lat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c2_vpath = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c2_beta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c2_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c2_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c2_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_yaw_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_roll_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_pitch_rate = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_numbytes = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_airspeed = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_recv_data = (int8_T (*)[1085])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_recv_data);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_airspeed);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_numbytes);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_pitch_rate);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_roll_rate);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_yaw_rate);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_pitch);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_roll);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_heading);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_alpha);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_beta);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_vpath);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_lat);
          _SFD_SET_DATA_VALUE_PTR(13U, c2_lon);
          _SFD_SET_DATA_VALUE_PTR(14U, c2_alt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_udpReceive_exampleMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ZsWgO5TqT6vrL0PQbLmF7B";
}

static void sf_opaque_initialize_c2_udpReceive_example(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
  initialize_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_udpReceive_example(void *chartInstanceVar)
{
  enable_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_udpReceive_example(void *chartInstanceVar)
{
  disable_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_udpReceive_example(void *chartInstanceVar)
{
  sf_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_udpReceive_example(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_udpReceive_example
    ((SFc2_udpReceive_exampleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_udpReceive_example();/* state var info */
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

extern void sf_internal_set_sim_state_c2_udpReceive_example(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_udpReceive_example();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_udpReceive_example(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_udpReceive_example(S);
}

static void sf_opaque_set_sim_state_c2_udpReceive_example(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_udpReceive_example(S, st);
}

static void sf_opaque_terminate_c2_udpReceive_example(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_udpReceive_exampleInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_udpReceive_example_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_udpReceive_example((SFc2_udpReceive_exampleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_udpReceive_example(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_udpReceive_example
      ((SFc2_udpReceive_exampleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_udpReceive_example(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_udpReceive_example_optimization_info();
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
        infoStruct,2,13);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(415246736U));
  ssSetChecksum1(S,(1439816708U));
  ssSetChecksum2(S,(447331264U));
  ssSetChecksum3(S,(3214025000U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_udpReceive_example(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_udpReceive_example(SimStruct *S)
{
  SFc2_udpReceive_exampleInstanceStruct *chartInstance;
  chartInstance = (SFc2_udpReceive_exampleInstanceStruct *)malloc(sizeof
    (SFc2_udpReceive_exampleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_udpReceive_exampleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_udpReceive_example;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_udpReceive_example;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_udpReceive_example;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_udpReceive_example;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_udpReceive_example;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_udpReceive_example;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_udpReceive_example;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_udpReceive_example;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_udpReceive_example;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_udpReceive_example;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_udpReceive_example;
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

void c2_udpReceive_example_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_udpReceive_example(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_udpReceive_example(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_udpReceive_example(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_udpReceive_example_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
