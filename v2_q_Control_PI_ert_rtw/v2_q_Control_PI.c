/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_q_Control_PI.c
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
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include <math.h>
#include "rtwtypes.h"
#include "v2_q_Control_PI_private.h"

/* Block signals (default storage) */
B_v2_q_Control_PI_T v2_q_Control_PI_B;

/* Continuous states */
X_v2_q_Control_PI_T v2_q_Control_PI_X;

/* Disabled State Vector */
XDis_v2_q_Control_PI_T v2_q_Control_PI_XDis;

/* Block states (default storage) */
DW_v2_q_Control_PI_T v2_q_Control_PI_DW;

/* Real-time model */
static RT_MODEL_v2_q_Control_PI_T v2_q_Control_PI_M_;
RT_MODEL_v2_q_Control_PI_T *const v2_q_Control_PI_M = &v2_q_Control_PI_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  v2_q_Control_PI_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  v2_q_Control_PI_step();
  v2_q_Control_PI_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  v2_q_Control_PI_step();
  v2_q_Control_PI_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void v2_q_Control_PI_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T Divide;
  real_T rtb_Sum;
  int32_T rtb_Encoder_0;
  boolean_T rtb_LessThan;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(v2_q_Control_PI_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&v2_q_Control_PI_M->solverInfo,
                          ((v2_q_Control_PI_M->Timing.clockTick0+1)*
      v2_q_Control_PI_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(v2_q_Control_PI_M)) {
    v2_q_Control_PI_M->Timing.t[0] = rtsiGetT(&v2_q_Control_PI_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(v2_q_Control_PI_M);
  if (tmp) {
    /* Constant: '<Root>/Constant1' */
    v2_q_Control_PI_B.Constant1 = v2_q_Control_PI_P.Constant1_Value;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  if (v2_q_Control_PI_DW.obj_e.TunablePropsChanged) {
    v2_q_Control_PI_DW.obj_e.TunablePropsChanged = false;
  }

  MW_EncoderRead(v2_q_Control_PI_DW.obj_e.Index, &rtb_Encoder_0);

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/PPRxCreductorax4'
   *  MATLABSystem: '<Root>/Encoder'
   */
  Divide = (real_T)rtb_Encoder_0 / v2_q_Control_PI_P.PPRxCreductorax4_Value;
  if (tmp) {
    /* SampleTimeMath: '<S1>/TSamp'
     *
     * About '<S1>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *   */
    rtb_TSamp = Divide * v2_q_Control_PI_P.TSamp_WtEt;

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
    v2_q_Control_PI_B.Velocidadrpms = (rtb_TSamp - v2_q_Control_PI_DW.UD_DSTATE)
      * v2_q_Control_PI_P.u0rpm360_Value;

    /* SignalConversion generated from: '<Root>/Mux' */
    v2_q_Control_PI_B.TmpSignalConversionAtTAQSigLogg[0] =
      v2_q_Control_PI_B.Constant1;
    v2_q_Control_PI_B.TmpSignalConversionAtTAQSigLogg[1] =
      v2_q_Control_PI_B.Velocidadrpms;

    /* SignalConversion generated from: '<Root>/Mux1' */
    v2_q_Control_PI_B.TmpSignalConversionAtTAQSigLo_e[0] =
      v2_q_Control_PI_B.Velocidadrpms;
    v2_q_Control_PI_B.TmpSignalConversionAtTAQSigLo_e[1] =
      v2_q_Control_PI_B.Velocidadrpms;

    /* Sum: '<Root>/Sum' */
    rtb_Sum = v2_q_Control_PI_B.Constant1 - v2_q_Control_PI_B.Velocidadrpms;

    /* Gain: '<S42>/Proportional Gain' */
    v2_q_Control_PI_B.ProportionalGain = v2_q_Control_PI_P.PIDController_P *
      rtb_Sum;
  }

  /* Sum: '<S46>/Sum' incorporates:
   *  Integrator: '<S37>/Integrator'
   */
  v2_q_Control_PI_B.Saturation = v2_q_Control_PI_B.ProportionalGain +
    v2_q_Control_PI_X.Integrator_CSTATE;

  /* Saturate: '<Root>/Saturation' */
  if (v2_q_Control_PI_B.Saturation > v2_q_Control_PI_P.Saturation_UpperSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    v2_q_Control_PI_B.Saturation = v2_q_Control_PI_P.Saturation_UpperSat;
  } else if (v2_q_Control_PI_B.Saturation <
             v2_q_Control_PI_P.Saturation_LowerSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    v2_q_Control_PI_B.Saturation = v2_q_Control_PI_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* RelationalOperator: '<Root>/Less Than' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_LessThan = (v2_q_Control_PI_B.Saturation <
                  v2_q_Control_PI_P.Constant3_Value);

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(2, (uint8_T)rtb_LessThan);

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin(4, (uint8_T)!rtb_LessThan);
  if (tmp) {
  }

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Abs: '<Root>/Abs'
   *  Gain: '<Root>/Gain'
   */
  v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
  MW_PWM_SetDutyCycle(v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, fmax
                      (fmin(v2_q_Control_PI_P.Gain_Gain * fabs
    (v2_q_Control_PI_B.Saturation), 255.0), 0.0));

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  v2_q_Control_PI_B.grados = Divide * v2_q_Control_PI_P.Constant4_Value;
  if (tmp) {
    /* Gain: '<S34>/Integral Gain' */
    v2_q_Control_PI_B.IntegralGain = v2_q_Control_PI_P.PIDController_I * rtb_Sum;
  }

  if (rtmIsMajorTimeStep(v2_q_Control_PI_M)) {
    if (rtmIsMajorTimeStep(v2_q_Control_PI_M)) {
      /* Update for UnitDelay: '<S1>/UD'
       *
       * Block description for '<S1>/UD':
       *
       *  Store in Global RAM
       */
      v2_q_Control_PI_DW.UD_DSTATE = rtb_TSamp;
    }

    if (rtmIsMajorTimeStep(v2_q_Control_PI_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((v2_q_Control_PI_M->Timing.clockTick1 * 1) + 0);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(v2_q_Control_PI_M)) {
    rt_ertODEUpdateContinuousStates(&v2_q_Control_PI_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++v2_q_Control_PI_M->Timing.clockTick0;
    v2_q_Control_PI_M->Timing.t[0] = rtsiGetSolverStopTime
      (&v2_q_Control_PI_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      v2_q_Control_PI_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void v2_q_Control_PI_derivatives(void)
{
  XDot_v2_q_Control_PI_T *_rtXdot;
  _rtXdot = ((XDot_v2_q_Control_PI_T *) v2_q_Control_PI_M->derivs);

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = v2_q_Control_PI_B.IntegralGain;
}

/* Model initialize function */
void v2_q_Control_PI_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&v2_q_Control_PI_M->solverInfo,
                          &v2_q_Control_PI_M->Timing.simTimeStep);
    rtsiSetTPtr(&v2_q_Control_PI_M->solverInfo, &rtmGetTPtr(v2_q_Control_PI_M));
    rtsiSetStepSizePtr(&v2_q_Control_PI_M->solverInfo,
                       &v2_q_Control_PI_M->Timing.stepSize0);
    rtsiSetdXPtr(&v2_q_Control_PI_M->solverInfo, &v2_q_Control_PI_M->derivs);
    rtsiSetContStatesPtr(&v2_q_Control_PI_M->solverInfo, (real_T **)
                         &v2_q_Control_PI_M->contStates);
    rtsiSetNumContStatesPtr(&v2_q_Control_PI_M->solverInfo,
      &v2_q_Control_PI_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&v2_q_Control_PI_M->solverInfo,
      &v2_q_Control_PI_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&v2_q_Control_PI_M->solverInfo,
      &v2_q_Control_PI_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&v2_q_Control_PI_M->solverInfo,
      &v2_q_Control_PI_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&v2_q_Control_PI_M->solverInfo, (boolean_T**)
      &v2_q_Control_PI_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&v2_q_Control_PI_M->solverInfo, (&rtmGetErrorStatus
      (v2_q_Control_PI_M)));
    rtsiSetRTModelPtr(&v2_q_Control_PI_M->solverInfo, v2_q_Control_PI_M);
  }

  rtsiSetSimTimeStep(&v2_q_Control_PI_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&v2_q_Control_PI_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&v2_q_Control_PI_M->solverInfo, false);
  v2_q_Control_PI_M->intgData.y = v2_q_Control_PI_M->odeY;
  v2_q_Control_PI_M->intgData.f[0] = v2_q_Control_PI_M->odeF[0];
  v2_q_Control_PI_M->intgData.f[1] = v2_q_Control_PI_M->odeF[1];
  v2_q_Control_PI_M->intgData.f[2] = v2_q_Control_PI_M->odeF[2];
  v2_q_Control_PI_M->contStates = ((X_v2_q_Control_PI_T *) &v2_q_Control_PI_X);
  v2_q_Control_PI_M->contStateDisabled = ((XDis_v2_q_Control_PI_T *)
    &v2_q_Control_PI_XDis);
  v2_q_Control_PI_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&v2_q_Control_PI_M->solverInfo, (void *)
                    &v2_q_Control_PI_M->intgData);
  rtsiSetSolverName(&v2_q_Control_PI_M->solverInfo,"ode3");
  rtmSetTPtr(v2_q_Control_PI_M, &v2_q_Control_PI_M->Timing.tArray[0]);
  rtmSetTFinal(v2_q_Control_PI_M, -1);
  v2_q_Control_PI_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  v2_q_Control_PI_M->Sizes.checksums[0] = (2675704681U);
  v2_q_Control_PI_M->Sizes.checksums[1] = (3816781048U);
  v2_q_Control_PI_M->Sizes.checksums[2] = (1321900648U);
  v2_q_Control_PI_M->Sizes.checksums[3] = (1956650070U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    v2_q_Control_PI_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(v2_q_Control_PI_M->extModeInfo,
      &v2_q_Control_PI_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(v2_q_Control_PI_M->extModeInfo,
                        v2_q_Control_PI_M->Sizes.checksums);
    rteiSetTFinalTicks(v2_q_Control_PI_M->extModeInfo, -1);
  }

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  v2_q_Control_PI_DW.UD_DSTATE =
    v2_q_Control_PI_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  v2_q_Control_PI_X.Integrator_CSTATE =
    v2_q_Control_PI_P.PIDController_InitialConditionF;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  v2_q_Control_PI_DW.obj_e.Index = 0U;
  v2_q_Control_PI_DW.obj_e.matlabCodegenIsDeleted = false;
  v2_q_Control_PI_DW.obj_e.isInitialized = 1;
  MW_EncoderSetup(19U, 25U, &v2_q_Control_PI_DW.obj_e.Index);
  v2_q_Control_PI_DW.obj_e.isSetupComplete = true;
  v2_q_Control_PI_DW.obj_e.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(v2_q_Control_PI_DW.obj_e.Index);

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  v2_q_Control_PI_DW.obj_j.matlabCodegenIsDeleted = false;
  v2_q_Control_PI_DW.obj_j.isInitialized = 1;
  digitalIOSetup(2, 1);
  v2_q_Control_PI_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  v2_q_Control_PI_DW.obj.matlabCodegenIsDeleted = false;
  v2_q_Control_PI_DW.obj.isInitialized = 1;
  digitalIOSetup(4, 1);
  v2_q_Control_PI_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  v2_q_Control_PI_DW.obj_o.matlabCodegenIsDeleted = false;
  v2_q_Control_PI_DW.obj_o.isSetupComplete = false;
  v2_q_Control_PI_DW.obj_o.isInitialized = 1;
  v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(21U, 0.0,
    0.0);
  v2_q_Control_PI_DW.obj_o.isSetupComplete = true;
}

/* Model terminate function */
void v2_q_Control_PI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!v2_q_Control_PI_DW.obj_e.matlabCodegenIsDeleted) {
    v2_q_Control_PI_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((v2_q_Control_PI_DW.obj_e.isInitialized == 1) &&
        v2_q_Control_PI_DW.obj_e.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!v2_q_Control_PI_DW.obj_j.matlabCodegenIsDeleted) {
    v2_q_Control_PI_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!v2_q_Control_PI_DW.obj.matlabCodegenIsDeleted) {
    v2_q_Control_PI_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!v2_q_Control_PI_DW.obj_o.matlabCodegenIsDeleted) {
    v2_q_Control_PI_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((v2_q_Control_PI_DW.obj_o.isInitialized == 1) &&
        v2_q_Control_PI_DW.obj_o.isSetupComplete) {
      v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
      MW_PWM_SetDutyCycle(v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(21U);
      MW_PWM_Close(v2_q_Control_PI_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
