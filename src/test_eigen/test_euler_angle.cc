/*
 * Copyright (c) MinWu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Author: MinWu <wumin199@126.com>, 2023/02/20
 */

#include <absl/base/pretty_print.h>  // print container
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <glog/logging.h>
#include <cmath>

const double MM2M = 0.001;
const double M2MM = 1000.0;

using CartPose = Eigen::Isometry3d;
using Quaternion = Eigen::Quaterniond;

inline double Rad2Deg(double rad) { return rad * 180.0 / M_PI; };

inline double Deg2Rad(double deg) { return deg * M_PI / 180.0; };

Eigen::Vector3d ConvertRotation(const Eigen::Matrix3d& rotation) {
  Eigen::Vector3d angles;
  angles = rotation.eulerAngles(2, 1, 0);  // rzyx
  return angles;
}

int main(int argc, char* argv[]) {
  std::cout << "hello" << std::endl;

  Quaternion q(-0.03820764984813447, -0.9515795634978994, 0.1448833656868248,
               -0.26841259317231625);  // wxyz
  // set cart pose
  Eigen::Vector3d pos(0.5882000000000001, 0.020010000000000003,
                      0.74138);  // in m

  CartPose cart_pose = CartPose ::Identity();
  cart_pose.linear() = q.toRotationMatrix();
  cart_pose.translation() = pos;

  auto angles = ConvertRotation(cart_pose.rotation());
  LOG(INFO) << Rad2Deg(angles[0]);
  LOG(INFO) << Rad2Deg(angles[1]);
  LOG(INFO) << Rad2Deg(angles[2]);
}
