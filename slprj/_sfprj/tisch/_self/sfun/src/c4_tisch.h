#ifndef __c4_tisch_h__
#define __c4_tisch_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_tischInstanceStruct
#define typedef_SFc4_tischInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_tisch;
  real_T *c4_m;
  real_T *c4_y;
  real_T *c4_c;
} SFc4_tischInstanceStruct;

#endif                                 /*typedef_SFc4_tischInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_tisch_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_tisch_get_check_sum(mxArray *plhs[]);
extern void c4_tisch_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
