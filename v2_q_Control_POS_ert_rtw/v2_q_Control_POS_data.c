/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_q_Control_POS_data.c
 *
 * Code generated for Simulink model 'v2_q_Control_POS'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Tue Sep 15 15:42:18 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "v2_q_Control_POS.h"

/* Block parameters (default storage) */
P_v2_q_Control_POS_T v2_q_Control_POS_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S35>/Integral Gain'
   */
  6.1811213532278,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S95>/Proportional Gain'
   */
  0.3,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  0.300796601333984,

  /* Expression: 180
   * Referenced by: '<Root>/Constant1'
   */
  180.0,

  /* Expression: 1408
   * Referenced by: '<Root>/PPRxCreductorax4'
   */
  1408.0,

  /* Expression: 360
   * Referenced by: '<Root>/Constant4'
   */
  360.0,

  /* Expression: 50
   * Referenced by: '<Root>/Saturation1'
   */
  50.0,

  /* Expression: -50
   * Referenced by: '<Root>/Saturation1'
   */
  -50.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  100.0,

  /* Expression: 360
   * Referenced by: '<Root>/60 (rpm) , 360(°)'
   */
  360.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<Root>/Saturation'
   */
  -100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 255/100
   * Referenced by: '<Root>/Gain'
   */
  2.55
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
