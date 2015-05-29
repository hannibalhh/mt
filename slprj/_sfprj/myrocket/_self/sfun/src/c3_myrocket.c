/* Include files */

#include <stddef.h>
#include "blas.h"
#include "myrocket_sfun.h"
#include "c3_myrocket.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "myrocket_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Antriebslos              ((uint8_T)1U)
#define c3_IN_Stufe1                   ((uint8_T)2U)
#define c3_IN_Stufe2                   ((uint8_T)3U)
#define c3_const_rE                    (6.378E+6)
#define c3_const_mE                    (5.9736000000000006E+24)
#define c3_const_G                     (6.6743E-11)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[8] = { "r1", "Fs1", "r2", "Fs2",
  "nargin", "nargout", "a1", "a2" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[9] = { "r1", "Fs1", "r2", "Fs2",
  "Schubkraft_2", "nargin", "nargout", "a1", "a2" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[9] = { "mR", "r1", "Fs1",
  "Schubkraft_1", "a", "nargin", "nargout", "a1", "a2" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void initialize_params_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance);
static void enable_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void disable_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance);
static void set_sim_state_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_myrocket
  (SFc3_myrocketInstanceStruct *chartInstance);
static void finalize_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void sf_gateway_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void mdl_start_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void zeroCrossings_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void derivatives_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void outputs_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void initSimStructsc3_myrocket(SFc3_myrocketInstanceStruct *chartInstance);
static void c3_eml_ini_fcn_to_be_inlined_71(SFc3_myrocketInstanceStruct
  *chartInstance);
static void c3_eml_term_fcn_to_be_inlined_71(SFc3_myrocketInstanceStruct
  *chartInstance);
static real_T c3_mrdivide(SFc3_myrocketInstanceStruct *chartInstance, real_T
  c3_A, real_T c3_B);
static void c3_assert(SFc3_myrocketInstanceStruct *chartInstance);
static real_T c3_rdivide(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
  real_T c3_y);
static void c3_isBuiltInNumeric(SFc3_myrocketInstanceStruct *chartInstance);
static void c3_eml_scalexp_compatible(SFc3_myrocketInstanceStruct *chartInstance);
static real_T c3_eml_div(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
  real_T c3_y);
static real_T c3_div(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
                     real_T c3_y);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const real_T c3_u);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const boolean_T c3_u);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_d_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_c_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_d_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_e_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const int32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier);
static int32_T c3_f_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const uint8_T c3_u);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Antriebslos, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance);
static const mxArray *c3_h_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const boolean_T c3_u[18]);
static void c3_i_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u);
static void c3_j_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[18]);
static void c3_k_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[18]);
static const mxArray *c3_l_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_m_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_myrocketInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_myrocketInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber, uint32_T
  c3_ssIdOfSourceObject, int32_T c3_offsetInSourceObject, int32_T
  c3_lengthInSourceObject);
static void init_dsm_address_info(SFc3_myrocketInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_myrocketInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_Antriebslos = 0U;
  chartInstance->c3_tp_Stufe1 = 0U;
  chartInstance->c3_tp_Stufe2 = 0U;
  chartInstance->c3_is_active_c3_myrocket = 0U;
  chartInstance->c3_is_c3_myrocket = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_rE = 6.378E+6;
  chartInstance->c3_mE = 5.9736000000000006E+24;
  chartInstance->c3_G = 6.6743E-11;
}

static void initialize_params_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  sf_mex_import_named("m1_leer", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_m1_leer = c3_d0;
  sf_mex_import_named("m2_leer", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_m2_leer = c3_d1;
  sf_mex_import_named("St1_Treibstoff", sf_mex_get_sfun_param(chartInstance->S,
    3, 0), &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_St1_Treibstoff = c3_d2;
  sf_mex_import_named("St2_Treibstoff", sf_mex_get_sfun_param(chartInstance->S,
    4, 0), &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_St2_Treibstoff = c3_d3;
  sf_mex_import_named("Durchsatz_1", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Durchsatz_1 = c3_d4;
  sf_mex_import_named("Durchsatz_2", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Durchsatz_2 = c3_d5;
  sf_mex_import_named("SchubProDurchsatz", sf_mex_get_sfun_param
                      (chartInstance->S, 2, 0), &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_SchubProDurchsatz = c3_d6;
}

static void enable_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_myrocket == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_myrocket == c3_IN_Antriebslos) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_myrocket == c3_IN_Stufe2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_myrocket == c3_IN_Stufe1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_myrocket(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_st, c3_g_emlrt_marshallOut(chartInstance), false);
  return c3_st;
}

static void set_sim_state_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_myrocket(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_myrocket
  (SFc3_myrocketInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_myrocket == c3_IN_Antriebslos) {
      chartInstance->c3_tp_Antriebslos = 1U;
    } else {
      chartInstance->c3_tp_Antriebslos = 0U;
    }

    if (chartInstance->c3_is_c3_myrocket == c3_IN_Stufe1) {
      chartInstance->c3_tp_Stufe1 = 1U;
    } else {
      chartInstance->c3_tp_Stufe1 = 0U;
    }

    if (chartInstance->c3_is_c3_myrocket == c3_IN_Stufe2) {
      chartInstance->c3_tp_Stufe2 = 1U;
    } else {
      chartInstance->c3_tp_Stufe2 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[8];
  real_T c3_r1;
  real_T c3_Fs1;
  real_T c3_r2;
  real_T c3_Fs2;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 2.0;
  real_T c3_v1_dot;
  real_T c3_v2_dot;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[9];
  real_T c3_mR;
  real_T c3_b_r1;
  real_T c3_b_Fs1;
  real_T c3_Schubkraft_1;
  real_T c3_a;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 2.0;
  real_T c3_b_v1_dot;
  real_T c3_b_v2_dot;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_c_r1;
  real_T c3_c_Fs1;
  real_T c3_b_r2;
  real_T c3_b_Fs2;
  real_T c3_Schubkraft_2;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 2.0;
  real_T c3_c_v1_dot;
  real_T c3_c_v2_dot;
  c3_set_sim_state_side_effects_c3_myrocket(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    chartInstance->c3_lastMajorTime = _sfTime_;
    chartInstance->c3_stateChanged = false;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1, 4U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2, 5U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1, 6U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2, 7U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_rE, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_mE, 9U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_G, 10U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_m1_leer, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_m2_leer, 12U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_St1_Treibstoff, 13U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_St2_Treibstoff, 14U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Durchsatz_1, 15U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Durchsatz_2, 16U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_SchubProDurchsatz, 17U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1, 18U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2, 19U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    chartInstance->c3_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_is_active_c3_myrocket == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_active_c3_myrocket = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      CV_EML_FCN(6, 0);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 3);
      *chartInstance->c3_x1 = 0.0;
      c3_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 4);
      *chartInstance->c3_v1 = 0.0;
      c3_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 6);
      *chartInstance->c3_x2 = 0.0;
      c3_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 7);
      *chartInstance->c3_v2 = 0.0;
      c3_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 9);
      *chartInstance->c3_m1 = chartInstance->c3_m1_leer +
        chartInstance->c3_St1_Treibstoff;
      c3_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, 10);
      *chartInstance->c3_m2 = chartInstance->c3_m2_leer +
        chartInstance->c3_St2_Treibstoff;
      c3_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(6U, chartInstance->c3_sfEvent, -10);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_stateChanged = true;
      chartInstance->c3_is_c3_myrocket = c3_IN_Stufe1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Stufe1 = 1U;
    } else {
      switch (chartInstance->c3_is_c3_myrocket) {
       case c3_IN_Antriebslos:
        CV_CHART_EVAL(0, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
        break;

       case c3_IN_Stufe1:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 10U, 1, 2);
        c3_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
          *chartInstance->c3_m1, chartInstance->c3_m1_leer, -1, 3U,
          *chartInstance->c3_m1 <= chartInstance->c3_m1_leer));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Stufe1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_myrocket = c3_IN_Stufe2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Stufe2 = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
        }
        break;

       case c3_IN_Stufe2:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 11U, 1, 2);
        c3_b_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
          *chartInstance->c3_m2, chartInstance->c3_m2_leer, -1, 3U,
          *chartInstance->c3_m2 <= chartInstance->c3_m2_leer));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Stufe2 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_stateChanged = true;
          chartInstance->c3_is_c3_myrocket = c3_IN_Antriebslos;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Antriebslos = 1U;
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);
        chartInstance->c3_is_c3_myrocket = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        break;
      }
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    if (chartInstance->c3_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_myrocket) {
   case c3_IN_Antriebslos:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_c_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v1_dot, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v2_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(2, 0);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 15U, 31, 2);
    c3_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 56, 2);
    c3_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_r1 * c3_r1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 15U, 76, 2);
    c3_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 101, 2);
    c3_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_r2 * c3_r2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 130, 2);
    c3_v1_dot = c3_mrdivide(chartInstance, -c3_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 147, 2);
    c3_v2_dot = c3_mrdivide(chartInstance, -c3_Fs2, *chartInstance->c3_m2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -9);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 64, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 76, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 7U, 116, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 7U, 126, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 137, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 147, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 7U, 158, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 7U, 168, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe1:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_g_debug_family_names,
      c3_d_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_mR, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs1, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_1, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_a, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 30, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 35, 2);
    c3_mR = *chartInstance->c3_m1 + *chartInstance->c3_m2;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 13U, 44, 2);
    c3_b_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_b_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE * c3_mR),
      c3_b_r1 * c3_b_r1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
    c3_Schubkraft_1 = chartInstance->c3_Durchsatz_1 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 161, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 164, 2);
    c3_a = c3_mrdivide(chartInstance, c3_Schubkraft_1 - c3_b_Fs1,
                       *chartInstance->c3_m1 + *chartInstance->c3_m2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_b_v1_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_b_v2_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 59, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 71, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 3U, 125, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 3U, 135, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 146, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 156, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 3U, 167, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 3U, 177, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe2:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
      c3_d_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_2, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(1, 0);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 14U, 31, 2);
    c3_c_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 56, 2);
    c3_c_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_c_r1 * c3_c_r1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 14U, 76, 2);
    c3_b_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 101, 2);
    c3_b_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_b_r2 * c3_b_r2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 7);
    c3_Schubkraft_2 = chartInstance->c3_Durchsatz_2 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 178, 2);
    c3_c_v1_dot = c3_mrdivide(chartInstance, -c3_c_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 10);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 209, 2);
    c3_c_v2_dot = c3_mrdivide(chartInstance, c3_Schubkraft_2 - c3_b_Fs2,
      *chartInstance->c3_m2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 59, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 71, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 6U, 124, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 6U, 134, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 145, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 155, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 6U, 166, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 6U, 176, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_myrocketMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void zeroCrossings_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T *c3_zcVar;
  c3_zcVar = (real_T *)(ssGetNonsampledZCs_wrapper(chartInstance->S) + 0);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_lastMajorTime == _sfTime_) {
    *c3_zcVar = -1.0;
  } else {
    chartInstance->c3_stateChanged = false;
    if (chartInstance->c3_is_active_c3_myrocket == 0U) {
      chartInstance->c3_stateChanged = true;
    } else {
      switch (chartInstance->c3_is_c3_myrocket) {
       case c3_IN_Antriebslos:
        CV_CHART_EVAL(0, 0, 1);
        break;

       case c3_IN_Stufe1:
        CV_CHART_EVAL(0, 0, 2);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 10U, 1, 2);
        c3_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
          *chartInstance->c3_m1, chartInstance->c3_m1_leer, -1, 3U,
          *chartInstance->c3_m1 <= chartInstance->c3_m1_leer));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       case c3_IN_Stufe2:
        CV_CHART_EVAL(0, 0, 3);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 11U, 1, 2);
        c3_b_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
          *chartInstance->c3_m2, chartInstance->c3_m2_leer, -1, 3U,
          *chartInstance->c3_m2 <= chartInstance->c3_m2_leer));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          chartInstance->c3_stateChanged = true;
        }
        break;

       default:
        CV_CHART_EVAL(0, 0, 0);
        chartInstance->c3_is_c3_myrocket = c3_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (chartInstance->c3_stateChanged) {
      *c3_zcVar = 1.0;
    } else {
      *c3_zcVar = -1.0;
    }
  }
}

static void derivatives_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[8];
  real_T c3_r1;
  real_T c3_Fs1;
  real_T c3_r2;
  real_T c3_Fs2;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 2.0;
  real_T c3_v1_dot;
  real_T c3_v2_dot;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_mR;
  real_T c3_b_r1;
  real_T c3_b_Fs1;
  real_T c3_Schubkraft_1;
  real_T c3_a;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 2.0;
  real_T c3_b_v1_dot;
  real_T c3_b_v2_dot;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_c_r1;
  real_T c3_c_Fs1;
  real_T c3_b_r2;
  real_T c3_b_Fs2;
  real_T c3_Schubkraft_2;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 2.0;
  real_T c3_c_v1_dot;
  real_T c3_c_v2_dot;
  real_T *c3_x1_dot;
  real_T *c3_x2_dot;
  real_T *c3_d_v1_dot;
  real_T *c3_d_v2_dot;
  real_T *c3_m1_dot;
  real_T *c3_m2_dot;
  c3_m2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 5);
  c3_m1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 4);
  c3_d_v2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 3);
  c3_d_v1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 2);
  c3_x2_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 1);
  c3_x1_dot = (real_T *)(ssGetdX_wrapper(chartInstance->S) + 0);
  *c3_x1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 4U);
  *c3_x2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 5U);
  *c3_d_v1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_d_v1_dot, 6U);
  *c3_d_v2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_d_v2_dot, 7U);
  *c3_m1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_m1_dot, 18U);
  *c3_m2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c3_m2_dot, 19U);
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_myrocket) {
   case c3_IN_Antriebslos:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_c_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v1_dot, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v2_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(2, 0);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 15U, 31, 2);
    c3_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 56, 2);
    c3_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_r1 * c3_r1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 15U, 76, 2);
    c3_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 101, 2);
    c3_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_r2 * c3_r2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 130, 2);
    c3_v1_dot = c3_mrdivide(chartInstance, -c3_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 147, 2);
    c3_v2_dot = c3_mrdivide(chartInstance, -c3_Fs2, *chartInstance->c3_m2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -9);
    _SFD_SYMBOL_SCOPE_POP();
    *c3_d_v1_dot = c3_v1_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v1_dot, 6U);
    *c3_d_v2_dot = c3_v2_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v2_dot, 7U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 64, 2);
    *c3_x1_dot = *chartInstance->c3_v1;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 4U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 76, 2);
    *c3_x2_dot = *chartInstance->c3_v2;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 5U);
    *c3_m1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c3_m1_dot, 18U);
    *c3_m2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c3_m2_dot, 19U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 7U, 116, 2);
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 7U, 126, 2);
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 137, 2);
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 147, 2);
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 7U, 158, 2);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 7U, 168, 2);
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe1:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_g_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_mR, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs1, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_1, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_a, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 30, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 35, 2);
    c3_mR = *chartInstance->c3_m1 + *chartInstance->c3_m2;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 13U, 44, 2);
    c3_b_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_b_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE * c3_mR),
      c3_b_r1 * c3_b_r1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
    c3_Schubkraft_1 = chartInstance->c3_Durchsatz_1 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 161, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 164, 2);
    c3_a = c3_mrdivide(chartInstance, c3_Schubkraft_1 - c3_b_Fs1,
                       *chartInstance->c3_m1 + *chartInstance->c3_m2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_b_v1_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_b_v2_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    *c3_d_v1_dot = c3_b_v1_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v1_dot, 6U);
    *c3_d_v2_dot = c3_b_v2_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v2_dot, 7U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 59, 2);
    *c3_x1_dot = *chartInstance->c3_v1;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 4U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 71, 2);
    *c3_x2_dot = *chartInstance->c3_v2;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 5U);
    *c3_m1_dot = -chartInstance->c3_Durchsatz_1;
    _SFD_DATA_RANGE_CHECK(*c3_m1_dot, 18U);
    *c3_m2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c3_m2_dot, 19U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 3U, 125, 2);
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 3U, 135, 2);
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 146, 2);
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 156, 2);
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 3U, 167, 2);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 3U, 177, 2);
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe2:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_2, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(1, 0);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 14U, 31, 2);
    c3_c_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 56, 2);
    c3_c_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_c_r1 * c3_c_r1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 14U, 76, 2);
    c3_b_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 101, 2);
    c3_b_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_b_r2 * c3_b_r2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 7);
    c3_Schubkraft_2 = chartInstance->c3_Durchsatz_2 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 178, 2);
    c3_c_v1_dot = c3_mrdivide(chartInstance, -c3_c_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 10);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 209, 2);
    c3_c_v2_dot = c3_mrdivide(chartInstance, c3_Schubkraft_2 - c3_b_Fs2,
      *chartInstance->c3_m2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    *c3_d_v1_dot = c3_c_v1_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v1_dot, 6U);
    *c3_d_v2_dot = c3_c_v2_dot;
    _SFD_DATA_RANGE_CHECK(*c3_d_v2_dot, 7U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 59, 2);
    *c3_x1_dot = *chartInstance->c3_v1;
    _SFD_DATA_RANGE_CHECK(*c3_x1_dot, 4U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 71, 2);
    *c3_x2_dot = *chartInstance->c3_v2;
    _SFD_DATA_RANGE_CHECK(*c3_x2_dot, 5U);
    *c3_m1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c3_m1_dot, 18U);
    *c3_m2_dot = -chartInstance->c3_Durchsatz_2;
    _SFD_DATA_RANGE_CHECK(*c3_m2_dot, 19U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 6U, 124, 2);
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 6U, 134, 2);
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 145, 2);
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 155, 2);
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 6U, 166, 2);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 6U, 176, 2);
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }
}

static void outputs_c3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[8];
  real_T c3_r1;
  real_T c3_Fs1;
  real_T c3_r2;
  real_T c3_Fs2;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 2.0;
  real_T c3_v1_dot;
  real_T c3_v2_dot;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_mR;
  real_T c3_b_r1;
  real_T c3_b_Fs1;
  real_T c3_Schubkraft_1;
  real_T c3_a;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 2.0;
  real_T c3_b_v1_dot;
  real_T c3_b_v2_dot;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_c_r1;
  real_T c3_c_Fs1;
  real_T c3_b_r2;
  real_T c3_b_Fs2;
  real_T c3_Schubkraft_2;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 2.0;
  real_T c3_c_v1_dot;
  real_T c3_c_v2_dot;
  _sfTime_ = sf_get_time(chartInstance->S);
  switch (chartInstance->c3_is_c3_myrocket) {
   case c3_IN_Antriebslos:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_c_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v1_dot, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_v2_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(2, 0);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 15U, 31, 2);
    c3_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 56, 2);
    c3_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_r1 * c3_r1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 15U, 76, 2);
    c3_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 101, 2);
    c3_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_r2 * c3_r2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 15U, 130, 2);
    c3_v1_dot = c3_mrdivide(chartInstance, -c3_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 15U, 147, 2);
    c3_v2_dot = c3_mrdivide(chartInstance, -c3_Fs2, *chartInstance->c3_m2);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -9);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 64, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 76, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 7U, 116, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 7U, 126, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 7U, 137, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 7U, 147, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 7U, 158, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 7U, 168, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe1:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_g_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_mR, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs1, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_1, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_a, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 30, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 35, 2);
    c3_mR = *chartInstance->c3_m1 + *chartInstance->c3_m2;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 13U, 44, 2);
    c3_b_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_b_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE * c3_mR),
      c3_b_r1 * c3_b_r1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
    c3_Schubkraft_1 = chartInstance->c3_Durchsatz_1 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 13U, 161, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 13U, 164, 2);
    c3_a = c3_mrdivide(chartInstance, c3_Schubkraft_1 - c3_b_Fs1,
                       *chartInstance->c3_m1 + *chartInstance->c3_m2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_b_v1_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_b_v2_dot = c3_a;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 59, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 71, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 3U, 125, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 3U, 135, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 3U, 146, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 3U, 156, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 3U, 167, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 3U, 177, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stufe2:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_r1, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_Fs1, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_r2, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Fs2, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Schubkraft_2, 4U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 5U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v1_dot, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_v2_dot, 8U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(1, 0);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 3);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 14U, 31, 2);
    c3_c_r1 = *chartInstance->c3_x1 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 4);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 56, 2);
    c3_c_Fs1 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m1), c3_c_r1 * c3_c_r1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 5);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 14U, 76, 2);
    c3_b_r2 = *chartInstance->c3_x2 + c3_const_rE;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 6);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 101, 2);
    c3_b_Fs2 = c3_mrdivide(chartInstance, c3_const_G * (c3_const_mE *
      *chartInstance->c3_m2), c3_b_r2 * c3_b_r2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 7);
    c3_Schubkraft_2 = chartInstance->c3_Durchsatz_2 *
      chartInstance->c3_SchubProDurchsatz;
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 9);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 14U, 178, 2);
    c3_c_v1_dot = c3_mrdivide(chartInstance, -c3_c_Fs1, *chartInstance->c3_m1);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, 10);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 14U, 209, 2);
    c3_c_v2_dot = c3_mrdivide(chartInstance, c3_Schubkraft_2 - c3_b_Fs2,
      *chartInstance->c3_m2);
    _SFD_EML_CALL(1U, chartInstance->c3_sfEvent, -10);
    _SFD_SYMBOL_SCOPE_POP();
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 59, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 71, 2);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 4U, 6U, 124, 2);
    *chartInstance->c3_x1_out = *chartInstance->c3_x1;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x1_out, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U, 6U, 134, 2);
    *chartInstance->c3_x2_out = *chartInstance->c3_x2;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_x2_out, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U, 6U, 145, 2);
    *chartInstance->c3_v1_out = *chartInstance->c3_v1;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v1_out, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U, 6U, 155, 2);
    *chartInstance->c3_v2_out = *chartInstance->c3_v2;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v2_out, 3U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 18U, 6U, 166, 2);
    *chartInstance->c3_m1_out = *chartInstance->c3_m1;
    c3_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m1_out, 20U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 19U, 6U, 176, 2);
    *chartInstance->c3_m2_out = *chartInstance->c3_m2;
    c3_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m2_out, 21U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    break;
  }
}

static void initSimStructsc3_myrocket(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_ini_fcn_to_be_inlined_71(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_term_fcn_to_be_inlined_71(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_mrdivide(SFc3_myrocketInstanceStruct *chartInstance, real_T
  c3_A, real_T c3_B)
{
  return c3_rdivide(chartInstance, c3_A, c3_B);
}

static void c3_assert(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_rdivide(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
  real_T c3_y)
{
  return c3_eml_div(chartInstance, c3_x, c3_y);
}

static void c3_isBuiltInNumeric(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_scalexp_compatible(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_eml_div(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
  real_T c3_y)
{
  return c3_div(chartInstance, c3_x, c3_y);
}

static real_T c3_div(SFc3_myrocketInstanceStruct *chartInstance, real_T c3_x,
                     real_T c3_y)
{
  (void)chartInstance;
  return c3_x / c3_y;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_emlrt_marshallOut(SFc3_myrocketInstanceStruct
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
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance, *(real_T
    *)c3_inData), false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
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

static real_T c3_b_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d7;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d7, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d7;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  *(real_T *)c3_outData = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const boolean_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_b_emlrt_marshallOut(chartInstance,
    *(boolean_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_y;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  *(boolean_T *)c3_outData = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_myrocket_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
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
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_c_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
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
}

static const mxArray *c3_c_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_d_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_e_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const int32_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_e_emlrt_marshallOut(chartInstance,
    *(int32_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_sfEvent, const char_T *c3_identifier)
{
  int32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  return c3_y;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c3_outData = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const uint8_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_f_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c3_inData), false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_Antriebslos, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Antriebslos),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Antriebslos);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
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

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  SFc3_myrocketInstanceStruct *chartInstance;
  chartInstance = (SFc3_myrocketInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c3_outData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_mxArrayInData), c3_varName);
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance)
{
  const mxArray *c3_y;
  int32_T c3_i1;
  boolean_T c3_bv0[18];
  c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(15, 1), false);
  sf_mex_setcell(c3_y, 0, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_m1_out));
  sf_mex_setcell(c3_y, 1, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_m2_out));
  sf_mex_setcell(c3_y, 2, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v1_out));
  sf_mex_setcell(c3_y, 3, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v2_out));
  sf_mex_setcell(c3_y, 4, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x1_out));
  sf_mex_setcell(c3_y, 5, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x2_out));
  sf_mex_setcell(c3_y, 6, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_m1));
  sf_mex_setcell(c3_y, 7, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_m2));
  sf_mex_setcell(c3_y, 8, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v1));
  sf_mex_setcell(c3_y, 9, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_v2));
  sf_mex_setcell(c3_y, 10, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x1));
  sf_mex_setcell(c3_y, 11, c3_emlrt_marshallOut(chartInstance,
    *chartInstance->c3_x2));
  sf_mex_setcell(c3_y, 12, c3_f_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_active_c3_myrocket));
  sf_mex_setcell(c3_y, 13, c3_f_emlrt_marshallOut(chartInstance,
    chartInstance->c3_is_c3_myrocket));
  for (c3_i1 = 0; c3_i1 < 18; c3_i1++) {
    c3_bv0[c3_i1] = chartInstance->c3_dataWrittenToVector[c3_i1];
  }

  sf_mex_setcell(c3_y, 14, c3_h_emlrt_marshallOut(chartInstance, c3_bv0));
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallOut(SFc3_myrocketInstanceStruct
  *chartInstance, const boolean_T c3_u[18])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 18), false);
  return c3_y;
}

static void c3_i_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u)
{
  boolean_T c3_bv1[18];
  int32_T c3_i2;
  *chartInstance->c3_m1_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "m1_out");
  *chartInstance->c3_m2_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "m2_out");
  *chartInstance->c3_v1_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "v1_out");
  *chartInstance->c3_v2_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "v2_out");
  *chartInstance->c3_x1_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "x1_out");
  *chartInstance->c3_x2_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "x2_out");
  *chartInstance->c3_m1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "m1");
  *chartInstance->c3_m2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "m2");
  *chartInstance->c3_v1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "v1");
  *chartInstance->c3_v2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "v2");
  *chartInstance->c3_x1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "x1");
  *chartInstance->c3_x2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "x2");
  chartInstance->c3_is_active_c3_myrocket = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 12)), "is_active_c3_myrocket");
  chartInstance->c3_is_c3_myrocket = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 13)), "is_c3_myrocket");
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
                        "dataWrittenToVector", c3_bv1);
  for (c3_i2 = 0; c3_i2 < 18; c3_i2++) {
    chartInstance->c3_dataWrittenToVector[c3_i2] = c3_bv1[c3_i2];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 15)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
}

static void c3_j_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[18])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_k_emlrt_marshallIn(SFc3_myrocketInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[18])
{
  boolean_T c3_bv2[18];
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv2, 1, 11, 0U, 1, 0U, 1, 18);
  for (c3_i3 = 0; c3_i3 < 18; c3_i3++) {
    c3_y[c3_i3] = c3_bv2[c3_i3];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_l_emlrt_marshallIn(SFc3_myrocketInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_m_emlrt_marshallIn(SFc3_myrocketInstanceStruct
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

static void c3_updateDataWrittenToVector(SFc3_myrocketInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  chartInstance->c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c3_vectorIndex, 0, 17, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_myrocketInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber, uint32_T
  c3_ssIdOfSourceObject, int32_T c3_offsetInSourceObject, int32_T
  c3_lengthInSourceObject)
{
  (void)c3_ssIdOfSourceObject;
  (void)c3_offsetInSourceObject;
  (void)c3_lengthInSourceObject;
  if (!chartInstance->c3_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c3_vectorIndex, 0, 17, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c3_dataNumber);
  }
}

static void init_dsm_address_info(SFc3_myrocketInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_myrocketInstanceStruct *chartInstance)
{
  chartInstance->c3_x1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_x2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_v1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_v2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_x1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    0);
  chartInstance->c3_x2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    1);
  chartInstance->c3_v1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    2);
  chartInstance->c3_v2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    3);
  chartInstance->c3_m1 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    4);
  chartInstance->c3_m2 = (real_T *)(ssGetContStates_wrapper(chartInstance->S) +
    5);
  chartInstance->c3_m1_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_m2_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
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

void sf_c3_myrocket_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1911095437U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1176178766U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3579252955U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1688483198U);
}

mxArray* sf_c3_myrocket_get_post_codegen_info(void);
mxArray *sf_c3_myrocket_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("088dqMS8HfELWOnDNvnx3C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_myrocket_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_myrocket_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_myrocket_jit_fallback_info(void)
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

mxArray *sf_c3_myrocket_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_myrocket_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_myrocket(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[47],T\"m1_out\",},{M[1],M[48],T\"m2_out\",},{M[1],M[16],T\"v1_out\",},{M[1],M[18],T\"v2_out\",},{M[1],M[12],T\"x1_out\",},{M[1],M[17],T\"x2_out\",},{M[5],M[33],T\"m1\",},{M[5],M[34],T\"m2\",},{M[5],M[21],T\"v1\",},{M[5],M[22],T\"v2\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[5],M[19],T\"x1\",},{M[5],M[20],T\"x2\",},{M[8],M[0],T\"is_active_c3_myrocket\",},{M[9],M[0],T\"is_c3_myrocket\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_myrocket_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_myrocketInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_myrocketInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _myrocketMachineNumber_,
           3,
           7,
           3,
           0,
           28,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_myrocketMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_myrocketMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _myrocketMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"x1_out");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x2_out");
          _SFD_SET_DATA_PROPS(2,2,0,1,"v1_out");
          _SFD_SET_DATA_PROPS(3,2,0,1,"v2_out");
          _SFD_SET_DATA_PROPS(4,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(5,0,0,0,"x2");
          _SFD_SET_DATA_PROPS(6,0,0,0,"v1");
          _SFD_SET_DATA_PROPS(7,0,0,0,"v2");
          _SFD_SET_DATA_PROPS(8,7,0,0,"rE");
          _SFD_SET_DATA_PROPS(9,7,0,0,"mE");
          _SFD_SET_DATA_PROPS(10,7,0,0,"G");
          _SFD_SET_DATA_PROPS(11,10,0,0,"m1_leer");
          _SFD_SET_DATA_PROPS(12,10,0,0,"m2_leer");
          _SFD_SET_DATA_PROPS(13,10,0,0,"St1_Treibstoff");
          _SFD_SET_DATA_PROPS(14,10,0,0,"St2_Treibstoff");
          _SFD_SET_DATA_PROPS(15,10,0,0,"Durchsatz_1");
          _SFD_SET_DATA_PROPS(16,10,0,0,"Durchsatz_2");
          _SFD_SET_DATA_PROPS(17,10,0,0,"SchubProDurchsatz");
          _SFD_SET_DATA_PROPS(18,0,0,0,"m1");
          _SFD_SET_DATA_PROPS(19,0,0,0,"m2");
          _SFD_SET_DATA_PROPS(20,2,0,1,"m1_out");
          _SFD_SET_DATA_PROPS(21,2,0,1,"m2_out");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,9,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_SET_DATA_PROPS(26,9,0,0,"");
          _SFD_SET_DATA_PROPS(27,9,0,0,"");
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,3);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"Acc3",0,-1,150);
        _SFD_CV_INIT_EML(6,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"init",0,-1,111);
        _SFD_CV_INIT_EML(1,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"Acc2",0,-1,212);
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"Acc1",0,-1,188);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,14,1,14);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,14,-1,3);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,14,1,14);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,14,-1,3);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_x1_out);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_x2_out);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_v1_out);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_v2_out);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_x1);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_x2);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_v1);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_v2);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_rE);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_mE);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_G);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_m1_leer);
        _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_m2_leer);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_St1_Treibstoff);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c3_St2_Treibstoff);
        _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c3_Durchsatz_1);
        _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c3_Durchsatz_2);
        _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c3_SchubProDurchsatz);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c3_m1);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c3_m2);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c3_m1_out);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c3_m2_out);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _myrocketMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "b1YyNdjT1dcuK5j0bHw3oF";
}

static void sf_opaque_initialize_c3_myrocket(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_myrocketInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
  initialize_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_myrocket(void *chartInstanceVar)
{
  enable_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_myrocket(void *chartInstanceVar)
{
  disable_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c3_myrocket(void *chartInstanceVar)
{
  zeroCrossings_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_outputs_c3_myrocket(void *chartInstanceVar)
{
  outputs_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_derivatives_c3_myrocket(void *chartInstanceVar)
{
  derivatives_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_myrocket(void *chartInstanceVar)
{
  sf_gateway_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_myrocket(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_myrocket((SFc3_myrocketInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_myrocket(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_myrocket((SFc3_myrocketInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_myrocket(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_myrocketInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_myrocket_optimization_info();
    }

    finalize_c3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_myrocket((SFc3_myrocketInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_myrocket(SimStruct *S)
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
    initialize_params_c3_myrocket((SFc3_myrocketInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_myrocket(SimStruct *S)
{
  /* Actual parameters from chart:
     Durchsatz_1 Durchsatz_2 SchubProDurchsatz St1_Treibstoff St2_Treibstoff m1_leer m2_leer
   */
  const char_T *rtParamNames[] = { "Durchsatz_1", "Durchsatz_2",
    "SchubProDurchsatz", "St1_Treibstoff", "St2_Treibstoff", "m1_leer",
    "m2_leer" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Durchsatz_1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Durchsatz_2*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for SchubProDurchsatz*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for St1_Treibstoff*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for St2_Treibstoff*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for m1_leer*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for m2_leer*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_myrocket_optimization_info();
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
        infoStruct,3,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2836011741U));
  ssSetChecksum1(S,(4087671518U));
  ssSetChecksum2(S,(79527079U));
  ssSetChecksum3(S,(3417095993U));
  ssSetNumContStates(S,6);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_myrocket(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_myrocket(SimStruct *S)
{
  SFc3_myrocketInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_myrocketInstanceStruct *)utMalloc(sizeof
    (SFc3_myrocketInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_myrocketInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_myrocket;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_myrocket;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_myrocket;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_myrocket;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_myrocket;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_myrocket;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_myrocket;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_myrocket;
  chartInstance->chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c3_myrocket;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c3_myrocket;
  chartInstance->chartInfo.derivatives = sf_opaque_derivatives_c3_myrocket;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_myrocket;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_myrocket;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_myrocket;
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

void c3_myrocket_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_myrocket(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_myrocket(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_myrocket(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_myrocket_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
