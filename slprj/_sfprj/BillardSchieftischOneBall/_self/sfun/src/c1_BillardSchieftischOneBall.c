/* Include files */

#include <stddef.h>
#include "blas.h"
#include "BillardSchieftischOneBall_sfun.h"
#include "c1_BillardSchieftischOneBall.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BillardSchieftischOneBall_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Roll                     ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[7] = { "d1", "d2", "d3", "d4",
  "nargin", "nargout", "fl" };

static const char * c1_c_debug_family_names[5] = { "fl", "vt", "vn", "nargin",
  "nargout" };

/* Function Declarations */
static void initialize_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void initialize_params_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void enable_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void disable_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void set_sim_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void c1_set_sim_state_side_effects_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void finalize_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void sf_gateway_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void mdl_start_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void zeroCrossings_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void derivatives_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void outputs_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void initSimStructsc1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_eml_ini_fcn_to_be_inlined_64
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_eml_term_fcn_to_be_inlined_64
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const int32_T
   c1_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_fl, const char_T *c1_identifier);
static int32_T c1_d_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_c_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_d_emlrt_marshallOut(const uint32_T c1_u);
static real_T c1_norm(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance, real_T c1_b_x[2]);
static real_T c1_genpnorm(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2]);
static void c1_eml_index_class(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static real_T c1_eml_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2]);
static void c1_inline(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance);
static real_T c1_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2]);
static boolean_T c1_use_refblas(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_below_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static real_T c1_b_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2]);
static void c1_realmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_eml_realmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_eml_float_model(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_eml_int_forloop_overflow_check
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_eml_int_forloop_overflow_check_helper
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_isfi(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_isnumerictype(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_b_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance);
static int32_T c1_intmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static real_T c1_abs(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance,
                     real_T c1_b_x);
static real_T c1_eml_scalar_abs(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x);
static void c1_mrdivide(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_A[2], real_T c1_B, real_T c1_y[2]);
static void c1_assert(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance);
static void c1_rdivide(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y, real_T c1_z[2]);
static void c1_b_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_eml_scalexp_compatible
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_eml_div(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y, real_T c1_z[2]);
static void c1_div(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance,
                   real_T c1_b_x[2], real_T c1_y, real_T c1_z[2]);
static real_T c1_eml_mtimes_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance, real_T c1_a[2], real_T c1_b[2]);
static void c1_common_checks(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_c_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_dynamic_size_checks(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance);
static void c1_eml_scalar_eg(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_scalarEg(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_any_enums(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_zerosum(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_b_zerosum(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static real_T c1_eml_xdotu(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2]);
static real_T c1_xdotu(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2]);
static real_T c1_xdot(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance, real_T c1_b_x[2], real_T c1_y[2]);
static void c1_b_below_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_b_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void c1_c_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance);
static real_T c1_b_xdot(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2]);
static real_T c1_xdotx(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2]);
static void c1_b_eml_mtimes_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance, real_T c1_a, real_T c1_b[2], real_T c1_y[2]);
static void c1_b_common_checks(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const uint8_T
   c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_b_tp_Roll, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[2]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_p1, const char_T *c1_identifier, real_T
  c1_y[2]);
static void c1_h_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[8]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_t, const char_T *c1_identifier, real_T
  c1_y[8]);
static void c1_j_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[4]);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_dist, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_l_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void c1_m_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_n_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_o_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_test_point_addr_map
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void **get_test_point_address_map
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance);
static void init_simulink_io_address
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_Roll = 0U;
  chartInstance->c1_is_active_c1_BillardSchieftischOneBall = 0U;
  chartInstance->c1_is_c1_BillardSchieftischOneBall = c1_IN_NO_ACTIVE_CHILD;
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    chartInstance->c1_p1[c1_i0] = 0.0;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    chartInstance->c1_p2[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    chartInstance->c1_p3[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_p4[c1_i3] = 0.0;
  }

  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    (*chartInstance->c1_x)[c1_i4] = 0.0;
  }

  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    (*chartInstance->c1_v)[c1_i5] = 0.0;
  }

  for (c1_i6 = 0; c1_i6 < 8; c1_i6++) {
    chartInstance->c1_t[c1_i6] = 0.0;
  }

  for (c1_i7 = 0; c1_i7 < 8; c1_i7++) {
    chartInstance->c1_n[c1_i7] = 0.0;
  }

  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    chartInstance->c1_dist[c1_i8] = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
      (*chartInstance->c1_x_out)[c1_i9] = 0.0;
    }
  }
}

static void initialize_params_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_dv0[2];
  int32_T c1_i10;
  real_T c1_dv1[2];
  int32_T c1_i11;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c1_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_r = c1_d0;
  sf_mex_import_named("x0", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c1_dv0, 0, 0, 0U, 1, 0U, 1, 2);
  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    chartInstance->c1_x0[c1_i10] = c1_dv0[c1_i10];
  }

  sf_mex_import_named("v0", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c1_dv1, 0, 0, 0U, 1, 0U, 1, 2);
  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    chartInstance->c1_v0[c1_i11] = c1_dv1[c1_i11];
  }
}

static void enable_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_BillardSchieftischOneBall == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_BillardSchieftischOneBall == c1_IN_Roll) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_i_emlrt_marshallOut(chartInstance), false);
  return c1_st;
}

static void set_sim_state_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_BillardSchieftischOneBall(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_BillardSchieftischOneBall == c1_IN_Roll) {
      chartInstance->c1_tp_Roll = 1U;
    } else {
      chartInstance->c1_tp_Roll = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  real_T c1_dv2[2];
  int32_T c1_i31;
  real_T c1_dv3[2];
  real_T c1_dv4[2];
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  real_T c1_dv5[2];
  int32_T c1_i35;
  real_T c1_dv6[2];
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  real_T c1_dv7[2];
  int32_T c1_i39;
  real_T c1_dv8[2];
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  real_T c1_dv9[2];
  int32_T c1_i43;
  real_T c1_dv10[2];
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  uint32_T c1_b_debug_family_var_map[7];
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i47;
  real_T c1_dv11[2];
  int32_T c1_i48;
  int32_T c1_i49;
  real_T c1_dv12[2];
  int32_T c1_i50;
  real_T c1_dv13[2];
  int32_T c1_i51;
  int32_T c1_i52;
  real_T c1_dv14[2];
  int32_T c1_i53;
  real_T c1_dv15[2];
  int32_T c1_i54;
  int32_T c1_i55;
  real_T c1_dv16[2];
  int32_T c1_i56;
  real_T c1_dv17[2];
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_dv18[2];
  boolean_T c1_out;
  uint32_T c1_c_debug_family_var_map[5];
  int32_T c1_fl;
  real_T c1_vt;
  real_T c1_vn;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_b_d1;
  real_T c1_b_d2;
  real_T c1_b_d3;
  real_T c1_b_d4;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  int32_T c1_i59;
  real_T c1_dv19[2];
  int32_T c1_i60;
  int32_T c1_i61;
  real_T c1_dv20[2];
  int32_T c1_i62;
  real_T c1_dv21[2];
  int32_T c1_i63;
  int32_T c1_i64;
  real_T c1_dv22[2];
  int32_T c1_i65;
  real_T c1_dv23[2];
  int32_T c1_i66;
  int32_T c1_i67;
  real_T c1_dv24[2];
  int32_T c1_i68;
  real_T c1_dv25[2];
  int32_T c1_i69;
  int32_T c1_i70;
  real_T c1_dv26[2];
  int32_T c1_i71;
  real_T c1_dv27[2];
  int32_T c1_i72;
  int32_T c1_i73;
  real_T c1_dv28[2];
  int32_T c1_i74;
  real_T c1_dv29[2];
  int32_T c1_i75;
  int32_T c1_i76;
  real_T c1_dv30[2];
  int32_T c1_i77;
  int32_T c1_i78;
  real_T c1_dv31[2];
  real_T c1_dv32[2];
  int32_T c1_i79;
  int32_T c1_i80;
  real_T c1_dv33[2];
  real_T c1_dv34[2];
  int32_T c1_i81;
  int32_T c1_i82;
  real_T c1_dv35[2];
  int32_T c1_i83;
  int32_T c1_i84;
  real_T c1_dv36[2];
  int32_T c1_i85;
  real_T c1_dv37[2];
  int32_T c1_i86;
  int32_T c1_i87;
  real_T c1_dv38[2];
  int32_T c1_i88;
  int32_T c1_i89;
  real_T c1_dv39[2];
  int32_T c1_i90;
  int32_T c1_i91;
  real_T c1_dv40[2];
  int32_T c1_i92;
  int32_T c1_i93;
  real_T c1_dv41[2];
  int32_T c1_i94;
  int32_T c1_i95;
  real_T c1_dv42[2];
  int32_T c1_i96;
  real_T c1_dv43[2];
  int32_T c1_i97;
  int32_T c1_i98;
  real_T c1_dv44[2];
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_dv45[2];
  int32_T c1_i101;
  int32_T c1_i102;
  real_T c1_dv46[2];
  int32_T c1_i103;
  int32_T c1_i104;
  real_T c1_dv47[2];
  int32_T c1_i105;
  int32_T c1_i106;
  real_T c1_dv48[2];
  int32_T c1_i107;
  real_T c1_dv49[2];
  int32_T c1_i108;
  int32_T c1_i109;
  real_T c1_dv50[2];
  int32_T c1_i110;
  int32_T c1_i111;
  real_T c1_dv51[2];
  int32_T c1_i112;
  int32_T c1_i113;
  real_T c1_dv52[2];
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  c1_set_sim_state_side_effects_c1_BillardSchieftischOneBall(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    chartInstance->c1_lastMajorTime = _sfTime_;
    chartInstance->c1_stateChanged = false;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 0U);
    for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_p1[c1_i12], 1U);
    }

    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_p2[c1_i13], 2U);
    }

    for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_p3[c1_i14], 3U);
    }

    for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_p4[c1_i15], 4U);
    }

    for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x)[c1_i16], 5U);
    }

    for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c1_v)[c1_i17], 6U);
    }

    for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x_out)[c1_i18], 7U);
    }

    for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_x0[c1_i19], 8U);
    }

    for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_v0[c1_i20], 9U);
    }

    for (c1_i21 = 0; c1_i21 < 8; c1_i21++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_t[c1_i21], 10U);
    }

    for (c1_i22 = 0; c1_i22 < 8; c1_i22++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_n[c1_i22], 11U);
    }

    for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_dist[c1_i23], 12U);
    }

    chartInstance->c1_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_active_c1_BillardSchieftischOneBall == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_stateChanged = true;
      chartInstance->c1_is_active_c1_BillardSchieftischOneBall = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      CV_EML_FCN(0, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
      for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
        chartInstance->c1_p1[c1_i24] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
      for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
        chartInstance->c1_p2[c1_i25] = 1.0 - (real_T)c1_i25;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
      for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
        chartInstance->c1_p3[c1_i26] = 1.0 + (real_T)c1_i26;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
      for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
        chartInstance->c1_p4[c1_i27] = (real_T)c1_i27;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
      for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
        (*chartInstance->c1_x)[c1_i28] = chartInstance->c1_x0[c1_i28];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
      for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
        (*chartInstance->c1_v)[c1_i29] = chartInstance->c1_v0[c1_i29];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
      for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
        c1_dv2[c1_i30] = chartInstance->c1_p2[c1_i30] - chartInstance->
          c1_p1[c1_i30];
      }

      for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
        c1_dv3[c1_i31] = chartInstance->c1_p2[c1_i31] - chartInstance->
          c1_p1[c1_i31];
      }

      c1_mrdivide(chartInstance, c1_dv3, c1_norm(chartInstance, c1_dv2), c1_dv4);
      c1_i32 = 0;
      for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
        chartInstance->c1_t[c1_i32] = c1_dv4[c1_i33];
        c1_i32 += 4;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
      for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
        c1_dv5[c1_i34] = chartInstance->c1_p3[c1_i34] - chartInstance->
          c1_p2[c1_i34];
      }

      for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
        c1_dv6[c1_i35] = chartInstance->c1_p3[c1_i35] - chartInstance->
          c1_p2[c1_i35];
      }

      c1_mrdivide(chartInstance, c1_dv6, c1_norm(chartInstance, c1_dv5), c1_dv4);
      c1_i36 = 0;
      for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
        chartInstance->c1_t[c1_i36 + 1] = c1_dv4[c1_i37];
        c1_i36 += 4;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
      for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
        c1_dv7[c1_i38] = chartInstance->c1_p4[c1_i38] - chartInstance->
          c1_p3[c1_i38];
      }

      for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
        c1_dv8[c1_i39] = chartInstance->c1_p4[c1_i39] - chartInstance->
          c1_p3[c1_i39];
      }

      c1_mrdivide(chartInstance, c1_dv8, c1_norm(chartInstance, c1_dv7), c1_dv4);
      c1_i40 = 0;
      for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
        chartInstance->c1_t[c1_i40 + 2] = c1_dv4[c1_i41];
        c1_i40 += 4;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      for (c1_i42 = 0; c1_i42 < 2; c1_i42++) {
        c1_dv9[c1_i42] = chartInstance->c1_p1[c1_i42] - chartInstance->
          c1_p4[c1_i42];
      }

      for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
        c1_dv10[c1_i43] = chartInstance->c1_p1[c1_i43] - chartInstance->
          c1_p4[c1_i43];
      }

      c1_mrdivide(chartInstance, c1_dv10, c1_norm(chartInstance, c1_dv9), c1_dv4);
      c1_i44 = 0;
      for (c1_i45 = 0; c1_i45 < 2; c1_i45++) {
        chartInstance->c1_t[c1_i44 + 3] = c1_dv4[c1_i45];
        c1_i44 += 4;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      chartInstance->c1_n[0] = -chartInstance->c1_t[4];
      chartInstance->c1_n[4] = chartInstance->c1_t[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      chartInstance->c1_n[1] = -chartInstance->c1_t[5];
      chartInstance->c1_n[5] = chartInstance->c1_t[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
      chartInstance->c1_n[2] = -chartInstance->c1_t[6];
      chartInstance->c1_n[6] = chartInstance->c1_t[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
      chartInstance->c1_n[3] = -chartInstance->c1_t[7];
      chartInstance->c1_n[7] = chartInstance->c1_t[3];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -21);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c1_stateChanged = true;
      chartInstance->c1_is_c1_BillardSchieftischOneBall = c1_IN_Roll;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Roll = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_SET_DATA_VALUE_PTR(13U, &c1_i46);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_b_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d1, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d2, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d3, 2U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d4, 3U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 4U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 5U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i46, 6U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      CV_EML_FCN(3, 0);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 4);
      for (c1_i47 = 0; c1_i47 < 2; c1_i47++) {
        c1_dv11[c1_i47] = (*chartInstance->c1_x)[c1_i47] - chartInstance->
          c1_p1[c1_i47];
      }

      c1_i48 = 0;
      for (c1_i49 = 0; c1_i49 < 2; c1_i49++) {
        c1_dv12[c1_i49] = chartInstance->c1_n[c1_i48];
        c1_i48 += 4;
      }

      c1_d1 = c1_eml_mtimes_helper(chartInstance, c1_dv11, c1_dv12);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 5);
      for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
        c1_dv13[c1_i50] = (*chartInstance->c1_x)[c1_i50] - chartInstance->
          c1_p2[c1_i50];
      }

      c1_i51 = 0;
      for (c1_i52 = 0; c1_i52 < 2; c1_i52++) {
        c1_dv14[c1_i52] = chartInstance->c1_n[c1_i51 + 1];
        c1_i51 += 4;
      }

      c1_d2 = c1_eml_mtimes_helper(chartInstance, c1_dv13, c1_dv14);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 6);
      for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
        c1_dv15[c1_i53] = (*chartInstance->c1_x)[c1_i53] - chartInstance->
          c1_p3[c1_i53];
      }

      c1_i54 = 0;
      for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
        c1_dv16[c1_i55] = chartInstance->c1_n[c1_i54 + 2];
        c1_i54 += 4;
      }

      c1_d3 = c1_eml_mtimes_helper(chartInstance, c1_dv15, c1_dv16);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 7);
      for (c1_i56 = 0; c1_i56 < 2; c1_i56++) {
        c1_dv17[c1_i56] = (*chartInstance->c1_x)[c1_i56] - chartInstance->
          c1_p4[c1_i56];
      }

      c1_i57 = 0;
      for (c1_i58 = 0; c1_i58 < 2; c1_i58++) {
        c1_dv18[c1_i58] = chartInstance->c1_n[c1_i57 + 3];
        c1_i57 += 4;
      }

      c1_d4 = c1_eml_mtimes_helper(chartInstance, c1_dv17, c1_dv18);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 12);
      if (CV_EML_IF(3, 1, 0, CV_RELATIONAL_EVAL(4U, 3U, 0, c1_d1,
            chartInstance->c1_r, -1, 3U, c1_d1 <= chartInstance->c1_r))) {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 13);
        c1_i46 = 1;
      } else {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 14);
        if (CV_EML_IF(3, 1, 1, CV_RELATIONAL_EVAL(4U, 3U, 1, c1_d2,
              chartInstance->c1_r, -1, 3U, c1_d2 <= chartInstance->c1_r))) {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 15);
          c1_i46 = 2;
        } else {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 16);
          if (CV_EML_IF(3, 1, 2, CV_RELATIONAL_EVAL(4U, 3U, 2, c1_d3,
                chartInstance->c1_r, -1, 3U, c1_d3 <= chartInstance->c1_r))) {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 17);
            c1_i46 = 3;
          } else {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 18);
            if (CV_EML_IF(3, 1, 3, CV_RELATIONAL_EVAL(4U, 3U, 3, c1_d4,
                  chartInstance->c1_r, -1, 3U, c1_d4 <= chartInstance->c1_r))) {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 19);
              c1_i46 = 4;
            } else {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 21);
              c1_i46 = 0;
            }
          }
        }
      }

      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -21);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_UNSET_DATA_VALUE_PTR(13U);
      c1_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)c1_i46, 0.0, 0, 1U,
        c1_i46 != 0) != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_c_debug_family_names,
          c1_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_fl, 0U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_vt, 1U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_vn, 2U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 3U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 4U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        CV_EML_FCN(1, 0);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 7);
        _SFD_SET_DATA_VALUE_PTR(13U, &c1_fl);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_b_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_d1, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_d2, 1U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_d3, 2U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_d4, 3U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 4U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 5U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_fl, 6U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        CV_EML_FCN(3, 0);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 4);
        for (c1_i59 = 0; c1_i59 < 2; c1_i59++) {
          c1_dv19[c1_i59] = (*chartInstance->c1_x)[c1_i59] -
            chartInstance->c1_p1[c1_i59];
        }

        c1_i60 = 0;
        for (c1_i61 = 0; c1_i61 < 2; c1_i61++) {
          c1_dv20[c1_i61] = chartInstance->c1_n[c1_i60];
          c1_i60 += 4;
        }

        c1_b_d1 = c1_eml_mtimes_helper(chartInstance, c1_dv19, c1_dv20);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 5);
        for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
          c1_dv21[c1_i62] = (*chartInstance->c1_x)[c1_i62] -
            chartInstance->c1_p2[c1_i62];
        }

        c1_i63 = 0;
        for (c1_i64 = 0; c1_i64 < 2; c1_i64++) {
          c1_dv22[c1_i64] = chartInstance->c1_n[c1_i63 + 1];
          c1_i63 += 4;
        }

        c1_b_d2 = c1_eml_mtimes_helper(chartInstance, c1_dv21, c1_dv22);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 6);
        for (c1_i65 = 0; c1_i65 < 2; c1_i65++) {
          c1_dv23[c1_i65] = (*chartInstance->c1_x)[c1_i65] -
            chartInstance->c1_p3[c1_i65];
        }

        c1_i66 = 0;
        for (c1_i67 = 0; c1_i67 < 2; c1_i67++) {
          c1_dv24[c1_i67] = chartInstance->c1_n[c1_i66 + 2];
          c1_i66 += 4;
        }

        c1_b_d3 = c1_eml_mtimes_helper(chartInstance, c1_dv23, c1_dv24);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 7);
        for (c1_i68 = 0; c1_i68 < 2; c1_i68++) {
          c1_dv25[c1_i68] = (*chartInstance->c1_x)[c1_i68] -
            chartInstance->c1_p4[c1_i68];
        }

        c1_i69 = 0;
        for (c1_i70 = 0; c1_i70 < 2; c1_i70++) {
          c1_dv26[c1_i70] = chartInstance->c1_n[c1_i69 + 3];
          c1_i69 += 4;
        }

        c1_b_d4 = c1_eml_mtimes_helper(chartInstance, c1_dv25, c1_dv26);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 12);
        if (CV_EML_IF(3, 1, 0, CV_RELATIONAL_EVAL(4U, 3U, 0, c1_b_d1,
              chartInstance->c1_r, -1, 3U, c1_b_d1 <= chartInstance->c1_r))) {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 13);
          c1_fl = 1;
        } else {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 14);
          if (CV_EML_IF(3, 1, 1, CV_RELATIONAL_EVAL(4U, 3U, 1, c1_b_d2,
                chartInstance->c1_r, -1, 3U, c1_b_d2 <= chartInstance->c1_r))) {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 15);
            c1_fl = 2;
          } else {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 16);
            if (CV_EML_IF(3, 1, 2, CV_RELATIONAL_EVAL(4U, 3U, 2, c1_b_d3,
                  chartInstance->c1_r, -1, 3U, c1_b_d3 <= chartInstance->c1_r)))
            {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 17);
              c1_fl = 3;
            } else {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 18);
              if (CV_EML_IF(3, 1, 3, CV_RELATIONAL_EVAL(4U, 3U, 3, c1_b_d4,
                    chartInstance->c1_r, -1, 3U, c1_b_d4 <= chartInstance->c1_r)))
              {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 19);
                c1_fl = 4;
              } else {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 21);
                c1_fl = 0;
              }
            }
          }
        }

        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -21);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_UNSET_DATA_VALUE_PTR(13U);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 10);
        switch (c1_fl) {
         case 1:
          CV_EML_SWITCH(1, 1, 0, 1);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 12);
          for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
            c1_dv27[c1_i71] = (*chartInstance->c1_v)[c1_i71];
          }

          c1_i72 = 0;
          for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
            c1_dv28[c1_i73] = chartInstance->c1_t[c1_i72];
            c1_i72 += 4;
          }

          c1_vt = c1_eml_mtimes_helper(chartInstance, c1_dv27, c1_dv28);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 13);
          for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
            c1_dv29[c1_i74] = (*chartInstance->c1_v)[c1_i74];
          }

          c1_i75 = 0;
          for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
            c1_dv30[c1_i76] = chartInstance->c1_n[c1_i75];
            c1_i75 += 4;
          }

          c1_vn = c1_eml_mtimes_helper(chartInstance, c1_dv29, c1_dv30);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 14);
          c1_i77 = 0;
          for (c1_i78 = 0; c1_i78 < 2; c1_i78++) {
            c1_dv31[c1_i78] = chartInstance->c1_t[c1_i77];
            c1_i77 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vt, c1_dv31, c1_dv32);
          c1_i79 = 0;
          for (c1_i80 = 0; c1_i80 < 2; c1_i80++) {
            c1_dv33[c1_i80] = chartInstance->c1_n[c1_i79];
            c1_i79 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vn, c1_dv33, c1_dv34);
          for (c1_i81 = 0; c1_i81 < 2; c1_i81++) {
            (*chartInstance->c1_v)[c1_i81] = c1_dv32[c1_i81] - c1_dv34[c1_i81];
          }
          break;

         case 2:
          CV_EML_SWITCH(1, 1, 0, 2);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 16);
          for (c1_i82 = 0; c1_i82 < 2; c1_i82++) {
            c1_dv35[c1_i82] = (*chartInstance->c1_v)[c1_i82];
          }

          c1_i83 = 0;
          for (c1_i84 = 0; c1_i84 < 2; c1_i84++) {
            c1_dv36[c1_i84] = chartInstance->c1_t[c1_i83 + 1];
            c1_i83 += 4;
          }

          c1_vt = c1_eml_mtimes_helper(chartInstance, c1_dv35, c1_dv36);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 17);
          for (c1_i85 = 0; c1_i85 < 2; c1_i85++) {
            c1_dv37[c1_i85] = (*chartInstance->c1_v)[c1_i85];
          }

          c1_i86 = 0;
          for (c1_i87 = 0; c1_i87 < 2; c1_i87++) {
            c1_dv38[c1_i87] = chartInstance->c1_n[c1_i86 + 1];
            c1_i86 += 4;
          }

          c1_vn = c1_eml_mtimes_helper(chartInstance, c1_dv37, c1_dv38);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 18);
          c1_i88 = 0;
          for (c1_i89 = 0; c1_i89 < 2; c1_i89++) {
            c1_dv39[c1_i89] = chartInstance->c1_t[c1_i88 + 1];
            c1_i88 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vt, c1_dv39, c1_dv32);
          c1_i90 = 0;
          for (c1_i91 = 0; c1_i91 < 2; c1_i91++) {
            c1_dv40[c1_i91] = chartInstance->c1_n[c1_i90 + 1];
            c1_i90 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vn, c1_dv40, c1_dv34);
          for (c1_i92 = 0; c1_i92 < 2; c1_i92++) {
            (*chartInstance->c1_v)[c1_i92] = c1_dv32[c1_i92] - c1_dv34[c1_i92];
          }
          break;

         case 3:
          CV_EML_SWITCH(1, 1, 0, 3);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 20);
          for (c1_i93 = 0; c1_i93 < 2; c1_i93++) {
            c1_dv41[c1_i93] = (*chartInstance->c1_v)[c1_i93];
          }

          c1_i94 = 0;
          for (c1_i95 = 0; c1_i95 < 2; c1_i95++) {
            c1_dv42[c1_i95] = chartInstance->c1_t[c1_i94 + 2];
            c1_i94 += 4;
          }

          c1_vt = c1_eml_mtimes_helper(chartInstance, c1_dv41, c1_dv42);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 21);
          for (c1_i96 = 0; c1_i96 < 2; c1_i96++) {
            c1_dv43[c1_i96] = (*chartInstance->c1_v)[c1_i96];
          }

          c1_i97 = 0;
          for (c1_i98 = 0; c1_i98 < 2; c1_i98++) {
            c1_dv44[c1_i98] = chartInstance->c1_n[c1_i97 + 2];
            c1_i97 += 4;
          }

          c1_vn = c1_eml_mtimes_helper(chartInstance, c1_dv43, c1_dv44);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 22);
          c1_i99 = 0;
          for (c1_i100 = 0; c1_i100 < 2; c1_i100++) {
            c1_dv45[c1_i100] = chartInstance->c1_t[c1_i99 + 2];
            c1_i99 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vt, c1_dv45, c1_dv32);
          c1_i101 = 0;
          for (c1_i102 = 0; c1_i102 < 2; c1_i102++) {
            c1_dv46[c1_i102] = chartInstance->c1_n[c1_i101 + 2];
            c1_i101 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vn, c1_dv46, c1_dv34);
          for (c1_i103 = 0; c1_i103 < 2; c1_i103++) {
            (*chartInstance->c1_v)[c1_i103] = c1_dv32[c1_i103] - c1_dv34[c1_i103];
          }
          break;

         case 4:
          CV_EML_SWITCH(1, 1, 0, 4);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 24);
          for (c1_i104 = 0; c1_i104 < 2; c1_i104++) {
            c1_dv47[c1_i104] = (*chartInstance->c1_v)[c1_i104];
          }

          c1_i105 = 0;
          for (c1_i106 = 0; c1_i106 < 2; c1_i106++) {
            c1_dv48[c1_i106] = chartInstance->c1_t[c1_i105 + 3];
            c1_i105 += 4;
          }

          c1_vt = c1_eml_mtimes_helper(chartInstance, c1_dv47, c1_dv48);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 25);
          for (c1_i107 = 0; c1_i107 < 2; c1_i107++) {
            c1_dv49[c1_i107] = (*chartInstance->c1_v)[c1_i107];
          }

          c1_i108 = 0;
          for (c1_i109 = 0; c1_i109 < 2; c1_i109++) {
            c1_dv50[c1_i109] = chartInstance->c1_n[c1_i108 + 3];
            c1_i108 += 4;
          }

          c1_vn = c1_eml_mtimes_helper(chartInstance, c1_dv49, c1_dv50);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 26);
          c1_i110 = 0;
          for (c1_i111 = 0; c1_i111 < 2; c1_i111++) {
            c1_dv51[c1_i111] = chartInstance->c1_t[c1_i110 + 3];
            c1_i110 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vt, c1_dv51, c1_dv32);
          c1_i112 = 0;
          for (c1_i113 = 0; c1_i113 < 2; c1_i113++) {
            c1_dv52[c1_i113] = chartInstance->c1_n[c1_i112 + 3];
            c1_i112 += 4;
          }

          c1_b_eml_mtimes_helper(chartInstance, c1_vn, c1_dv52, c1_dv34);
          for (c1_i114 = 0; c1_i114 < 2; c1_i114++) {
            (*chartInstance->c1_v)[c1_i114] = c1_dv32[c1_i114] - c1_dv34[c1_i114];
          }
          break;

         default:
          CV_EML_SWITCH(1, 1, 0, 0);
          break;
        }

        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -26);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c1_tp_Roll = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_stateChanged = true;
        chartInstance->c1_is_c1_BillardSchieftischOneBall = c1_IN_Roll;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Roll = 1U;
      } else {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
  for (c1_i115 = 0; c1_i115 < 2; c1_i115++) {
    (*chartInstance->c1_x_out)[c1_i115] = (*chartInstance->c1_x)[c1_i115];
  }

  for (c1_i116 = 0; c1_i116 < 2; c1_i116++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x_out)[c1_i116], 7U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_BillardSchieftischOneBallMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  int32_T c1_i117;
  uint32_T c1_debug_family_var_map[7];
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i118;
  real_T c1_dv53[2];
  int32_T c1_i119;
  int32_T c1_i120;
  real_T c1_dv54[2];
  int32_T c1_i121;
  real_T c1_dv55[2];
  int32_T c1_i122;
  int32_T c1_i123;
  real_T c1_dv56[2];
  int32_T c1_i124;
  real_T c1_dv57[2];
  int32_T c1_i125;
  int32_T c1_i126;
  real_T c1_dv58[2];
  int32_T c1_i127;
  real_T c1_dv59[2];
  int32_T c1_i128;
  int32_T c1_i129;
  real_T c1_dv60[2];
  boolean_T c1_out;
  real_T *c1_zcVar;
  c1_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    chartInstance->c1_stateChanged = false;
    if (chartInstance->c1_is_active_c1_BillardSchieftischOneBall == 0U) {
      chartInstance->c1_stateChanged = true;
    } else {
      _SFD_SET_DATA_VALUE_PTR(13U, &c1_i117);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_b_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d1, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d2, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d3, 2U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d4, 3U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i117, 6U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      CV_EML_FCN(3, 0);
      for (c1_i118 = 0; c1_i118 < 2; c1_i118++) {
        c1_dv53[c1_i118] = (*chartInstance->c1_x)[c1_i118] -
          chartInstance->c1_p1[c1_i118];
      }

      c1_i119 = 0;
      for (c1_i120 = 0; c1_i120 < 2; c1_i120++) {
        c1_dv54[c1_i120] = chartInstance->c1_n[c1_i119];
        c1_i119 += 4;
      }

      c1_d1 = c1_eml_mtimes_helper(chartInstance, c1_dv53, c1_dv54);
      for (c1_i121 = 0; c1_i121 < 2; c1_i121++) {
        c1_dv55[c1_i121] = (*chartInstance->c1_x)[c1_i121] -
          chartInstance->c1_p2[c1_i121];
      }

      c1_i122 = 0;
      for (c1_i123 = 0; c1_i123 < 2; c1_i123++) {
        c1_dv56[c1_i123] = chartInstance->c1_n[c1_i122 + 1];
        c1_i122 += 4;
      }

      c1_d2 = c1_eml_mtimes_helper(chartInstance, c1_dv55, c1_dv56);
      for (c1_i124 = 0; c1_i124 < 2; c1_i124++) {
        c1_dv57[c1_i124] = (*chartInstance->c1_x)[c1_i124] -
          chartInstance->c1_p3[c1_i124];
      }

      c1_i125 = 0;
      for (c1_i126 = 0; c1_i126 < 2; c1_i126++) {
        c1_dv58[c1_i126] = chartInstance->c1_n[c1_i125 + 2];
        c1_i125 += 4;
      }

      c1_d3 = c1_eml_mtimes_helper(chartInstance, c1_dv57, c1_dv58);
      for (c1_i127 = 0; c1_i127 < 2; c1_i127++) {
        c1_dv59[c1_i127] = (*chartInstance->c1_x)[c1_i127] -
          chartInstance->c1_p4[c1_i127];
      }

      c1_i128 = 0;
      for (c1_i129 = 0; c1_i129 < 2; c1_i129++) {
        c1_dv60[c1_i129] = chartInstance->c1_n[c1_i128 + 3];
        c1_i128 += 4;
      }

      c1_d4 = c1_eml_mtimes_helper(chartInstance, c1_dv59, c1_dv60);
      if (CV_EML_IF(3, 1, 0, CV_RELATIONAL_EVAL(4U, 3U, 0, c1_d1,
            chartInstance->c1_r, -1, 3U, c1_d1 <= chartInstance->c1_r))) {
        c1_i117 = 1;
      } else if (CV_EML_IF(3, 1, 1, CV_RELATIONAL_EVAL(4U, 3U, 1, c1_d2,
                   chartInstance->c1_r, -1, 3U, c1_d2 <= chartInstance->c1_r)))
      {
        c1_i117 = 2;
      } else if (CV_EML_IF(3, 1, 2, CV_RELATIONAL_EVAL(4U, 3U, 2, c1_d3,
                   chartInstance->c1_r, -1, 3U, c1_d3 <= chartInstance->c1_r)))
      {
        c1_i117 = 3;
      } else if (CV_EML_IF(3, 1, 3, CV_RELATIONAL_EVAL(4U, 3U, 3, c1_d4,
                   chartInstance->c1_r, -1, 3U, c1_d4 <= chartInstance->c1_r)))
      {
        c1_i117 = 4;
      } else {
        c1_i117 = 0;
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_UNSET_DATA_VALUE_PTR(13U);
      c1_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)c1_i117, 0.0, 0, 1U,
        c1_i117 != 0) != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_out) {
        chartInstance->c1_stateChanged = true;
      }
    }

    if (chartInstance->c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  int32_T c1_i130;
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  int32_T c1_i134;
  int32_T c1_i135;
  int32_T c1_i136;
  int32_T c1_i137;
  int32_T c1_i138;
  real_T (*c1_x_dot)[2];
  real_T (*c1_v_dot)[2];
  c1_v_dot = (real_T (*)[2])(ssGetdX_wrapper(chartInstance->S) + 2);
  c1_x_dot = (real_T (*)[2])(ssGetdX_wrapper(chartInstance->S) + 0);
  for (c1_i130 = 0; c1_i130 < 2; c1_i130++) {
    (*c1_x_dot)[c1_i130] = 0.0;
  }

  for (c1_i131 = 0; c1_i131 < 2; c1_i131++) {
    _SFD_DATA_RANGE_CHECK((*c1_x_dot)[c1_i131], 5U);
  }

  for (c1_i132 = 0; c1_i132 < 2; c1_i132++) {
    (*c1_v_dot)[c1_i132] = 0.0;
  }

  for (c1_i133 = 0; c1_i133 < 2; c1_i133++) {
    _SFD_DATA_RANGE_CHECK((*c1_v_dot)[c1_i133], 6U);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
  for (c1_i134 = 0; c1_i134 < 2; c1_i134++) {
    (*c1_x_dot)[c1_i134] = (*chartInstance->c1_v)[c1_i134];
  }

  for (c1_i135 = 0; c1_i135 < 2; c1_i135++) {
    _SFD_DATA_RANGE_CHECK((*c1_x_dot)[c1_i135], 5U);
  }

  for (c1_i136 = 0; c1_i136 < 2; c1_i136++) {
    (*c1_v_dot)[c1_i136] = 0.0;
  }

  for (c1_i137 = 0; c1_i137 < 2; c1_i137++) {
    _SFD_DATA_RANGE_CHECK((*c1_v_dot)[c1_i137], 6U);
  }

  for (c1_i138 = 0; c1_i138 < 2; c1_i138++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x_out)[c1_i138], 7U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
}

static void outputs_c1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  int32_T c1_i139;
  int32_T c1_i140;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
  for (c1_i139 = 0; c1_i139 < 2; c1_i139++) {
    (*chartInstance->c1_x_out)[c1_i139] = (*chartInstance->c1_x)[c1_i139];
  }

  for (c1_i140 = 0; c1_i140 < 2; c1_i140++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x_out)[c1_i140], 7U);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_BillardSchieftischOneBall
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_ini_fcn_to_be_inlined_64
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_term_fcn_to_be_inlined_64
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance, *(real_T
    *)c1_inData), false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  *(real_T *)c1_outData = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const int32_T
   c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    *(int32_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_fl, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_fl), &c1_thisId);
  sf_mex_destroy(&c1_fl);
  return c1_y;
}

static int32_T c1_d_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i141;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i141, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i141;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  *(int32_T *)c1_outData = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_BillardSchieftischOneBall_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 52, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
  const mxArray *c1_rhs39 = NULL;
  const mxArray *c1_lhs39 = NULL;
  const mxArray *c1_rhs40 = NULL;
  const mxArray *c1_lhs40 = NULL;
  const mxArray *c1_rhs41 = NULL;
  const mxArray *c1_lhs41 = NULL;
  const mxArray *c1_rhs42 = NULL;
  const mxArray *c1_lhs42 = NULL;
  const mxArray *c1_rhs43 = NULL;
  const mxArray *c1_lhs43 = NULL;
  const mxArray *c1_rhs44 = NULL;
  const mxArray *c1_lhs44 = NULL;
  const mxArray *c1_rhs45 = NULL;
  const mxArray *c1_lhs45 = NULL;
  const mxArray *c1_rhs46 = NULL;
  const mxArray *c1_lhs46 = NULL;
  const mxArray *c1_rhs47 = NULL;
  const mxArray *c1_lhs47 = NULL;
  const mxArray *c1_rhs48 = NULL;
  const mxArray *c1_lhs48 = NULL;
  const mxArray *c1_rhs49 = NULL;
  const mxArray *c1_lhs49 = NULL;
  const mxArray *c1_rhs50 = NULL;
  const mxArray *c1_lhs50 = NULL;
  const mxArray *c1_rhs51 = NULL;
  const mxArray *c1_lhs51 = NULL;
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("norm"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 1);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  3);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1375980692U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 6);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 7);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 8);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 9);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("realmin"), "name", "name",
                  10);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 11);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 13);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 21);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("intmin"), "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("abs"), "name", "name", 23);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 25);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "context", "context", 26);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("mrdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 27);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 27);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 28);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("rdivide"), "name", "name",
                  28);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 30);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_div"), "name", "name",
                  31);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 32);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "context", "context", 33);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 34);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 36);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 37);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  39);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c1_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 40);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c1_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 41);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c1_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 42);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 42);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c1_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 43);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 43);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c1_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 44);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 44);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c1_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 45);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c1_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 46);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 46);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c1_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 47);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c1_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 48);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 48);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c1_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 49);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 49);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c1_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 50);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c1_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 51);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c1_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs51), "lhs", "lhs",
                  51);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
  sf_mex_destroy(&c1_rhs39);
  sf_mex_destroy(&c1_lhs39);
  sf_mex_destroy(&c1_rhs40);
  sf_mex_destroy(&c1_lhs40);
  sf_mex_destroy(&c1_rhs41);
  sf_mex_destroy(&c1_lhs41);
  sf_mex_destroy(&c1_rhs42);
  sf_mex_destroy(&c1_lhs42);
  sf_mex_destroy(&c1_rhs43);
  sf_mex_destroy(&c1_lhs43);
  sf_mex_destroy(&c1_rhs44);
  sf_mex_destroy(&c1_lhs44);
  sf_mex_destroy(&c1_rhs45);
  sf_mex_destroy(&c1_lhs45);
  sf_mex_destroy(&c1_rhs46);
  sf_mex_destroy(&c1_lhs46);
  sf_mex_destroy(&c1_rhs47);
  sf_mex_destroy(&c1_lhs47);
  sf_mex_destroy(&c1_rhs48);
  sf_mex_destroy(&c1_lhs48);
  sf_mex_destroy(&c1_rhs49);
  sf_mex_destroy(&c1_lhs49);
  sf_mex_destroy(&c1_rhs50);
  sf_mex_destroy(&c1_lhs50);
  sf_mex_destroy(&c1_rhs51);
  sf_mex_destroy(&c1_lhs51);
}

static const mxArray *c1_c_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_d_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static real_T c1_norm(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance, real_T c1_b_x[2])
{
  int32_T c1_i142;
  real_T c1_c_x[2];
  for (c1_i142 = 0; c1_i142 < 2; c1_i142++) {
    c1_c_x[c1_i142] = c1_b_x[c1_i142];
  }

  return c1_genpnorm(chartInstance, c1_c_x);
}

static real_T c1_genpnorm(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2])
{
  int32_T c1_i143;
  real_T c1_c_x[2];
  for (c1_i143 = 0; c1_i143 < 2; c1_i143++) {
    c1_c_x[c1_i143] = c1_b_x[c1_i143];
  }

  return c1_eml_xnrm2(chartInstance, c1_c_x);
}

static void c1_eml_index_class(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_eml_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2])
{
  int32_T c1_i144;
  real_T c1_c_x[2];
  for (c1_i144 = 0; c1_i144 < 2; c1_i144++) {
    c1_c_x[c1_i144] = c1_b_x[c1_i144];
  }

  return c1_xnrm2(chartInstance, c1_c_x);
}

static void c1_inline(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2])
{
  int32_T c1_i145;
  real_T c1_c_x[2];
  for (c1_i145 = 0; c1_i145 < 2; c1_i145++) {
    c1_c_x[c1_i145] = c1_b_x[c1_i145];
  }

  return c1_b_xnrm2(chartInstance, c1_c_x);
}

static boolean_T c1_use_refblas(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
  return false;
}

static void c1_below_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_b_xnrm2(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2])
{
  real_T c1_y;
  real_T c1_scale;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_absxk;
  real_T c1_b_t;
  c1_y = 0.0;
  c1_scale = 2.2250738585072014E-308;
  for (c1_k = 1; c1_k < 3; c1_k++) {
    c1_b_k = c1_k;
    c1_absxk = c1_abs(chartInstance, c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 2, 1, 0) - 1]);
    if (c1_absxk > c1_scale) {
      c1_b_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_b_t * c1_b_t;
      c1_scale = c1_absxk;
    } else {
      c1_b_t = c1_absxk / c1_scale;
      c1_y += c1_b_t * c1_b_t;
    }
  }

  return c1_scale * muDoubleScalarSqrt(c1_y);
}

static void c1_realmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_realmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_float_model(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_int_forloop_overflow_check
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_int_forloop_overflow_check_helper
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_isfi(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_isnumerictype(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_b_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static int32_T c1_intmin(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static real_T c1_abs(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance,
                     real_T c1_b_x)
{
  return c1_eml_scalar_abs(chartInstance, c1_b_x);
}

static real_T c1_eml_scalar_abs(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x)
{
  (void)chartInstance;
  return muDoubleScalarAbs(c1_b_x);
}

static void c1_mrdivide(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_A[2], real_T c1_B, real_T c1_y[2])
{
  int32_T c1_i146;
  real_T c1_b_A[2];
  for (c1_i146 = 0; c1_i146 < 2; c1_i146++) {
    c1_b_A[c1_i146] = c1_A[c1_i146];
  }

  c1_rdivide(chartInstance, c1_b_A, c1_B, c1_y);
}

static void c1_assert(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance)
{
  (void)chartInstance;
}

static void c1_rdivide(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y, real_T c1_z[2])
{
  int32_T c1_i147;
  real_T c1_c_x[2];
  for (c1_i147 = 0; c1_i147 < 2; c1_i147++) {
    c1_c_x[c1_i147] = c1_b_x[c1_i147];
  }

  c1_eml_div(chartInstance, c1_c_x, c1_y, c1_z);
}

static void c1_b_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_scalexp_compatible
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_div(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y, real_T c1_z[2])
{
  int32_T c1_i148;
  real_T c1_c_x[2];
  for (c1_i148 = 0; c1_i148 < 2; c1_i148++) {
    c1_c_x[c1_i148] = c1_b_x[c1_i148];
  }

  c1_div(chartInstance, c1_c_x, c1_y, c1_z);
}

static void c1_div(SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance,
                   real_T c1_b_x[2], real_T c1_y, real_T c1_z[2])
{
  int32_T c1_i149;
  (void)chartInstance;
  for (c1_i149 = 0; c1_i149 < 2; c1_i149++) {
    c1_z[c1_i149] = c1_b_x[c1_i149] / c1_y;
  }
}

static real_T c1_eml_mtimes_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance, real_T c1_a[2], real_T c1_b[2])
{
  real_T c1_y;
  real_T c1_d2;
  int32_T c1_i150;
  int32_T c1_i151;
  real_T c1_b_a[2];
  int32_T c1_i152;
  real_T c1_b_b[2];
  if (c1_use_refblas(chartInstance)) {
    c1_d2 = 0.0;
    for (c1_i150 = 0; c1_i150 < 2; c1_i150++) {
      c1_d2 += c1_a[c1_i150] * c1_b[c1_i150];
    }

    c1_y = c1_d2;
  } else {
    for (c1_i151 = 0; c1_i151 < 2; c1_i151++) {
      c1_b_a[c1_i151] = c1_a[c1_i151];
    }

    for (c1_i152 = 0; c1_i152 < 2; c1_i152++) {
      c1_b_b[c1_i152] = c1_b[c1_i152];
    }

    c1_y = c1_eml_xdotu(chartInstance, c1_b_a, c1_b_b);
  }

  return c1_y;
}

static void c1_common_checks(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_c_isBuiltInNumeric(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_dynamic_size_checks(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_scalar_eg(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_scalarEg(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_any_enums(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_zerosum(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_b_zerosum(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_eml_xdotu(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2])
{
  int32_T c1_i153;
  real_T c1_c_x[2];
  int32_T c1_i154;
  real_T c1_b_y[2];
  for (c1_i153 = 0; c1_i153 < 2; c1_i153++) {
    c1_c_x[c1_i153] = c1_b_x[c1_i153];
  }

  for (c1_i154 = 0; c1_i154 < 2; c1_i154++) {
    c1_b_y[c1_i154] = c1_y[c1_i154];
  }

  return c1_xdotu(chartInstance, c1_c_x, c1_b_y);
}

static real_T c1_xdotu(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2])
{
  int32_T c1_i155;
  real_T c1_c_x[2];
  int32_T c1_i156;
  real_T c1_b_y[2];
  for (c1_i155 = 0; c1_i155 < 2; c1_i155++) {
    c1_c_x[c1_i155] = c1_b_x[c1_i155];
  }

  for (c1_i156 = 0; c1_i156 < 2; c1_i156++) {
    c1_b_y[c1_i156] = c1_y[c1_i156];
  }

  return c1_xdot(chartInstance, c1_c_x, c1_b_y);
}

static real_T c1_xdot(SFc1_BillardSchieftischOneBallInstanceStruct
                      *chartInstance, real_T c1_b_x[2], real_T c1_y[2])
{
  int32_T c1_i157;
  real_T c1_c_x[2];
  int32_T c1_i158;
  real_T c1_b_y[2];
  for (c1_i157 = 0; c1_i157 < 2; c1_i157++) {
    c1_c_x[c1_i157] = c1_b_x[c1_i157];
  }

  for (c1_i158 = 0; c1_i158 < 2; c1_i158++) {
    c1_b_y[c1_i158] = c1_y[c1_i158];
  }

  return c1_b_xdot(chartInstance, c1_c_x, c1_b_y);
}

static void c1_b_below_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_b_threshold(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_c_eml_switch_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static real_T c1_b_xdot(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2])
{
  int32_T c1_i159;
  real_T c1_c_x[2];
  int32_T c1_i160;
  real_T c1_b_y[2];
  for (c1_i159 = 0; c1_i159 < 2; c1_i159++) {
    c1_c_x[c1_i159] = c1_b_x[c1_i159];
  }

  for (c1_i160 = 0; c1_i160 < 2; c1_i160++) {
    c1_b_y[c1_i160] = c1_y[c1_i160];
  }

  return c1_xdotx(chartInstance, c1_c_x, c1_b_y);
}

static real_T c1_xdotx(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, real_T c1_b_x[2], real_T c1_y[2])
{
  real_T c1_d;
  int32_T c1_k;
  int32_T c1_b_k;
  (void)chartInstance;
  c1_d = 0.0;
  for (c1_k = 1; c1_k < 3; c1_k++) {
    c1_b_k = c1_k;
    c1_d += c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_b_k), 1, 2, 1, 0) - 1] * c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 2, 1, 0) - 1];
  }

  return c1_d;
}

static void c1_b_eml_mtimes_helper(SFc1_BillardSchieftischOneBallInstanceStruct *
  chartInstance, real_T c1_a, real_T c1_b[2], real_T c1_y[2])
{
  int32_T c1_i161;
  (void)chartInstance;
  for (c1_i161 = 0; c1_i161 < 2; c1_i161++) {
    c1_y[c1_i161] = c1_a * c1_b[c1_i161];
  }
}

static void c1_b_common_checks(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const uint8_T
   c1_u)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_e_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c1_inData), false);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_b_tp_Roll, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Roll),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Roll);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  *(uint8_T *)c1_outData = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[2])
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  return c1_y;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_f_emlrt_marshallOut(chartInstance,
    *(real_T (*)[2])c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_p1, const char_T *c1_identifier, real_T
  c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_p1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_p1);
}

static void c1_h_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv61[2];
  int32_T c1_i162;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv61, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i162 = 0; c1_i162 < 2; c1_i162++) {
    c1_y[c1_i162] = c1_dv61[c1_i162];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv62[2];
  int32_T c1_i163;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv62);
  for (c1_i163 = 0; c1_i163 < 2; c1_i163++) {
    (*(real_T (*)[2])c1_outData)[c1_i163] = c1_dv62[c1_i163];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[8])
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 2), false);
  return c1_y;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_g_emlrt_marshallOut(chartInstance,
    *(real_T (*)[8])c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_t, const char_T *c1_identifier, real_T
  c1_y[8])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_t), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_t);
}

static void c1_j_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv63[8];
  int32_T c1_i164;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv63, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c1_i164 = 0; c1_i164 < 8; c1_i164++) {
    c1_y[c1_i164] = c1_dv63[c1_i164];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv64[8];
  int32_T c1_i165;
  int32_T c1_i166;
  int32_T c1_i167;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv64);
  c1_i165 = 0;
  for (c1_i166 = 0; c1_i166 < 2; c1_i166++) {
    for (c1_i167 = 0; c1_i167 < 4; c1_i167++) {
      (*(real_T (*)[8])c1_outData)[c1_i167 + c1_i165] = c1_dv64[c1_i167 +
        c1_i165];
    }

    c1_i165 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const real_T
   c1_u[4])
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), false);
  return c1_y;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_h_emlrt_marshallOut(chartInstance,
    *(real_T (*)[4])c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_b_dist, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_dist), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_dist);
}

static void c1_l_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv65[4];
  int32_T c1_i168;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv65, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i168 = 0; c1_i168 < 4; c1_i168++) {
    c1_y[c1_i168] = c1_dv65[c1_i168];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv66[4];
  int32_T c1_i169;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInstanceVoid;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv66);
  for (c1_i169 = 0; c1_i169 < 4; c1_i169++) {
    (*(real_T (*)[4])c1_outData)[c1_i169] = c1_dv66[c1_i169];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_emlrt_marshallOut
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  const mxArray *c1_y;
  int32_T c1_i170;
  real_T c1_dv67[2];
  int32_T c1_i171;
  real_T c1_dv68[4];
  int32_T c1_i172;
  real_T c1_dv69[8];
  int32_T c1_i173;
  real_T c1_dv70[2];
  int32_T c1_i174;
  real_T c1_dv71[2];
  int32_T c1_i175;
  real_T c1_dv72[2];
  int32_T c1_i176;
  real_T c1_dv73[2];
  int32_T c1_i177;
  real_T c1_dv74[8];
  int32_T c1_i178;
  real_T c1_dv75[2];
  int32_T c1_i179;
  real_T c1_dv76[2];
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(12, 1), false);
  for (c1_i170 = 0; c1_i170 < 2; c1_i170++) {
    c1_dv67[c1_i170] = (*chartInstance->c1_x_out)[c1_i170];
  }

  sf_mex_setcell(c1_y, 0, c1_f_emlrt_marshallOut(chartInstance, c1_dv67));
  for (c1_i171 = 0; c1_i171 < 4; c1_i171++) {
    c1_dv68[c1_i171] = chartInstance->c1_dist[c1_i171];
  }

  sf_mex_setcell(c1_y, 1, c1_h_emlrt_marshallOut(chartInstance, c1_dv68));
  for (c1_i172 = 0; c1_i172 < 8; c1_i172++) {
    c1_dv69[c1_i172] = chartInstance->c1_n[c1_i172];
  }

  sf_mex_setcell(c1_y, 2, c1_g_emlrt_marshallOut(chartInstance, c1_dv69));
  for (c1_i173 = 0; c1_i173 < 2; c1_i173++) {
    c1_dv70[c1_i173] = chartInstance->c1_p1[c1_i173];
  }

  sf_mex_setcell(c1_y, 3, c1_f_emlrt_marshallOut(chartInstance, c1_dv70));
  for (c1_i174 = 0; c1_i174 < 2; c1_i174++) {
    c1_dv71[c1_i174] = chartInstance->c1_p2[c1_i174];
  }

  sf_mex_setcell(c1_y, 4, c1_f_emlrt_marshallOut(chartInstance, c1_dv71));
  for (c1_i175 = 0; c1_i175 < 2; c1_i175++) {
    c1_dv72[c1_i175] = chartInstance->c1_p3[c1_i175];
  }

  sf_mex_setcell(c1_y, 5, c1_f_emlrt_marshallOut(chartInstance, c1_dv72));
  for (c1_i176 = 0; c1_i176 < 2; c1_i176++) {
    c1_dv73[c1_i176] = chartInstance->c1_p4[c1_i176];
  }

  sf_mex_setcell(c1_y, 6, c1_f_emlrt_marshallOut(chartInstance, c1_dv73));
  for (c1_i177 = 0; c1_i177 < 8; c1_i177++) {
    c1_dv74[c1_i177] = chartInstance->c1_t[c1_i177];
  }

  sf_mex_setcell(c1_y, 7, c1_g_emlrt_marshallOut(chartInstance, c1_dv74));
  for (c1_i178 = 0; c1_i178 < 2; c1_i178++) {
    c1_dv75[c1_i178] = (*chartInstance->c1_v)[c1_i178];
  }

  sf_mex_setcell(c1_y, 8, c1_f_emlrt_marshallOut(chartInstance, c1_dv75));
  for (c1_i179 = 0; c1_i179 < 2; c1_i179++) {
    c1_dv76[c1_i179] = (*chartInstance->c1_x)[c1_i179];
  }

  sf_mex_setcell(c1_y, 9, c1_f_emlrt_marshallOut(chartInstance, c1_dv76));
  sf_mex_setcell(c1_y, 10, c1_e_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_active_c1_BillardSchieftischOneBall));
  sf_mex_setcell(c1_y, 11, c1_e_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_c1_BillardSchieftischOneBall));
  return c1_y;
}

static void c1_m_emlrt_marshallIn(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  real_T c1_dv77[2];
  int32_T c1_i180;
  real_T c1_dv78[4];
  int32_T c1_i181;
  real_T c1_dv79[8];
  int32_T c1_i182;
  real_T c1_dv80[2];
  int32_T c1_i183;
  real_T c1_dv81[2];
  int32_T c1_i184;
  real_T c1_dv82[2];
  int32_T c1_i185;
  real_T c1_dv83[2];
  int32_T c1_i186;
  real_T c1_dv84[8];
  int32_T c1_i187;
  real_T c1_dv85[2];
  int32_T c1_i188;
  real_T c1_dv86[2];
  int32_T c1_i189;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "x_out", c1_dv77);
  for (c1_i180 = 0; c1_i180 < 2; c1_i180++) {
    (*chartInstance->c1_x_out)[c1_i180] = c1_dv77[c1_i180];
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "dist", c1_dv78);
  for (c1_i181 = 0; c1_i181 < 4; c1_i181++) {
    chartInstance->c1_dist[c1_i181] = c1_dv78[c1_i181];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)), "n",
                        c1_dv79);
  for (c1_i182 = 0; c1_i182 < 8; c1_i182++) {
    chartInstance->c1_n[c1_i182] = c1_dv79[c1_i182];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)), "p1",
                        c1_dv80);
  for (c1_i183 = 0; c1_i183 < 2; c1_i183++) {
    chartInstance->c1_p1[c1_i183] = c1_dv80[c1_i183];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)), "p2",
                        c1_dv81);
  for (c1_i184 = 0; c1_i184 < 2; c1_i184++) {
    chartInstance->c1_p2[c1_i184] = c1_dv81[c1_i184];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)), "p3",
                        c1_dv82);
  for (c1_i185 = 0; c1_i185 < 2; c1_i185++) {
    chartInstance->c1_p3[c1_i185] = c1_dv82[c1_i185];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)), "p4",
                        c1_dv83);
  for (c1_i186 = 0; c1_i186 < 2; c1_i186++) {
    chartInstance->c1_p4[c1_i186] = c1_dv83[c1_i186];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)), "t",
                        c1_dv84);
  for (c1_i187 = 0; c1_i187 < 8; c1_i187++) {
    chartInstance->c1_t[c1_i187] = c1_dv84[c1_i187];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)), "v",
                        c1_dv85);
  for (c1_i188 = 0; c1_i188 < 2; c1_i188++) {
    (*chartInstance->c1_v)[c1_i188] = c1_dv85[c1_i188];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 9)), "x",
                        c1_dv86);
  for (c1_i189 = 0; c1_i189 < 2; c1_i189++) {
    (*chartInstance->c1_x)[c1_i189] = c1_dv86[c1_i189];
  }

  chartInstance->c1_is_active_c1_BillardSchieftischOneBall =
    c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
    "is_active_c1_BillardSchieftischOneBall");
  chartInstance->c1_is_c1_BillardSchieftischOneBall = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 11)),
     "is_c1_BillardSchieftischOneBall");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 12)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_n_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_o_emlrt_marshallIn
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_test_point_addr_map
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  chartInstance->c1_testPointAddrMap[0] = chartInstance->c1_v;
}

static void **get_test_point_address_map
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointMappingInfo;
}

static void init_dsm_address_info(SFc1_BillardSchieftischOneBallInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance)
{
  chartInstance->c1_x = (real_T (*)[2])(ssGetContStates_wrapper(chartInstance->S)
    + 0);
  chartInstance->c1_v = (real_T (*)[2])(ssGetContStates_wrapper(chartInstance->S)
    + 2);
  chartInstance->c1_x_out = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_BillardSchieftischOneBall_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1531155432U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(200798301U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2742560091U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3623444602U);
}

mxArray* sf_c1_BillardSchieftischOneBall_get_post_codegen_info(void);
mxArray *sf_c1_BillardSchieftischOneBall_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JmnHjYgA83AJWcfJMthA0");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_BillardSchieftischOneBall_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_BillardSchieftischOneBall_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_BillardSchieftischOneBall_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_BillardSchieftischOneBall_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_BillardSchieftischOneBall_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_BillardSchieftischOneBall(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[9],T\"x_out\",},{M[3],M[19],T\"dist\",},{M[3],M[18],T\"n\",},{M[3],M[2],T\"p1\",},{M[3],M[3],T\"p2\",},{M[3],M[4],T\"p3\",},{M[3],M[5],T\"p4\",},{M[3],M[17],T\"t\",},{M[5],M[7],T\"v\",},{M[5],M[6],T\"x\",}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_BillardSchieftischOneBall\",},{M[9],M[0],T\"is_c1_BillardSchieftischOneBall\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_BillardSchieftischOneBall_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _BillardSchieftischOneBallMachineNumber_,
           1,
           4,
           2,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_BillardSchieftischOneBallMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _BillardSchieftischOneBallMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _BillardSchieftischOneBallMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,0,0,0,"p1");
          _SFD_SET_DATA_PROPS(2,0,0,0,"p2");
          _SFD_SET_DATA_PROPS(3,0,0,0,"p3");
          _SFD_SET_DATA_PROPS(4,0,0,0,"p4");
          _SFD_SET_DATA_PROPS(5,0,0,0,"x");
          _SFD_SET_DATA_PROPS(6,0,0,0,"v");
          _SFD_SET_DATA_PROPS(7,2,0,1,"x_out");
          _SFD_SET_DATA_PROPS(8,10,0,0,"x0");
          _SFD_SET_DATA_PROPS(9,10,0,0,"v0");
          _SFD_SET_DATA_PROPS(10,0,0,0,"t");
          _SFD_SET_DATA_PROPS(11,0,0,0,"n");
          _SFD_SET_DATA_PROPS(12,0,0,0,"dist");
          _SFD_SET_DATA_PROPS(13,9,0,0,"");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 25 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 25 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"Init",0,-1,478);
        _SFD_CV_INIT_EML(3,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"isBallOutOfBounds",0,-1,441);
        _SFD_CV_INIT_EML_IF(3,1,0,274,285,305,434);
        _SFD_CV_INIT_EML_IF(3,1,1,305,319,339,434);
        _SFD_CV_INIT_EML_IF(3,1,2,339,353,373,434);
        _SFD_CV_INIT_EML_IF(3,1,3,373,387,407,434);
        _SFD_CV_INIT_EML_RELATIONAL(3,1,0,278,285,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(3,1,1,312,319,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(3,1,2,346,353,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(3,1,3,380,387,-1,3);
        _SFD_CV_INIT_EML(1,1,1,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"Reflection",0,-1,656);

        {
          static int caseStart[] = { -1, 267, 364, 461, 558 };

          static int caseExprEnd[] = { 8, 273, 370, 467, 564 };

          _SFD_CV_INIT_EML_SWITCH(1,1,0,253,263,654,5,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c1_r);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_p1);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_p2);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_p3);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_p4);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c1_x);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c1_v);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c1_x_out);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c1_x0);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_v0);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c1_t);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c1_n);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c1_dist);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _BillardSchieftischOneBallMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "02NdwGdu7YPc48dHZ8NVOE";
}

static void sf_opaque_initialize_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_BillardSchieftischOneBallInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
  initialize_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_BillardSchieftischOneBall(void *chartInstanceVar)
{
  enable_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  disable_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  zeroCrossings_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  outputs_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  derivatives_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  sf_gateway_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_BillardSchieftischOneBall
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_BillardSchieftischOneBall(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_BillardSchieftischOneBall(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_BillardSchieftischOneBallInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_BillardSchieftischOneBall_optimization_info();
    }

    finalize_c1_BillardSchieftischOneBall
      ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_BillardSchieftischOneBall
    ((SFc1_BillardSchieftischOneBallInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_BillardSchieftischOneBall(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c1_BillardSchieftischOneBall
      ((SFc1_BillardSchieftischOneBallInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_BillardSchieftischOneBall(SimStruct *S)
{
  /* Actual parameters from chart:
     r v0 x0
   */
  const char_T *rtParamNames[] = { "r", "v0", "x0" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for v0*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for x0*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BillardSchieftischOneBall_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2324180212U));
  ssSetChecksum1(S,(2596786555U));
  ssSetChecksum2(S,(1309781438U));
  ssSetChecksum3(S,(2099811839U));
  ssSetNumContStates(S,4);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_BillardSchieftischOneBall(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_BillardSchieftischOneBall(SimStruct *S)
{
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)utMalloc
    (sizeof(SFc1_BillardSchieftischOneBallInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_BillardSchieftischOneBallInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.outputs =
    sf_opaque_outputs_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_BillardSchieftischOneBall;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_BillardSchieftischOneBall_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_BillardSchieftischOneBall(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_BillardSchieftischOneBall(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_BillardSchieftischOneBall(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_BillardSchieftischOneBall_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_VECTOR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/v", "v", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  2, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    2324180212U,
    2596786555U,
    1309781438U,
    2099811839U
  }
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc1_BillardSchieftischOneBallInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  chartInstance = (SFc1_BillardSchieftischOneBallInstanceStruct *)
    chartInfo->chartInstance;
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
