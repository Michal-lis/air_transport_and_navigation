/* Include files */

#include "blascompat32.h"
#include "engine_control_sfun.h"
#include "c2_engine_control.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "engine_control_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance);
static void initialize_params_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance);
static void enable_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance);
static void disable_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance);
static void set_sim_state_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance);
static void sf_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_engine_control, const char_T *
  c2_name);
static void init_dsm_address_info(SFc2_engine_controlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_engine_control = 0U;
}

static void initialize_params_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance)
{
}

static void enable_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_d_y;
  c2_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_d_y;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_engine_control;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_is_active_c2_engine_control = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_engine_control");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_engine_control(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
}

static void sf_c2_engine_control(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y;
  real_T *c2_b_u;
  real_T *c2_b_y;
  c2_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  c2_hoistedGlobal = *c2_b_u;
  c2_u = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_u, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_y, c2_sf_marshall, 3U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  c2_y = c2_u;
  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  *c2_b_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_engine_controlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c2_engine_control
  (SFc2_engine_controlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_engine_controlInstanceStruct *chartInstance;
  chartInstance = (SFc2_engine_controlInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_engine_control_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_engine_controlInstanceStruct *chartInstance;
  chartInstance = (SFc2_engine_controlInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_name)
{
  real_T c2_b_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_y), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_engine_controlInstanceStruct
  *chartInstance, const mxArray *
  c2_b_is_active_c2_engine_control, const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_engine_control), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_engine_control);
  return c2_y;
}

static void init_dsm_address_info(SFc2_engine_controlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_engine_control_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2700736034U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1581833948U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2886792735U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(830448571U);
}

mxArray *sf_c2_engine_control_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4124909918U);
    pr[1] = (double)(1077482488U);
    pr[2] = (double)(2884167377U);
    pr[3] = (double)(201768029U);
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

static mxArray *sf_get_sim_state_info_c2_engine_control(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_engine_control\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_engine_control_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_engine_controlInstanceStruct *chartInstance;
    chartInstance = (SFc2_engine_controlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_engine_controlMachineNumber_,
           2,
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
          init_script_number_translation(_engine_controlMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_engine_controlMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_engine_controlMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,33);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);

        {
          real_T *c2_u;
          real_T *c2_y;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_engine_controlMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_engine_control(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_engine_controlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_engine_control((SFc2_engine_controlInstanceStruct*)
    chartInstanceVar);
  initialize_c2_engine_control((SFc2_engine_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_engine_control(void *chartInstanceVar)
{
  enable_c2_engine_control((SFc2_engine_controlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_engine_control(void *chartInstanceVar)
{
  disable_c2_engine_control((SFc2_engine_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_engine_control(void *chartInstanceVar)
{
  sf_c2_engine_control((SFc2_engine_controlInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_engine_control(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_engine_control
    ((SFc2_engine_controlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_engine_control();/* state var info */
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

static void sf_internal_set_sim_state_c2_engine_control(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_engine_control();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_engine_control((SFc2_engine_controlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_engine_control(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_engine_control(S);
}

static void sf_opaque_set_sim_state_c2_engine_control(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_engine_control(S, st);
}

static void sf_opaque_terminate_c2_engine_control(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_engine_controlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_engine_control((SFc2_engine_controlInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_engine_control
    ((SFc2_engine_controlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_engine_control(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_engine_control((SFc2_engine_controlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_engine_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"engine_control","engine_control",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"engine_control","engine_control",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"engine_control",
      "engine_control",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"engine_control","engine_control",2,
        1);
      sf_mark_chart_reusable_outputs(S,"engine_control","engine_control",2,1);
    }

    sf_set_rtw_dwork_info(S,"engine_control","engine_control",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3822070547U));
  ssSetChecksum1(S,(1600524796U));
  ssSetChecksum2(S,(3894159231U));
  ssSetChecksum3(S,(1452561976U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_engine_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "engine_control", "engine_control",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_engine_control(SimStruct *S)
{
  SFc2_engine_controlInstanceStruct *chartInstance;
  chartInstance = (SFc2_engine_controlInstanceStruct *)malloc(sizeof
    (SFc2_engine_controlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_engine_controlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_engine_control;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_engine_control;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_engine_control;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_engine_control;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_engine_control;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_engine_control;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_engine_control;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_engine_control;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_engine_control;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_engine_control;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_engine_control;
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

void c2_engine_control_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_engine_control(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_engine_control(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_engine_control(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_engine_control_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
