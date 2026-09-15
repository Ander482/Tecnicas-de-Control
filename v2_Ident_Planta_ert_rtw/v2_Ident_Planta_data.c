/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_Ident_Planta_data.c
 *
 * Code generated for Simulink model 'v2_Ident_Planta'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Sat Sep 12 12:55:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "v2_Ident_Planta.h"

/* Block parameters (default storage) */
P_v2_Ident_Planta_T v2_Ident_Planta_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: 75
   * Referenced by: '<Root>/PWM (0-100)'
   */
  75.0,

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

  /* Expression: 360
   * Referenced by: '<Root>/Constant4'
   */
  360.0,

  /* Expression: 255/100
   * Referenced by: '<Root>/Gain'
   */
  2.55,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
