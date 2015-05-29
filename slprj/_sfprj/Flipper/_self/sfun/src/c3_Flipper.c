/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Flipper_sfun.h"
#include "c3_Flipper.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Flipper_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Flipper                  ((uint8_T)1U)
#define c3_const_R                     (0.25)
#define c3_const_RHnd                  (0.8)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[4] = { "vt", "vn", "nargin", "nargout"
};

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[4] = { "vt", "vn", "nargin",
  "nargout" };

static const char * c3_d_debug_family_names[6] = { "n", "t", "vt", "vn",
  "nargin", "nargout" };

static const char * c3_e_debug_family_names[4] = { "vt", "vn", "nargin",
  "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[3] = { "a", "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout", "k" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout", "k" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout", "k" };

static const char * c3_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[5] = { "n", "t", "nargin", "nargout",
  "k" };

static const char * c3_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void initialize_params_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance);
static void enable_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void disable_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance);
static void set_sim_state_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Flipper(SFc3_FlipperInstanceStruct *
  chartInstance);
static void finalize_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void sf_gateway_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void mdl_start_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void zeroCrossings_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void derivatives_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void outputs_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void initSimStructsc3_Flipper(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_ini_fcn_to_be_inlined_113(SFc3_FlipperInstanceStruct
  *chartInstance);
static void c3_eml_term_fcn_to_be_inlined_113(SFc3_FlipperInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u[2]);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_t, const char_T *c3_identifier, real_T c3_y[2]);
static void c3_d_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const boolean_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_e_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_sf_internal_predicateOutput, const char_T *c3_identifier);
static boolean_T c3_f_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_d_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_e_emlrt_marshallOut(const uint32_T c3_u);
static real_T c3_eml_mtimes_helper(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_a[2], real_T c3_b[2]);
static void c3_common_checks(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_b_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_dynamic_size_checks(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_index_class(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_scalar_eg(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_scalarEg(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_any_enums(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_zerosum(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_b_zerosum(SFc3_FlipperInstanceStruct *chartInstance);
static boolean_T c3_use_refblas(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_eml_xdotu(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2], real_T c3_y[2]);
static void c3_inline(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_xdotu(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2]);
static real_T c3_xdot(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
                      real_T c3_y[2]);
static void c3_below_threshold(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_threshold(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_b_xdot(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2]);
static real_T c3_xdotx(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2]);
static void c3_eml_int_forloop_overflow_check(SFc3_FlipperInstanceStruct
  *chartInstance);
static void c3_eml_int_forloop_overflow_check_helper(SFc3_FlipperInstanceStruct *
  chartInstance);
static void c3_isfi(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_isnumerictype(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_b_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance);
static int32_T c3_intmin(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_b_eml_mtimes_helper(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_a, real_T c3_b[2], real_T c3_y[2]);
static void c3_b_common_checks(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_c_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_norm(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2]);
static real_T c3_genpnorm(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2]);
static real_T c3_eml_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2]);
static real_T c3_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2]);
static void c3_b_below_threshold(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_b_threshold(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_c_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_b_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x
  [2]);
static void c3_realmin(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_realmin(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_float_model(SFc3_FlipperInstanceStruct *chartInstance);
static real_T c3_abs(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x);
static real_T c3_eml_scalar_abs(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_x);
static void c3_mrdivide(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_A[2],
  real_T c3_B, real_T c3_y[2]);
static void c3_assert(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_rdivide(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y, real_T c3_z[2]);
static void c3_eml_scalexp_compatible(SFc3_FlipperInstanceStruct *chartInstance);
static void c3_eml_div(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y, real_T c3_z[2]);
static void c3_div(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
                   real_T c3_y, real_T c3_z[2]);
static const mxArray *c3_f_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const int32_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_g_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_h_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const uint8_T c3_u);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_i_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Flipper, const char_T *c3_identifier);
static uint8_T c3_j_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u[2]);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_k_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_Hnd, const char_T *c3_identifier, real_T c3_y[2]);
static void c3_l_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance);
static const mxArray *c3_j_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const boolean_T c3_u[19]);
static void c3_m_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u);
static void c3_n_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[19]);
static void c3_o_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[19]);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_FlipperInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_q_emlrt_marshallIn(SFc3_FlipperInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_FlipperInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_FlipperInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber, uint32_T
  c3_ssIdOfSourceObject, int32_T c3_offsetInSourceObject, int32_T
  c3_lengthInSourceObject);
static void init_dsm_address_info(SFc3_FlipperInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_FlipperInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_Flipper = 0U;
  chartInstance->c3_is_active_c3_Flipper = 0U;
  chartInstance->c3_is_c3_Flipper = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_R = 0.25;
  chartInstance->c3_RHnd = 0.8;
}

static void initialize_params_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_Flipper == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Flipper == c3_IN_Flipper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_Flipper(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_st, c3_i_emlrt_marshallOut(chartInstance), false);
  return c3_st;
}

static void set_sim_state_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Flipper(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Flipper(SFc3_FlipperInstanceStruct *
  chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_Flipper == c3_IN_Flipper) {
      chartInstance->c3_tp_Flipper = 1U;
    } else {
      chartInstance->c3_tp_Flipper = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_dv0[2];
  int32_T c3_i22;
  real_T c3_dv1[2];
  real_T c3_dv2[2];
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_dv3[2];
  int32_T c3_i25;
  real_T c3_dv4[2];
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_dv5[2];
  int32_T c3_i28;
  real_T c3_dv6[2];
  int32_T c3_i29;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_k;
  int32_T c3_i30;
  real_T c3_dv7[2];
  int32_T c3_i31;
  real_T c3_dv8[2];
  real_T c3_d0;
  int32_T c3_i32;
  real_T c3_dv9[2];
  int32_T c3_i33;
  real_T c3_dv10[2];
  real_T c3_d1;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[4];
  real_T c3_vt;
  real_T c3_vn;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i34;
  real_T c3_dv11[2];
  int32_T c3_i35;
  real_T c3_dv12[2];
  int32_T c3_i36;
  real_T c3_dv13[2];
  int32_T c3_i37;
  real_T c3_dv14[2];
  int32_T c3_i38;
  real_T c3_dv15[2];
  int32_T c3_i39;
  real_T c3_dv16[2];
  real_T c3_dv17[2];
  int32_T c3_i40;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_b_k;
  int32_T c3_i41;
  real_T c3_dv18[2];
  int32_T c3_i42;
  real_T c3_dv19[2];
  real_T c3_d2;
  int32_T c3_i43;
  real_T c3_dv20[2];
  int32_T c3_i44;
  real_T c3_dv21[2];
  real_T c3_d3;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_b_vt;
  real_T c3_b_vn;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  int32_T c3_i45;
  real_T c3_dv22[2];
  int32_T c3_i46;
  real_T c3_dv23[2];
  int32_T c3_i47;
  real_T c3_dv24[2];
  int32_T c3_i48;
  real_T c3_dv25[2];
  int32_T c3_i49;
  real_T c3_dv26[2];
  int32_T c3_i50;
  real_T c3_dv27[2];
  int32_T c3_i51;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 1.0;
  boolean_T c3_c_k;
  int32_T c3_i52;
  real_T c3_dv28[2];
  int32_T c3_i53;
  real_T c3_dv29[2];
  real_T c3_d4;
  int32_T c3_i54;
  real_T c3_dv30[2];
  int32_T c3_i55;
  real_T c3_dv31[2];
  real_T c3_d5;
  real_T c3_m_nargin = 0.0;
  real_T c3_m_nargout = 0.0;
  real_T c3_c_vt;
  real_T c3_c_vn;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 0.0;
  int32_T c3_i56;
  real_T c3_dv32[2];
  int32_T c3_i57;
  real_T c3_dv33[2];
  int32_T c3_i58;
  real_T c3_dv34[2];
  int32_T c3_i59;
  real_T c3_dv35[2];
  int32_T c3_i60;
  real_T c3_dv36[2];
  int32_T c3_i61;
  real_T c3_dv37[2];
  int32_T c3_i62;
  real_T c3_o_nargin = 0.0;
  real_T c3_o_nargout = 1.0;
  boolean_T c3_d_out;
  uint32_T c3_d_debug_family_var_map[5];
  real_T c3_n[2];
  real_T c3_t[2];
  real_T c3_p_nargin = 0.0;
  real_T c3_p_nargout = 1.0;
  boolean_T c3_d_k;
  int32_T c3_i63;
  real_T c3_dv38[2];
  int32_T c3_i64;
  real_T c3_dv39[2];
  real_T c3_dv40[2];
  int32_T c3_i65;
  int32_T c3_i66;
  real_T c3_dv41[2];
  real_T c3_d6;
  int32_T c3_i67;
  real_T c3_dv42[2];
  int32_T c3_i68;
  real_T c3_b_n[2];
  real_T c3_d7;
  real_T c3_q_nargin = 0.0;
  real_T c3_q_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[6];
  real_T c3_c_n[2];
  real_T c3_b_t[2];
  real_T c3_d_vt;
  real_T c3_d_vn;
  real_T c3_r_nargin = 0.0;
  real_T c3_r_nargout = 0.0;
  int32_T c3_i69;
  real_T c3_dv43[2];
  int32_T c3_i70;
  real_T c3_dv44[2];
  real_T c3_dv45[2];
  int32_T c3_i71;
  int32_T c3_i72;
  real_T c3_dv46[2];
  int32_T c3_i73;
  real_T c3_c_t[2];
  int32_T c3_i74;
  real_T c3_dv47[2];
  int32_T c3_i75;
  real_T c3_d_n[2];
  int32_T c3_i76;
  real_T c3_d_t[2];
  int32_T c3_i77;
  real_T c3_e_n[2];
  int32_T c3_i78;
  real_T c3_s_nargin = 0.0;
  real_T c3_s_nargout = 0.0;
  real_T c3_a[2];
  real_T c3_t_nargin = 0.0;
  real_T c3_t_nargout = 1.0;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c3_set_sim_state_side_effects_c3_Flipper(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    chartInstance->c3_lastMajorTime = _sfTime_;
    chartInstance->c3_stateChanged = false;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_R, 0U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_RHnd, 1U);
    for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_Hnd[c3_i0], 2U);
    }

    for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n1[c3_i1], 3U);
    }

    for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n2[c3_i2], 4U);
    }

    for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n3[c3_i3], 5U);
    }

    for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_p1[c3_i4], 6U);
    }

    for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_p2[c3_i5], 7U);
    }

    for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_p3[c3_i6], 8U);
    }

    for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_p4[c3_i7], 9U);
    }

    for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_t1[c3_i8], 10U);
    }

    for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_t2[c3_i9], 11U);
    }

    for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_t3[c3_i10], 12U);
    }

    for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_v1)[c3_i11], 13U);
    }

    for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_x1)[c3_i12], 14U);
    }

    for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
      _SFD_DATA_RANGE_CHECK((*chartInstance->c3_x1_out)[c3_i13], 15U);
    }

    chartInstance->c3_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_active_c3_Flipper == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_active_c3_Flipper = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      CV_EML_FCN(4, 0);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 3);
      for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
        (*chartInstance->c3_x1)[c3_i14] = 4.0 + (real_T)c3_i14;
      }

      c3_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 4);
      for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
        (*chartInstance->c3_v1)[c3_i15] = 0.0;
      }

      c3_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 6);
      for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
        chartInstance->c3_p1[c3_i16] = 5.0 * (real_T)c3_i16;
      }

      c3_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 7);
      for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
        chartInstance->c3_p2[c3_i17] = 5.0 + -5.0 * (real_T)c3_i17;
      }

      c3_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 8);
      for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
        chartInstance->c3_p3[c3_i18] = 9.0 + -9.0 * (real_T)c3_i18;
      }

      c3_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 9);
      for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
        chartInstance->c3_p4[c3_i19] = 10.0 + -3.0 * (real_T)c3_i19;
      }

      c3_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 10);
      for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
        chartInstance->c3_Hnd[c3_i20] = 6.0 + -3.5 * (real_T)c3_i20;
      }

      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 12);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 7U, 3U, 118, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 6U, 3U, 123, 2);
      for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
        c3_dv0[c3_i21] = chartInstance->c3_p2[c3_i21] - chartInstance->
          c3_p1[c3_i21];
      }

      for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
        c3_dv1[c3_i22] = chartInstance->c3_p2[c3_i22] - chartInstance->
          c3_p1[c3_i22];
      }

      c3_mrdivide(chartInstance, c3_dv1, c3_norm(chartInstance, c3_dv0), c3_dv2);
      for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
        chartInstance->c3_t1[c3_i23] = c3_dv2[c3_i23];
      }

      c3_updateDataWrittenToVector(chartInstance, 4U);
      c3_updateDataWrittenToVector(chartInstance, 5U);
      c3_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 13);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U, 3U, 149, 2);
      chartInstance->c3_n1[0] = -chartInstance->c3_t1[1];
      chartInstance->c3_n1[1] = chartInstance->c3_t1[0];
      c3_updateDataWrittenToVector(chartInstance, 8U);
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 15);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 8U, 3U, 171, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 7U, 3U, 176, 2);
      for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
        c3_dv3[c3_i24] = chartInstance->c3_p3[c3_i24] - chartInstance->
          c3_p2[c3_i24];
      }

      for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
        c3_dv4[c3_i25] = chartInstance->c3_p3[c3_i25] - chartInstance->
          c3_p2[c3_i25];
      }

      c3_mrdivide(chartInstance, c3_dv4, c3_norm(chartInstance, c3_dv3), c3_dv2);
      for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
        chartInstance->c3_t2[c3_i26] = c3_dv2[c3_i26];
      }

      c3_updateDataWrittenToVector(chartInstance, 5U);
      c3_updateDataWrittenToVector(chartInstance, 6U);
      c3_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 16);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 11U, 3U, 202, 2);
      chartInstance->c3_n2[0] = -chartInstance->c3_t2[1];
      chartInstance->c3_n2[1] = chartInstance->c3_t2[0];
      c3_updateDataWrittenToVector(chartInstance, 9U);
      c3_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 18);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 9U, 3U, 224, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 8U, 3U, 229, 2);
      for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
        c3_dv5[c3_i27] = chartInstance->c3_p4[c3_i27] - chartInstance->
          c3_p3[c3_i27];
      }

      for (c3_i28 = 0; c3_i28 < 2; c3_i28++) {
        c3_dv6[c3_i28] = chartInstance->c3_p4[c3_i28] - chartInstance->
          c3_p3[c3_i28];
      }

      c3_mrdivide(chartInstance, c3_dv6, c3_norm(chartInstance, c3_dv5), c3_dv2);
      for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
        chartInstance->c3_t3[c3_i29] = c3_dv2[c3_i29];
      }

      c3_updateDataWrittenToVector(chartInstance, 6U);
      c3_updateDataWrittenToVector(chartInstance, 7U);
      c3_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 19);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U, 3U, 255, 2);
      chartInstance->c3_n3[0] = -chartInstance->c3_t3[1];
      chartInstance->c3_n3[1] = chartInstance->c3_t3[0];
      c3_updateDataWrittenToVector(chartInstance, 10U);
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, -19);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_c3_Flipper = c3_IN_Flipper;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Flipper = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      CV_EML_FCN(5, 0);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 2);
      c3_k = false;
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 3);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 10U, 46, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 6U, 10U, 51, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 10U, 58, 2);
      for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
        c3_dv7[c3_i30] = (*chartInstance->c3_x1)[c3_i30] - chartInstance->
          c3_p1[c3_i30];
      }

      for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
        c3_dv8[c3_i31] = chartInstance->c3_n1[c3_i31];
      }

      c3_d0 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance, c3_dv7,
        c3_dv8));
      guard4 = false;
      if (CV_EML_COND(5, 1, 0, CV_RELATIONAL_EVAL(4U, 5U, 0, c3_d0, c3_const_R,
            -1, 3U, c3_d0 <= c3_const_R))) {
        for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
          c3_dv9[c3_i32] = (*chartInstance->c3_v1)[c3_i32];
        }

        for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
          c3_dv10[c3_i33] = chartInstance->c3_n1[c3_i33];
        }

        c3_d1 = c3_eml_mtimes_helper(chartInstance, c3_dv9, c3_dv10);
        if (CV_EML_COND(5, 1, 1, CV_RELATIONAL_EVAL(4U, 5U, 1, c3_d1, 0.0, -1,
              2U, c3_d1 < 0.0))) {
          CV_EML_MCDC(5, 1, 0, true);
          CV_EML_IF(5, 1, 0, true);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 4);
          c3_k = true;
        } else {
          guard4 = true;
        }
      } else {
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 10U, 77, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 10U, 71, 2);
        guard4 = true;
      }

      if (guard4 == true) {
        CV_EML_MCDC(5, 1, 0, false);
        CV_EML_IF(5, 1, 0, false);
      }

      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -4);
      _SFD_SYMBOL_SCOPE_POP();
      c3_out = CV_EML_IF(2, 0, 0, c3_k);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_debug_family_names,
          c3_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_vt, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_vn, 1U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 2U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 3U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        CV_EML_FCN(6, 0);
        _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 3);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 9U, 25, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U, 9U, 31, 2);
        for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
          c3_dv11[c3_i34] = (*chartInstance->c3_v1)[c3_i34];
        }

        for (c3_i35 = 0; c3_i35 < 2; c3_i35++) {
          c3_dv12[c3_i35] = chartInstance->c3_t1[c3_i35];
        }

        c3_vt = c3_eml_mtimes_helper(chartInstance, c3_dv11, c3_dv12);
        _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 4);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 9U, 40, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 9U, 46, 2);
        for (c3_i36 = 0; c3_i36 < 2; c3_i36++) {
          c3_dv13[c3_i36] = (*chartInstance->c3_v1)[c3_i36];
        }

        for (c3_i37 = 0; c3_i37 < 2; c3_i37++) {
          c3_dv14[c3_i37] = chartInstance->c3_n1[c3_i37];
        }

        c3_vn = c3_eml_mtimes_helper(chartInstance, c3_dv13, c3_dv14);
        _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 6);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U, 9U, 61, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 9U, 71, 2);
        for (c3_i38 = 0; c3_i38 < 2; c3_i38++) {
          c3_dv15[c3_i38] = chartInstance->c3_t1[c3_i38];
        }

        c3_b_eml_mtimes_helper(chartInstance, c3_vt, c3_dv15, c3_dv2);
        for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
          c3_dv16[c3_i39] = chartInstance->c3_n1[c3_i39];
        }

        c3_b_eml_mtimes_helper(chartInstance, c3_vn, c3_dv16, c3_dv17);
        for (c3_i40 = 0; c3_i40 < 2; c3_i40++) {
          (*chartInstance->c3_v1)[c3_i40] = c3_dv2[c3_i40] - c3_dv17[c3_i40];
        }

        c3_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, -6);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_Flipper = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_stateChanged = true;
        chartInstance->c3_is_c3_Flipper = c3_IN_Flipper;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Flipper = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_k, 2U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        CV_EML_FCN(9, 0);
        _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 2);
        c3_b_k = false;
        _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 3);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 12U, 46, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 7U, 12U, 51, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 12U, 58, 2);
        for (c3_i41 = 0; c3_i41 < 2; c3_i41++) {
          c3_dv18[c3_i41] = (*chartInstance->c3_x1)[c3_i41] -
            chartInstance->c3_p2[c3_i41];
        }

        for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
          c3_dv19[c3_i42] = chartInstance->c3_n2[c3_i42];
        }

        c3_d2 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance,
          c3_dv18, c3_dv19));
        guard3 = false;
        if (CV_EML_COND(9, 1, 0, CV_RELATIONAL_EVAL(4U, 9U, 0, c3_d2, c3_const_R,
              -1, 3U, c3_d2 <= c3_const_R))) {
          for (c3_i43 = 0; c3_i43 < 2; c3_i43++) {
            c3_dv20[c3_i43] = (*chartInstance->c3_v1)[c3_i43];
          }

          for (c3_i44 = 0; c3_i44 < 2; c3_i44++) {
            c3_dv21[c3_i44] = chartInstance->c3_n2[c3_i44];
          }

          c3_d3 = c3_eml_mtimes_helper(chartInstance, c3_dv20, c3_dv21);
          if (CV_EML_COND(9, 1, 1, CV_RELATIONAL_EVAL(4U, 9U, 1, c3_d3, 0.0, -1,
                2U, c3_d3 < 0.0))) {
            CV_EML_MCDC(9, 1, 0, true);
            CV_EML_IF(9, 1, 0, true);
            _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 4);
            c3_b_k = true;
          } else {
            guard3 = true;
          }
        } else {
          c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 12U, 77, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 12U, 71, 2);
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(9, 1, 0, false);
          CV_EML_IF(9, 1, 0, false);
        }

        _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, -4);
        _SFD_SYMBOL_SCOPE_POP();
        c3_b_out = CV_EML_IF(1, 0, 0, c3_b_k);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_c_debug_family_names,
            c3_c_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_vt, 0U, c3_sf_marshallOut,
            c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_vn, 1U, c3_sf_marshallOut,
            c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 2U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 3U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          CV_EML_FCN(10, 0);
          _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 3);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 13U, 25, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 11U, 13U, 31, 2);
          for (c3_i45 = 0; c3_i45 < 2; c3_i45++) {
            c3_dv22[c3_i45] = (*chartInstance->c3_v1)[c3_i45];
          }

          for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
            c3_dv23[c3_i46] = chartInstance->c3_t2[c3_i46];
          }

          c3_b_vt = c3_eml_mtimes_helper(chartInstance, c3_dv22, c3_dv23);
          _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 4);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 13U, 40, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 13U, 46, 2);
          for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
            c3_dv24[c3_i47] = (*chartInstance->c3_v1)[c3_i47];
          }

          for (c3_i48 = 0; c3_i48 < 2; c3_i48++) {
            c3_dv25[c3_i48] = chartInstance->c3_n2[c3_i48];
          }

          c3_b_vn = c3_eml_mtimes_helper(chartInstance, c3_dv24, c3_dv25);
          _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 6);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 11U, 13U, 61, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 13U, 71, 2);
          for (c3_i49 = 0; c3_i49 < 2; c3_i49++) {
            c3_dv26[c3_i49] = chartInstance->c3_t2[c3_i49];
          }

          c3_b_eml_mtimes_helper(chartInstance, c3_b_vt, c3_dv26, c3_dv2);
          for (c3_i50 = 0; c3_i50 < 2; c3_i50++) {
            c3_dv27[c3_i50] = chartInstance->c3_n2[c3_i50];
          }

          c3_b_eml_mtimes_helper(chartInstance, c3_b_vn, c3_dv27, c3_dv17);
          for (c3_i51 = 0; c3_i51 < 2; c3_i51++) {
            (*chartInstance->c3_v1)[c3_i51] = c3_dv2[c3_i51] - c3_dv17[c3_i51];
          }

          c3_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, -6);
          _SFD_SYMBOL_SCOPE_POP();
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c3_tp_Flipper = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_Flipper = c3_IN_Flipper;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Flipper = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U,
            c3_c_sf_marshallOut, c3_c_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_k, 2U, c3_c_sf_marshallOut,
            c3_c_sf_marshallIn);
          CV_EML_FCN(7, 0);
          _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 2);
          c3_c_k = false;
          _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 3);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 15U, 46, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 8U, 15U, 51, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 15U, 58, 2);
          for (c3_i52 = 0; c3_i52 < 2; c3_i52++) {
            c3_dv28[c3_i52] = (*chartInstance->c3_x1)[c3_i52] -
              chartInstance->c3_p3[c3_i52];
          }

          for (c3_i53 = 0; c3_i53 < 2; c3_i53++) {
            c3_dv29[c3_i53] = chartInstance->c3_n3[c3_i53];
          }

          c3_d4 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance,
            c3_dv28, c3_dv29));
          guard2 = false;
          if (CV_EML_COND(7, 1, 0, CV_RELATIONAL_EVAL(4U, 7U, 0, c3_d4,
                c3_const_R, -1, 3U, c3_d4 <= c3_const_R))) {
            for (c3_i54 = 0; c3_i54 < 2; c3_i54++) {
              c3_dv30[c3_i54] = (*chartInstance->c3_v1)[c3_i54];
            }

            for (c3_i55 = 0; c3_i55 < 2; c3_i55++) {
              c3_dv31[c3_i55] = chartInstance->c3_n3[c3_i55];
            }

            c3_d5 = c3_eml_mtimes_helper(chartInstance, c3_dv30, c3_dv31);
            if (CV_EML_COND(7, 1, 1, CV_RELATIONAL_EVAL(4U, 7U, 1, c3_d5, 0.0,
                  -1, 2U, c3_d5 < 0.0))) {
              CV_EML_MCDC(7, 1, 0, true);
              CV_EML_IF(7, 1, 0, true);
              _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 4);
              c3_c_k = true;
            } else {
              guard2 = true;
            }
          } else {
            c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 15U, 77, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 15U, 71, 2);
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(7, 1, 0, false);
            CV_EML_IF(7, 1, 0, false);
          }

          _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, -4);
          _SFD_SYMBOL_SCOPE_POP();
          c3_c_out = CV_EML_IF(4, 0, 0, c3_c_k);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_q_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_e_debug_family_names,
              c3_c_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_vt, 0U, c3_sf_marshallOut,
              c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_vn, 1U, c3_sf_marshallOut,
              c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 2U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 3U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            CV_EML_FCN(8, 0);
            _SFD_EML_CALL(8U, chartInstance->c3_sfEvent, 3);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 16U, 25, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U, 16U, 31, 2);
            for (c3_i56 = 0; c3_i56 < 2; c3_i56++) {
              c3_dv32[c3_i56] = (*chartInstance->c3_v1)[c3_i56];
            }

            for (c3_i57 = 0; c3_i57 < 2; c3_i57++) {
              c3_dv33[c3_i57] = chartInstance->c3_t3[c3_i57];
            }

            c3_c_vt = c3_eml_mtimes_helper(chartInstance, c3_dv32, c3_dv33);
            _SFD_EML_CALL(8U, chartInstance->c3_sfEvent, 4);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 16U, 40, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 16U, 46, 2);
            for (c3_i58 = 0; c3_i58 < 2; c3_i58++) {
              c3_dv34[c3_i58] = (*chartInstance->c3_v1)[c3_i58];
            }

            for (c3_i59 = 0; c3_i59 < 2; c3_i59++) {
              c3_dv35[c3_i59] = chartInstance->c3_n3[c3_i59];
            }

            c3_c_vn = c3_eml_mtimes_helper(chartInstance, c3_dv34, c3_dv35);
            _SFD_EML_CALL(8U, chartInstance->c3_sfEvent, 6);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U, 16U, 61, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 16U, 71, 2);
            for (c3_i60 = 0; c3_i60 < 2; c3_i60++) {
              c3_dv36[c3_i60] = chartInstance->c3_t3[c3_i60];
            }

            c3_b_eml_mtimes_helper(chartInstance, c3_c_vt, c3_dv36, c3_dv2);
            for (c3_i61 = 0; c3_i61 < 2; c3_i61++) {
              c3_dv37[c3_i61] = chartInstance->c3_n3[c3_i61];
            }

            c3_b_eml_mtimes_helper(chartInstance, c3_c_vn, c3_dv37, c3_dv17);
            for (c3_i62 = 0; c3_i62 < 2; c3_i62++) {
              (*chartInstance->c3_v1)[c3_i62] = c3_dv2[c3_i62] - c3_dv17[c3_i62];
            }

            c3_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(8U, chartInstance->c3_sfEvent, -6);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_SYMBOL_SCOPE_POP();
            chartInstance->c3_tp_Flipper = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_stateChanged = true;
            chartInstance->c3_is_c3_Flipper = c3_IN_Flipper;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_Flipper = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                         chartInstance->c3_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U,
              c3_c_sf_marshallOut, c3_c_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_s_debug_family_names,
              c3_d_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_n, 0U, c3_b_sf_marshallOut,
              c3_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_t, 1U, c3_b_sf_marshallOut,
              c3_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 2U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 3U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_k, 4U,
              c3_c_sf_marshallOut, c3_c_sf_marshallIn);
            CV_EML_FCN(2, 0);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 2);
            c3_d_k = false;
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 6U, 41, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U, 6U, 46, 3);
            for (c3_i63 = 0; c3_i63 < 2; c3_i63++) {
              c3_dv38[c3_i63] = (*chartInstance->c3_x1)[c3_i63] -
                chartInstance->c3_Hnd[c3_i63];
            }

            for (c3_i64 = 0; c3_i64 < 2; c3_i64++) {
              c3_dv39[c3_i64] = (*chartInstance->c3_x1)[c3_i64] -
                chartInstance->c3_Hnd[c3_i64];
            }

            c3_mrdivide(chartInstance, c3_dv39, c3_norm(chartInstance, c3_dv38),
                        c3_dv40);
            for (c3_i65 = 0; c3_i65 < 2; c3_i65++) {
              c3_n[c3_i65] = c3_dv40[c3_i65];
            }

            c3_updateDataWrittenToVector(chartInstance, 0U);
            c3_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
            c3_t[0] = -c3_n[1];
            c3_t[1] = c3_n[0];
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 7);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U, 6U, 99, 3);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 6U, 105, 2);
            for (c3_i66 = 0; c3_i66 < 2; c3_i66++) {
              c3_dv41[c3_i66] = chartInstance->c3_Hnd[c3_i66] -
                (*chartInstance->c3_x1)[c3_i66];
            }

            c3_d6 = c3_norm(chartInstance, c3_dv41);
            guard1 = false;
            if (CV_EML_COND(2, 1, 0, CV_RELATIONAL_EVAL(4U, 2U, 0, c3_d6, 1.05,
                  -1, 3U, c3_d6 <= 1.05))) {
              for (c3_i67 = 0; c3_i67 < 2; c3_i67++) {
                c3_dv42[c3_i67] = (*chartInstance->c3_v1)[c3_i67];
              }

              for (c3_i68 = 0; c3_i68 < 2; c3_i68++) {
                c3_b_n[c3_i68] = c3_n[c3_i68];
              }

              c3_d7 = c3_eml_mtimes_helper(chartInstance, c3_dv42, c3_b_n);
              if (CV_EML_COND(2, 1, 1, CV_RELATIONAL_EVAL(4U, 2U, 1, c3_d7, 0.0,
                    -1, 2U, c3_d7 < 0.0))) {
                CV_EML_MCDC(2, 1, 0, true);
                CV_EML_IF(2, 1, 0, true);
                _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
                c3_d_k = true;
              } else {
                guard1 = true;
              }
            } else {
              c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 6U, 125, 2);
              guard1 = true;
            }

            if (guard1 == true) {
              CV_EML_MCDC(2, 1, 0, false);
              CV_EML_IF(2, 1, 0, false);
            }

            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -8);
            _SFD_SYMBOL_SCOPE_POP();
            c3_d_out = CV_EML_IF(3, 0, 0, c3_d_k);
            _SFD_SYMBOL_SCOPE_POP();
            if (c3_d_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_t_debug_family_names,
                c3_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargin, 0U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_q_nargout, 1U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
                c3_e_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_c_n, 0U,
                c3_b_sf_marshallOut, c3_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_t, 1U,
                c3_b_sf_marshallOut, c3_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_vt, 2U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_vn, 3U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargin, 4U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r_nargout, 5U,
                c3_sf_marshallOut, c3_sf_marshallIn);
              CV_EML_FCN(3, 0);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 3);
              c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U, 7U, 23, 3);
              c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 7U, 29, 2);
              for (c3_i69 = 0; c3_i69 < 2; c3_i69++) {
                c3_dv43[c3_i69] = chartInstance->c3_Hnd[c3_i69] -
                  (*chartInstance->c3_x1)[c3_i69];
              }

              for (c3_i70 = 0; c3_i70 < 2; c3_i70++) {
                c3_dv44[c3_i70] = chartInstance->c3_Hnd[c3_i70] -
                  (*chartInstance->c3_x1)[c3_i70];
              }

              c3_mrdivide(chartInstance, c3_dv44, c3_norm(chartInstance, c3_dv43),
                          c3_dv45);
              for (c3_i71 = 0; c3_i71 < 2; c3_i71++) {
                c3_c_n[c3_i71] = c3_dv45[c3_i71];
              }

              c3_updateDataWrittenToVector(chartInstance, 12U);
              c3_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 4);
              c3_b_t[0] = c3_c_n[1];
              c3_b_t[1] = -c3_c_n[0];
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 6);
              c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 7U, 76, 2);
              for (c3_i72 = 0; c3_i72 < 2; c3_i72++) {
                c3_dv46[c3_i72] = (*chartInstance->c3_v1)[c3_i72];
              }

              for (c3_i73 = 0; c3_i73 < 2; c3_i73++) {
                c3_c_t[c3_i73] = c3_b_t[c3_i73];
              }

              c3_d_vt = c3_eml_mtimes_helper(chartInstance, c3_dv46, c3_c_t);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 7);
              c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 7U, 90, 2);
              for (c3_i74 = 0; c3_i74 < 2; c3_i74++) {
                c3_dv47[c3_i74] = (*chartInstance->c3_v1)[c3_i74];
              }

              for (c3_i75 = 0; c3_i75 < 2; c3_i75++) {
                c3_d_n[c3_i75] = c3_c_n[c3_i75];
              }

              c3_d_vn = c3_eml_mtimes_helper(chartInstance, c3_dv47, c3_d_n);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 9);
              for (c3_i76 = 0; c3_i76 < 2; c3_i76++) {
                c3_d_t[c3_i76] = c3_b_t[c3_i76];
              }

              c3_b_eml_mtimes_helper(chartInstance, c3_d_vt, c3_d_t, c3_dv2);
              for (c3_i77 = 0; c3_i77 < 2; c3_i77++) {
                c3_e_n[c3_i77] = c3_c_n[c3_i77];
              }

              c3_b_eml_mtimes_helper(chartInstance, c3_d_vn, c3_e_n, c3_dv17);
              for (c3_i78 = 0; c3_i78 < 2; c3_i78++) {
                (*chartInstance->c3_v1)[c3_i78] = c3_dv2[c3_i78] -
                  c3_dv17[c3_i78];
              }

              c3_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -9);
              _SFD_SYMBOL_SCOPE_POP();
              _SFD_SYMBOL_SCOPE_POP();
              chartInstance->c3_tp_Flipper = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
              chartInstance->c3_stateChanged = true;
              chartInstance->c3_is_c3_Flipper = c3_IN_Flipper;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_Flipper = 1U;
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U,
                           chartInstance->c3_sfEvent);
            }
          }
        }
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_s_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 2U, 23, 2);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_a, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_t_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i79 = 0; c3_i79 < 2; c3_i79++) {
    c3_a[c3_i79] = 0.0 - (real_T)c3_i79;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 2U, 48, 2);
  for (c3_i80 = 0; c3_i80 < 2; c3_i80++) {
    (*chartInstance->c3_x1_out)[c3_i80] = (*chartInstance->c3_x1)[c3_i80];
  }

  c3_updateDataWrittenToVector(chartInstance, 13U);
  for (c3_i81 = 0; c3_i81 < 2; c3_i81++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_x1_out)[c3_i81], 15U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FlipperMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_k;
  int32_T c3_i82;
  real_T c3_dv48[2];
  int32_T c3_i83;
  real_T c3_dv49[2];
  real_T c3_d8;
  int32_T c3_i84;
  real_T c3_dv50[2];
  int32_T c3_i85;
  real_T c3_dv51[2];
  real_T c3_d9;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_b_k;
  int32_T c3_i86;
  real_T c3_dv52[2];
  int32_T c3_i87;
  real_T c3_dv53[2];
  real_T c3_d10;
  int32_T c3_i88;
  real_T c3_dv54[2];
  int32_T c3_i89;
  real_T c3_dv55[2];
  real_T c3_d11;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_c_k;
  int32_T c3_i90;
  real_T c3_dv56[2];
  int32_T c3_i91;
  real_T c3_dv57[2];
  real_T c3_d12;
  int32_T c3_i92;
  real_T c3_dv58[2];
  int32_T c3_i93;
  real_T c3_dv59[2];
  real_T c3_d13;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_d_out;
  uint32_T c3_b_debug_family_var_map[5];
  real_T c3_n[2];
  real_T c3_t[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_d_k;
  int32_T c3_i94;
  real_T c3_dv60[2];
  int32_T c3_i95;
  real_T c3_dv61[2];
  real_T c3_dv62[2];
  int32_T c3_i96;
  int32_T c3_i97;
  real_T c3_dv63[2];
  real_T c3_d14;
  int32_T c3_i98;
  real_T c3_dv64[2];
  int32_T c3_i99;
  real_T c3_b_n[2];
  real_T c3_d15;
  real_T *c3_zcVar;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c3_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_lastMajorTime == _sfTime_) {
    *c3_zcVar = -1.0;
  } else {
    chartInstance->c3_stateChanged = false;
    if (chartInstance->c3_is_active_c3_Flipper == 0U) {
      chartInstance->c3_stateChanged = true;
    } else {
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      CV_EML_FCN(5, 0);
      c3_k = false;
      c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 10U, 46, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 6U, 10U, 51, 2);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 10U, 58, 2);
      for (c3_i82 = 0; c3_i82 < 2; c3_i82++) {
        c3_dv48[c3_i82] = (*chartInstance->c3_x1)[c3_i82] - chartInstance->
          c3_p1[c3_i82];
      }

      for (c3_i83 = 0; c3_i83 < 2; c3_i83++) {
        c3_dv49[c3_i83] = chartInstance->c3_n1[c3_i83];
      }

      c3_d8 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance, c3_dv48,
        c3_dv49));
      guard4 = false;
      if (CV_EML_COND(5, 1, 0, CV_RELATIONAL_EVAL(4U, 5U, 0, c3_d8, c3_const_R,
            -1, 3U, c3_d8 <= c3_const_R))) {
        for (c3_i84 = 0; c3_i84 < 2; c3_i84++) {
          c3_dv50[c3_i84] = (*chartInstance->c3_v1)[c3_i84];
        }

        for (c3_i85 = 0; c3_i85 < 2; c3_i85++) {
          c3_dv51[c3_i85] = chartInstance->c3_n1[c3_i85];
        }

        c3_d9 = c3_eml_mtimes_helper(chartInstance, c3_dv50, c3_dv51);
        if (CV_EML_COND(5, 1, 1, CV_RELATIONAL_EVAL(4U, 5U, 1, c3_d9, 0.0, -1,
              2U, c3_d9 < 0.0))) {
          CV_EML_MCDC(5, 1, 0, true);
          CV_EML_IF(5, 1, 0, true);
          c3_k = true;
        } else {
          guard4 = true;
        }
      } else {
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U, 10U, 77, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 10U, 71, 2);
        guard4 = true;
      }

      if (guard4 == true) {
        CV_EML_MCDC(5, 1, 0, false);
        CV_EML_IF(5, 1, 0, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
      c3_out = CV_EML_IF(2, 0, 0, c3_k);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        chartInstance->c3_stateChanged = true;
      } else {
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_k, 2U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        CV_EML_FCN(9, 0);
        c3_b_k = false;
        c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 12U, 46, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 7U, 12U, 51, 2);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 12U, 58, 2);
        for (c3_i86 = 0; c3_i86 < 2; c3_i86++) {
          c3_dv52[c3_i86] = (*chartInstance->c3_x1)[c3_i86] -
            chartInstance->c3_p2[c3_i86];
        }

        for (c3_i87 = 0; c3_i87 < 2; c3_i87++) {
          c3_dv53[c3_i87] = chartInstance->c3_n2[c3_i87];
        }

        c3_d10 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance,
          c3_dv52, c3_dv53));
        guard3 = false;
        if (CV_EML_COND(9, 1, 0, CV_RELATIONAL_EVAL(4U, 9U, 0, c3_d10,
              c3_const_R, -1, 3U, c3_d10 <= c3_const_R))) {
          for (c3_i88 = 0; c3_i88 < 2; c3_i88++) {
            c3_dv54[c3_i88] = (*chartInstance->c3_v1)[c3_i88];
          }

          for (c3_i89 = 0; c3_i89 < 2; c3_i89++) {
            c3_dv55[c3_i89] = chartInstance->c3_n2[c3_i89];
          }

          c3_d11 = c3_eml_mtimes_helper(chartInstance, c3_dv54, c3_dv55);
          if (CV_EML_COND(9, 1, 1, CV_RELATIONAL_EVAL(4U, 9U, 1, c3_d11, 0.0, -1,
                2U, c3_d11 < 0.0))) {
            CV_EML_MCDC(9, 1, 0, true);
            CV_EML_IF(9, 1, 0, true);
            c3_b_k = true;
          } else {
            guard3 = true;
          }
        } else {
          c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 12U, 77, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 12U, 71, 2);
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(9, 1, 0, false);
          CV_EML_IF(9, 1, 0, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
        c3_b_out = CV_EML_IF(1, 0, 0, c3_b_k);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          chartInstance->c3_stateChanged = true;
        } else {
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U,
            c3_c_sf_marshallOut, c3_c_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_k, 2U, c3_c_sf_marshallOut,
            c3_c_sf_marshallIn);
          CV_EML_FCN(7, 0);
          c3_c_k = false;
          c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 15U, 46, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 8U, 15U, 51, 2);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 15U, 58, 2);
          for (c3_i90 = 0; c3_i90 < 2; c3_i90++) {
            c3_dv56[c3_i90] = (*chartInstance->c3_x1)[c3_i90] -
              chartInstance->c3_p3[c3_i90];
          }

          for (c3_i91 = 0; c3_i91 < 2; c3_i91++) {
            c3_dv57[c3_i91] = chartInstance->c3_n3[c3_i91];
          }

          c3_d12 = c3_abs(chartInstance, c3_eml_mtimes_helper(chartInstance,
            c3_dv56, c3_dv57));
          guard2 = false;
          if (CV_EML_COND(7, 1, 0, CV_RELATIONAL_EVAL(4U, 7U, 0, c3_d12,
                c3_const_R, -1, 3U, c3_d12 <= c3_const_R))) {
            for (c3_i92 = 0; c3_i92 < 2; c3_i92++) {
              c3_dv58[c3_i92] = (*chartInstance->c3_v1)[c3_i92];
            }

            for (c3_i93 = 0; c3_i93 < 2; c3_i93++) {
              c3_dv59[c3_i93] = chartInstance->c3_n3[c3_i93];
            }

            c3_d13 = c3_eml_mtimes_helper(chartInstance, c3_dv58, c3_dv59);
            if (CV_EML_COND(7, 1, 1, CV_RELATIONAL_EVAL(4U, 7U, 1, c3_d13, 0.0,
                  -1, 2U, c3_d13 < 0.0))) {
              CV_EML_MCDC(7, 1, 0, true);
              CV_EML_IF(7, 1, 0, true);
              c3_c_k = true;
            } else {
              guard2 = true;
            }
          } else {
            c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U, 15U, 77, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 15U, 71, 2);
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(7, 1, 0, false);
            CV_EML_IF(7, 1, 0, false);
          }

          _SFD_SYMBOL_SCOPE_POP();
          c3_c_out = CV_EML_IF(4, 0, 0, c3_c_k);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_c_out) {
            chartInstance->c3_stateChanged = true;
          } else {
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
              c3_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U,
              c3_c_sf_marshallOut, c3_c_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_s_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_n, 0U, c3_b_sf_marshallOut,
              c3_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_t, 1U, c3_b_sf_marshallOut,
              c3_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 2U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 3U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_k, 4U,
              c3_c_sf_marshallOut, c3_c_sf_marshallIn);
            CV_EML_FCN(2, 0);
            c3_d_k = false;
            c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 6U, 41, 2);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U, 6U, 46, 3);
            for (c3_i94 = 0; c3_i94 < 2; c3_i94++) {
              c3_dv60[c3_i94] = (*chartInstance->c3_x1)[c3_i94] -
                chartInstance->c3_Hnd[c3_i94];
            }

            for (c3_i95 = 0; c3_i95 < 2; c3_i95++) {
              c3_dv61[c3_i95] = (*chartInstance->c3_x1)[c3_i95] -
                chartInstance->c3_Hnd[c3_i95];
            }

            c3_mrdivide(chartInstance, c3_dv61, c3_norm(chartInstance, c3_dv60),
                        c3_dv62);
            for (c3_i96 = 0; c3_i96 < 2; c3_i96++) {
              c3_n[c3_i96] = c3_dv62[c3_i96];
            }

            c3_updateDataWrittenToVector(chartInstance, 0U);
            c3_updateDataWrittenToVector(chartInstance, 12U);
            c3_t[0] = -c3_n[1];
            c3_t[1] = c3_n[0];
            c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U, 6U, 99, 3);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 6U, 105, 2);
            for (c3_i97 = 0; c3_i97 < 2; c3_i97++) {
              c3_dv63[c3_i97] = chartInstance->c3_Hnd[c3_i97] -
                (*chartInstance->c3_x1)[c3_i97];
            }

            c3_d14 = c3_norm(chartInstance, c3_dv63);
            guard1 = false;
            if (CV_EML_COND(2, 1, 0, CV_RELATIONAL_EVAL(4U, 2U, 0, c3_d14, 1.05,
                  -1, 3U, c3_d14 <= 1.05))) {
              for (c3_i98 = 0; c3_i98 < 2; c3_i98++) {
                c3_dv64[c3_i98] = (*chartInstance->c3_v1)[c3_i98];
              }

              for (c3_i99 = 0; c3_i99 < 2; c3_i99++) {
                c3_b_n[c3_i99] = c3_n[c3_i99];
              }

              c3_d15 = c3_eml_mtimes_helper(chartInstance, c3_dv64, c3_b_n);
              if (CV_EML_COND(2, 1, 1, CV_RELATIONAL_EVAL(4U, 2U, 1, c3_d15, 0.0,
                    -1, 2U, c3_d15 < 0.0))) {
                CV_EML_MCDC(2, 1, 0, true);
                CV_EML_IF(2, 1, 0, true);
                c3_d_k = true;
              } else {
                guard1 = true;
              }
            } else {
              c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 6U, 125, 2);
              guard1 = true;
            }

            if (guard1 == true) {
              CV_EML_MCDC(2, 1, 0, false);
              CV_EML_IF(2, 1, 0, false);
            }

            _SFD_SYMBOL_SCOPE_POP();
            c3_d_out = CV_EML_IF(3, 0, 0, c3_d_k);
            _SFD_SYMBOL_SCOPE_POP();
            if (c3_d_out) {
              chartInstance->c3_stateChanged = true;
            }
          }
        }
      }
    }

    if (chartInstance->c3_stateChanged) {
      *c3_zcVar = 1.0;
    } else {
      *c3_zcVar = -1.0;
    }
  }
}

static void derivatives_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i104;
  int32_T c3_i105;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_a[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  real_T (*c3_v1_dot)[2];
  real_T (*c3_x1_dot)[2];
  c3_x1_dot = (real_T (*)[2])(ssGetdX_wrapper(chartInstance->S) + 2);
  c3_v1_dot = (real_T (*)[2])(ssGetdX_wrapper(chartInstance->S) + 0);
  for (c3_i100 = 0; c3_i100 < 2; c3_i100++) {
    (*c3_v1_dot)[c3_i100] = 0.0;
  }

  for (c3_i101 = 0; c3_i101 < 2; c3_i101++) {
    _SFD_DATA_RANGE_CHECK((*c3_v1_dot)[c3_i101], 13U);
  }

  for (c3_i102 = 0; c3_i102 < 2; c3_i102++) {
    (*c3_x1_dot)[c3_i102] = 0.0;
  }

  for (c3_i103 = 0; c3_i103 < 2; c3_i103++) {
    _SFD_DATA_RANGE_CHECK((*c3_x1_dot)[c3_i103], 14U);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 2U, 23, 2);
  for (c3_i104 = 0; c3_i104 < 2; c3_i104++) {
    (*c3_x1_dot)[c3_i104] = (*chartInstance->c3_v1)[c3_i104];
  }

  for (c3_i105 = 0; c3_i105 < 2; c3_i105++) {
    _SFD_DATA_RANGE_CHECK((*c3_x1_dot)[c3_i105], 14U);
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_a, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i106 = 0; c3_i106 < 2; c3_i106++) {
    c3_a[c3_i106] = 0.0 - (real_T)c3_i106;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i107 = 0; c3_i107 < 2; c3_i107++) {
    (*c3_v1_dot)[c3_i107] = 0.0 - (real_T)c3_i107;
  }

  for (c3_i108 = 0; c3_i108 < 2; c3_i108++) {
    _SFD_DATA_RANGE_CHECK((*c3_v1_dot)[c3_i108], 13U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 2U, 48, 2);
  c3_updateDataWrittenToVector(chartInstance, 13U);
  for (c3_i109 = 0; c3_i109 < 2; c3_i109++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_x1_out)[c3_i109], 15U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void outputs_c3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_a[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U, 2U, 23, 2);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_a, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i110 = 0; c3_i110 < 2; c3_i110++) {
    c3_a[c3_i110] = 0.0 - (real_T)c3_i110;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U, 2U, 48, 2);
  for (c3_i111 = 0; c3_i111 < 2; c3_i111++) {
    (*chartInstance->c3_x1_out)[c3_i111] = (*chartInstance->c3_x1)[c3_i111];
  }

  c3_updateDataWrittenToVector(chartInstance, 13U);
  for (c3_i112 = 0; c3_i112 < 2; c3_i112++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_x1_out)[c3_i112], 15U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Flipper(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_ini_fcn_to_be_inlined_113(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_term_fcn_to_be_inlined_113(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance, *(real_T
    *)c3_inData), false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d16;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d16, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d16;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  *(real_T *)c3_outData = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u[2])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), false);
  return c3_y;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_b_emlrt_marshallOut(chartInstance,
    *(real_T (*)[2])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_t, const char_T *c3_identifier, real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_t), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_t);
}

static void c3_d_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv65[2];
  int32_T c3_i113;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv65, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i113 = 0; c3_i113 < 2; c3_i113++) {
    c3_y[c3_i113] = c3_dv65[c3_i113];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv66[2];
  int32_T c3_i114;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv66);
  for (c3_i114 = 0; c3_i114 < 2; c3_i114++) {
    (*(real_T (*)[2])c3_outData)[c3_i114] = c3_dv66[c3_i114];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const boolean_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_c_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static boolean_T c3_e_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_sf_internal_predicateOutput, const char_T *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_y;
}

static boolean_T c3_f_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c3_outData = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Flipper_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 53, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  const mxArray *c3_rhs48 = NULL;
  const mxArray *c3_lhs48 = NULL;
  const mxArray *c3_rhs49 = NULL;
  const mxArray *c3_lhs49 = NULL;
  const mxArray *c3_rhs50 = NULL;
  const mxArray *c3_lhs50 = NULL;
  const mxArray *c3_rhs51 = NULL;
  const mxArray *c3_lhs51 = NULL;
  const mxArray *c3_rhs52 = NULL;
  const mxArray *c3_lhs52 = NULL;
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 11);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 11);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 14);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 17);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 18);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("isfi"), "name", "name", 20);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 21);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 25);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "context", "context", 26);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("norm"), "name", "name", 26);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 27);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 28);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 29);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  29);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1375980692U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 30);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 31);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 32);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 32);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 33);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 33);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 34);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 34);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 35);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("realmin"), "name", "name",
                  35);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 36);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 37);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 39);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 40);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 41);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 41);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("abs"), "name", "name", 42);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 43);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 44);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "context", "context", 45);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("mrdivide"), "name", "name",
                  45);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 46);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 46);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 47);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("rdivide"), "name", "name",
                  47);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 48);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c3_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 49);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c3_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("eml_div"), "name", "name",
                  50);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c3_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 51);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c3_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(""), "context", "context", 52);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("abs"), "name", "name", 52);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_e_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c3_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs52), "lhs", "lhs",
                  52);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
  sf_mex_destroy(&c3_rhs48);
  sf_mex_destroy(&c3_lhs48);
  sf_mex_destroy(&c3_rhs49);
  sf_mex_destroy(&c3_lhs49);
  sf_mex_destroy(&c3_rhs50);
  sf_mex_destroy(&c3_lhs50);
  sf_mex_destroy(&c3_rhs51);
  sf_mex_destroy(&c3_lhs51);
  sf_mex_destroy(&c3_rhs52);
  sf_mex_destroy(&c3_lhs52);
}

static const mxArray *c3_d_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_e_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static real_T c3_eml_mtimes_helper(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_a[2], real_T c3_b[2])
{
  real_T c3_y;
  real_T c3_d17;
  int32_T c3_i115;
  int32_T c3_i116;
  real_T c3_b_a[2];
  int32_T c3_i117;
  real_T c3_b_b[2];
  if (c3_use_refblas(chartInstance)) {
    c3_d17 = 0.0;
    for (c3_i115 = 0; c3_i115 < 2; c3_i115++) {
      c3_d17 += c3_a[c3_i115] * c3_b[c3_i115];
    }

    c3_y = c3_d17;
  } else {
    for (c3_i116 = 0; c3_i116 < 2; c3_i116++) {
      c3_b_a[c3_i116] = c3_a[c3_i116];
    }

    for (c3_i117 = 0; c3_i117 < 2; c3_i117++) {
      c3_b_b[c3_i117] = c3_b[c3_i117];
    }

    c3_y = c3_eml_xdotu(chartInstance, c3_b_a, c3_b_b);
  }

  return c3_y;
}

static void c3_common_checks(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_dynamic_size_checks(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_index_class(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_scalar_eg(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_scalarEg(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_any_enums(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_zerosum(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_zerosum(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c3_use_refblas(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return false;
}

static real_T c3_eml_xdotu(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2], real_T c3_y[2])
{
  int32_T c3_i118;
  real_T c3_b_x[2];
  int32_T c3_i119;
  real_T c3_b_y[2];
  for (c3_i118 = 0; c3_i118 < 2; c3_i118++) {
    c3_b_x[c3_i118] = c3_x[c3_i118];
  }

  for (c3_i119 = 0; c3_i119 < 2; c3_i119++) {
    c3_b_y[c3_i119] = c3_y[c3_i119];
  }

  return c3_xdotu(chartInstance, c3_b_x, c3_b_y);
}

static void c3_inline(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_xdotu(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2])
{
  int32_T c3_i120;
  real_T c3_b_x[2];
  int32_T c3_i121;
  real_T c3_b_y[2];
  for (c3_i120 = 0; c3_i120 < 2; c3_i120++) {
    c3_b_x[c3_i120] = c3_x[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 2; c3_i121++) {
    c3_b_y[c3_i121] = c3_y[c3_i121];
  }

  return c3_xdot(chartInstance, c3_b_x, c3_b_y);
}

static real_T c3_xdot(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
                      real_T c3_y[2])
{
  int32_T c3_i122;
  real_T c3_b_x[2];
  int32_T c3_i123;
  real_T c3_b_y[2];
  for (c3_i122 = 0; c3_i122 < 2; c3_i122++) {
    c3_b_x[c3_i122] = c3_x[c3_i122];
  }

  for (c3_i123 = 0; c3_i123 < 2; c3_i123++) {
    c3_b_y[c3_i123] = c3_y[c3_i123];
  }

  return c3_b_xdot(chartInstance, c3_b_x, c3_b_y);
}

static void c3_below_threshold(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_threshold(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_b_xdot(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2])
{
  int32_T c3_i124;
  real_T c3_b_x[2];
  int32_T c3_i125;
  real_T c3_b_y[2];
  for (c3_i124 = 0; c3_i124 < 2; c3_i124++) {
    c3_b_x[c3_i124] = c3_x[c3_i124];
  }

  for (c3_i125 = 0; c3_i125 < 2; c3_i125++) {
    c3_b_y[c3_i125] = c3_y[c3_i125];
  }

  return c3_xdotx(chartInstance, c3_b_x, c3_b_y);
}

static real_T c3_xdotx(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y[2])
{
  real_T c3_d;
  int32_T c3_k;
  int32_T c3_b_k;
  (void)chartInstance;
  c3_d = 0.0;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k;
    c3_d += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1] * c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 2, 1, 0) - 1];
  }

  return c3_d;
}

static void c3_eml_int_forloop_overflow_check(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_int_forloop_overflow_check_helper(SFc3_FlipperInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c3_isfi(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_isnumerictype(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static int32_T c3_intmin(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static void c3_b_eml_mtimes_helper(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_a, real_T c3_b[2], real_T c3_y[2])
{
  int32_T c3_i126;
  (void)chartInstance;
  for (c3_i126 = 0; c3_i126 < 2; c3_i126++) {
    c3_y[c3_i126] = c3_a * c3_b[c3_i126];
  }
}

static void c3_b_common_checks(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_c_isBuiltInNumeric(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_norm(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2])
{
  int32_T c3_i127;
  real_T c3_b_x[2];
  for (c3_i127 = 0; c3_i127 < 2; c3_i127++) {
    c3_b_x[c3_i127] = c3_x[c3_i127];
  }

  return c3_genpnorm(chartInstance, c3_b_x);
}

static real_T c3_genpnorm(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2])
{
  int32_T c3_i128;
  real_T c3_b_x[2];
  for (c3_i128 = 0; c3_i128 < 2; c3_i128++) {
    c3_b_x[c3_i128] = c3_x[c3_i128];
  }

  return c3_eml_xnrm2(chartInstance, c3_b_x);
}

static real_T c3_eml_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T
  c3_x[2])
{
  int32_T c3_i129;
  real_T c3_b_x[2];
  for (c3_i129 = 0; c3_i129 < 2; c3_i129++) {
    c3_b_x[c3_i129] = c3_x[c3_i129];
  }

  return c3_xnrm2(chartInstance, c3_b_x);
}

static real_T c3_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2])
{
  int32_T c3_i130;
  real_T c3_b_x[2];
  for (c3_i130 = 0; c3_i130 < 2; c3_i130++) {
    c3_b_x[c3_i130] = c3_x[c3_i130];
  }

  return c3_b_xnrm2(chartInstance, c3_b_x);
}

static void c3_b_below_threshold(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_b_threshold(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_c_eml_switch_helper(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_b_xnrm2(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x
  [2])
{
  real_T c3_y;
  real_T c3_scale;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_absxk;
  real_T c3_t;
  c3_y = 0.0;
  c3_scale = 2.2250738585072014E-308;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k;
    c3_absxk = c3_abs(chartInstance, c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 2, 1, 0) - 1]);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static void c3_realmin(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_realmin(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_float_model(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_abs(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x)
{
  return c3_eml_scalar_abs(chartInstance, c3_x);
}

static real_T c3_eml_scalar_abs(SFc3_FlipperInstanceStruct *chartInstance,
  real_T c3_x)
{
  (void)chartInstance;
  return muDoubleScalarAbs(c3_x);
}

static void c3_mrdivide(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_A[2],
  real_T c3_B, real_T c3_y[2])
{
  int32_T c3_i131;
  real_T c3_b_A[2];
  for (c3_i131 = 0; c3_i131 < 2; c3_i131++) {
    c3_b_A[c3_i131] = c3_A[c3_i131];
  }

  c3_rdivide(chartInstance, c3_b_A, c3_B, c3_y);
}

static void c3_assert(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_rdivide(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y, real_T c3_z[2])
{
  int32_T c3_i132;
  real_T c3_b_x[2];
  for (c3_i132 = 0; c3_i132 < 2; c3_i132++) {
    c3_b_x[c3_i132] = c3_x[c3_i132];
  }

  c3_eml_div(chartInstance, c3_b_x, c3_y, c3_z);
}

static void c3_eml_scalexp_compatible(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_div(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
  real_T c3_y, real_T c3_z[2])
{
  int32_T c3_i133;
  real_T c3_b_x[2];
  for (c3_i133 = 0; c3_i133 < 2; c3_i133++) {
    c3_b_x[c3_i133] = c3_x[c3_i133];
  }

  c3_div(chartInstance, c3_b_x, c3_y, c3_z);
}

static void c3_div(SFc3_FlipperInstanceStruct *chartInstance, real_T c3_x[2],
                   real_T c3_y, real_T c3_z[2])
{
  int32_T c3_i134;
  (void)chartInstance;
  for (c3_i134 = 0; c3_i134 < 2; c3_i134++) {
    c3_z[c3_i134] = c3_x[c3_i134] / c3_y;
  }
}

static const mxArray *c3_f_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const int32_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_f_emlrt_marshallOut(chartInstance,
    *(int32_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier)
{
  int32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  return c3_y;
}

static int32_T c3_h_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i135;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i135, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i135;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c3_outData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const uint8_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_g_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Flipper, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Flipper),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Flipper);
  return c3_y;
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c3_outData = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const real_T c3_u[2])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  return c3_y;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_h_emlrt_marshallOut(chartInstance,
    *(real_T (*)[2])c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_Hnd, const char_T *c3_identifier, real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Hnd), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Hnd);
}

static void c3_l_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv67[2];
  int32_T c3_i136;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv67, 1, 0, 0U, 1, 0U, 2, 2, 1);
  for (c3_i136 = 0; c3_i136 < 2; c3_i136++) {
    c3_y[c3_i136] = c3_dv67[c3_i136];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  real_T c3_dv68[2];
  int32_T c3_i137;
  SFc3_FlipperInstanceStruct *chartInstance;
  chartInstance = (SFc3_FlipperInstanceStruct *)chartInstanceVoid;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mxArrayInData), c3_varName,
                        c3_dv68);
  for (c3_i137 = 0; c3_i137 < 2; c3_i137++) {
    (*(real_T (*)[2])c3_outData)[c3_i137] = c3_dv68[c3_i137];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance)
{
  const mxArray *c3_y;
  int32_T c3_i138;
  real_T c3_dv69[2];
  int32_T c3_i139;
  real_T c3_dv70[2];
  int32_T c3_i140;
  real_T c3_dv71[2];
  int32_T c3_i141;
  real_T c3_dv72[2];
  int32_T c3_i142;
  real_T c3_dv73[2];
  int32_T c3_i143;
  real_T c3_dv74[2];
  int32_T c3_i144;
  real_T c3_dv75[2];
  int32_T c3_i145;
  real_T c3_dv76[2];
  int32_T c3_i146;
  real_T c3_dv77[2];
  int32_T c3_i147;
  real_T c3_dv78[2];
  int32_T c3_i148;
  real_T c3_dv79[2];
  int32_T c3_i149;
  real_T c3_dv80[2];
  int32_T c3_i150;
  real_T c3_dv81[2];
  int32_T c3_i151;
  real_T c3_dv82[2];
  int32_T c3_i152;
  boolean_T c3_bv0[19];
  c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(17, 1), false);
  for (c3_i138 = 0; c3_i138 < 2; c3_i138++) {
    c3_dv69[c3_i138] = (*chartInstance->c3_x1_out)[c3_i138];
  }

  sf_mex_setcell(c3_y, 0, c3_h_emlrt_marshallOut(chartInstance, c3_dv69));
  for (c3_i139 = 0; c3_i139 < 2; c3_i139++) {
    c3_dv70[c3_i139] = chartInstance->c3_Hnd[c3_i139];
  }

  sf_mex_setcell(c3_y, 1, c3_h_emlrt_marshallOut(chartInstance, c3_dv70));
  for (c3_i140 = 0; c3_i140 < 2; c3_i140++) {
    c3_dv71[c3_i140] = chartInstance->c3_n1[c3_i140];
  }

  sf_mex_setcell(c3_y, 2, c3_h_emlrt_marshallOut(chartInstance, c3_dv71));
  for (c3_i141 = 0; c3_i141 < 2; c3_i141++) {
    c3_dv72[c3_i141] = chartInstance->c3_n2[c3_i141];
  }

  sf_mex_setcell(c3_y, 3, c3_h_emlrt_marshallOut(chartInstance, c3_dv72));
  for (c3_i142 = 0; c3_i142 < 2; c3_i142++) {
    c3_dv73[c3_i142] = chartInstance->c3_n3[c3_i142];
  }

  sf_mex_setcell(c3_y, 4, c3_h_emlrt_marshallOut(chartInstance, c3_dv73));
  for (c3_i143 = 0; c3_i143 < 2; c3_i143++) {
    c3_dv74[c3_i143] = chartInstance->c3_p1[c3_i143];
  }

  sf_mex_setcell(c3_y, 5, c3_h_emlrt_marshallOut(chartInstance, c3_dv74));
  for (c3_i144 = 0; c3_i144 < 2; c3_i144++) {
    c3_dv75[c3_i144] = chartInstance->c3_p2[c3_i144];
  }

  sf_mex_setcell(c3_y, 6, c3_h_emlrt_marshallOut(chartInstance, c3_dv75));
  for (c3_i145 = 0; c3_i145 < 2; c3_i145++) {
    c3_dv76[c3_i145] = chartInstance->c3_p3[c3_i145];
  }

  sf_mex_setcell(c3_y, 7, c3_h_emlrt_marshallOut(chartInstance, c3_dv76));
  for (c3_i146 = 0; c3_i146 < 2; c3_i146++) {
    c3_dv77[c3_i146] = chartInstance->c3_p4[c3_i146];
  }

  sf_mex_setcell(c3_y, 8, c3_h_emlrt_marshallOut(chartInstance, c3_dv77));
  for (c3_i147 = 0; c3_i147 < 2; c3_i147++) {
    c3_dv78[c3_i147] = chartInstance->c3_t1[c3_i147];
  }

  sf_mex_setcell(c3_y, 9, c3_h_emlrt_marshallOut(chartInstance, c3_dv78));
  for (c3_i148 = 0; c3_i148 < 2; c3_i148++) {
    c3_dv79[c3_i148] = chartInstance->c3_t2[c3_i148];
  }

  sf_mex_setcell(c3_y, 10, c3_h_emlrt_marshallOut(chartInstance, c3_dv79));
  for (c3_i149 = 0; c3_i149 < 2; c3_i149++) {
    c3_dv80[c3_i149] = chartInstance->c3_t3[c3_i149];
  }

  sf_mex_setcell(c3_y, 11, c3_h_emlrt_marshallOut(chartInstance, c3_dv80));
  for (c3_i150 = 0; c3_i150 < 2; c3_i150++) {
    c3_dv81[c3_i150] = (*chartInstance->c3_v1)[c3_i150];
  }

  sf_mex_setcell(c3_y, 12, c3_h_emlrt_marshallOut(chartInstance, c3_dv81));
  for (c3_i151 = 0; c3_i151 < 2; c3_i151++) {
    c3_dv82[c3_i151] = (*chartInstance->c3_x1)[c3_i151];
  }

  sf_mex_setcell(c3_y, 13, c3_h_emlrt_marshallOut(chartInstance, c3_dv82));
  sf_mex_setcell(c3_y, 14, c3_g_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_active_c3_Flipper));
  sf_mex_setcell(c3_y, 15, c3_g_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_c3_Flipper));
  for (c3_i152 = 0; c3_i152 < 19; c3_i152++) {
    c3_bv0[c3_i152] = chartInstance->c3_dataWrittenToVector[c3_i152];
  }

  sf_mex_setcell(c3_y, 16, c3_j_emlrt_marshallOut(chartInstance, c3_bv0));
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallOut(SFc3_FlipperInstanceStruct
  *chartInstance, const boolean_T c3_u[19])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 19), false);
  return c3_y;
}

static void c3_m_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u)
{
  real_T c3_dv83[2];
  int32_T c3_i153;
  real_T c3_dv84[2];
  int32_T c3_i154;
  real_T c3_dv85[2];
  int32_T c3_i155;
  real_T c3_dv86[2];
  int32_T c3_i156;
  real_T c3_dv87[2];
  int32_T c3_i157;
  real_T c3_dv88[2];
  int32_T c3_i158;
  real_T c3_dv89[2];
  int32_T c3_i159;
  real_T c3_dv90[2];
  int32_T c3_i160;
  real_T c3_dv91[2];
  int32_T c3_i161;
  real_T c3_dv92[2];
  int32_T c3_i162;
  real_T c3_dv93[2];
  int32_T c3_i163;
  real_T c3_dv94[2];
  int32_T c3_i164;
  real_T c3_dv95[2];
  int32_T c3_i165;
  real_T c3_dv96[2];
  int32_T c3_i166;
  boolean_T c3_bv1[19];
  int32_T c3_i167;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "x1_out", c3_dv83);
  for (c3_i153 = 0; c3_i153 < 2; c3_i153++) {
    (*chartInstance->c3_x1_out)[c3_i153] = c3_dv83[c3_i153];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "Hnd", c3_dv84);
  for (c3_i154 = 0; c3_i154 < 2; c3_i154++) {
    chartInstance->c3_Hnd[c3_i154] = c3_dv84[c3_i154];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)), "n1",
                        c3_dv85);
  for (c3_i155 = 0; c3_i155 < 2; c3_i155++) {
    chartInstance->c3_n1[c3_i155] = c3_dv85[c3_i155];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)), "n2",
                        c3_dv86);
  for (c3_i156 = 0; c3_i156 < 2; c3_i156++) {
    chartInstance->c3_n2[c3_i156] = c3_dv86[c3_i156];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)), "n3",
                        c3_dv87);
  for (c3_i157 = 0; c3_i157 < 2; c3_i157++) {
    chartInstance->c3_n3[c3_i157] = c3_dv87[c3_i157];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)), "p1",
                        c3_dv88);
  for (c3_i158 = 0; c3_i158 < 2; c3_i158++) {
    chartInstance->c3_p1[c3_i158] = c3_dv88[c3_i158];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)), "p2",
                        c3_dv89);
  for (c3_i159 = 0; c3_i159 < 2; c3_i159++) {
    chartInstance->c3_p2[c3_i159] = c3_dv89[c3_i159];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)), "p3",
                        c3_dv90);
  for (c3_i160 = 0; c3_i160 < 2; c3_i160++) {
    chartInstance->c3_p3[c3_i160] = c3_dv90[c3_i160];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)), "p4",
                        c3_dv91);
  for (c3_i161 = 0; c3_i161 < 2; c3_i161++) {
    chartInstance->c3_p4[c3_i161] = c3_dv91[c3_i161];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)), "t1",
                        c3_dv92);
  for (c3_i162 = 0; c3_i162 < 2; c3_i162++) {
    chartInstance->c3_t1[c3_i162] = c3_dv92[c3_i162];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)),
                        "t2", c3_dv93);
  for (c3_i163 = 0; c3_i163 < 2; c3_i163++) {
    chartInstance->c3_t2[c3_i163] = c3_dv93[c3_i163];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 11)),
                        "t3", c3_dv94);
  for (c3_i164 = 0; c3_i164 < 2; c3_i164++) {
    chartInstance->c3_t3[c3_i164] = c3_dv94[c3_i164];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 12)),
                        "v1", c3_dv95);
  for (c3_i165 = 0; c3_i165 < 2; c3_i165++) {
    (*chartInstance->c3_v1)[c3_i165] = c3_dv95[c3_i165];
  }

  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
                        "x1", c3_dv96);
  for (c3_i166 = 0; c3_i166 < 2; c3_i166++) {
    (*chartInstance->c3_x1)[c3_i166] = c3_dv96[c3_i166];
  }

  chartInstance->c3_is_active_c3_Flipper = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 14)), "is_active_c3_Flipper");
  chartInstance->c3_is_c3_Flipper = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 15)), "is_c3_Flipper");
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 16)),
                        "dataWrittenToVector", c3_bv1);
  for (c3_i167 = 0; c3_i167 < 19; c3_i167++) {
    chartInstance->c3_dataWrittenToVector[c3_i167] = c3_bv1[c3_i167];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 17)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
}

static void c3_n_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[19])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_o_emlrt_marshallIn(SFc3_FlipperInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[19])
{
  boolean_T c3_bv2[19];
  int32_T c3_i168;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv2, 1, 11, 0U, 1, 0U, 1, 19);
  for (c3_i168 = 0; c3_i168 < 19; c3_i168++) {
    c3_y[c3_i168] = c3_bv2[c3_i168];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_FlipperInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_q_emlrt_marshallIn(SFc3_FlipperInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_FlipperInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  chartInstance->c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c3_vectorIndex, 0, 18, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_FlipperInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber, uint32_T
  c3_ssIdOfSourceObject, int32_T c3_offsetInSourceObject, int32_T
  c3_lengthInSourceObject)
{
  (void)c3_ssIdOfSourceObject;
  (void)c3_offsetInSourceObject;
  (void)c3_lengthInSourceObject;
  if (!chartInstance->c3_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c3_vectorIndex, 0, 18, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c3_dataNumber);
  }
}

static void init_dsm_address_info(SFc3_FlipperInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_FlipperInstanceStruct *chartInstance)
{
  chartInstance->c3_v1 = (real_T (*)[2])(ssGetContStates_wrapper
    (chartInstance->S) + 0);
  chartInstance->c3_x1 = (real_T (*)[2])(ssGetContStates_wrapper
    (chartInstance->S) + 2);
  chartInstance->c3_x1_out = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c3_Flipper_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3065579888U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(249136406U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(569441375U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1334219463U);
}

mxArray* sf_c3_Flipper_get_post_codegen_info(void);
mxArray *sf_c3_Flipper_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cOUjw6rjI38Pg982GYjqRE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_Flipper_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Flipper_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Flipper_jit_fallback_info(void)
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

mxArray *sf_c3_Flipper_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Flipper_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Flipper(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[44],T\"x1_out\",},{M[3],M[31],T\"Hnd\",},{M[3],M[32],T\"n1\",},{M[3],M[33],T\"n2\",},{M[3],M[34],T\"n3\",},{M[3],M[35],T\"p1\",},{M[3],M[36],T\"p2\",},{M[3],M[37],T\"p3\",},{M[3],M[38],T\"p4\",},{M[3],M[39],T\"t1\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[3],M[40],T\"t2\",},{M[3],M[41],T\"t3\",},{M[5],M[42],T\"v1\",},{M[5],M[43],T\"x1\",},{M[8],M[0],T\"is_active_c3_Flipper\",},{M[9],M[0],T\"is_c3_Flipper\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Flipper_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_FlipperInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_FlipperInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FlipperMachineNumber_,
           3,
           11,
           5,
           0,
           21,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_FlipperMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FlipperMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FlipperMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,7,0,0,"R");
          _SFD_SET_DATA_PROPS(1,7,0,0,"RHnd");
          _SFD_SET_DATA_PROPS(2,0,0,0,"Hnd");
          _SFD_SET_DATA_PROPS(3,0,0,0,"n1");
          _SFD_SET_DATA_PROPS(4,0,0,0,"n2");
          _SFD_SET_DATA_PROPS(5,0,0,0,"n3");
          _SFD_SET_DATA_PROPS(6,0,0,0,"p1");
          _SFD_SET_DATA_PROPS(7,0,0,0,"p2");
          _SFD_SET_DATA_PROPS(8,0,0,0,"p3");
          _SFD_SET_DATA_PROPS(9,0,0,0,"p4");
          _SFD_SET_DATA_PROPS(10,0,0,0,"t1");
          _SFD_SET_DATA_PROPS(11,0,0,0,"t2");
          _SFD_SET_DATA_PROPS(12,0,0,0,"t3");
          _SFD_SET_DATA_PROPS(13,0,0,0,"v1");
          _SFD_SET_DATA_PROPS(14,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(15,2,0,1,"x1_out");
          _SFD_SET_DATA_PROPS(16,9,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"WandLRefl",0,-1,74);
        _SFD_CV_INIT_EML(5,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(5,0,"WandLKontakt",0,-1,103);
        _SFD_CV_INIT_EML_IF(5,1,0,37,85,-1,103);

        {
          static int condStart[] = { 41, 70 };

          static int condEnd[] = { 66, 84 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,1,0,41,84,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(5,1,0,41,66,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(5,1,1,70,84,-1,2);
        _SFD_CV_INIT_EML(4,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"Init",0,-1,269);
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"Acc",0,-1,31);
        _SFD_CV_INIT_EML(9,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(9,0,"WandUKontakt",0,-1,104);
        _SFD_CV_INIT_EML_IF(9,1,0,37,85,-1,104);

        {
          static int condStart[] = { 41, 70 };

          static int condEnd[] = { 66, 84 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,1,0,41,84,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(9,1,0,41,66,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(9,1,1,70,84,-1,2);
        _SFD_CV_INIT_EML(10,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(10,0,"WandURefl",0,-1,74);
        _SFD_CV_INIT_EML(2,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(2,0,"HndKontakt",0,-1,156);
        _SFD_CV_INIT_EML_IF(2,1,0,89,138,-1,156);

        {
          static int condStart[] = { 94, 124 };

          static int condEnd[] = { 120, 137 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,1,0,94,137,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(2,1,0,94,120,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,1,124,137,-1,2);
        _SFD_CV_INIT_EML(3,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"HndRefl",0,-1,121);
        _SFD_CV_INIT_EML(7,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(7,0,"WandRKontakt",0,-1,103);
        _SFD_CV_INIT_EML_IF(7,1,0,37,85,-1,103);

        {
          static int condStart[] = { 41, 70 };

          static int condEnd[] = { 66, 84 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,1,0,41,84,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(7,1,0,41,66,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(7,1,1,70,84,-1,2);
        _SFD_CV_INIT_EML(8,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"WandRRefl",0,-1,74);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,13,1,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c3_R);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c3_RHnd);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_Hnd);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_n1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_n2);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_n3);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_p1);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_p2);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_p3);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_p4);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_t1);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_t2);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c3_t3);
        _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c3_v1);
        _SFD_SET_DATA_VALUE_PTR(14U, *chartInstance->c3_x1);
        _SFD_SET_DATA_VALUE_PTR(15U, *chartInstance->c3_x1_out);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FlipperMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Mc8C5dbHMyD7Ul2WkIHPi";
}

static void sf_opaque_initialize_c3_Flipper(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_FlipperInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
  initialize_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Flipper(void *chartInstanceVar)
{
  enable_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Flipper(void *chartInstanceVar)
{
  disable_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c3_Flipper(void *chartInstanceVar)
{
  zeroCrossings_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c3_Flipper(void *chartInstanceVar)
{
  outputs_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c3_Flipper(void *chartInstanceVar)
{
  derivatives_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Flipper(void *chartInstanceVar)
{
  sf_gateway_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Flipper(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_Flipper((SFc3_FlipperInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Flipper(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_Flipper((SFc3_FlipperInstanceStruct*)chartInfo->chartInstance,
    st);
}

static void sf_opaque_terminate_c3_Flipper(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_FlipperInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Flipper_optimization_info();
    }

    finalize_c3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Flipper((SFc3_FlipperInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Flipper(SimStruct *S)
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
    initialize_params_c3_Flipper((SFc3_FlipperInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Flipper(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Flipper_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2072639245U));
  ssSetChecksum1(S,(494815572U));
  ssSetChecksum2(S,(2545941012U));
  ssSetChecksum3(S,(1247216376U));
  ssSetNumContStates(S,4);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Flipper(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Flipper(SimStruct *S)
{
  SFc3_FlipperInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_FlipperInstanceStruct *)utMalloc(sizeof
    (SFc3_FlipperInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_FlipperInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Flipper;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Flipper;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Flipper;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Flipper;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Flipper;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Flipper;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Flipper;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Flipper;
  chartInstance->chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c3_Flipper;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_Flipper;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c3_Flipper;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Flipper;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Flipper;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Flipper;
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
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_Flipper_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Flipper(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Flipper(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Flipper(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Flipper_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
