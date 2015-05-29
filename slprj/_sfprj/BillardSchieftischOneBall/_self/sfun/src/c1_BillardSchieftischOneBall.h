#ifndef __c1_BillardSchieftischOneBall_h__
#define __c1_BillardSchieftischOneBall_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc1_BillardSchieftischOneBallInstanceStruct
#define typedef_SFc1_BillardSchieftischOneBallInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Roll;
  boolean_T c1_isStable;
  boolean_T c1_stateChanged;
  real_T c1_lastMajorTime;
  uint8_T c1_is_active_c1_BillardSchieftischOneBall;
  uint8_T c1_is_c1_BillardSchieftischOneBall;
  real_T c1_r;
  real_T c1_p1[2];
  real_T c1_p2[2];
  real_T c1_p3[2];
  real_T c1_p4[2];
  real_T c1_x0[2];
  real_T c1_v0[2];
  real_T c1_t[8];
  real_T c1_n[8];
  real_T c1_dist[4];
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  void *c1_testPointAddrMap[1];
  real_T (*c1_x)[2];
  real_T (*c1_v)[2];
  real_T (*c1_x_out)[2];
} SFc1_BillardSchieftischOneBallInstanceStruct;

#endif                                 /*typedef_SFc1_BillardSchieftischOneBallInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_BillardSchieftischOneBall_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_BillardSchieftischOneBall_get_check_sum(mxArray *plhs[]);
extern void c1_BillardSchieftischOneBall_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
