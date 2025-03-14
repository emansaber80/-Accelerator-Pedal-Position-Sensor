/*
 * File: APP.c
 *
 * Code generated for Simulink model 'APP'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Mar 14 04:03:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "APP.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void APP_h(void);

/* Output and update for atomic system: '<Root>/APP' */
static void APP_h(void)
{
  /* Outport: '<Root>/APP_bCohFailure' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Inport: '<Root>/APP_vSensor1'
   *  Inport: '<Root>/APP_vSensor2'
   *  RelationalOperator: '<S1>/NotEqual'
   *  Sum: '<S1>/Add'
   */
  rtY.APP_bCohFailure = (rtU.APP_vSensor2 + rtU.APP_vSensor1 != 5.0);

  /* Outport: '<Root>/APP_bSensor1Failure' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/APP_vSensor1'
   *  Logic: '<S1>/OR'
   *  RelationalOperator: '<S1>/GreaterThan'
   *  RelationalOperator: '<S1>/Less Than'
   */
  rtY.APP_bSensor1Failure = ((rtU.APP_vSensor1 < 0.5) || (rtU.APP_vSensor1 > 4.5));

  /* Outport: '<Root>/APP_bSensor2Failure' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/APP_vSensor2'
   *  Logic: '<S1>/OR1'
   *  RelationalOperator: '<S1>/GreaterThan1'
   *  RelationalOperator: '<S1>/Less Than1'
   */
  rtY.APP_bSensor2Failure = ((rtU.APP_vSensor2 < 0.5) || (rtU.APP_vSensor2 > 4.5));
}

/* Model step function */
void APP_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/APP' */
  APP_h();

  /* End of Outputs for SubSystem: '<Root>/APP' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void APP_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
