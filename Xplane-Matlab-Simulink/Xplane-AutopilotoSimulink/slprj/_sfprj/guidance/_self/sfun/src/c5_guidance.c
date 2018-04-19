/* Include files */

#include "blascompat32.h"
#include "guidance_sfun.h"
#include "c5_guidance.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "guidance_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_b_HOLD_HEADING              (1.0)
#define c5_b_heading_value             (180.0)

/* Variable Declarations */

/* Variable Definitions */
static const char *c5_debug_family_names[6] = { "HOLD_HEADING", "heading_value",
  "nargin", "nargout", "heading_target_in", "heading_target" };

/* Function Declarations */
static void initialize_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance);
static void initialize_params_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance);
static void enable_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance);
static void disable_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance);
static void set_sim_state_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance);
static void sf_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c5_guidance
  (SFc5_guidanceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static real_T c5_emlrt_marshallIn(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_heading_target, const char_T *c5_name);
static uint8_T c5_b_emlrt_marshallIn(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_guidance, const char_T *c5_name);
static void init_dsm_address_info(SFc5_guidanceInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_guidance = 0U;
}

static void initialize_params_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance)
{
  real_T c5_d0;
  real_T c5_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'HOLD_HEADING' in the parent workspace.\n");
  sf_mex_import("HOLD_HEADING", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                &c5_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_HOLD_HEADING = c5_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'heading_value' in the parent workspace.\n");
  sf_mex_import("heading_value", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                &c5_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_heading_value = c5_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_guidance(SFc5_guidanceInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_heading_target;
  c5_heading_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2));
  c5_hoistedGlobal = *c5_heading_target;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_guidance;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_heading_target;
  c5_heading_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_heading_target = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "heading_target");
  chartInstance->c5_is_active_c5_guidance = c5_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "is_active_c5_guidance");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_guidance(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance)
{
}

static void sf_c5_guidance(SFc5_guidanceInstanceStruct *chartInstance)
{
  int32_T c5_previousEvent;
  real_T c5_hoistedGlobal;
  real_T c5_heading_target_in;
  uint32_T c5_debug_family_var_map[6];
  real_T c5_c_HOLD_HEADING = c5_b_HOLD_HEADING;
  real_T c5_c_heading_value = c5_b_heading_value;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_heading_target;
  real_T *c5_b_heading_target_in;
  real_T *c5_b_heading_target;
  c5_b_heading_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_heading_target_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2);
  _SFD_DATA_RANGE_CHECK(*c5_b_heading_target_in, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_heading_target, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_HOLD_HEADING, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_heading_value, 3U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2);
  c5_hoistedGlobal = *c5_b_heading_target_in;
  c5_heading_target_in = c5_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_c_HOLD_HEADING, c5_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c5_c_heading_value, c5_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c5_heading_target_in, c5_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c5_heading_target, c5_sf_marshall, 5U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  CV_EML_IF(0, 0, (int32_T)c5_b_HOLD_HEADING);
  _SFD_EML_CALL(0, 4);
  c5_heading_target = c5_b_heading_value;
  _SFD_EML_CALL(0, -6);
  sf_debug_symbol_scope_pop();
  *c5_b_heading_target = c5_heading_target;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_guidanceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c5_guidance
  (SFc5_guidanceInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc5_guidanceInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_guidance_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c5_nameCaptureInfo;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc5_guidanceInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static real_T c5_emlrt_marshallIn(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_heading_target, const char_T *
  c5_name)
{
  real_T c5_y;
  real_T c5_d2;
  sf_mex_import(c5_name, sf_mex_dup(c5_heading_target), &c5_d2, 1, 0, 0U, 0, 0U,
                0);
  c5_y = c5_d2;
  sf_mex_destroy(&c5_heading_target);
  return c5_y;
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_guidanceInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_guidance, const
  char_T *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_b_is_active_c5_guidance), &c5_u0, 1, 3,
                0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_b_is_active_c5_guidance);
  return c5_y;
}

static void init_dsm_address_info(SFc5_guidanceInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_guidance_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2406350052U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2696278757U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1788571714U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2170689920U);
}

mxArray *sf_c5_guidance_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3577050397U);
    pr[1] = (double)(64908567U);
    pr[2] = (double)(1016460226U);
    pr[3] = (double)(2196663838U);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c5_guidance(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"heading_target\",},{M[8],M[0],T\"is_active_c5_guidance\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_guidance_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_guidanceInstanceStruct *chartInstance;
    chartInstance = (SFc5_guidanceInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_guidanceMachineNumber_,
          5,
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
          init_script_number_translation(_guidanceMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_guidanceMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_guidanceMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"heading_target_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"heading_target");
          _SFD_SET_DATA_PROPS(2,10,0,0,"HOLD_HEADING");
          _SFD_SET_DATA_PROPS(3,10,0,0,"heading_value");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,185);
        _SFD_CV_INIT_EML_IF(0,0,79,94,131,179);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);

        {
          real_T *c5_heading_target_in;
          real_T *c5_heading_target;
          c5_heading_target = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c5_heading_target_in = (real_T *)ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_heading_target_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_heading_target);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c5_HOLD_HEADING);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c5_heading_value);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_guidanceMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_guidance(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_guidanceInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
  initialize_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_guidance(void *chartInstanceVar)
{
  enable_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_guidance(void *chartInstanceVar)
{
  disable_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_guidance(void *chartInstanceVar)
{
  sf_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c5_guidance(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_guidance((SFc5_guidanceInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c5_guidance();/* state var info */
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

static void sf_internal_set_sim_state_c5_guidance(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_guidance();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_guidance((SFc5_guidanceInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c5_guidance(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_guidance(S);
}

static void sf_opaque_set_sim_state_c5_guidance(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_guidance(S, st);
}

static void sf_opaque_terminate_c5_guidance(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_guidanceInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_guidance((SFc5_guidanceInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c5_guidance((SFc5_guidanceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_guidance(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_guidance((SFc5_guidanceInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_guidance(SimStruct *S)
{
  /* Actual parameters from chart:
     HOLD_HEADING heading_value
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for HOLD_HEADING*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for heading_value*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"guidance","guidance",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"guidance","guidance",5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"guidance","guidance",5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"guidance","guidance",5,1);
      sf_mark_chart_reusable_outputs(S,"guidance","guidance",5,1);
    }

    sf_set_rtw_dwork_info(S,"guidance","guidance",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2071559673U));
  ssSetChecksum1(S,(3878505652U));
  ssSetChecksum2(S,(2086192385U));
  ssSetChecksum3(S,(142829950U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_guidance(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "guidance", "guidance",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_guidance(SimStruct *S)
{
  SFc5_guidanceInstanceStruct *chartInstance;
  chartInstance = (SFc5_guidanceInstanceStruct *)malloc(sizeof
    (SFc5_guidanceInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_guidanceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_guidance;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_guidance;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_guidance;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_guidance;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_guidance;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_guidance;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_guidance;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_guidance;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_guidance;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_guidance;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_guidance;
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

void c5_guidance_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_guidance(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_guidance(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_guidance(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_guidance_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
