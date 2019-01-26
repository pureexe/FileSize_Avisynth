// FileSize_Avisynth.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "avisynth.h"
#include <fstream>

const AVS_Linkage *AVS_linkage = 0;

std::ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

AVSValue __cdecl FileSize_calculation(AVSValue args, void* user_data, IScriptEnvironment* env)
{
	// Validate Input
	if (!args[0].IsString()) {
		env->ThrowError("FileSize: input must be string!");
	}
	//use float to avoid int overflow
	float fileLenght = (float) filesize(args[0].AsString());
	return (AVSValue) fileLenght;
}

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors) {
	AVS_linkage = vectors;
	env->AddFunction("FileSize", "s", FileSize_calculation, 0);
	return "MD5 plugin";
}
