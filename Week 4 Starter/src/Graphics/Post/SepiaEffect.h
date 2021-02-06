#pragma once

#include "Graphics/Post/PostEffect.h"

class SepiaEffect : public PostEffect
{
public:
	//initializes framebuffer
	void Init(unsigned width, unsigned height) override;

	//applies effect to this buffer
	void ApplyEffect(PostEffect* buffer) override;

	//getters
	float GetIntensity() const;

	//setters
	void SetIntensity(float intensity);
private:
	float _intensity = 0.7f;
};