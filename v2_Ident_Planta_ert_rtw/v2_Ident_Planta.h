/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: v2_Ident_Planta.h
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

#ifndef v2_Ident_Planta_h_
#define v2_Ident_Planta_h_
#ifndef v2_Ident_Planta_COMMON_INCLUDES_
#define v2_Ident_Planta_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* v2_Ident_Planta_COMMON_INCLUDES_ */

#include "v2_Ident_Planta_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PWM0100;                      /* '<Root>/PWM (0-100)' */
  real_T Velocidadrpms;                /* '<Root>/Product1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T grados;                       /* '<Root>/Product' */
} B_v2_Ident_Planta_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_e;/* '<Root>/Encoder' */
  codertarget_arduinobase_int_n_T obj_o;/* '<Root>/PWM' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_v2_Ident_Planta_T;

/* Parameters (default storage) */
struct P_v2_Ident_Planta_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T PWM0100_Value;                /* Expression: 75
                                        * Referenced by: '<Root>/PWM (0-100)'
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
  real_T Constant4_Value;              /* Expression: 360
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/100
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_v2_Ident_Planta_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_v2_Ident_Planta_T v2_Ident_Planta_P;

/* Block signals (default storage) */
extern B_v2_Ident_Planta_T v2_Ident_Planta_B;

/* Block states (default storage) */
extern DW_v2_Ident_Planta_T v2_Ident_Planta_DW;

/* Model entry point functions */
extern void v2_Ident_Planta_initialize(void);
extern void v2_Ident_Planta_step(void);
extern void v2_Ident_Planta_terminate(void);

/* Real-time Model object */
extern RT_MODEL_v2_Ident_Planta_T *const v2_Ident_Planta_M;
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
 * '<Root>' : 'v2_Ident_Planta'
 * '<S1>'   : 'v2_Ident_Planta/Discrete Derivative'
 */
#endif                                 /* v2_Ident_Planta_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
