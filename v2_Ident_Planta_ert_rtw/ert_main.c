/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "v2_Ident_Planta.h"
#include "v2_Ident_Planta_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "ext_mode.h"                  /* External mode header file */
#include "MW_ArduinoHWInit.h"
#include "mw_freertos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
SemaphoreHandle_t stopSem;
SemaphoreHandle_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(v2_Ident_Planta_M) == (NULL));
  while (runModel) {
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)0;
    extmodeErrorCode_T extmodeError = EXTMODE_SUCCESS;
    mw_osSemaphoreWaitEver(&baserateTaskSem);

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    extmodeTime = (extmodeSimulationTime_T)
      (((v2_Ident_Planta_M->Timing.clockTick0 * 1) + 0));
    v2_Ident_Planta_step();

    /* Get model outputs here */
    extmodeError = extmodeEvent((extmodeEventId_T)(0), extmodeTime);
    if (extmodeError != EXTMODE_SUCCESS) {
      /* Code to handle external mode event errors may be added here */
    }

    stopRequested = !((rtmGetErrorStatus(v2_Ident_Planta_M) == (NULL)));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(v2_Ident_Planta_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  v2_Ident_Planta_terminate();

  /* External Mode reset */
  extmodeReset();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int app_main(int argc, char **argv)
{
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(v2_Ident_Planta_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T**)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  /* Initialize model */
  v2_Ident_Planta_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(v2_Ident_Planta_M->extModeInfo,
    (extmodeSimulationTime_T *)rteiGetPtrTFinalTicks
    (v2_Ident_Planta_M->extModeInfo));
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(v2_Ident_Planta_M, true);
    }
  }

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.01, 0);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSemaphoreDelete(&timerTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
