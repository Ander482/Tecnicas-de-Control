/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_q_Control_PI.h
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

#ifndef v2_q_Control_PI_h_
#define v2_q_Control_PI_h_
#ifndef v2_q_Control_PI_COMMON_INCLUDES_
#define v2_q_Control_PI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "ext_mode.h"
#endif                                 /* v2_q_Control_PI_COMMON_INCLUDES_ */

#include "v2_q_Control_PI_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T Velocidadrpms;                /* '<Root>/Product1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T TmpSignalConversionAtTAQSigLo_e[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T ProportionalGain;             /* '<S42>/Proportional Gain' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T IntegralGain;                 /* '<S34>/Integral Gain' */
  real_T grados;                       /* '<Root>/Product' */
} B_v2_q_Control_PI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_e;/* '<Root>/Encoder' */
  codertarget_arduinobase_int_a_T obj_o;/* '<Root>/PWM' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_v2_q_Control_PI_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
} X_v2_q_Control_PI_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
} XDot_v2_q_Control_PI_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S37>/Integrator' */
} XDis_v2_q_Control_PI_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_v2_q_Control_PI_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PPRxCreductorax4_Value;       /* Expression: 1408
                                        * Referenced by: '<Root>/PPRxCreductorax4'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T u0rpm360_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/60 (rpm) , 360(°)'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/100
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant4_Value;              /* Expression: 360
                                        * Referenced by: '<Root>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_v2_q_Control_PI_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_v2_q_Control_PI_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_v2_q_Control_PI_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_v2_q_Control_PI_T v2_q_Control_PI_P;

/* Block signals (default storage) */
extern B_v2_q_Control_PI_T v2_q_Control_PI_B;

/* Continuous states (default storage) */
extern X_v2_q_Control_PI_T v2_q_Control_PI_X;

/* Disabled states (default storage) */
extern XDis_v2_q_Control_PI_T v2_q_Control_PI_XDis;

/* Block states (default storage) */
extern DW_v2_q_Control_PI_T v2_q_Control_PI_DW;

/* Model entry point functions */
extern void v2_q_Control_PI_initialize(void);
extern void v2_q_Control_PI_step(void);
extern void v2_q_Control_PI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_v2_q_Control_PI_T *const v2_q_Control_PI_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'v2_q_Control_PI'
 * '<S1>'   : 'v2_q_Control_PI/Discrete Derivative'
 * '<S2>'   : 'v2_q_Control_PI/PID Controller'
 * '<S3>'   : 'v2_q_Control_PI/PID Controller/Anti-windup'
 * '<S4>'   : 'v2_q_Control_PI/PID Controller/D Gain'
 * '<S5>'   : 'v2_q_Control_PI/PID Controller/External Derivative'
 * '<S6>'   : 'v2_q_Control_PI/PID Controller/Filter'
 * '<S7>'   : 'v2_q_Control_PI/PID Controller/Filter ICs'
 * '<S8>'   : 'v2_q_Control_PI/PID Controller/I Gain'
 * '<S9>'   : 'v2_q_Control_PI/PID Controller/Ideal P Gain'
 * '<S10>'  : 'v2_q_Control_PI/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'v2_q_Control_PI/PID Controller/Integrator'
 * '<S12>'  : 'v2_q_Control_PI/PID Controller/Integrator ICs'
 * '<S13>'  : 'v2_q_Control_PI/PID Controller/N Copy'
 * '<S14>'  : 'v2_q_Control_PI/PID Controller/N Gain'
 * '<S15>'  : 'v2_q_Control_PI/PID Controller/P Copy'
 * '<S16>'  : 'v2_q_Control_PI/PID Controller/Parallel P Gain'
 * '<S17>'  : 'v2_q_Control_PI/PID Controller/Reset Signal'
 * '<S18>'  : 'v2_q_Control_PI/PID Controller/Saturation'
 * '<S19>'  : 'v2_q_Control_PI/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'v2_q_Control_PI/PID Controller/Sum'
 * '<S21>'  : 'v2_q_Control_PI/PID Controller/Sum Fdbk'
 * '<S22>'  : 'v2_q_Control_PI/PID Controller/Tracking Mode'
 * '<S23>'  : 'v2_q_Control_PI/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'v2_q_Control_PI/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'v2_q_Control_PI/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'v2_q_Control_PI/PID Controller/postSat Signal'
 * '<S27>'  : 'v2_q_Control_PI/PID Controller/preInt Signal'
 * '<S28>'  : 'v2_q_Control_PI/PID Controller/preSat Signal'
 * '<S29>'  : 'v2_q_Control_PI/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'v2_q_Control_PI/PID Controller/D Gain/Disabled'
 * '<S31>'  : 'v2_q_Control_PI/PID Controller/External Derivative/Disabled'
 * '<S32>'  : 'v2_q_Control_PI/PID Controller/Filter/Disabled'
 * '<S33>'  : 'v2_q_Control_PI/PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'v2_q_Control_PI/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'v2_q_Control_PI/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'v2_q_Control_PI/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'v2_q_Control_PI/PID Controller/Integrator/Continuous'
 * '<S38>'  : 'v2_q_Control_PI/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'v2_q_Control_PI/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'v2_q_Control_PI/PID Controller/N Gain/Disabled'
 * '<S41>'  : 'v2_q_Control_PI/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'v2_q_Control_PI/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'v2_q_Control_PI/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'v2_q_Control_PI/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'v2_q_Control_PI/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'v2_q_Control_PI/PID Controller/Sum/Sum_PI'
 * '<S47>'  : 'v2_q_Control_PI/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'v2_q_Control_PI/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'v2_q_Control_PI/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'v2_q_Control_PI/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'v2_q_Control_PI/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'v2_q_Control_PI/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'v2_q_Control_PI/PID Controller/preInt Signal/Internal PreInt'
 * '<S54>'  : 'v2_q_Control_PI/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* v2_q_Control_PI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
