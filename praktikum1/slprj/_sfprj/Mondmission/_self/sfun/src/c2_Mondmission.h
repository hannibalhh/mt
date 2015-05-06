#ifndef __c2_Mondmission_h__
#define __c2_Mondmission_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_MondmissionInstanceStruct
#define typedef_SFc2_MondmissionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Mondmission;
  real_T *c2_theta;
  real_T *c2_v0;
  real_T (*c2_x0)[2];
  real_T (*c2_v0welt)[2];
} SFc2_MondmissionInstanceStruct;

#endif                                 /*typedef_SFc2_MondmissionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Mondmission_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Mondmission_get_check_sum(mxArray *plhs[]);
extern void c2_Mondmission_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
