#ifndef SRBD_MPC_MPC_HPP_
#define SRBD_MPC_MPC_HPP_

#include "srbd_mpc/contact_schedule.hpp"
#include "srbd_mpc/gait_command.hpp"
#include "srbd_mpc/robot_state.hpp"
#include "srbd_mpc/state_equation.hpp"
#include "srbd_mpc/cost_function.hpp"
#include "srbd_mpc/friction_cone.hpp"
#include "srbd_mpc/qp_data.hpp"
#include "srbd_mpc/qp_solver.hpp"


namespace srbd_mpc {

class MPC {
public:
  MPC(const StateEquation& state_equation, const CostFunction& cost_function, 
      const FrictionCone& friction_cone);

  MPC() = default;

  ~MPC() = default;

  void init(const ContactSchedule& contact_schedule);

  void solve(const ContactSchedule& contact_schedule,
             const GaitCommand& gait_command, const RobotState& robot_state);

private:
  StateEquation state_equation_;
  CostFunction cost_function_;
  FrictionCone friction_cone_;
  QPData qp_data_;
  QPSolver qp_solver_;
};

} // namespace srbd_mpc

#endif // SRBD_MPC_MPC_HPP_