#pragma once

/// @brief Based on https://github.com/ocornut/imgui/discussions/3862#discussioncomment-422097
/// @param alignment Normalized (0.5f = centered)
/// @param fmt The text that is rendered. Same as passing a formatted string to printf, with its arguments after.
void ImGuiTextAligned(float alignment, const char *fmt, ...);

void renderImGUIFrame(void *appstate);
