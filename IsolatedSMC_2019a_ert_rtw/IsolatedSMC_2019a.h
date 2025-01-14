//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: IsolatedSMC_2019a.h
//
// Code generated for Simulink model 'IsolatedSMC_2019a'.
//
// Model version                  : 1.2
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Thu Dec  2 12:20:31 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_IsolatedSMC_2019a_h_
#define RTW_HEADER_IsolatedSMC_2019a_h_
#include <math.h>
#include <string.h>
#ifndef IsolatedSMC_2019a_COMMON_INCLUDES_
# define IsolatedSMC_2019a_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // IsolatedSMC_2019a_COMMON_INCLUDES_

#include "IsolatedSMC_2019a_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UD_DSTATE;                    // '<S3>/UD'
  real_T UD_DSTATE_b;                  // '<S4>/UD'
  real_T UD_DSTATE_m;                  // '<S1>/UD'
  real_T UD_DSTATE_o;                  // '<S2>/UD'
  real_T en;                           // '<S12>/MATLAB Function'
} DW_IsolatedSMC_2019a_T;

// External inputs (root inport signals with default storage)
typedef struct {
  real_T psi;                          // '<Root>/psi'
  real_T Vx;                           // '<Root>/Vx'
  real_T X_est;                        // '<Root>/X_est'
  real_T Y_est;                        // '<Root>/Y_est'
  real_T X_goal;                       // '<Root>/X_goal'
  real_T Y_goal;                       // '<Root>/Y_goal'
  real_T ox;                           // '<Root>/ox'
  real_T oy;                           // '<Root>/oy'
} ExtU_IsolatedSMC_2019a_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T Vx_cmd;                       // '<Root>/Vx_cmd'
  real_T psi_cmd;                      // '<Root>/psi_cmd'
} ExtY_IsolatedSMC_2019a_T;

// Real-time Model Data Structure
struct tag_RTM_IsolatedSMC_2019a_T {
  const char_T * volatile errorStatus;
  DW_IsolatedSMC_2019a_T *dwork;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    boolean_T stopRequestedFlag;
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void IsolatedSMC_2019a_initialize(RT_MODEL_IsolatedSMC_2019a_T *const
    IsolatedSMC_2019a_M, ExtU_IsolatedSMC_2019a_T *IsolatedSMC_2019a_U,
    ExtY_IsolatedSMC_2019a_T *IsolatedSMC_2019a_Y);
  extern void IsolatedSMC_2019a_step(RT_MODEL_IsolatedSMC_2019a_T *const
    IsolatedSMC_2019a_M, ExtU_IsolatedSMC_2019a_T *IsolatedSMC_2019a_U,
    ExtY_IsolatedSMC_2019a_T *IsolatedSMC_2019a_Y);
  extern void IsolatedSMC_2019a_terminate(RT_MODEL_IsolatedSMC_2019a_T *const
    IsolatedSMC_2019a_M);

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Data Type Duplicate' : Unused code path elimination
//  Block '<S2>/Data Type Duplicate' : Unused code path elimination
//  Block '<S3>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/Data Type Duplicate' : Unused code path elimination
//  Block '<S11>/Scope1' : Unused code path elimination
//  Block '<S11>/Scope3' : Unused code path elimination
//  Block '<S11>/Scope4' : Unused code path elimination
//  Block '<Root>/Rate Transition' : Unused code path elimination
//  Block '<Root>/Rate Transition1' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<Root>/To Workspace1' : Unused code path elimination
//  Block '<Root>/To Workspace5' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'IsolatedSMC_2019a'
//  '<S1>'   : 'IsolatedSMC_2019a/Discrete Derivative'
//  '<S2>'   : 'IsolatedSMC_2019a/Discrete Derivative1'
//  '<S3>'   : 'IsolatedSMC_2019a/Discrete Derivative2'
//  '<S4>'   : 'IsolatedSMC_2019a/Discrete Derivative3'
//  '<S5>'   : 'IsolatedSMC_2019a/GUIDANCE '
//  '<S6>'   : 'IsolatedSMC_2019a/IsNonZero'
//  '<S7>'   : 'IsolatedSMC_2019a/IsZero'
//  '<S8>'   : 'IsolatedSMC_2019a/MATLAB Function'
//  '<S9>'   : 'IsolatedSMC_2019a/MATLAB Function1'
//  '<S10>'  : 'IsolatedSMC_2019a/MATLAB Function2'
//  '<S11>'  : 'IsolatedSMC_2019a/GUIDANCE /APF'
//  '<S12>'  : 'IsolatedSMC_2019a/GUIDANCE /INITIAL ORIENTATION'
//  '<S13>'  : 'IsolatedSMC_2019a/GUIDANCE /APF/IAPF'
//  '<S14>'  : 'IsolatedSMC_2019a/GUIDANCE /INITIAL ORIENTATION/MATLAB Function'

#endif                                 // RTW_HEADER_IsolatedSMC_2019a_h_

//
// File trailer for generated code.
//
// [EOF]
//
