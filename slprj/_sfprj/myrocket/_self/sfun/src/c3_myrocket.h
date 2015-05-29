#ifndef __c3_myrocket_h__
#define __c3_myrocket_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_myrocketInstanceStruct
#define typedef_SFc3_myrocketInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Antriebslos;
  uint8_T c3_tp_Stufe2;
  uint8_T c3_tp_Stufe1;
  boolean_T c3_isStable;
  boolean_T c3_stateChanged;
  real_T c3_lastMajorTime;
  uint8_T c3_is_active_c3_myrocket;
  uint8_T c3_is_c3_myrocket;
  real_T c3_rE;
  real_T c3_mE;
  real_T c3_G;
  real_T c3_m1_leer;
  real_T c3_m2_leer;
  real_T c3_St1_Treibstoff;
  real_T c3_St2_Treibstoff;
  real_T c3_Durchsatz_1;
  real_T c3_Durchsatz_2;
  real_T c3_SchubProDurchsatz;
  boolean_T c3_dataWrittenToVector[18];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T *c3_x1_out;
  real_T *c3_x2_out;
  real_T *c3_v1_out;
  real_T *c3_v2_out;
  real_T *c3_x1;
  real_T *c3_x2;
  real_T *c3_v1;
  real_T *c3_v2;
  real_T *c3_m1;
  real_T *c3_m2;
  real_T *c3_m1_out;
  real_T *c3_m2_out;
} SFc3_myrocketInstanceStruct;

#endif                                 /*typedef_SFc3_myrocketInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_myrocket_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_myrocket_get_check_sum(mxArray *plhs[]);
extern void c3_myrocket_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
