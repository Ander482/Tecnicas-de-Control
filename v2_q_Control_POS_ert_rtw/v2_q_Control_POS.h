/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_q_Control_POS.h
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

#ifndef v2_q_Control_POS_h_
#define v2_q_Control_POS_h_
#ifndef v2_q_Control_POS_COMMON_INCLUDES_
#define v2_q_Control_POS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "ext_mode.h"
#endif                                 /* v2_q_Control_POS_COMMON_INCLUDES_ */

#include "v2_q_Control_POS_types.h"
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
  real_T grados;                       /* '<Root>/Product' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Velocidad;                    /* '<Root>/Product1' */
  real_T TmpSignalConversionAtTAQSigLo_i[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T IntegralGain;                 /* '<S35>/Integral Gain' */
} B_v2_q_Control_POS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_e;/* '<Root>/Encoder' */
  codertarget_arduinobase_int_k_T obj_o;/* '<Root>/PWM' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_v2_q_Control_POS_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
} X_v2_q_Control_POS_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
} XDot_v2_q_Control_POS_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S38>/Integrator' */
} XDis_v2_q_Control_POS_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_v2_q_Control_POS_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S95>/Proportional Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 180
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PPRxCreductorax4_Value;       /* Expression: 1408
                                        * Referenced by: '<Root>/PPRxCreductorax4'
                                        */
  real_T Constant4_Value;              /* Expression: 360
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 50
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -50
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T u0rpm360_Value;               /* Expression: 360
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
};

/* Real-time Model Data Structure */
struct tag_RTM_v2_q_Control_POS_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_v2_q_Control_POS_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_v2_q_Control_POS_T *contStateDisabled;
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
extern P_v2_q_Control_POS_T v2_q_Control_POS_P;

/* Block signals (default storage) */
extern B_v2_q_Control_POS_T v2_q_Control_POS_B;

/* Continuous states (default storage) */
extern X_v2_q_Control_POS_T v2_q_Control_POS_X;

/* Disabled states (default storage) */
extern XDis_v2_q_Control_POS_T v2_q_Control_POS_XDis;

/* Block states (default storage) */
extern DW_v2_q_Control_POS_T v2_q_Control_POS_DW;

/* Model entry point functions */
extern void v2_q_Control_POS_initialize(void);
extern void v2_q_Control_POS_step(void);
extern void v2_q_Control_POS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_v2_q_Control_POS_T *const v2_q_Control_POS_M;
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
 * '<Root>' : 'v2_q_Control_POS'
 * '<S1>'   : 'v2_q_Control_POS/Discrete Derivative'
 * '<S2>'   : 'v2_q_Control_POS/PID Controller'
 * '<S3>'   : 'v2_q_Control_POS/PID Controller1'
 * '<S4>'   : 'v2_q_Control_POS/PID Controller/Anti-windup'
 * '<S5>'   : 'v2_q_Control_POS/PID Controller/D Gain'
 * '<S6>'   : 'v2_q_Control_POS/PID Controller/External Derivative'
 * '<S7>'   : 'v2_q_Control_POS/PID Controller/Filter'
 * '<S8>'   : 'v2_q_Control_POS/PID Controller/Filter ICs'
 * '<S9>'   : 'v2_q_Control_POS/PID Controller/I Gain'
 * '<S10>'  : 'v2_q_Control_POS/PID Controller/Ideal P Gain'
 * '<S11>'  : 'v2_q_Control_POS/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'v2_q_Control_POS/PID Controller/Integrator'
 * '<S13>'  : 'v2_q_Control_POS/PID Controller/Integrator ICs'
 * '<S14>'  : 'v2_q_Control_POS/PID Controller/N Copy'
 * '<S15>'  : 'v2_q_Control_POS/PID Controller/N Gain'
 * '<S16>'  : 'v2_q_Control_POS/PID Controller/P Copy'
 * '<S17>'  : 'v2_q_Control_POS/PID Controller/Parallel P Gain'
 * '<S18>'  : 'v2_q_Control_POS/PID Controller/Reset Signal'
 * '<S19>'  : 'v2_q_Control_POS/PID Controller/Saturation'
 * '<S20>'  : 'v2_q_Control_POS/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'v2_q_Control_POS/PID Controller/Sum'
 * '<S22>'  : 'v2_q_Control_POS/PID Controller/Sum Fdbk'
 * '<S23>'  : 'v2_q_Control_POS/PID Controller/Tracking Mode'
 * '<S24>'  : 'v2_q_Control_POS/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'v2_q_Control_POS/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'v2_q_Control_POS/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'v2_q_Control_POS/PID Controller/postSat Signal'
 * '<S28>'  : 'v2_q_Control_POS/PID Controller/preInt Signal'
 * '<S29>'  : 'v2_q_Control_POS/PID Controller/preSat Signal'
 * '<S30>'  : 'v2_q_Control_POS/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'v2_q_Control_POS/PID Controller/D Gain/Disabled'
 * '<S32>'  : 'v2_q_Control_POS/PID Controller/External Derivative/Disabled'
 * '<S33>'  : 'v2_q_Control_POS/PID Controller/Filter/Disabled'
 * '<S34>'  : 'v2_q_Control_POS/PID Controller/Filter ICs/Disabled'
 * '<S35>'  : 'v2_q_Control_POS/PID Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'v2_q_Control_POS/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'v2_q_Control_POS/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'v2_q_Control_POS/PID Controller/Integrator/Continuous'
 * '<S39>'  : 'v2_q_Control_POS/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'v2_q_Control_POS/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S41>'  : 'v2_q_Control_POS/PID Controller/N Gain/Disabled'
 * '<S42>'  : 'v2_q_Control_POS/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'v2_q_Control_POS/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'v2_q_Control_POS/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'v2_q_Control_POS/PID Controller/Saturation/Passthrough'
 * '<S46>'  : 'v2_q_Control_POS/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'v2_q_Control_POS/PID Controller/Sum/Sum_PI'
 * '<S48>'  : 'v2_q_Control_POS/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'v2_q_Control_POS/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'v2_q_Control_POS/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'v2_q_Control_POS/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'v2_q_Control_POS/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'v2_q_Control_POS/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'v2_q_Control_POS/PID Controller/preInt Signal/Internal PreInt'
 * '<S55>'  : 'v2_q_Control_POS/PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'v2_q_Control_POS/PID Controller1/Anti-windup'
 * '<S57>'  : 'v2_q_Control_POS/PID Controller1/D Gain'
 * '<S58>'  : 'v2_q_Control_POS/PID Controller1/External Derivative'
 * '<S59>'  : 'v2_q_Control_POS/PID Controller1/Filter'
 * '<S60>'  : 'v2_q_Control_POS/PID Controller1/Filter ICs'
 * '<S61>'  : 'v2_q_Control_POS/PID Controller1/I Gain'
 * '<S62>'  : 'v2_q_Control_POS/PID Controller1/Ideal P Gain'
 * '<S63>'  : 'v2_q_Control_POS/PID Controller1/Ideal P Gain Fdbk'
 * '<S64>'  : 'v2_q_Control_POS/PID Controller1/Integrator'
 * '<S65>'  : 'v2_q_Control_POS/PID Controller1/Integrator ICs'
 * '<S66>'  : 'v2_q_Control_POS/PID Controller1/N Copy'
 * '<S67>'  : 'v2_q_Control_POS/PID Controller1/N Gain'
 * '<S68>'  : 'v2_q_Control_POS/PID Controller1/P Copy'
 * '<S69>'  : 'v2_q_Control_POS/PID Controller1/Parallel P Gain'
 * '<S70>'  : 'v2_q_Control_POS/PID Controller1/Reset Signal'
 * '<S71>'  : 'v2_q_Control_POS/PID Controller1/Saturation'
 * '<S72>'  : 'v2_q_Control_POS/PID Controller1/Saturation Fdbk'
 * '<S73>'  : 'v2_q_Control_POS/PID Controller1/Sum'
 * '<S74>'  : 'v2_q_Control_POS/PID Controller1/Sum Fdbk'
 * '<S75>'  : 'v2_q_Control_POS/PID Controller1/Tracking Mode'
 * '<S76>'  : 'v2_q_Control_POS/PID Controller1/Tracking Mode Sum'
 * '<S77>'  : 'v2_q_Control_POS/PID Controller1/Tsamp - Integral'
 * '<S78>'  : 'v2_q_Control_POS/PID Controller1/Tsamp - Ngain'
 * '<S79>'  : 'v2_q_Control_POS/PID Controller1/postSat Signal'
 * '<S80>'  : 'v2_q_Control_POS/PID Controller1/preInt Signal'
 * '<S81>'  : 'v2_q_Control_POS/PID Controller1/preSat Signal'
 * '<S82>'  : 'v2_q_Control_POS/PID Controller1/Anti-windup/Disabled'
 * '<S83>'  : 'v2_q_Control_POS/PID Controller1/D Gain/Disabled'
 * '<S84>'  : 'v2_q_Control_POS/PID Controller1/External Derivative/Disabled'
 * '<S85>'  : 'v2_q_Control_POS/PID Controller1/Filter/Disabled'
 * '<S86>'  : 'v2_q_Control_POS/PID Controller1/Filter ICs/Disabled'
 * '<S87>'  : 'v2_q_Control_POS/PID Controller1/I Gain/Disabled'
 * '<S88>'  : 'v2_q_Control_POS/PID Controller1/Ideal P Gain/Passthrough'
 * '<S89>'  : 'v2_q_Control_POS/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'v2_q_Control_POS/PID Controller1/Integrator/Disabled'
 * '<S91>'  : 'v2_q_Control_POS/PID Controller1/Integrator ICs/Disabled'
 * '<S92>'  : 'v2_q_Control_POS/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S93>'  : 'v2_q_Control_POS/PID Controller1/N Gain/Disabled'
 * '<S94>'  : 'v2_q_Control_POS/PID Controller1/P Copy/Disabled'
 * '<S95>'  : 'v2_q_Control_POS/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'v2_q_Control_POS/PID Controller1/Reset Signal/Disabled'
 * '<S97>'  : 'v2_q_Control_POS/PID Controller1/Saturation/Passthrough'
 * '<S98>'  : 'v2_q_Control_POS/PID Controller1/Saturation Fdbk/Disabled'
 * '<S99>'  : 'v2_q_Control_POS/PID Controller1/Sum/Passthrough_P'
 * '<S100>' : 'v2_q_Control_POS/PID Controller1/Sum Fdbk/Disabled'
 * '<S101>' : 'v2_q_Control_POS/PID Controller1/Tracking Mode/Disabled'
 * '<S102>' : 'v2_q_Control_POS/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'v2_q_Control_POS/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S104>' : 'v2_q_Control_POS/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'v2_q_Control_POS/PID Controller1/postSat Signal/Forward_Path'
 * '<S106>' : 'v2_q_Control_POS/PID Controller1/preInt Signal/Internal PreInt'
 * '<S107>' : 'v2_q_Control_POS/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* v2_q_Control_POS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
