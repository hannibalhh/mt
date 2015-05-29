#ifndef __c2_tisch_h__
#define __c2_tisch_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_tischInstanceStruct
#define typedef_SFc2_tischInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_tisch;
  real_T *c2_u;
  real_T *c2_xpp;
  real_T *c2_m;
  real_T *c2_c;
  real_T *c2_d;
  real_T *c2_x;
  real_T *c2_v1;
  real_T *c2_v2;
} SFc2_tischInstanceStruct;

#endif                                 /*typedef_SFc2_tischInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_tisch_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_tisch_get_check_sum(mxArray *plhs[]);
extern void c2_tisch_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
