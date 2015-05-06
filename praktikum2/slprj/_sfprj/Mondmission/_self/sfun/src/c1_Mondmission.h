#ifndef __c1_Mondmission_h__
#define __c1_Mondmission_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_MondmissionInstanceStruct
#define typedef_SFc1_MondmissionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Mondmission;
  real_T *c1_delta;
  real_T (*c1_x0)[2];
  real_T *c1_hoehe;
} SFc1_MondmissionInstanceStruct;

#endif                                 /*typedef_SFc1_MondmissionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Mondmission_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Mondmission_get_check_sum(mxArray *plhs[]);
extern void c1_Mondmission_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
