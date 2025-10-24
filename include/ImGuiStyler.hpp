#pragma once

#include "imgui.h"

class ImGuiStyler {
private:
  static void StyleColorsCustom(ImVec4 txt,
                                ImVec4 bgLr, ImVec4 bgL, ImVec4 bg, ImVec4 bgD, ImVec4 bgDr,
                                ImVec4 accL, ImVec4 acc, ImVec4 accD,
                                ImVec4 accAltL, ImVec4 accAlt, ImVec4 accAltD);

public:
  static void StyleFormat();
  static void StyleColorsCustomDark();
  static void StyleColorsCustomLight();
};

// TODO: config ImGuiIO also
