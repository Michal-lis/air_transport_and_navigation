/* Include files */

#include "udpReceive_example_sfun.h"
#include "c2_udpReceive_example.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _udpReceive_exampleMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void udpReceive_example_initializer(void)
{
}

void udpReceive_example_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_udpReceive_example_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_udpReceive_example_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_udpReceive_example_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2714127397U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1342697392U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2322890733U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4185539820U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4248309713U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2866943518U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(71688626U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(192977127U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_udpReceive_example_get_check_sum(mxArray *plhs[]);
          sf_c2_udpReceive_example_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1364419805U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2764653824U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2249386536U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(447431750U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_udpReceive_example_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(aiChksum, "53Iqod9wjMEurE9YZG0AfH") == 0) {
          extern mxArray *sf_c2_udpReceive_example_get_autoinheritance_info(void);
          plhs[0] = sf_c2_udpReceive_example_get_autoinheritance_info();
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

unsigned int sf_udpReceive_example_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c2_udpReceive_example_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_udpReceive_example_get_eml_resolved_functions_info();
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

void udpReceive_example_debug_initialize(void)
{
  _udpReceive_exampleMachineNumber_ = sf_debug_initialize_machine(
    "udpReceive_example","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_udpReceive_exampleMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_udpReceive_exampleMachineNumber_,0);
}

void udpReceive_example_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_udpReceive_example_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "udpReceive_example", "udpReceive_example");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_udpReceive_example_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
