//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: IsolatedSMC_2019a.cpp
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
#include "IsolatedSMC_2019a.h"
#include "IsolatedSMC_2019a_private.h"

// Forward declaration for local functions
static real_T IsolatedSMC_2019a_norm(const real_T x[2]);

// Function for MATLAB Function: '<S11>/IAPF'
static real_T IsolatedSMC_2019a_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void IsolatedSMC_2019a_step(RT_MODEL_IsolatedSMC_2019a_T *const
  IsolatedSMC_2019a_M, ExtU_IsolatedSMC_2019a_T *IsolatedSMC_2019a_U,
  ExtY_IsolatedSMC_2019a_T *IsolatedSMC_2019a_Y)
{
  DW_IsolatedSMC_2019a_T *IsolatedSMC_2019a_DW = ((DW_IsolatedSMC_2019a_T *)
    IsolatedSMC_2019a_M->dwork);
  real_T F_repy;
  real_T obst;
  real_T rho;
  real_T F_totx;
  real_T F_toty;
  real_T F_tot;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T rtb_enable_signal;
  real_T rtb_psiref;
  int32_T rtb_eos;
  real_T q[2];
  real_T q_0[2];
  real_T q_tmp;
  boolean_T guard1 = false;

  // MATLAB Function: '<S11>/IAPF' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/X_est'
  //   Inport: '<Root>/X_goal'
  //   Inport: '<Root>/Y_est'
  //   Inport: '<Root>/Y_goal'
  //   Inport: '<Root>/ox'
  //   Inport: '<Root>/oy'

  F_tot = IsolatedSMC_2019a_U->X_est - IsolatedSMC_2019a_U->X_goal;
  q_0[0] = F_tot;
  scale = IsolatedSMC_2019a_U->Y_est - IsolatedSMC_2019a_U->Y_goal;
  q_0[1] = scale;
  rtb_psiref = IsolatedSMC_2019a_norm(q_0);
  if (rtb_psiref <= 2.0) {
    F_totx = (IsolatedSMC_2019a_U->X_est - IsolatedSMC_2019a_U->X_goal) * -0.15;
    F_toty = (IsolatedSMC_2019a_U->Y_est - IsolatedSMC_2019a_U->Y_goal) * -0.15;
  } else {
    F_totx = F_tot * -0.15 * 2.0 / rtb_psiref;
    F_toty = scale * -0.15 * 2.0 / rtb_psiref;
  }

  absxk = 0.0;
  F_repy = 0.0;
  obst = 0.0;
  t = IsolatedSMC_2019a_U->X_est - IsolatedSMC_2019a_U->ox;
  q_0[0] = t;
  q_tmp = IsolatedSMC_2019a_U->Y_est - IsolatedSMC_2019a_U->oy;
  q_0[1] = q_tmp;
  if (10000.0 >= IsolatedSMC_2019a_norm(q_0)) {
    q_0[0] = t;
    q_0[1] = q_tmp;
    rho = IsolatedSMC_2019a_norm(q_0);
    if (rho <= 0.7) {
      q_0[0] = t;
      q[0] = t;
      q_0[1] = q_tmp;
      q[1] = q_tmp;
      obst = (1.0 / rho - 1.4285714285714286) * 0.05 / (rho * rho);
      absxk = obst * t / IsolatedSMC_2019a_norm(q_0);
      F_repy = obst * q_tmp / IsolatedSMC_2019a_norm(q);
      obst = 1.0 / rho;
    }
  }

  q_0[0] = IsolatedSMC_2019a_U->X_goal - IsolatedSMC_2019a_U->ox;
  q_0[1] = IsolatedSMC_2019a_U->Y_goal - IsolatedSMC_2019a_U->oy;
  guard1 = false;
  if (IsolatedSMC_2019a_norm(q_0) <= 0.3) {
    q_0[0] = F_tot;
    q_0[1] = scale;
    if (IsolatedSMC_2019a_norm(q_0) <= 0.3) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    F_totx += absxk;
    F_toty += F_repy;
  }

  scale = 3.3121686421112381E-170;
  absxk = fabs(F_totx);
  if (absxk > 3.3121686421112381E-170) {
    F_tot = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    F_tot = t * t;
  }

  absxk = fabs(F_toty);
  if (absxk > scale) {
    t = scale / absxk;
    F_tot = F_tot * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    F_tot += t * t;
  }

  F_tot = scale * sqrt(F_tot);
  F_totx = rt_atan2d_snf(F_toty, F_totx);
  obst = 0.6 / ((0.4 / rtb_psiref + obst) + 2.0);
  rtb_eos = 0;
  if (fabs(rtb_psiref) <= 0.1) {
    rtb_eos = 1;
  }

  if (F_tot == 0.0) {
    F_totx = 0.0;
    obst = -0.3;
  }

  // End of MATLAB Function: '<S11>/IAPF'

  // MATLAB Function: '<S12>/MATLAB Function' incorporates:
  //   Inport: '<Root>/X_goal'
  //   Inport: '<Root>/Y_goal'
  //   Inport: '<Root>/psi'

  rtb_psiref = 0.0;
  rtb_enable_signal = 0;
  if (IsolatedSMC_2019a_DW->en == 0.0) {
    if ((-3.1415926535897931 < IsolatedSMC_2019a_U->psi) &&
        (IsolatedSMC_2019a_U->psi <= -1.5707963267948966)) {
      if ((IsolatedSMC_2019a_U->X_goal >= 0.0) && (IsolatedSMC_2019a_U->Y_goal >=
           0.0)) {
        IsolatedSMC_2019a_DW->en = 0.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal > 0.0) && (IsolatedSMC_2019a_U->Y_goal <
           0.0)) {
        IsolatedSMC_2019a_DW->en = 0.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal <= 0.0) && (IsolatedSMC_2019a_U->Y_goal <=
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal < 0.0) && (IsolatedSMC_2019a_U->Y_goal >
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }
    }

    if ((1.5707963267948966 < IsolatedSMC_2019a_U->psi) &&
        (IsolatedSMC_2019a_U->psi <= 3.1415926535897931)) {
      if ((IsolatedSMC_2019a_U->X_goal >= 0.0) && (IsolatedSMC_2019a_U->Y_goal >=
           0.0)) {
        rtb_enable_signal = 0;
        IsolatedSMC_2019a_DW->en = 0.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal > 0.0) && (IsolatedSMC_2019a_U->Y_goal <
           0.0)) {
        rtb_enable_signal = 0;
        IsolatedSMC_2019a_DW->en = 0.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal <= 0.0) && (IsolatedSMC_2019a_U->Y_goal <=
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal < 0.0) && (IsolatedSMC_2019a_U->Y_goal >
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }
    }

    if ((-1.5707963267948966 <= IsolatedSMC_2019a_U->psi) &&
        (IsolatedSMC_2019a_U->psi <= 1.5707963267948966)) {
      if ((IsolatedSMC_2019a_U->X_goal >= 0.0) && (IsolatedSMC_2019a_U->Y_goal >=
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal > 0.0) && (IsolatedSMC_2019a_U->Y_goal <
           0.0)) {
        rtb_enable_signal = 1;
        IsolatedSMC_2019a_DW->en = 1.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal <= 0.0) && (IsolatedSMC_2019a_U->Y_goal <=
           0.0)) {
        rtb_enable_signal = 0;
        rtb_psiref = -3.1415926535897931;
        IsolatedSMC_2019a_DW->en = 0.0;
      }

      if ((IsolatedSMC_2019a_U->X_goal < 0.0) && (IsolatedSMC_2019a_U->Y_goal >
           0.0)) {
        rtb_enable_signal = 0;
        rtb_psiref = 3.1415926535897931;
        IsolatedSMC_2019a_DW->en = 0.0;
      }
    }
  } else {
    rtb_enable_signal = 1;
  }

  // End of MATLAB Function: '<S12>/MATLAB Function'

  // Sum: '<S5>/Sum' incorporates:
  //   Product: '<S5>/Product1'

  F_tot = F_totx * static_cast<real_T>(rtb_enable_signal) + rtb_psiref;

  // SampleTimeMath: '<S3>/TSamp'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_psiref = F_tot * 100.0;

  // SampleTimeMath: '<S4>/TSamp' incorporates:
  //   Inport: '<Root>/psi'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  F_totx = IsolatedSMC_2019a_U->psi * 100.0;

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/psi'

  F_toty = 57.295779513082323 * F_tot - 57.295779513082323 *
    IsolatedSMC_2019a_U->psi;
  if (fabs(F_toty) > 180.0) {
    if (F_toty < 0.0) {
      F_tot = -1.0;
    } else if (F_toty > 0.0) {
      F_tot = 1.0;
    } else if (F_toty == 0.0) {
      F_tot = 0.0;
    } else {
      F_tot = (rtNaN);
    }

    F_toty -= 360.0 * F_tot;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   Sum: '<Root>/Sum2'
  //   Sum: '<S3>/Diff'
  //   Sum: '<S4>/Diff'
  //   UnitDelay: '<S3>/UD'
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  F_tot = ((rtb_psiref - IsolatedSMC_2019a_DW->UD_DSTATE) - (F_totx -
            IsolatedSMC_2019a_DW->UD_DSTATE_b)) + 100.0 * F_toty;
  if (F_tot < 0.0) {
    F_tot = -1.0;
  } else if (F_tot > 0.0) {
    F_tot = 1.0;
  } else if (F_tot == 0.0) {
    F_tot = 0.0;
  } else {
    F_tot = (rtNaN);
  }

  // Outport: '<Root>/psi_cmd' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function2'

  IsolatedSMC_2019a_Y->psi_cmd = 0.2 * F_tot;

  // Product: '<S5>/Product'
  F_tot = obst * static_cast<real_T>(rtb_enable_signal);

  // SampleTimeMath: '<S1>/TSamp'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  obst = F_tot * 100.0;

  // SampleTimeMath: '<S2>/TSamp' incorporates:
  //   Inport: '<Root>/Vx'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  F_toty = IsolatedSMC_2019a_U->Vx * 100.0;

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/Vx'
  //   Sum: '<Root>/Sum'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<S1>/Diff'
  //   Sum: '<S2>/Diff'
  //   UnitDelay: '<S1>/UD'
  //   UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S1>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  F_tot = ((obst - IsolatedSMC_2019a_DW->UD_DSTATE_m) - (F_toty -
            IsolatedSMC_2019a_DW->UD_DSTATE_o)) + (F_tot -
    IsolatedSMC_2019a_U->Vx) * 30.0;
  if (F_tot < 0.0) {
    F_tot = -1.0;
  } else if (F_tot > 0.0) {
    F_tot = 1.0;
  } else if (F_tot == 0.0) {
    F_tot = 0.0;
  } else {
    F_tot = (rtNaN);
  }

  // Outport: '<Root>/Vx_cmd' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function1'

  IsolatedSMC_2019a_Y->Vx_cmd = 0.1 * F_tot;

  // Stop: '<Root>/Stop Simulation' incorporates:
  //   Constant: '<S6>/Constant'
  //   RelationalOperator: '<S6>/Compare'

  if (rtb_eos != 0) {
    rtmSetStopRequested(IsolatedSMC_2019a_M, 1);
  }

  // End of Stop: '<Root>/Stop Simulation'

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  IsolatedSMC_2019a_DW->UD_DSTATE = rtb_psiref;

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  IsolatedSMC_2019a_DW->UD_DSTATE_b = F_totx;

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  IsolatedSMC_2019a_DW->UD_DSTATE_m = obst;

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  IsolatedSMC_2019a_DW->UD_DSTATE_o = F_toty;
}

// Model initialize function
void IsolatedSMC_2019a_initialize(RT_MODEL_IsolatedSMC_2019a_T *const
  IsolatedSMC_2019a_M, ExtU_IsolatedSMC_2019a_T *IsolatedSMC_2019a_U,
  ExtY_IsolatedSMC_2019a_T *IsolatedSMC_2019a_Y)
{
  DW_IsolatedSMC_2019a_T *IsolatedSMC_2019a_DW = ((DW_IsolatedSMC_2019a_T *)
    IsolatedSMC_2019a_M->dwork);

  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // states (dwork)
  (void) memset((void *)IsolatedSMC_2019a_DW, 0,
                sizeof(DW_IsolatedSMC_2019a_T));

  // external inputs
  (void)memset(IsolatedSMC_2019a_U, 0, sizeof(ExtU_IsolatedSMC_2019a_T));

  // external outputs
  (void) memset((void *)IsolatedSMC_2019a_Y, 0,
                sizeof(ExtY_IsolatedSMC_2019a_T));

  // SystemInitialize for MATLAB Function: '<S12>/MATLAB Function'
  IsolatedSMC_2019a_DW->en = 0.0;
}

// Model terminate function
void IsolatedSMC_2019a_terminate(RT_MODEL_IsolatedSMC_2019a_T *const
  IsolatedSMC_2019a_M)
{
  // (no terminate code required)
  UNUSED_PARAMETER(IsolatedSMC_2019a_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
