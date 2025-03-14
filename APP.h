/*
 * File: APP.h
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

#ifndef RTW_HEADER_APP_h_
#define RTW_HEADER_APP_h_
#ifndef APP_COMMON_INCLUDES_
#define APP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* APP_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T APP_vSensor1;                 /* '<Root>/APP_vSensor1' */
  real_T APP_vSensor2;                 /* '<Root>/APP_vSensor2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T APP_bSensor1Failure;       /* '<Root>/APP_bSensor1Failure' */
  boolean_T APP_bSensor2Failure;       /* '<Root>/APP_bSensor2Failure' */
  boolean_T APP_bCohFailure;           /* '<Root>/APP_bCohFailure' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void APP_initialize(void);
extern void APP_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Clock' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Output' : Unused code path elimination
 * Block '<S2>/Product' : Unused code path elimination
 * Block '<S2>/Step' : Unused code path elimination
 * Block '<S2>/Sum' : Unused code path elimination
 * Block '<S3>/Clock' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Output' : Unused code path elimination
 * Block '<S3>/Product' : Unused code path elimination
 * Block '<S3>/Step' : Unused code path elimination
 * Block '<S3>/Sum' : Unused code path elimination
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
 * '<Root>' : 'APP'
 * '<S1>'   : 'APP/APP'
 * '<S2>'   : 'APP/Ramp'
 * '<S3>'   : 'APP/Ramp1'
 */
#endif                                 /* RTW_HEADER_APP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
