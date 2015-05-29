#ifndef __c3_Flipper_h__
#define __c3_Flipper_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_FlipperInstanceStruct
#define typedef_SFc3_FlipperInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Flipper;
  boolean_T c3_isStable;
  boolean_T c3_stateChanged;
  real_T c3_lastMajorTime;
  uint8_T c3_is_active_c3_Flipper;
  uint8_T c3_is_c3_Flipper;
  real_T c3_R;
  real_T c3_RHnd;
  real_T c3_Hnd[2];
  real_T c3_n1[2];
  real_T c3_n2[2];
  real_T c3_n3[2];
  real_T c3_p1[2];
  real_T c3_p2[2];
  real_T c3_p3[2];
  real_T c3_p4[2];
  real_T c3_t1[2];
  real_T c3_t2[2];
  real_T c3_t3[2];
  boolean_T c3_dataWrittenToVector[19];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T (*c3_v1)[2];
  real_T (*c3_x1)[2];
  real_T (*c3_x1_out)[2];
} SFc3_FlipperInstanceStruct;

#endif                                 /*typedef_SFc3_FlipperInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Flipper_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Flipper_get_check_sum(mxArray *plhs[]);
extern void c3_Flipper_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
