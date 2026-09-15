/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_q_Control_PI_data.c
 *
 * Code generated for Simulink model 'v2_q_Control_PI'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Sep 12 13:00:31 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "v2_q_Control_PI.h"

/* Block parameters (default storage) */
P_v2_q_Control_PI_T v2_q_Control_PI_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  37.5967315261707,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  1.16905686651183,

  /* Expression: 60
   * Referenced by: '<Root>/Constant1'
   */
  60.0,

  /* Expression: 1408
   * Referenced by: '<Root>/PPRxCreductorax4'
   */
  1408.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  100.0,

  /* Expression: 60
   * Referenced by: '<Root>/60 (rpm) , 360(°)'
   */
  60.0,

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
  2.55,

  /* Expression: 360
   * Referenced by: '<Root>/Constant4'
   */
  360.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
