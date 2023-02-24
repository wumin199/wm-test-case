/*
 * Copyright (c) MinWu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Author: MinWu <wumin199@126.com>, 2023/02/24
 */

#include <absl/base/pretty_print.h>  // print container
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <glog/logging.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <future>

void test_1() {
  LOG(INFO) << "hello: test_1";
  LOG(FATAL) << "fatal error";
  LOG(INFO) << "test_1 ended";
}

void test_print() {
  LOG(INFO) << "hello: test_print";
  LOG(FATAL) << "fatal error";
  LOG(INFO) << "test_print ended";
}

int test_calculate(int value) {
  LOG(INFO) << "calculate " << value << " + 1";
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return (value + 1);
}

void test_2() {
  int num = 100;
  auto res1 = std::async(std::launch::async, test_calculate, num);
  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  [[maybe_unused]] auto res2 = std::async(std::launch::async, test_print);

  auto value = res1.get();

  std::cout << num << " + 1 = " << value;
}

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_colorlogtostderr = true;
  FLAGS_alsologtostderr = true;

  //  test_1();
  test_2();
}
