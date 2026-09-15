/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_Ident_Planta.c
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
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#include <math.h>
#include "v2_Ident_Planta_private.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_v2_Ident_Planta_T v2_Ident_Planta_B;

/* Block states (default storage) */
DW_v2_Ident_Planta_T v2_Ident_Planta_DW;

/* Real-time model */
static RT_MODEL_v2_Ident_Planta_T v2_Ident_Planta_M_;
RT_MODEL_v2_Ident_Planta_T *const v2_Ident_Planta_M = &v2_Ident_Planta_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void v2_Ident_Planta_step(void)
{
  real_T rtb_Divide;
  real_T rtb_TSamp;
  int32_T rtb_Encoder_0;
  uint8_T tmp;

  /* Constant: '<Root>/PWM (0-100)' */
  v2_Ident_Planta_B.PWM0100 = v2_Ident_Planta_P.PWM0100_Value;

  /* MATLABSystem: '<Root>/Encoder' */
  if (v2_Ident_Planta_DW.obj_e.TunablePropsChanged) {
    v2_Ident_Planta_DW.obj_e.TunablePropsChanged = false;
  }

  MW_EncoderRead(v2_Ident_Planta_DW.obj_e.Index, &rtb_Encoder_0);

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/PPRxCreductorax4'
   *  MATLABSystem: '<Root>/Encoder'
   */
  rtb_Divide = (real_T)rtb_Encoder_0 / v2_Ident_Planta_P.PPRxCreductorax4_Value;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Divide * v2_Ident_Planta_P.TSamp_WtEt;

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<Root>/60 (rpm) , 360(°)'
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  v2_Ident_Planta_B.Velocidadrpms = (rtb_TSamp - v2_Ident_Planta_DW.UD_DSTATE) *
    v2_Ident_Planta_P.u0rpm360_Value;

  /* SignalConversion generated from: '<Root>/Mux' */
  v2_Ident_Planta_B.TmpSignalConversionAtTAQSigLogg[0] =
    v2_Ident_Planta_B.PWM0100;
  v2_Ident_Planta_B.TmpSignalConversionAtTAQSigLogg[1] =
    v2_Ident_Planta_B.Velocidadrpms;

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  v2_Ident_Planta_B.grados = rtb_Divide * v2_Ident_Planta_P.Constant4_Value;

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Gain: '<Root>/Gain'
   */
  v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
  MW_PWM_SetDutyCycle(v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, fmax
                      (fmin(v2_Ident_Planta_P.Gain_Gain *
    v2_Ident_Planta_B.PWM0100, 255.0), 0.0));

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Divide = rt_roundd_snf(v2_Ident_Planta_P.Constant_Value);
  if (rtb_Divide < 256.0) {
    if (rtb_Divide >= 0.0) {
      tmp = (uint8_T)rtb_Divide;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_Divide = rt_roundd_snf(v2_Ident_Planta_P.Constant2_Value);
  if (rtb_Divide < 256.0) {
    if (rtb_Divide >= 0.0) {
      tmp = (uint8_T)rtb_Divide;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  v2_Ident_Planta_DW.UD_DSTATE = rtb_TSamp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  v2_Ident_Planta_M->Timing.clockTick0++;
}

/* Model initialize function */
void v2_Ident_Planta_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(v2_Ident_Planta_M, -1);

  /* External mode info */
  v2_Ident_Planta_M->Sizes.checksums[0] = (2431382384U);
  v2_Ident_Planta_M->Sizes.checksums[1] = (3981183269U);
  v2_Ident_Planta_M->Sizes.checksums[2] = (3597889642U);
  v2_Ident_Planta_M->Sizes.checksums[3] = (2655433295U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    v2_Ident_Planta_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(v2_Ident_Planta_M->extModeInfo,
      &v2_Ident_Planta_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(v2_Ident_Planta_M->extModeInfo,
                        v2_Ident_Planta_M->Sizes.checksums);
    rteiSetTFinalTicks(v2_Ident_Planta_M->extModeInfo, -1);
  }

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  v2_Ident_Planta_DW.UD_DSTATE =
    v2_Ident_Planta_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  v2_Ident_Planta_DW.obj_e.Index = 0U;
  v2_Ident_Planta_DW.obj_e.matlabCodegenIsDeleted = false;
  v2_Ident_Planta_DW.obj_e.isInitialized = 1;
  MW_EncoderSetup(19U, 25U, &v2_Ident_Planta_DW.obj_e.Index);
  v2_Ident_Planta_DW.obj_e.isSetupComplete = true;
  v2_Ident_Planta_DW.obj_e.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(v2_Ident_Planta_DW.obj_e.Index);

  /* Start for MATLABSystem: '<Root>/PWM' */
  v2_Ident_Planta_DW.obj_o.matlabCodegenIsDeleted = false;
  v2_Ident_Planta_DW.obj_o.isSetupComplete = false;
  v2_Ident_Planta_DW.obj_o.isInitialized = 1;
  v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(21U, 0.0,
    0.0);
  v2_Ident_Planta_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  v2_Ident_Planta_DW.obj_j.matlabCodegenIsDeleted = false;
  v2_Ident_Planta_DW.obj_j.isInitialized = 1;
  digitalIOSetup(2, 1);
  v2_Ident_Planta_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  v2_Ident_Planta_DW.obj.matlabCodegenIsDeleted = false;
  v2_Ident_Planta_DW.obj.isInitialized = 1;
  digitalIOSetup(4, 1);
  v2_Ident_Planta_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void v2_Ident_Planta_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!v2_Ident_Planta_DW.obj_e.matlabCodegenIsDeleted) {
    v2_Ident_Planta_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((v2_Ident_Planta_DW.obj_e.isInitialized == 1) &&
        v2_Ident_Planta_DW.obj_e.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!v2_Ident_Planta_DW.obj_o.matlabCodegenIsDeleted) {
    v2_Ident_Planta_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((v2_Ident_Planta_DW.obj_o.isInitialized == 1) &&
        v2_Ident_Planta_DW.obj_o.isSetupComplete) {
      v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
      MW_PWM_SetDutyCycle(v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
      MW_PWM_Close(v2_Ident_Planta_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!v2_Ident_Planta_DW.obj_j.matlabCodegenIsDeleted) {
    v2_Ident_Planta_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!v2_Ident_Planta_DW.obj.matlabCodegenIsDeleted) {
    v2_Ident_Planta_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
