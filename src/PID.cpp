#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
  Kp = 0.0;
  Ki = 0.0;
  Kd = 0.0;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  }

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error = 0.0;
  total_error =  - Kp * p_error - Kd * d_error - Ki * i_error;
  return total_error;  // TODO: Add your total error calc here!
}

void PID::PrintError(){
  std::cout << "P_Error: " << p_error <<", I_Error: " << i_error << ", D_Error: " << d_error << std::endl;
}

void PID::PrintGain(){
  std::cout << "Kp: " << Kp << ", Ki: " << Ki << ", Kd: " << Kd << std::endl;
}