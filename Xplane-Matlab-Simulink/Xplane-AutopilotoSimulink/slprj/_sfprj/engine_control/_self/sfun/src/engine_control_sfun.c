/* Include files */

#include "engine_control_sfun.h"
#include "c2_engine_control.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _engine_controlMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void engine_control_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void engine_control_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_engine_control_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_engine_control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_engine_control_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(458718871U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3487547682U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3031478344U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(885241565U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4231367979U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2578099746U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(41651897U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(537933093U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_engine_control_get_check_sum(mxArray *plhs[]);
          sf_c2_engine_control_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3431108939U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3492008416U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1511005255U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2400379370U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_engine_control_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_engine_control_get_autoinheritance_info(void);
        plhs[0] = sf_c2_engine_control_get_autoinheritance_info();
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

unsigned int sf_engine_control_get_eml_resolved_functions_info( int nlhs,
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
     case 2:
      {
        extern const mxArray
          *sf_c2_engine_control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_engine_control_get_eml_resolved_functions_info();
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

void engine_control_debug_initialize(void)
{
  _engine_controlMachineNumber_ = sf_debug_initialize_machine("engine_control",
    "sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_engine_controlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_engine_controlMachineNumber_,0);
}

void engine_control_register_exported_symbols(SimStruct* S)
{
}
