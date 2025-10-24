#pragma once

/// @brief Based on https://github.com/ocornut/imgui/discussions/3862#discussioncomment-422097
/// @param textElement The text that is rendered. Used to calculate its px width
/// @param alignment Normalized (0.5f = centered)
void alignNextImguitextElement(const char *textElement, float alignment = 0.5f);

void renderImGUIFrame(void *appstate);
