/* Include files */

#include "lateral_control2_sfun.h"
#include "c1_lateral_control2.h"
#include "c3_lateral_control2.h"
#include "c5_lateral_control2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _lateral_control2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void lateral_control2_initializer(void)
{
}

void lateral_control2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_lateral_control2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_lateral_control2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_lateral_control2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_lateral_control2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_lateral_control2_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(983014886U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2484479112U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1476047410U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(748600239U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3676310486U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3848568372U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2932739467U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1166453545U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_lateral_control2_get_check_sum(mxArray *plhs[]);
          sf_c1_lateral_control2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_lateral_control2_get_check_sum(mxArray *plhs[]);
          sf_c3_lateral_control2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_lateral_control2_get_check_sum(mxArray *plhs[]);
          sf_c5_lateral_control2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2248892818U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(781595618U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3220101939U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1723474520U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lateral_control2_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "h8J30dnN8SJ6VIV8vA8fJB") == 0) {
          extern mxArray *sf_c1_lateral_control2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_lateral_control2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "yVXbmPoNzggfss1iQZKJHE") == 0) {
          extern mxArray *sf_c3_lateral_control2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_lateral_control2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "IxgfM2UUjfdsSryvBuMaYF") == 0) {
          extern mxArray *sf_c5_lateral_control2_get_autoinheritance_info(void);
          plhs[0] = sf_c5_lateral_control2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lateral_control2_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_lateral_control2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_lateral_control2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_lateral_control2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_lateral_control2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_lateral_control2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_lateral_control2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void lateral_control2_debug_initialize(void)
{
  _lateral_control2MachineNumber_ = sf_debug_initialize_machine(
    "lateral_control2","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(_lateral_control2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_lateral_control2MachineNumber_,0);
}

void lateral_control2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_lateral_control2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "lateral_control2", "lateral_control2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_lateral_control2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
