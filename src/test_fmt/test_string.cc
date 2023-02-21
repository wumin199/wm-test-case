/*
 * Copyright (c) MinWu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Author: MinWu <wumin199@126.com>, 2023/02/20
 */

#include <iostream>
#include <string>
#include <cstring>
using byte = uint8_t;

using usigned_word = uint16_t;
using signed_word = int16_t;
using usigned_dword = uint32_t;
using signed_dword = int32_t;

typedef byte *pbyte;

std::string GetCharsAt(const byte *buffer, int pos, int size) {
  std::string res{""};
  res.insert(0, (char *)&buffer[pos], size);
  res.insert(0, reinterpret_cast<const char *>(&buffer[pos]), size);
}

void SetStringAt(byte *buffer, int pos, int max_len, std::string value) {
  int size = value.size();
  value.copy(((char *)&buffer[pos + 2]), size);
  value.copy(reinterpret_cast<char *>(&buffer[pos + 2]), size);
}

int32_t GetDIntAt(const byte *buffer, int pos) {
  int32_t result;
  result = buffer[pos];
  result <<= 8;
  result += buffer[pos + 1];
  result <<= 8;
  result += buffer[pos + 2];
  result <<= 8;
  result += buffer[pos + 3];
  return result;
}

void SetDIntAt(byte *buffer, int pos, int32_t value) {
  buffer[pos + 3] = static_cast<byte>(value & 0xff);
  buffer[pos + 2] = static_cast<byte>((value >> 8) & 0xff);
  buffer[pos + 1] = static_cast<byte>((value >> 16) & 0xff);
  buffer[pos] = static_cast<byte>((value >> 24) & 0xff);
}

uint32_t GetUDIntAt(const byte *buffer, int pos) {
  uint32_t result;
  result = buffer[pos];
  result <<= 8;
  result += buffer[pos + 1];
  result <<= 8;
  result += buffer[pos + 2];
  result <<= 8;
  result += buffer[pos + 3];
  return result;
}

void SetUDIntAt(byte *buffer, int pos, int32_t value) {
  buffer[pos + 3] = static_cast<byte>(value & 0xff);
  buffer[pos + 2] = static_cast<byte>((value >> 8) & 0xff);
  buffer[pos + 1] = static_cast<byte>((value >> 16) & 0xff);
  buffer[pos] = static_cast<byte>((value >> 24) & 0xff);
}

float GetRealAt(const byte *buffer, int pos) {
  uint32_t pack = GetUDIntAt(buffer, pos);
  float result;
  memcpy(&result, &pack, 4);

  // @TODO: test it
  //  result = *reinterpret_cast<float *>(&pack);
  return result;
}

void SetRealAt(byte *buffer, int pos, float value) {
  uint32_t pack;
  memcpy(&pack, &value, 4);
  SetUDIntAt(buffer, pos, pack);

}

int main(int argc, char *argv[]) {}