#pragma once

#include "Graphics/Framebuffer.h"
#include "Shader.h"

class PostEffect
{
public:
	//initialize this effects [will be overriden in each derived class]
	virtual void Init(unsigned width, unsigned height);

	//applies the effect
	virtual void ApplyEffect(PostEffect* previousBuffer);
	virtual void DrawToScreen();

	//reshapes the buffer
	virtual void Reshape(unsigned width, unsigned height);

	//clears the buffers
	void clear();

	//unloads the buffers
	void unload();

	//binds buffers
	void BindBuffer(int index);
	void unbindBuffer();

	//bind textures
	void BindColorAsTexture(int index, int colorBuffer, int textureSlot);
	void BindDepthAsTexture(int index, int textureSlot);
	void UnbindTexture(int textureSlot);

	//bind shaders
	void BindShader(int index);
	void UnbindShader();

protected:
	//holds all our buffers for the effects
	std::vector<Framebuffer*>_buffers;
	//holds all our shaders for the effects
	std::vector<Shader::sptr>_shaders;
};