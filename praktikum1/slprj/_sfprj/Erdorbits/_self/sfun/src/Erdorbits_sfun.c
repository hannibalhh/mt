/* Include files */

#include "Erdorbits_sfun.h"
#include "Erdorbits_sfun_debug_macros.h"
#include "c1_Erdorbits.h"
#include "c2_Erdorbits.h"
#include "c3_Erdorbits.h"
#include "c4_Erdorbits.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ErdorbitsMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Erdorbits_initializer(void)
{
}

void Erdorbits_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Erdorbits_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Erdorbits_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Erdorbits_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Erdorbits_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Erdorbits_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Erdorbits_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Erdorbits_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2141063144U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1589782289U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1355562221U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2802650836U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(581846107U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3331217892U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3349713667U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1928517669U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Erdorbits_get_check_sum(mxArray *plhs[]);
          sf_c1_Erdorbits_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Erdorbits_get_check_sum(mxArray *plhs[]);
          sf_c2_Erdorbits_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Erdorbits_get_check_sum(mxArray *plhs[]);
          sf_c3_Erdorbits_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Erdorbits_get_check_sum(mxArray *plhs[]);
          sf_c4_Erdorbits_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2515920432U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3908508645U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2530489944U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2924353608U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4138602619U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1858187429U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1137776892U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2803758139U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Erdorbits_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "z57mwCjCtttj4qpZSbZB8C") == 0) {
          extern mxArray *sf_c1_Erdorbits_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Erdorbits_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "S7bvMKCbIcq7xnza10mOwF") == 0) {
          extern mxArray *sf_c2_Erdorbits_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Erdorbits_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "CDhUvjJG2EMcybUrUdle1B") == 0) {
          extern mxArray *sf_c3_Erdorbits_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Erdorbits_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "RfX0ZA6bnT2Ui2f5pG9RZC") == 0) {
          extern mxArray *sf_c4_Erdorbits_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Erdorbits_get_autoinheritance_info();
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

unsigned int sf_Erdorbits_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_Erdorbits_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Erdorbits_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_Erdorbits_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Erdorbits_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_Erdorbits_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Erdorbits_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Erdorbits_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Erdorbits_get_eml_resolved_functions_info();
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

unsigned int sf_Erdorbits_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "LhRWY4pURcwH1nE5CZRSmE") == 0) {
          extern mxArray *sf_c1_Erdorbits_third_party_uses_info(void);
          plhs[0] = sf_c1_Erdorbits_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PKsk2lrLmeOHPle4sac9EH") == 0) {
          extern mxArray *sf_c2_Erdorbits_third_party_uses_info(void);
          plhs[0] = sf_c2_Erdorbits_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "wgsakTvRKXZuxrayu5EIJ") == 0) {
          extern mxArray *sf_c3_Erdorbits_third_party_uses_info(void);
          plhs[0] = sf_c3_Erdorbits_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "9Rq55etPOKUChU7z71c3NC") == 0) {
          extern mxArray *sf_c4_Erdorbits_third_party_uses_info(void);
          plhs[0] = sf_c4_Erdorbits_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Erdorbits_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "LhRWY4pURcwH1nE5CZRSmE") == 0) {
          extern mxArray *sf_c1_Erdorbits_jit_fallback_info(void);
          plhs[0] = sf_c1_Erdorbits_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PKsk2lrLmeOHPle4sac9EH") == 0) {
          extern mxArray *sf_c2_Erdorbits_jit_fallback_info(void);
          plhs[0] = sf_c2_Erdorbits_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "wgsakTvRKXZuxrayu5EIJ") == 0) {
          extern mxArray *sf_c3_Erdorbits_jit_fallback_info(void);
          plhs[0] = sf_c3_Erdorbits_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "9Rq55etPOKUChU7z71c3NC") == 0) {
          extern mxArray *sf_c4_Erdorbits_jit_fallback_info(void);
          plhs[0] = sf_c4_Erdorbits_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Erdorbits_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "LhRWY4pURcwH1nE5CZRSmE") == 0) {
          extern mxArray *sf_c1_Erdorbits_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Erdorbits_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PKsk2lrLmeOHPle4sac9EH") == 0) {
          extern mxArray *sf_c2_Erdorbits_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Erdorbits_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "wgsakTvRKXZuxrayu5EIJ") == 0) {
          extern mxArray *sf_c3_Erdorbits_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Erdorbits_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "9Rq55etPOKUChU7z71c3NC") == 0) {
          extern mxArray *sf_c4_Erdorbits_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Erdorbits_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Erdorbits_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "LhRWY4pURcwH1nE5CZRSmE") == 0) {
        extern mxArray *sf_c1_Erdorbits_get_post_codegen_info(void);
        plhs[0] = sf_c1_Erdorbits_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "PKsk2lrLmeOHPle4sac9EH") == 0) {
        extern mxArray *sf_c2_Erdorbits_get_post_codegen_info(void);
        plhs[0] = sf_c2_Erdorbits_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "wgsakTvRKXZuxrayu5EIJ") == 0) {
        extern mxArray *sf_c3_Erdorbits_get_post_codegen_info(void);
        plhs[0] = sf_c3_Erdorbits_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "9Rq55etPOKUChU7z71c3NC") == 0) {
        extern mxArray *sf_c4_Erdorbits_get_post_codegen_info(void);
        plhs[0] = sf_c4_Erdorbits_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Erdorbits_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _ErdorbitsMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Erdorbits","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_ErdorbitsMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_ErdorbitsMachineNumber_,0);
}

void Erdorbits_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Erdorbits_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Erdorbits",
      "Erdorbits");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Erdorbits_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
