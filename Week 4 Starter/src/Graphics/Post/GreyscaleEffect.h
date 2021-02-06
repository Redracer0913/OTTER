#pragma once

#include "Graphics/Post/PostEffect.h"

class GreyscaleEffect : public PostEffect
{
public:
// initializes framebuffer
	//overrides post effect Init
	void Init(unsigned width, unsigned height) override;

	//applies the effect to this buffer
	//passes the previous frame buffer with texture to apply as a parameter
	void ApplyEffect(PostEffect* buffer) override;

	//applies the effect to the screen
	//void DrawToScreen() override;
	//getters
	float GetIntensity() const;

	//setters
	void SetIntensity(float intensity);
private:
	float _intensity = 1.0f;
};