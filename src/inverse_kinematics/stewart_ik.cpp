#include "config_arm.h"
#include "mldivide.h"
#include <cmath>
#include <cstring>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <array>

namespace py = pybind11;

std::array<double, 6> config_arm(const double q_d[6])
{
  std::array<double, 6> L;
  static const double dv1[576]{199.57765972422868,0.0, 0.0, 0.0, 0.0,0.0 0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.66967264209154,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.57767911267032,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.67001654730237,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.57774740937427,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.67013831817718,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.57765972422868,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.66967264209154,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.57767911267032,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.67001654730237,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.57774740937427,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.67013831817718,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               197.09874175397468,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               200.96103668373129,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               200.59972523660147,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               198.39340550028368,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               198.1193404440869,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.38657242653028,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               197.09874175397468,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               200.96103668373129,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               200.59972523660147,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               198.39340550028368,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               198.1193404440869,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               0.0,
                               199.38657242653028};
  static const double Pdi_b[72]{
      -147.625, -190.187, -42.5,    42.438,   190.125,  147.75,   -147.625,
      -190.187, -42.5,    42.438,   190.125,  147.75,   -44.799,  -191.363,
      -148.558, 146.689,  188.883,  40.2,     -44.799,  -191.363, -148.558,
      146.689,  188.883,  40.2,     0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      -134.306,
      -60.802,  195.0,    195.108,  -60.694,  -134.306, -134.306, -60.802,
      195.0,    195.108,  -60.694,  -134.306, -191.94,  61.364,   134.799,
      133.575,  59.787,   -195.292, -191.94,  61.364,   134.799,  133.575,
      59.787,   -195.292};
  static const double Pdi_b0[72]{
      -147.625, -190.187, -42.5,    42.438,   190.125,  147.75,   -147.625,
      -190.187, -42.5,    42.438,   190.125,  147.75,   -44.799,  -191.363,
      -148.558, 146.689,  188.883,  40.2,     -44.799,  -191.363, -148.558,
      146.689,  188.883,  40.2,     0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      25.0,     25.0,     0.0,      0.0,      0.0,
      0.0,      356.765,  356.765,  356.765,  356.765,  356.765,  356.765,
      381.765,  381.765,  381.765,  381.765,  381.765,  381.765,  -134.306,
      -60.802,  195.0,    195.108,  -60.694,  -134.306, -134.306, -60.802,
      195.0,    195.108,  -60.694,  -134.306, -191.94,  61.364,   134.799,
      133.575,  59.787,   -195.292, -191.94,  61.364,   134.799,  133.575,
      59.787,   -195.292};
  static const double b_Axis1[72]{
      134.306,  60.802,   -195.0,   -195.108, 60.694,   134.306,  134.306,
      60.802,   -195.0,   -195.108, 60.694,   134.306,  191.94,   -61.364,
      -134.799, -133.575, -59.787,  195.292,  191.94,   -61.364,  -134.799,
      -133.575, -59.787,  195.292,  0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,
      0.0,      0.0,      0.0,      0.0,      0.0,      0.0,      -147.625,
      -190.187, -42.5,    42.438,   190.125,  147.75,   -147.625, -190.187,
      -42.5,    42.438,   190.125,  147.75,   -44.799,  -191.363, -148.558,
      146.689,  188.883,  40.2,     -44.799,  -191.363, -148.558, 146.689,
      188.883,  40.2};
  static const double dv[36]{
      -44.799, -191.363, -148.558, 146.689, 188.883, 40.2,
      -44.799, -191.363, -148.558, 146.689, 188.883, 40.2,
      356.765, 356.765,  356.765,  356.765, 356.765, 356.765,
      381.765, 381.765,  381.765,  381.765, 381.765, 381.765,
      -191.94, 61.364,   134.799,  133.575, 59.787,  -195.292,
      -191.94, 61.364,   134.799,  133.575, 59.787,  -195.292};
  static const double a[24]{134.306,  60.802,   -195.0,  -195.108, 60.694,
                            134.306,  134.306,  60.802,  -195.0,   -195.108,
                            60.694,   134.306,  191.94,  -61.364,  -134.799,
                            -133.575, -59.787,  195.292, 191.94,   -61.364,
                            -134.799, -133.575, -59.787, 195.292};
  static const double b_a[24]{-147.625, -190.187, -42.5,    42.438,   190.125,
                              147.75,   -147.625, -190.187, -42.5,    42.438,
                              190.125,  147.75,   -44.799,  -191.363, -148.558,
                              146.689,  188.883,  40.2,     -44.799,  -191.363,
                              -148.558, 146.689,  188.883,  40.2};
  static const double c_a[24]{-134.306, -60.802,  195.0,    195.108, -60.694,
                              -134.306, -134.306, -60.802,  195.0,   195.108,
                              -60.694,  -134.306, -191.94,  61.364,  134.799,
                              133.575,  59.787,   -195.292, -191.94, 61.364,
                              134.799,  133.575,  59.787,   -195.292};
  static const double d_a[16]{1.0, 0.0, 0.0, 0.0, 0.0, 1.0,     0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0, 0.0, 381.765, 0.0, 1.0};
  static const signed char c_b[12]{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
  static const signed char iv[12]{-25, -25, -25, -25, -25, -25,
                                  0,   0,   0,   0,   0,   0};
  static const signed char b[9]{0, 1, 0, -1, 0, 0, 0, 0, 0};
  static const signed char b_b[9]{0, 0, -1, 0, 0, 0, 1, 0, 0};
  static const signed char e_a[9]{0, 0, -1, 0, 1, 0, 1, 0, 0};
  static const signed char d_b[3]{0, 1, 0};
  static const signed char e_b[3]{1, 0, 0};
  static const signed char iv1[3]{1, 0, 0};
  static const signed char iv2[3]{0, 25, 0};
  static const signed char iv3[3]{0, 1, 0};
  static const signed char iv4[3]{0, 0, 1};
  double d[576];
  double Tdi_b[96];
  double Axis1[72];
  double Axis2[72];
  double GUp[36];
  double Len1[24];
  double b_T[24];
  double GUp_fix[18];
  double axis_b[18];
  double T[16];
  double Tci3_ci1[16];
  double b_R_tmp[9];
  double b_invR[9];
  double c_R_tmp[9];
  double invR[9];
  double R_tmp;
  double absxk;
  double b_d;
  double d1;
  double d2;
  double d3;
  double s;
  double scale;
  double smax;
  double t;
  int i;
  int i1;
  int jA;
  int temp_tmp;
  //
  // 计算轴方向
  // 垂直方向轴
  // 平行方向轴
  //  figure(1);plot(gimbal1(1:6,1),gimbal1(1:6,3),'bo');axis equal;hold on;
  //
  //  plot(gimbal1(7:12,1),gimbal1(7:12,3),'ko');
  //  plot(gimbal1(13:18,1),gimbal1(13:18,3),'ro');
  //  plot(gimbal1(19:24,1),gimbal1(19:24,3),'yo');
  //
  // 中立点高度
  // 下层点坐标
  // 上层点在上层的坐标
  std::copy(&dv[0], &dv[36], &GUp[0]);
  for (i = 0; i < 12; i++) {
    GUp[i + 12] = iv[i];
  }
  // 短连杆长度d=14;%非相交十字轴两轴距离14mm
  // mm
  // 垂直方向轴
  for (int k{0}; k < 24; k++) {
    b_d = a[k];
    d1 = b_a[k];
    Len1[k] = std::sqrt(b_d * b_d + d1 * d1);
  }
  std::memset(&d[0], 0, 576U * sizeof(double));
  for (int j{0}; j < 24; j++) {
    d[j + 24 * j] = Len1[j];
  }
  std::copy(&b_Axis1[0], &b_Axis1[72], &Axis1[0]);
  coder::mldivide(d, Axis1);
  // 平行方向轴
  // 记录原始位置
  // 用于计算两轴
  for (int k{0}; k < 24; k++) {
    b_d = b_a[k];
    d1 = c_a[k];
    Len1[k] = std::sqrt(b_d * b_d + d1 * d1);
  }
  std::memset(&d[0], 0, 576U * sizeof(double));
  for (int j{0}; j < 24; j++) {
    d[j + 24 * j] = Len1[j];
  }
  std::copy(&Pdi_b[0], &Pdi_b[72], &Axis2[0]);
  coder::mldivide(d, Axis2);
  for (int ii{0}; ii < 6; ii++) {
    // 与推导公式不一样
    // 用原始位置
    jA = ii << 4;
    Tdi_b[jA] = Axis2[ii];
    Tdi_b[jA + 4] = 0.0;
    Tdi_b[jA + 8] = Axis1[ii];
    Tdi_b[jA + 12] = Pdi_b0[ii];
    Tdi_b[jA + 1] = Axis2[ii + 24];
    Tdi_b[jA + 5] = 1.0;
    Tdi_b[jA + 9] = Axis1[ii + 24];
    Tdi_b[jA + 13] = Pdi_b0[ii + 24];
    Tdi_b[jA + 2] = Axis2[ii + 48];
    Tdi_b[jA + 6] = 0.0;
    Tdi_b[jA + 10] = Axis1[ii + 48];
    Tdi_b[jA + 14] = Pdi_b0[ii + 48];
    Tdi_b[jA + 3] = 0.0;
    Tdi_b[jA + 7] = 0.0;
    Tdi_b[jA + 11] = 0.0;
    Tdi_b[jA + 15] = 1.0;
  }
  //
  // 中立位置
  // %%b系到p系
  // 下层固定点坐标
  // 运动%%%模拟随机运动，平移+旋转
  // %%相对动平台，在p系
  //  rot1=randn(3,1);
  //  rot1=rot1/norm(rot1)*0.8;
  //  R1=expm(cross_m(rot1));%计算叉乘
  // %%R1=rotz_new2old(q_d(6))*roty_new2old(q_d(5))*rotx_new2old(q_d(4));
  // 绕Y轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
  t = std::sin(q_d[4]);
  R_tmp = std::cos(q_d[4]);
  // 绕Z轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
  scale = std::sin(q_d[5]);
  absxk = std::cos(q_d[5]);
  // 绕X轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
  s = std::sin(q_d[3]);
  smax = std::cos(q_d[3]);
  // 转序问题
  // 逆运动学
  // 上层位姿
  b_R_tmp[0] = R_tmp;
  b_R_tmp[3] = 0.0;
  b_R_tmp[6] = t;
  b_R_tmp[2] = -t;
  b_R_tmp[5] = 0.0;
  b_R_tmp[8] = R_tmp;
  c_R_tmp[0] = absxk;
  c_R_tmp[3] = -scale;
  c_R_tmp[6] = 0.0;
  c_R_tmp[1] = scale;
  c_R_tmp[4] = absxk;
  c_R_tmp[7] = 0.0;
  b_R_tmp[1] = 0.0;
  c_R_tmp[2] = 0.0;
  b_R_tmp[4] = 1.0;
  c_R_tmp[5] = 0.0;
  b_R_tmp[7] = 0.0;
  c_R_tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    b_d = b_R_tmp[i];
    i1 = static_cast<int>(b_R_tmp[i + 3]);
    d1 = b_R_tmp[i + 6];
    for (temp_tmp = 0; temp_tmp < 3; temp_tmp++) {
      invR[i + 3 * temp_tmp] =
          (b_d * c_R_tmp[3 * temp_tmp] +
           static_cast<double>(i1) * c_R_tmp[3 * temp_tmp + 1]) +
          d1 * c_R_tmp[3 * temp_tmp + 2];
    }
    b_invR[3 * i] = iv1[i];
  }
  b_invR[1] = 0.0;
  b_invR[4] = smax;
  b_invR[7] = -s;
  b_invR[2] = 0.0;
  b_invR[5] = s;
  b_invR[8] = smax;
  for (i = 0; i < 3; i++) {
    b_d = invR[i];
    d1 = invR[i + 3];
    d2 = invR[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_R_tmp[i + 3 * i1] = (b_d * b_invR[3 * i1] + d1 * b_invR[3 * i1 + 1]) +
                            d2 * b_invR[3 * i1 + 2];
    }
  }
  for (i = 0; i < 3; i++) {
    jA = i << 2;
    Tci3_ci1[jA] = b_R_tmp[3 * i];
    Tci3_ci1[jA + 1] = b_R_tmp[3 * i + 1];
    Tci3_ci1[jA + 2] = b_R_tmp[3 * i + 2];
    Tci3_ci1[i + 12] = q_d[i];
  }
  Tci3_ci1[3] = 0.0;
  Tci3_ci1[7] = 0.0;
  Tci3_ci1[11] = 0.0;
  Tci3_ci1[15] = 1.0;
  for (i = 0; i < 4; i++) {
    b_d = d_a[i];
    d1 = d_a[i + 4];
    d2 = d_a[i + 8];
    d3 = d_a[i + 12];
    for (i1 = 0; i1 < 4; i1++) {
      temp_tmp = i1 << 2;
      T[i + temp_tmp] =
          ((b_d * Tci3_ci1[temp_tmp] + d1 * Tci3_ci1[temp_tmp + 1]) +
           d2 * Tci3_ci1[temp_tmp + 2]) +
          d3 * Tci3_ci1[temp_tmp + 3];
    }
  }
  // %%初始位置
  // 上下层固定点坐标
  for (i = 0; i < 6; i++) {
    jA = i << 2;
    Len1[jA] = GUp[i + 6];
    Len1[jA + 1] = GUp[i + 18];
    Len1[jA + 2] = GUp[i + 30];
    Len1[jA + 3] = 1.0;
  }
  for (i = 0; i < 4; i++) {
    b_d = T[i];
    d1 = T[i + 4];
    d2 = T[i + 8];
    d3 = T[i + 12];
    for (i1 = 0; i1 < 6; i1++) {
      temp_tmp = i1 << 2;
      b_T[i + temp_tmp] = ((b_d * Len1[temp_tmp] + d1 * Len1[temp_tmp + 1]) +
                           d2 * Len1[temp_tmp + 2]) +
                          d3 * Len1[temp_tmp + 3];
    }
  }
  for (i = 0; i < 6; i++) {
    jA = i << 2;
    GUp_fix[3 * i] = b_T[jA];
    GUp_fix[3 * i + 1] = b_T[jA + 1];
    GUp_fix[3 * i + 2] = b_T[jA + 2];
  }
  // 上下层辅助杆矢量
  // Psudo_cylinder=GUp_fix-GDp(1:6,:)';
  // 上铰接点在b系中的位置
  // 上层固定轴的方向约束
  // 每组3连杆的位姿
  // 逆运动学求解杆长
  // Pos_ui_b=GUp_fix;%上铰接点在b系中的位置
  // 上层固定轴的方向约束
  std::copy(&b_Axis1[0], &b_Axis1[72], &Axis1[0]);
  coder::mldivide(dv1, Axis1);
  for (i = 0; i < 3; i++) {
    b_d = T[i];
    d1 = T[i + 4];
    d2 = T[i + 8];
    for (i1 = 0; i1 < 6; i1++) {
      axis_b[i + 3 * i1] =
          (b_d * Axis1[i1 + 18] + d1 * Axis1[i1 + 42]) + d2 * Axis1[i1 + 66];
    }
  }
  // 每组3连杆的位姿
  // 逆运动学求解杆长
  b_d = Tdi_b[12];
  d1 = Tdi_b[13];
  d2 = Tdi_b[14];
  for (int ii{0}; ii < 6; ii++) {
    double b_GUp_fix[4];
    double Li;
    double d4;
    double d5;
    double gam1;
    double gam2;
    double gam3;
    double phi_i;
    int jj;
    boolean_T exitg1;
    // 上轴中点在b系中的坐标
    for (i = 0; i < 3; i++) {
      invR[3 * i] = Tdi_b[i];
      invR[3 * i + 1] = Tdi_b[i + 4];
      invR[3 * i + 2] = Tdi_b[i + 8];
    }
    // Psudo_cylinder(:,ii);%从下轴到上轴之间的矢量，用于计算初始长度
    // psud = Psudo_cylinder(:,ii);
    // first guess
    // Li=norm(psud)-2*d;%%%这里有问题
    for (i = 0; i < 9; i++) {
      b_invR[i] = -invR[i];
    }
    for (i = 0; i < 3; i++) {
      jA = i << 2;
      Tci3_ci1[jA] = invR[3 * i];
      Tci3_ci1[jA + 1] = invR[3 * i + 1];
      Tci3_ci1[jA + 2] = invR[3 * i + 2];
      Tci3_ci1[i + 12] =
          (b_invR[i] * b_d + b_invR[i + 3] * d1) + b_invR[i + 6] * d2;
    }
    Tci3_ci1[3] = 0.0;
    Tci3_ci1[7] = 0.0;
    Tci3_ci1[11] = 0.0;
    Tci3_ci1[15] = 1.0;
    d3 = GUp_fix[3 * ii];
    d4 = GUp_fix[3 * ii + 1];
    d5 = GUp_fix[3 * ii + 2];
    for (i = 0; i < 4; i++) {
      b_GUp_fix[i] =
          ((Tci3_ci1[i] * d3 + Tci3_ci1[i + 4] * d4) + Tci3_ci1[i + 8] * d5) +
          Tci3_ci1[i + 12];
    }
    scale = 3.3121686421112381E-170;
    absxk = std::abs(b_GUp_fix[0]);
    if (absxk > 3.3121686421112381E-170) {
      s = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      s = t * t;
    }
    absxk = std::abs(b_GUp_fix[1]);
    if (absxk > scale) {
      t = scale / absxk;
      s = s * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      s += t * t;
    }
    absxk = std::abs(b_GUp_fix[2]);
    if (absxk > scale) {
      t = scale / absxk;
      s = s * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      s += t * t;
    }
    s = scale * std::sqrt(s);
    Li = s - 50.0;
    //      invR = Tdi_b(1:3,1:3)';
    //      invT = [invR,-invR*Tdi_b(1:3,4);0 0 0 1];
    //      psud = invT*[p0;1];%Psudo_cylinder(:,ii);
    // first guess
    gam1 = 0.0;
    gam2 = 0.0;
    gam3 = 0.0;
    phi_i = 0.0;
    // norm(psud)-2*d;
    // 迭代
    jj = 0;
    exitg1 = false;
    while ((!exitg1) && (jj < 100)) {
      double Jaco1[30];
      double y_tmp[30];
      double A[25];
      double Tci1_b[16];
      double Tci2_b[16];
      double Tci3_ci2[16];
      double b_h12_tmp[12];
      double c_h12_tmp[12];
      double b_h14_tmp[9];
      double h12_tmp[9];
      double h14_tmp[9];
      double dpa[6];
      double dx[5];
      double c_invR[3];
      double x[3];
      double d6;
      int jBcol;
      int jp1j;
      signed char ipiv[5];
      signed char i2;
      // Tdi_b为下短杆基座坐标系到b系的位姿矩阵
      // d为非相交十字轴的轴间距
      // gam1,gam2,gam3依次为下短轴转角，电动缸z转角，上短轴z转角
      // phi_i为电动缸扭角
      // Li为电动缸长
      // p0为上短杆与上平台铰接点中点坐标（在基座b系）
      // axis0为上短杆与上平台铰接轴的正单位矢量（在基座b系）
      // Tci3_b为由上短杆坐标ci3系到b系的位姿变换矩阵
      // [d_p0;d_axis0]=Jaco*[d_gam1;d_gam2;d_gam3;d_phi_i;d_Li]
      // Tdi_b=generate_Tdi_b(gimbal1);
      // 绕Z轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      t = std::sin(gam1);
      R_tmp = std::cos(gam1);
      // TurnZ(gam1)';
      // Tci2_ci1=generate_Tci2_ci1(gam2轴转角,di两轴距离)
      // 绕Z轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      scale = std::sin(gam2);
      absxk = std::cos(gam2);
      // TurnZ(gam2)';
      b_R_tmp[0] = absxk;
      b_R_tmp[3] = -scale;
      b_R_tmp[6] = 0.0;
      b_R_tmp[1] = scale;
      b_R_tmp[4] = absxk;
      b_R_tmp[7] = 0.0;
      b_R_tmp[2] = 0.0;
      b_R_tmp[5] = 0.0;
      b_R_tmp[8] = 1.0;
      for (i = 0; i < 3; i++) {
        signed char i3;
        signed char i4;
        i2 = e_a[i];
        i3 = e_a[i + 3];
        i4 = e_a[i + 6];
        for (i1 = 0; i1 < 3; i1++) {
          c_R_tmp[i + 3 * i1] =
              (static_cast<double>(i2) * b_R_tmp[3 * i1] +
               static_cast<double>(i3) * b_R_tmp[3 * i1 + 1]) +
              static_cast<double>(i4) * b_R_tmp[3 * i1 + 2];
        }
      }
      for (i = 0; i < 3; i++) {
        jA = i << 2;
        T[jA] = c_R_tmp[3 * i];
        T[jA + 1] = c_R_tmp[3 * i + 1];
        T[jA + 2] = c_R_tmp[3 * i + 2];
        T[i + 12] = iv2[i];
      }
      T[3] = 0.0;
      T[7] = 0.0;
      T[11] = 0.0;
      T[15] = 1.0;
      // Tci2_ci1=generate_Tci2_ci1(gam2轴转角,di两轴距离)
      // 绕Y轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      smax = std::sin(phi_i);
      s = std::cos(phi_i);
      // 绕Z轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      scale = std::sin(gam3);
      absxk = std::cos(gam3);
      // TurnY(phi_i)'*TurnZ(gam3)';
      b_R_tmp[0] = s;
      b_R_tmp[3] = 0.0;
      b_R_tmp[6] = smax;
      b_R_tmp[2] = -smax;
      b_R_tmp[5] = 0.0;
      b_R_tmp[8] = s;
      c_R_tmp[0] = absxk;
      c_R_tmp[3] = -scale;
      c_R_tmp[6] = 0.0;
      c_R_tmp[1] = scale;
      c_R_tmp[4] = absxk;
      c_R_tmp[7] = 0.0;
      b_R_tmp[1] = 0.0;
      c_R_tmp[2] = 0.0;
      b_R_tmp[4] = 1.0;
      c_R_tmp[5] = 0.0;
      b_R_tmp[7] = 0.0;
      c_R_tmp[8] = 1.0;
      for (i = 0; i < 3; i++) {
        d3 = b_R_tmp[i];
        i1 = static_cast<int>(b_R_tmp[i + 3]);
        d4 = b_R_tmp[i + 6];
        for (temp_tmp = 0; temp_tmp < 3; temp_tmp++) {
          invR[i + 3 * temp_tmp] =
              (d3 * c_R_tmp[3 * temp_tmp] +
               static_cast<double>(i1) * c_R_tmp[3 * temp_tmp + 1]) +
              d4 * c_R_tmp[3 * temp_tmp + 2];
        }
      }
      for (i = 0; i < 3; i++) {
        jA = i << 2;
        Tci3_ci2[jA] = invR[3 * i];
        Tci3_ci2[jA + 1] = invR[3 * i + 1];
        Tci3_ci2[jA + 2] = invR[3 * i + 2];
      }
      Tci3_ci2[12] = 0.0;
      Tci3_ci2[13] = Li;
      Tci3_ci2[14] = 0.0;
      Tci3_ci2[3] = 0.0;
      Tci3_ci2[7] = 0.0;
      Tci3_ci2[11] = 0.0;
      Tci3_ci2[15] = 1.0;
      Tci3_ci1[0] = R_tmp;
      Tci3_ci1[4] = -t;
      Tci3_ci1[8] = 0.0;
      Tci3_ci1[1] = t;
      Tci3_ci1[5] = R_tmp;
      Tci3_ci1[9] = 0.0;
      Tci3_ci1[2] = 0.0;
      Tci3_ci1[12] = 0.0;
      Tci3_ci1[6] = 0.0;
      Tci3_ci1[13] = 0.0;
      Tci3_ci1[10] = 1.0;
      Tci3_ci1[14] = 0.0;
      Tci3_ci1[3] = 0.0;
      Tci3_ci1[7] = 0.0;
      Tci3_ci1[11] = 0.0;
      Tci3_ci1[15] = 1.0;
      for (i = 0; i < 4; i++) {
        i1 = i + (ii << 4);
        for (temp_tmp = 0; temp_tmp < 4; temp_tmp++) {
          jA = temp_tmp << 2;
          Tci1_b[i + jA] =
              ((Tdi_b[i1] * Tci3_ci1[jA] + Tdi_b[i1 + 4] * Tci3_ci1[jA + 1]) +
               Tdi_b[i1 + 8] * Tci3_ci1[jA + 2]) +
              Tdi_b[i1 + 12] * Tci3_ci1[jA + 3];
        }
      }
      for (i = 0; i < 4; i++) {
        d3 = Tci1_b[i];
        d4 = Tci1_b[i + 4];
        d5 = Tci1_b[i + 8];
        d6 = Tci1_b[i + 12];
        for (i1 = 0; i1 < 4; i1++) {
          temp_tmp = i1 << 2;
          jA = i + temp_tmp;
          Tci2_b[jA] = ((d3 * T[temp_tmp] + d4 * T[temp_tmp + 1]) +
                        d5 * T[temp_tmp + 2]) +
                       d6 * T[temp_tmp + 3];
          Tci3_ci1[jA] =
              ((T[i] * Tci3_ci2[temp_tmp] + T[i + 4] * Tci3_ci2[temp_tmp + 1]) +
               T[i + 8] * Tci3_ci2[temp_tmp + 2]) +
              T[i + 12] * Tci3_ci2[temp_tmp + 3];
        }
      }
      for (i = 0; i < 4; i++) {
        d3 = Tci2_b[i];
        d4 = Tci2_b[i + 4];
        d5 = Tci2_b[i + 8];
        d6 = Tci2_b[i + 12];
        for (i1 = 0; i1 < 4; i1++) {
          temp_tmp = i1 << 2;
          T[i + temp_tmp] =
              ((d3 * Tci3_ci2[temp_tmp] + d4 * Tci3_ci2[temp_tmp + 1]) +
               d5 * Tci3_ci2[temp_tmp + 2]) +
              d6 * Tci3_ci2[temp_tmp + 3];
        }
      }
      // 位置
      // 轴
      // %%雅可比矩阵各元素
      // h14 =
      // d*Tci2_b(1:3,1:3)*TurnY(phi_i)'*cross_m([0;1;0])*TurnZ(gam3)'*[0;1;0];
      // 绕Y轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      h14_tmp[0] = s;
      h14_tmp[3] = 0.0;
      h14_tmp[6] = smax;
      h14_tmp[2] = -smax;
      h14_tmp[5] = 0.0;
      h14_tmp[8] = s;
      // 绕Z轴旋转alph角后，由新坐标到旧坐标的姿态旋转矩阵，alph的单位为rad
      b_h14_tmp[0] = absxk;
      b_h14_tmp[3] = -scale;
      b_h14_tmp[6] = 0.0;
      b_h14_tmp[1] = scale;
      b_h14_tmp[4] = absxk;
      b_h14_tmp[7] = 0.0;
      // h24 = Rci2_b*TurnY(phi_i)'*cross_m([0;1;0])*TurnZ(gam3)'*[1;0;0];
      for (i = 0; i < 3; i++) {
        h14_tmp[3 * i + 1] = iv3[i];
        b_h14_tmp[3 * i + 2] = iv4[i];
        d3 = 0.0;
        d4 = Tci1_b[i];
        d5 = Tci1_b[i + 4];
        d6 = Tci1_b[i + 8];
        smax = Tci2_b[i];
        s = Tci2_b[i + 4];
        scale = Tci2_b[i + 8];
        for (i1 = 0; i1 < 3; i1++) {
          i2 = b[3 * i1];
          absxk = d4 * static_cast<double>(i2);
          t = smax * static_cast<double>(i2);
          i2 = b[3 * i1 + 1];
          absxk += d5 * static_cast<double>(i2);
          t += s * static_cast<double>(i2);
          i2 = b[3 * i1 + 2];
          absxk += d6 * static_cast<double>(i2);
          t += scale * static_cast<double>(i2);
          jA = i + 3 * i1;
          h12_tmp[jA] = t;
          invR[jA] = absxk;
          d3 += Tci3_ci1[i + (i1 << 2)] * 25.0 * static_cast<double>(d_b[i1]);
        }
        x[i] = d3 + Tci3_ci1[i + 12];
        d3 = h12_tmp[i];
        d4 = h12_tmp[i + 3];
        d5 = h12_tmp[i + 6];
        for (i1 = 0; i1 < 4; i1++) {
          b_h12_tmp[i + 3 * i1] = (d3 * static_cast<double>(c_b[3 * i1]) +
                                   d4 * static_cast<double>(c_b[3 * i1 + 1])) +
                                  d5 * static_cast<double>(c_b[3 * i1 + 2]);
        }
        d3 = b_h12_tmp[i];
        d4 = b_h12_tmp[i + 3];
        d5 = b_h12_tmp[i + 6];
        d6 = b_h12_tmp[i + 9];
        for (i1 = 0; i1 < 4; i1++) {
          temp_tmp = i1 << 2;
          c_h12_tmp[i + 3 * i1] =
              ((d3 * Tci3_ci2[temp_tmp] + d4 * Tci3_ci2[temp_tmp + 1]) +
               d5 * Tci3_ci2[temp_tmp + 2]) +
              d6 * Tci3_ci2[temp_tmp + 3];
        }
      }
      for (i = 0; i < 3; i++) {
        d3 = Tci2_b[i];
        d4 = Tci2_b[i + 4];
        d5 = Tci2_b[i + 8];
        for (i1 = 0; i1 < 3; i1++) {
          b_invR[i + 3 * i1] =
              (25.0 * d3 * h14_tmp[3 * i1] + 25.0 * d4 * h14_tmp[3 * i1 + 1]) +
              25.0 * d5 * h14_tmp[3 * i1 + 2];
        }
        d3 = b_invR[i];
        d4 = b_invR[i + 3];
        d5 = b_invR[i + 6];
        for (i1 = 0; i1 < 3; i1++) {
          c_R_tmp[i + 3 * i1] = (d3 * static_cast<double>(b_b[3 * i1]) +
                                 d4 * static_cast<double>(b_b[3 * i1 + 1])) +
                                d5 * static_cast<double>(b_b[3 * i1 + 2]);
        }
        d3 = c_R_tmp[i];
        d4 = c_R_tmp[i + 3];
        d5 = c_R_tmp[i + 6];
        d6 = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          jA = i + 3 * i1;
          b_invR[jA] = (d3 * b_h14_tmp[3 * i1] + d4 * b_h14_tmp[3 * i1 + 1]) +
                       d5 * b_h14_tmp[3 * i1 + 2];
          d6 += invR[jA] * x[i1];
        }
        c_invR[i] = d6;
      }
      for (i = 0; i < 3; i++) {
        d3 = 0.0;
        d4 = 0.0;
        d5 = 0.0;
        d6 = h12_tmp[i];
        smax = h12_tmp[i + 3];
        s = h12_tmp[i + 6];
        scale = invR[i];
        absxk = invR[i + 3];
        t = invR[i + 6];
        for (i1 = 0; i1 < 3; i1++) {
          temp_tmp = i1 << 2;
          jA = i + temp_tmp;
          d3 += -25.0 * T[jA] * static_cast<double>(e_b[i1]);
          jBcol = d_b[i1];
          jp1j = i + 3 * i1;
          d4 += b_invR[jp1j] * static_cast<double>(jBcol);
          d5 += Tci2_b[jA] * static_cast<double>(jBcol);
          b_R_tmp[jp1j] =
              (d6 * Tci3_ci2[temp_tmp] + smax * Tci3_ci2[temp_tmp + 1]) +
              s * Tci3_ci2[temp_tmp + 2];
          b_invR[jp1j] =
              (scale * Tci3_ci1[temp_tmp] + absxk * Tci3_ci1[temp_tmp + 1]) +
              t * Tci3_ci1[temp_tmp + 2];
        }
        d6 = Tci2_b[i];
        smax = Tci2_b[i + 4];
        s = Tci2_b[i + 8];
        for (i1 = 0; i1 < 3; i1++) {
          invR[i + 3 * i1] =
              (d6 * h14_tmp[3 * i1] + smax * h14_tmp[3 * i1 + 1]) +
              s * h14_tmp[3 * i1 + 2];
        }
        d6 = invR[i];
        smax = invR[i + 3];
        s = invR[i + 6];
        for (i1 = 0; i1 < 3; i1++) {
          c_R_tmp[i + 3 * i1] = (d6 * static_cast<double>(b_b[3 * i1]) +
                                 smax * static_cast<double>(b_b[3 * i1 + 1])) +
                                s * static_cast<double>(b_b[3 * i1 + 2]);
        }
        d6 = c_R_tmp[i];
        smax = c_R_tmp[i + 3];
        s = c_R_tmp[i + 6];
        scale = 0.0;
        absxk = 0.0;
        t = 0.0;
        R_tmp = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          double d7;
          d7 = (d6 * b_h14_tmp[3 * i1] + smax * b_h14_tmp[3 * i1 + 1]) +
               s * b_h14_tmp[3 * i1 + 2];
          jA = i + 3 * i1;
          invR[jA] = d7;
          jBcol = e_b[i1];
          scale += b_invR[jA] * static_cast<double>(jBcol);
          absxk += b_R_tmp[jA] * static_cast<double>(jBcol);
          t += T[i + (i1 << 2)] * static_cast<double>(d_b[i1]);
          R_tmp += d7 * static_cast<double>(jBcol);
        }
        Jaco1[i] = c_invR[i];
        Jaco1[i + 6] = ((c_h12_tmp[i] * 0.0 + c_h12_tmp[i + 3] * 25.0) +
                        c_h12_tmp[i + 6] * 0.0) +
                       c_h12_tmp[i + 9];
        Jaco1[i + 12] = d3;
        Jaco1[i + 18] = d4;
        Jaco1[i + 24] = d5;
        Jaco1[i + 3] = scale;
        Jaco1[i + 9] = absxk;
        Jaco1[i + 15] = t;
        Jaco1[i + 21] = R_tmp;
        Jaco1[i + 27] = 0.0;
      }
      // p0(4)=[];%把齐次坐标变为普通坐标
      for (i = 0; i < 4; i++) {
        b_GUp_fix[i] =
            ((T[i] * 0.0 + T[i + 4] * 25.0) + T[i + 8] * 0.0) + T[i + 12];
      }
      for (i = 0; i < 3; i++) {
        jA = i + 3 * ii;
        dpa[i] = b_GUp_fix[i] - GUp_fix[jA];
        dpa[i + 3] = ((T[i] + T[i + 4] * 0.0) + T[i + 8] * 0.0) - axis_b[jA];
      }
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < 5; i1++) {
          y_tmp[i1 + 5 * i] = Jaco1[i + 6 * i1];
        }
      }
      for (i = 0; i < 5; i++) {
        for (i1 = 0; i1 < 5; i1++) {
          d3 = 0.0;
          for (temp_tmp = 0; temp_tmp < 6; temp_tmp++) {
            d3 += y_tmp[i + 5 * temp_tmp] * Jaco1[temp_tmp + 6 * i1];
          }
          A[i + 5 * i1] = d3;
        }
        ipiv[i] = static_cast<signed char>(i + 1);
      }
      for (int j{0}; j < 4; j++) {
        int b_tmp;
        int mmj_tmp;
        mmj_tmp = 3 - j;
        b_tmp = j * 6;
        jp1j = b_tmp + 2;
        jA = 5 - j;
        jBcol = 0;
        smax = std::abs(A[b_tmp]);
        for (int k{2}; k <= jA; k++) {
          s = std::abs(A[(b_tmp + k) - 1]);
          if (s > smax) {
            jBcol = k - 1;
            smax = s;
          }
        }
        if (A[b_tmp + jBcol] != 0.0) {
          if (jBcol != 0) {
            jA = j + jBcol;
            ipiv[j] = static_cast<signed char>(jA + 1);
            for (int k{0}; k < 5; k++) {
              temp_tmp = j + k * 5;
              s = A[temp_tmp];
              jBcol = jA + k * 5;
              A[temp_tmp] = A[jBcol];
              A[jBcol] = s;
            }
          }
          i = (b_tmp - j) + 5;
          for (temp_tmp = jp1j; temp_tmp <= i; temp_tmp++) {
            A[temp_tmp - 1] /= A[b_tmp];
          }
        }
        jA = b_tmp;
        for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
          smax = A[(b_tmp + jp1j * 5) + 5];
          if (smax != 0.0) {
            i = jA + 7;
            i1 = (jA - j) + 10;
            for (jBcol = i; jBcol <= i1; jBcol++) {
              A[jBcol - 1] += A[((b_tmp + jBcol) - jA) - 6] * -smax;
            }
          }
          jA += 5;
        }
        i2 = ipiv[j];
        if (i2 != j + 1) {
          for (jp1j = 0; jp1j < 6; jp1j++) {
            temp_tmp = j + 5 * jp1j;
            s = y_tmp[temp_tmp];
            jA = (i2 + 5 * jp1j) - 1;
            y_tmp[temp_tmp] = y_tmp[jA];
            y_tmp[jA] = s;
          }
        }
      }
      for (int j{0}; j < 6; j++) {
        jBcol = 5 * j;
        for (int k{0}; k < 5; k++) {
          jp1j = 5 * k;
          i = k + jBcol;
          if (y_tmp[i] != 0.0) {
            i1 = k + 2;
            for (temp_tmp = i1; temp_tmp < 6; temp_tmp++) {
              jA = (temp_tmp + jBcol) - 1;
              y_tmp[jA] -= y_tmp[i] * A[(temp_tmp + jp1j) - 1];
            }
          }
        }
      }
      for (int j{0}; j < 6; j++) {
        jBcol = 5 * j;
        for (int k{4}; k >= 0; k--) {
          jp1j = 5 * k;
          i = k + jBcol;
          d3 = y_tmp[i];
          if (d3 != 0.0) {
            y_tmp[i] = d3 / A[k + jp1j];
            for (temp_tmp = 0; temp_tmp < k; temp_tmp++) {
              jA = temp_tmp + jBcol;
              y_tmp[jA] -= y_tmp[i] * A[temp_tmp + jp1j];
            }
          }
        }
      }
      for (i = 0; i < 5; i++) {
        d3 = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d3 += y_tmp[i + 5 * i1] * dpa[i1];
        }
        dx[i] = d3;
      }
      // 左除求解方程组
      // 修正
      gam1 -= dx[0];
      if (gam1 > 1.5707963267948966) {
        gam1 = 1.5707963267948966;
      }
      if (gam1 < -1.5707963267948966) {
        gam1 = -1.5707963267948966;
      }
      gam2 -= dx[1];
      if (gam2 > 1.5707963267948966) {
        gam2 = 1.5707963267948966;
      }
      if (gam2 < -1.5707963267948966) {
        gam2 = -1.5707963267948966;
      }
      gam3 -= dx[2];
      if (gam3 > 1.5707963267948966) {
        gam3 = 1.5707963267948966;
      }
      if (gam3 < -1.5707963267948966) {
        gam3 = -1.5707963267948966;
      }
      phi_i -= dx[3];
      if (phi_i > 3.1730085801256909) {
        phi_i = 3.1730085801256909;
      }
      if (phi_i < -3.1730085801256909) {
        phi_i = -3.1730085801256909;
      }
      if (phi_i > 3.1415926535897931) {
        phi_i -= 6.2831853071795862;
      }
      if (phi_i < -3.1415926535897931) {
        phi_i += 6.2831853071795862;
      }
      Li -= dx[4];
      if (Li < 190.0) {
        Li = 190.0;
      }
      if (Li > 1000.0) {
        Li = 1000.0;
      }
      smax = 0.0;
      scale = 3.3121686421112381E-170;
      for (int k{0}; k < 6; k++) {
        absxk = std::abs(dpa[k]);
        if (absxk > scale) {
          t = scale / absxk;
          smax = smax * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          smax += t * t;
        }
      }
      smax = scale * std::sqrt(smax);
      if (smax < 1.0E-10) {
        exitg1 = true;
      } else {
        jj++;
      }
    }
    // norm([p01-p0;a01-a0]);
    L[ii] = Li;
  }
  return L;
}

PYBIND11_MODULE(stewart_ik, m) {
    m.def("config_arm", [](py::array_t<double, py::array::c_style | py::array::forcecast> q_d) {
        if (q_d.size() != 6) {
            throw std::runtime_error("Input must be of size 6");
        }
        double q_d_array[6];
        std::memcpy(q_d_array, q_d.data(), sizeof(double) * 6);
        return config_arm(q_d_array);
    }, "Calculates the arm lengths for the Stewart platform.");
}