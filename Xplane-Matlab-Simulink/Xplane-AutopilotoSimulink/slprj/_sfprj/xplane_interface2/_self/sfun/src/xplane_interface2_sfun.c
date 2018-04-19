/* Include files */

#include "xplane_interface2_sfun.h"
#include "c1_xplane_interface2.h"
#include "c2_xplane_interface2.h"
#include "c3_xplane_interface2.h"
#include "c4_xplane_interface2.h"
#include "c5_xplane_interface2.h"
#include "c6_xplane_interface2.h"
#include "c7_xplane_interface2.h"
#include "c8_xplane_interface2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _xplane_interface2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void xplane_interface2_initializer(void)
{
}

void xplane_interface2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_xplane_interface2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_xplane_interface2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_xplane_interface2_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4229797454U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4267523916U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4061443529U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1039935155U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2144621485U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3664346410U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(736538376U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3866871382U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c1_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c2_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c3_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c4_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c5_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c6_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c7_xplane_interface2_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_xplane_interface2_get_check_sum(mxArray *plhs[]);
          sf_c8_xplane_interface2_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2988722914U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(415853905U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2540824170U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3136088641U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_xplane_interface2_autoinheritance_info( int nlhs, mxArray *
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
     case 1:
      {
        if (strcmp(aiChksum, "1Cmcrz5Oj0KMvWS45ZftIC") == 0) {
          extern mxArray *sf_c1_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "wtfjBmjkGsUsqo61CMhif") == 0) {
          extern mxArray *sf_c2_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "zwFvRgB1q82tltrg0rdf9E") == 0) {
          extern mxArray *sf_c3_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "Y1JOoYAhxKpuHImjc3NIqH") == 0) {
          extern mxArray *sf_c4_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c4_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "mWJ6verXwfjo4Cefl3mHYC") == 0) {
          extern mxArray *sf_c5_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c5_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "qE97Oz8uqvGCWmeLbGMNoB") == 0) {
          extern mxArray *sf_c6_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c6_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "MyjRSMkTuTZhDKNJxMGdzC") == 0) {
          extern mxArray *sf_c7_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c7_xplane_interface2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "y7PgmeyFQGmuSkcKlynFHC") == 0) {
          extern mxArray *sf_c8_xplane_interface2_get_autoinheritance_info(void);
          plhs[0] = sf_c8_xplane_interface2_get_autoinheritance_info();
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

unsigned int sf_xplane_interface2_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_xplane_interface2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_xplane_interface2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_xplane_interface2_get_eml_resolved_functions_info();
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

void xplane_interface2_debug_initialize(void)
{
  _xplane_interface2MachineNumber_ = sf_debug_initialize_machine(
    "xplane_interface2","sfun",0,8,0,0,0);
  sf_debug_set_machine_event_thresholds(_xplane_interface2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_xplane_interface2MachineNumber_,0);
}

void xplane_interface2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_xplane_interface2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "xplane_interface2", "xplane_interface2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_xplane_interface2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
