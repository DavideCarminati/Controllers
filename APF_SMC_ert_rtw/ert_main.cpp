//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'APF_SMC'.
//
// Model version                  : 1.113
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Thu Dec  2 12:23:48 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include "APF_SMC.h"                   // Model's header file
#include "rtwtypes.h"

static RT_MODEL_APF_SMC_T APF_SMC_M_;
static RT_MODEL_APF_SMC_T *const APF_SMC_MPtr = &APF_SMC_M_;// Real-time model
static DW_APF_SMC_T APF_SMC_DW;        // Observable states
static ExtU_APF_SMC_T APF_SMC_U;       // External inputs
static ExtY_APF_SMC_T APF_SMC_Y;       // External outputs

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(RT_MODEL_APF_SMC_T *const APF_SMC_M);
void rt_OneStep(RT_MODEL_APF_SMC_T *const APF_SMC_M)
{
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(APF_SMC_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  APF_SMC_step(APF_SMC_M, &APF_SMC_U, &APF_SMC_Y);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example "main" function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific.  This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_APF_SMC_T *const APF_SMC_M = APF_SMC_MPtr;

  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Pack model data into RTM
  APF_SMC_M->dwork = &APF_SMC_DW;

  // Initialize model
  APF_SMC_initialize(APF_SMC_M, &APF_SMC_U, &APF_SMC_Y);

  // Simulating the model step behavior (in non real-time) to
  //   simulate model behavior at stop time.

  while ((rtmGetErrorStatus(APF_SMC_M) == (NULL)) && !rtmGetStopRequested
         (APF_SMC_M)) {
    rt_OneStep(APF_SMC_M);
  }

  // Disable rt_OneStep() here

  // Terminate model
  APF_SMC_terminate(APF_SMC_M);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
